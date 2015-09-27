<?hh

include_once 'kmk.hh';

class AboutVectors extends PHPUnit_Framework_TestCase {

  public function test_creating_vectors() {
    $empty_vector = Vector {};
    $this->assertEquals('object', gettype($empty_vector));
    $this->assertEquals('HH\Vector', get_class($empty_vector));
    $this->assertEquals(0,    $empty_vector->count());
    $this->assertEquals(true, $empty_vector->isEmpty());
  }

  public function test_vector_adding() {
    $vector = Vector {};

    $vector[] = 1;
    $this->assertEquals(Vector {1}, $vector);

    try {
      $vector[1] = 2;
    } catch(OutOfBoundsException $e) {
      // Vectors will throw an OutOfBoundsException when setting a key that is
      // out of range.  This is a bad way to push elements to an array / vector.
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

  public function test_splicing_vectors() {
    $vector = Vector {'eat', 'sleep', 'rave', 'repeat'};
    $result = $vector->splice(1, 2);

    $this->assertEquals(null, $result);
    $this->assertEquals(Vector { 'eat', 'repeat' }, $vector);
  }

  public function test_adding_and_popping_vectors() {
    $vector = Vector {1, 2};
    $vector->add('last');

    $this->assertEquals(Vector {1, 2, 'last'}, $vector);

    $popped_value = $vector->pop();
    $this->assertEquals('last', $popped_value);
    $this->assertEquals(Vector {1, 2}, $vector);
  }

}
