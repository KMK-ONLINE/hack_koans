<?hh

include_once 'kmk.hh';

class SimpleClass {
  public int $i = 123;
  public string $s = "asdf";
}

class AboutObjects extends PHPUnit_Framework_TestCase {

  public function test_these_are_not_objects() {
    $this->assertEquals('integer', gettype(1));
    $this->assertEquals(false, get_class(1));

    $this->assertEquals('double', gettype(1.5));
    $this->assertEquals(false, get_class(1.5));

    $this->assertEquals('string', gettype("string"));
    $this->assertEquals(false, get_class("string"));

    $this->assertEquals('NULL',         gettype(NULL));
    $this->assertEquals('AboutObjects', get_class(NULL));
  }

  public function test_objects() {
    $instance = new SimpleClass();
    $this->assertEquals(123,    $instance->i);
    $this->assertEquals("asdf", $instance->s);

    // TODO: how could I get this checked / expose
    // type checking at runtime w/o using just functions.
    //
    // $instance->i = "asdf";
    // $instance->s = 123;
    //
    // $this->assertEquals("asdf", $instance->i);
    // $this->assertEquals(123,    $instance->s);
  }

}
