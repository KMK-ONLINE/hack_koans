<?hh

include_once 'kmk.hh';

class AboutArrays extends PHPUnit_Framework_TestCase {

  public function test_creating_arrays() {
    // Old style initialization
    $old_array = array();
    $this->assertEquals('array', gettype($old_array));
    $this->assertEquals(false, get_class($old_array));
    $this->assertEquals(0, count($old_array));

    // New literal initialization
    $new_array = [];
    $this->assertEquals('array', gettype($new_array));
    $this->assertEquals(false, get_class($new_array));
    $this->assertEquals(0, count($new_array));

    $this->assertEquals($new_array, $old_array);
  }

  public function test_array_pushing() {
    $array = [];

    $array[] = 1;
    $this->assertEquals([1], $array);

    $array[1] = 2;
    $this->assertEquals([1, 2], $array);

    array_push($array, 333);
    $this->assertEquals([1, 2, 333], $array);
  }

  public function test_accessing_array_elements() {
    $array = ['eat', 'sleep', 'rave', 'repeat'];

    $this->assertEquals('eat', $array[0]);
    $this->assertEquals('repeat', $array[3]);
  }

  /**
   * @expectedException              Exception
   * @expectedExceptionMessage       Undefined index: -1
   * @expectedExceptionCode          8
   */
  public function test_accessing_invalid_indexes() {
    $array = ['eat', 'sleep', 'rave', 'repeat'];
    $array[-1];
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

  public function test_pushing_and_popping_arrays() {
    $array = [1, 2];
    array_push($array, 'last');

    $this->assertEquals([1, 2, 'last'], $array);

    $popped_value = array_pop($array);
    $this->assertEquals('last', $popped_value);
    $this->assertEquals([1, 2], $array);
  }

  public function test_shifting_arrays() {
    $array = [1, 2];
    array_unshift($array, 'first');

    $this->assertEquals(['first', 1, 2], $array);

    $shifted_value = array_shift($array);
    $this->assertEquals('first', $shifted_value);
    $this->assertEquals([1, 2], $array);
  }

}
