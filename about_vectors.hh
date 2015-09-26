<?hh

include_once 'kmk.hh';

class AboutVectors extends PHPUnit_Framework_TestCase {

  public function test_creating_vectors() {
    $empty_vector = Vector {};
    $this->assertEquals('object', gettype($empty_vector));
    $this->assertEquals(0,    $empty_vector->count());
    $this->assertEquals(true, $empty_vector->isEmpty());
  }

  public function test_vector_literal_adding() {
    $vector = Vector {};

    $vector[] = 1;
    $this->assertEquals(Vector {1}, $vector);

    try {
      $vector[1] = 2;
    } catch(OutOfBoundsException $e) {
      // Vectors will throw an OutOfBoundsException if the key is out of bounds
    }

    $this->assertEquals(Vector {1}, $vector);

    $vector->add(333);
    $this->assertEquals(Vector {1, 333}, $vector);
  }

  public function test_accessing_vector_elements() {
    $vector = Vector {'eat', 'sleep', 'rave', 'repeat'};

    $this->assertEquals('eat', $vector->at(0));
    $this->assertEquals('repeat', $vector->at(3));
  }

  /**
   * @expectedException              OutOfBoundsException
   * @expectedExceptionMessage       Integer key -1 is out of bounds
   * @expectedExceptionCode          0
   */
  public function test_accessing_invalid_indexes() {
    $vector = Vector {'eat', 'sleep', 'rave', 'repeat'};
    $vector[-1];
  }

  public function test_accessing_invalid_indexes_can_be_caught() {
    $vector = Vector {'eat', 'sleep', 'rave', 'repeat'};

    try {
      $vector[-1];
    } catch(OutOfBoundsException $e) {
      $this->assertEquals("Integer key -1 is out of bounds",
                          $e->getMessage());
    }

    try {
      $vector->at(-1);
    } catch(OutOfBoundsException $e) {
      $this->assertEquals("Integer key -1 is out of bounds",
                          $e->getMessage());
    }

    $this->assertEquals(null, $vector->get(-1));
  }

  public function test_array_class_is_false() {
    $array = array();
    $class = get_class($array);
    $this->assertEquals(false, $class);
  }

}
