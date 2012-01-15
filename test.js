
// test.js - script to test the built module
(function() {
  
  var util = require('util');

  function test(summary, func) {
    try {
      console.log(summary);
      return func();

    } catch (e) {
      console.log(e);
      process.exit(1);
    }
  }
  
  var nx = test("Loading module.", function() {
    return require('./build/Release/nx');
  });

  var obj = test("`new NxObject()`", function() {
    return new nx.NxObject();
  });

  test("Inspecting the instance.", function() {
    console.log(util.inspect(obj));
  });
  
})();
