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

    static Handle<Value> GetCount(Local<String> property, const AccessorInfo& info);
    static void SetCount(Local<String> property, Local<Value> value, const AccessorInfo& info);
    static Handle<Value> IncrementCount(const Arguments& args);
};
