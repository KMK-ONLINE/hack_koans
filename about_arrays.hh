<?hh

include_once 'kmk.hh';

class AboutArrays extends PHPUnit_Framework_TestCase {

  public function test_creating_arrays() {
    $empty_array = array();
    $this->assertEquals('array', gettype($empty_array));
    $this->assertEquals(0, count($empty_array));
  }

  public function test_array_literal_pushing() {
    $array = array();
    $this->assertEquals([], $array);

    $array[] = 1;
    $this->assertEquals([1], $array);

    $array[1] = 2;
    $this->assertEquals([1, 2], $array);

    array_push($array, 333);
    $this->assertEquals([1, 2, 333], $array);
  }

  public function test_accessing_array_elements() {
    $array = array('eat', 'sleep', 'rave', 'repeat');

    $this->assertEquals('eat', $array[0]);
    $this->assertEquals('repeat', $array[3]);
  }

  /**
   * @expectedException              Exception
   * @expectedExceptionMessage       Undefined index: -1
   * @expectedExceptionCode          8
   */
  public function test_accessing_invalid_indexes() {
    $array = array('eat', 'sleep', 'rave', 'repeat');
    print $array[-1];
  }

  public function test_slicing_arrays() {
    $array = array('eat', 'sleep', 'rave', 'repeat');
    $this->assertEquals(['eat'],            array_slice($array, 0,  1));
    $this->assertEquals(['eat', 'sleep'],   array_slice($array, 0,  2));
    $this->assertEquals(['rave', 'repeat'], array_slice($array, 2,  2));
    $this->assertEquals(['rave', 'repeat'], array_slice($array, 2, 20));
    $this->assertEquals([],                 array_slice($array, 4,  0));
    $this->assertEquals([],                 array_slice($array, 4, 10));
    $this->assertEquals([],                 array_slice($array, 5,  0));
  }

  public function test_array_class_is_false() {
    $array = array();
    $class = get_class($array);
    $this->assertEquals(false, $class);
  }

}
