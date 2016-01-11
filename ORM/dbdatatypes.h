#ifndef DBDATATYPES_H
#define DBDATATYPES_H
#include <string>
#include <QDate>
#include <QColor>
#include <QDebug>

class QIDBCell{
public:
    virtual void fromString(std::string)=0;
    virtual std::string toString()const=0;
};

class QDBColor: public QIDBCell{
private:
    QColor value;
public:
    QDBColor(){}
    QDBColor(const QColor &color){
        value=color;
    }

    void fromString(std::string _value){
        value = QColor(_value.c_str());
    }
    std::string toString() const{
        return value.name().toStdString();
    }

    QColor getRawaValue(){
        return value;
    }
    void operator=(const QDBColor &assigned){
        value=assigned.value;
    }

    ~QDBColor(){
        //if(value) delete value;
    }

    static std::string getSQLDataType();
};

class QDBDate: public QIDBCell{
private:
    QDate value;
public:
    QDBDate(){
        //value = new QDate();
    }
    QDBDate(const QDate &date){
        //value = new QDate(date);
        value = date;
    }

    void fromString(std::string _value){
        value = QDate::fromString(_value.c_str(),"dd.MM.yyyy");
    }
    std::string toString() const{
        return value.toString("dd.MM.yyyy").toStdString();
    }
    QDate getRawaValue(){
        return value;
    }
    void operator=(const QDBDate &assigned){
        value=assigned.value;
    }
    ~QDBDate(){
        //if(value) delete value;
    }

    static std::string getSQLDataType();
};

class QDBString: public QIDBCell{
private:
    QString value;
public:
    QDBString(){
        //value = new QString();
    }
    QDBString(const QString &string){
        //value = new QString(string);
        value = string;
    }

    void fromString(std::string _value){
        value = QString::fromStdString(_value);
    }
    std::string toString() const{
        return value.toStdString();
    }

    QString getRawaValue(){
        return value;
    }
    void operator=(const QDBString &assigned){
        value=assigned.value;
    }
    ~QDBString(){
        //if(value) delete value;
    }
    static std::string getSQLDataType();
};

template<typename CellEnum>
class QDBEnum:public QIDBCell{
private:
    CellEnum value;
public:
    QDBEnum(){

    }
    QDBEnum(const CellEnum &enum_value){
        value=enum_value;
    }

    void fromString(std::string _value){
        value=static_cast<CellEnum>(std::stoi(_value));
    }

    std::string toString() const{
        return std::to_string(static_cast<int>(value));
    }
    CellEnum getRawaValue(){
        return value;
    }

    void operator=(const CellEnum &assigned){
        value=assigned.value;
    }
    static std::string getSQLDataType();
};

template<typename CellType>
std::string QDBEnum<CellType>::getSQLDataType(){
    return "INTEGER";
}

#endif // DBDATATYPES_H

