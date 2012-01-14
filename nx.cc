#include <stdio.h>
#define BUILDING_NODE_EXTENSION 1
#include <v8.h>
#include <node.h>

using namespace v8;
using namespace node;

static Persistent<FunctionTemplate> s_ct;
