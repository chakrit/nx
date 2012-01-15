
// test.js - script to test the built module
(function() {
  
  var util = require('util');

  function test(summary, func) {
    try {
      console.log(summary);
      var result = func();
      console.log('... ok.');

      return func();

    } catch (e) {
      console.log(e);
      process.exit(1);
    }
  }
  
  var nx = test("Loading module.", function() { return require('../build/Release/nx'); });
  var obj = test("`new NxObject()`", function() { return new nx.NxObject(); });

  test("Inspecting the instance.", function() { util.inspect(obj); });
  
  var count = test("Incrementing count.", function() { return obj.incrementCount(); });
  console.log("Count = %d", count);
  
  count = test("Get count.", function() { return obj.count; });
  console.log("Count = %d", count);

  count = test("Set count to 7.", function() { return obj.count = 7; });
  count = test("Get count (again)", function() { return obj.count });
  console.log("Count = %d", count);
  
})();
