(function() {
  var Animal, animal;

  Animal = (function() {
    function Animal(name) {
      this.name = name;
    }

    return Animal;

  })();

  animal = new Animal("sheep");

}).call(this);
