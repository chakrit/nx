#include <v8.h>
#include "NxObject.hh"

using namespace v8;
using namespace node;

// persistent store for v8 js function template
static Persistent<FunctionTemplate> createNxObjectTmpl; 

Handle<Value>
createNxObject(const Arguments& args) {
  HandleScope scope;

  Local<Value> obj = NxObject::GetFunctionTemplate()->InstanceTemplate()->NewInstance();
  return scope.Close(obj);
}

// node module entry point
void
init(Handle<Object> target)
{
  HandleScope scope;

  // export the NxObject class
  target->Set(String::NewSymbol("NxObject"), NxObject::GetFunctionTemplate()->GetFunction());

  // export the createNxObject function
  createNxObjectTmpl = Persistent<FunctionTemplate>::New(FunctionTemplate::New(createNxObject));
  target->Set(String::NewSymbol("createNxObject"), createNxObjectTmpl->GetFunction());
}

NODE_MODULE(nx, init)
