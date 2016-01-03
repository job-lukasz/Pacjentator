#ifndef DBDATATYPES_H
#define DBDATATYPES_H
#include <string>
#include <QDate>
#include <QColor>

class QIDBCell{
public:
    virtual void fromString(const std::string&)=0;
    virtual std::string toString()=0;
};

class QDBDate: public QIDBCell{
private:
    QDate value;
public:
    QDBDate(){}
    QDBDate(const QDate &date){
        value = date;
    }

    void fromString(const std::string &_value){
        value = QDate().fromString(_value.c_str());
    }
    std::string toString(){
        return value.toString().toStdString();
    }
    QDate getRawaValue(){
        return value;
    }
};

class QDBColor: public QIDBCell{
private:
    QColor value;
public:
    QDBColor(){}
    QDBColor(const QColor &color){
        value=color;
    }

    void fromString(const std::string& _value){
        value = QColor("black");
    }
    std::string toString(){
        return "black";
    }

    QColor getRawaValue(){
        return value;
    }
};

class QDBString: public QIDBCell{
private:
    QString value;
public:
    QDBString(){}
    QDBString(const QString &string){
        value=string;
    }

    void fromString(const std::string& _value){
        value = QString().fromStdString(_value);
    }
    std::string toString(){
        return value.toStdString();
    }

    QString getRawaValue(){
        return value;
    }
};

template<typename CellEnum>
class QDBEnum:public QIDBCell{
private:
    CellEnum value;
public:
    QDBEnum(){}
    QDBEnum(const CellEnum &enum_value){
        value=enum_value;
    }

    void fromString(const std::string &_value){
        value = static_cast<CellEnum>(std::stoi(_value));
    }

    std::string toString(){
        return std::to_string(static_cast<int>(value));
    }
    CellEnum getRawaValue(){
        return value;
    }
};

#endif // DBDATATYPES_H

