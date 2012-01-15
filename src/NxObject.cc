#include "NxObject.hh"

using namespace v8;
using namespace node;

// persistent store for function template
static Persistent<FunctionTemplate> funcTemplate = Persistent<FunctionTemplate>();

Handle<FunctionTemplate>
NxObject::GetFunctionTemplate(void) {
  HandleScope scope;
  if (funcTemplate.IsEmpty()) {
    funcTemplate = Persistent<FunctionTemplate>::New(FunctionTemplate::New(NxObject::New));
    funcTemplate->InstanceTemplate()->SetInternalFieldCount(1);
    funcTemplate->SetClassName(String::NewSymbol("NxObject"));
  }

  return funcTemplate;
}

Handle<Value>
New(const Arguments& args) {
  NxObject *obj = new NxObject();
  obj->Init(args.This());

  return args.This();
}


NxObject::NxObject() : ObjectWrap(), _count(0) {
}

NxObject::~NxObject() {
}

void
NxObject::Init(Handle<Object> target) {
  this->Wrap(target);
  //TODO: Add members
}

int
NxObject::getCount() { 
  return _count;
}

void
NxObject::setCount(int value) {
  _count = value;
}
