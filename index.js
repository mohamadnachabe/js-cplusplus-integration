var addon = require('bindings')('echo');

console.log(addon.echo('hello world from javascript!'));
