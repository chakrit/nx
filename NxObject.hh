#include <v8.h>
#include <node.h>

using namespace v8;
using namespace node;

class NxObject : ObjectWrap {
  private:
    int _count;

  public:
    static Handle<FunctionTemplate> GetFunctionTemplate(void);
    static Handle<Value> New(const Arguments& args);

    NxObject();
    ~NxObject();
    void Init(Handle<Object> target);

    int getCount();
    void setCount(int value);
};
