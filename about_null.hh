<?hh // strict

require 'vendor/autoload.php';

class AboutNull extends PHPUnit_Framework_TestCase {

  public function test_null_is_a_type() {
    $x = NULL;
    $this->assertTrue(is_null($x));
    $this->assertEquals('NULL', gettype($x), "Just like NULL in other languages");
  }

}
