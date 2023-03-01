#include <iostream>
#include <string>
using namespace std;


class Image{
    public:
        operator string() {
            return "사진";
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

void printMessage(Message &m) {
    cout << "보낸 시간 : " << m.GetSendTime() << endl;
    cout << "보낸 사람 : " << m.GetSendName() << endl;
    cout << "  내용 " << m.GetContent() << endl;
    cout << endl;
}

int main() {

    Image *dogImage = new Image;

    Message *messages[] = {
        new TextMessage(10, "민국", "안녕"),
        new ImageMessage(20, "민국", dogImage),
        new TextMessage(30, "민국", "잘가")
    }
    
    for (Message *m : messages) {
        printMessage(*m);
    }
    
    for (Message *m : messages) {
        delete m;
    }
    
    delete dogImage;

}