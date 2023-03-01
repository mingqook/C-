#include <iostream>
using namespace std;


class Image{
    public:
        operator string() {
            return "����";
        }
};

class Message {
    public:
        Message(int sendTime, string sendName) {
            this -> sendTime = sendTime;
            this -> sendName = sendName;
        }
        virtual ~Message() {

        }
        
        int GetSendTime() const { 
            return sendTime;
        }

        string GetSendName() const {
            return sendName;
        }

        virtual string GetContent() const {
            return "";
        }
    private :
        int sendTime;
        string sendName;
};

class TextMessage : public Message {
    public:
        TextMessage(int sendTime, string sendName, string text)
            : Message(sendTime, sendName) {
            this -> text = text;
        }

        string GetContent() const {
            return text;
        }
    private:
        string text;
};

class ImageMessage : public Message {
    public:
        ImageMessage(int sendTime, string sendName, Image *image) 
            : Message(sendTime, sendName) {
            this -> image = image;
        }

        string GetContent() const {
            return (string)*image;
        }
    private:
        Image *image;
};

void printMessage(Message *m) {
    cout << "���� �ð� : " << m -> GetSendTime() << endl;
    cout << "���� ��� : " << m -> GetSendName() << endl;
    cout << "  ���� " << m -> GetContent() << endl;
    cout << endl;
}

int main() {

    Image *dogImage = new Image;
    TextMessage *hello = new TextMessage(10, "�α�", "�ȳ�");
    ImageMessage *dog = new ImageMessage(20, "�α�", dogImage);
    
    printMessage(hello);
    printMessage(dog);

    delete dogImage;
    delete hello;
    delete dog;
}