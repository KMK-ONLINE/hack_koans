<?hh // strict

require 'vendor/autoload.php';

class AboutArrays extends PHPUnit_Framework_TestCase {

  // Local variables cannot be statically typed :-/
  // their types are inferred by arguments or parameters.
  public function test_creating_arrays() {
    $empty_array = array();
    $this->assertEquals('array', gettype($empty_array));
    $this->assertEquals(0, count($empty_array));
  }

  // Instance variables can be typed.
  private int $variable_of_integer = 0;
  private array<int> $array_of_integers = array();

  public function test_arrays_with_type() {
    $this->variable_of_integer = "foobar";

    $this->assertEquals('array', gettype($this->array_of_integers));

    $this->array_of_integers[] = 1;
    $this->assertEquals(1, count($this->array_of_integers));
  }

  public function test_arrays_with_type_throw_exceptions() {
    $this->array_of_integers[] = "foobar";
    $this->assertEquals(1, count($this->array_of_integers));
  }

  // def test_creating_arrays
  //   empty_array = Array.new
  //   assert_equal __, empty_array.class
  //   assert_equal __, empty_array.size
  // end
  //
  // def test_array_literals
  //   array = Array.new
  //   assert_equal [], array
  //
  //   array[0] = 1
  //   assert_equal [1], array
  //
  //   array[1] = 2
  //   assert_equal [1, __], array
  //
  //   array << 333
  //   assert_equal __, array
  // end
  //
  // def test_accessing_array_elements
  //   array = [:peanut, :butter, :and, :jelly]
  //
  //   assert_equal __, array[0]
  //   assert_equal __, array.first
  //   assert_equal __, array[3]
  //   assert_equal __, array.last
  //   assert_equal __, array[-1]
  //   assert_equal __, array[-3]
  // end
  //
  // def test_slicing_arrays
  //   array = [:peanut, :butter, :and, :jelly]
  //
  //   assert_equal __, array[0,1]
  //   assert_equal __, array[0,2]
  //   assert_equal __, array[2,2]
  //   assert_equal __, array[2,20]
  //   assert_equal __, array[4,0]
  //   assert_equal __, array[4,100]
  //   assert_equal __, array[5,0]
  // end
  //
  // def test_arrays_and_ranges
  //   assert_equal __, (1..5).class
  //   assert_not_equal [1,2,3,4,5], (1..5)
  //   assert_equal __, (1..5).to_a
  //   assert_equal __, (1...5).to_a
  // end
  //
  // def test_slicing_with_ranges
  //   array = [:peanut, :butter, :and, :jelly]
  //
  //   assert_equal __, array[0..2]
  //   assert_equal __, array[0...2]
  //   assert_equal __, array[2..-1]
  // end
  //
  // def test_pushing_and_popping_arrays
  //   array = [1,2]
  //   array.push(:last)
  //
  //   assert_equal __, array
  //
  //   popped_value = array.pop
  //   assert_equal __, popped_value
  //   assert_equal __, array
  // end
  //
  // def test_shifting_arrays
  //   array = [1,2]
  //   array.unshift(:first)
  //
  //   assert_equal __, array
  //
  //   shifted_value = array.shift
  //   assert_equal __, shifted_value
  //   assert_equal __, array
  // end



}
