#ifndef GRACEFUL_DATAMAP_H
#define GRACEFUL_DATAMAP_H

#include <QMap>
#include <QObject>
#include <QPaintDevice>

#include "graceful.h"
#include "graceful-export.h"


namespace Graceful
{
//* data map
/** it maps templatized data object to associated object */
template<typename K, typename T> class GRACEFUL_EXPORT BaseDataMap : public QMap<const K *, WeakPointer<T>>
{
public:
    using Key = const K *;
    using Value = WeakPointer<T>;

    //* constructor
    BaseDataMap()
        : QMap<Key, Value>()
        , _enabled(true)
        , _lastKey(NULL)
    {
    }

    //* destructor
    virtual ~BaseDataMap()
    {
    }

    //* insertion
    virtual typename QMap<Key, Value>::iterator insert(const Key &key, const Value &value, bool enabled = true)
    {
        if (value) {
            value.data()->setEnabled(enabled);
        }
        return QMap<Key, Value>::insert(key, value);
    }

    //* find value
    Value find(Key key)
    {
        if (!(enabled() && key)) {
            return Value();
        }
        if (key == _lastKey) {
            return _lastValue;
        } else {
            Value out;
            typename QMap<Key, Value>::iterator iter(QMap<Key, Value>::find(key));
            if (iter != QMap<Key, Value>::end()) {
                out = iter.value();
            }
            _lastKey = key;
            _lastValue = out;
            return out;
        }
    }

    //* unregister widget
    bool unregisterWidget(Key key)
    {
        // check key
        if (!key) {
            return false;
        }

        // clear last value if needed
        if (key == _lastKey) {
            if (_lastValue) {
                _lastValue.clear();
            }
            _lastKey = NULL;
        }

        // find key in map
        typename QMap<Key, Value>::iterator iter(QMap<Key, Value>::find(key));
        if (iter == QMap<Key, Value>::end()) {
            return false;
        }

        // delete value from map if found
        if (iter.value()) {
            iter.value().data()->deleteLater();
        }
        QMap<Key, Value>::erase(iter);

        return true;
    }

    //* maxFrame
    void setEnabled(bool enabled)
    {
        _enabled = enabled;
        for (auto value = this->constBegin(); value != this->constEnd(); ++value) {
            if (*value) {
                value->data()->setEnabled(enabled);
            }
        }
    }

    //* enability
    bool enabled() const
    {
        return _enabled;
    }

    //* duration
    void setDuration(int duration) const
    {
        for (auto value = this->constBegin(); value != this->constEnd(); ++value) {
            if (*value) {
                value->data()->setDuration(duration);
            }
        }
    }

private:
    //* enability
    bool _enabled;

    //* last key
    Key _lastKey;

    //* last value
    Value _lastValue;
};

//* standard data map, using QObject as a key
template<typename T> class GRACEFUL_EXPORT DataMap : public BaseDataMap<QObject, T>
{
public:
    //* constructor
    DataMap()
    {
    }

    //* destructor
    virtual ~DataMap()
    {
    }
};

//* QPaintDevice based dataMap
template<typename T> class GRACEFUL_EXPORT PaintDeviceDataMap : public BaseDataMap<QPaintDevice, T>
{
public:
    //* constructor
    PaintDeviceDataMap()
    {
    }

    //* destructor
    virtual ~PaintDeviceDataMap()
    {
    }
};

}

#endif
