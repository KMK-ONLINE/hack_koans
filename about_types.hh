<?hh

include_once 'kmk.hh';

class AboutTypes extends PHPUnit_Framework_TestCase {

  public function kembali(): int {
    return 1;
  }

  // TODO: how could I get this checked / expose
  // type checking at runtime w/o using just functions.
  //
  // private int $variable_of_integer = 0;
  // private array<int> $array_of_integers = [];
  //
  // public function test_types() {
  //   $result = $this->kembali();
  //
  //   $this->variable_of_integer = "asdf";
  //
  //   array_push($this->array_of_integers, "asdf");
  // }

}
