#include "NxObject.hh"

using namespace v8;
using namespace node;

// persistent store for function template
static Persistent<FunctionTemplate> objFuncTmpl;

Handle<FunctionTemplate>
NxObject::GetFunctionTemplate(void) {
  HandleScope scope;
  if (objFuncTmpl.IsEmpty()) {
    objFuncTmpl = Persistent<FunctionTemplate>::New(FunctionTemplate::New(NxObject::New));
    objFuncTmpl->SetClassName(String::NewSymbol("NxObject"));

    Handle<ObjectTemplate> objTmpl = objFuncTmpl->InstanceTemplate();
    objTmpl->SetInternalFieldCount(1);

    Local<Value> value = Integer::New(0);
    objTmpl->SetAccessor(String::NewSymbol("count"), NxObject::GetCount, NxObject::SetCount, value);

    Local<FunctionTemplate> incrementCountFuncTmpl = FunctionTemplate::New(NxObject::IncrementCount);
    objTmpl->Set(String::NewSymbol("incrementCount"), incrementCountFuncTmpl->GetFunction());
  }

  return scope.Close(objFuncTmpl);
}

Handle<Value>
NxObject::New(const Arguments& args) {
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

Handle<Value>
NxObject::GetCount(Local<String> property, const AccessorInfo& info) {
  HandleScope scope;

  NxObject *instance = ObjectWrap::Unwrap<NxObject>(info.Holder());
  Local<Value> value = Local<Value>::New(Integer::New(instance->_count));

  return scope.Close(value);
}

void
NxObject::SetCount(Local<String> property, Local<Value> value, const AccessorInfo& info) {
  HandleScope scope;
  if (!value->IsInt32())
    return;

  NxObject *instance = ObjectWrap::Unwrap<NxObject>(info.Holder());
  instance->_count = value->Int32Value();
}

Handle<Value>
NxObject::IncrementCount(const Arguments& args) {
  HandleScope scope;

  NxObject *instance = ObjectWrap::Unwrap<NxObject>(args.This());
  int count = instance->_count++;

  return scope.Close(Local<Value>::New(Integer::New(count)));
}
