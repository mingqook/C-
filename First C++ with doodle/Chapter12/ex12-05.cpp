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
        
        int GetSendTime() const { 
            return sendTime;
        }

        string GetSendName() const {
            return sendName;
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

        string GetText() const {
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

        Image *GetImage() const {
            return image;
        }
    private:
        Image *image;
};


int main() {

    Image *dogImage = new Image;
    TextMessage *hello = new TextMessage(10, "�α�", "�ȳ�");
    ImageMessage *dog = new ImageMessage(20, "�α�", dogImage);
    
    cout << "���� �ð� : " << hello -> GetSendTime() << endl;
    cout << "���� ��� : " << hello -> GetSendName() << endl;
    cout << "  ���� " << hello -> GetText() << endl;
    cout << endl;

    cout << "���� �ð� : " << dog -> GetSendTime() << endl;
    cout << "���� ��� : " << dog -> GetSendName() << endl;
    cout << "  ���� " << (string)*dog -> GetImage() << endl;
    cout << endl;

    delete dogImage;
    delete hello;
    delete dog;
}