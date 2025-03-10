<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Integration\Mvc\View\Engine\Volt\Compiler;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Mvc\View\Exception;

class CompileStringCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: compileString()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-01-17
     *
     * @dataProvider getVoltCompileString
     */
    public function mvcViewEngineVoltCompilerCompileString(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - compileString()");

        $param    = $example[0];
        $expected = $example[1];

        $volt = new Compiler();

        $I->assertEquals(
            $expected,
            $volt->compileString($param)
        );
    }

    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: compileString() - syntax
     * error
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-01-17
     *
     * @dataProvider getVoltCompileStringErrors
     */
    public function mvcViewEngineVoltCompilerCompileStringSyntaxError(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - compileString() - syntax error");

        $code    = $example[0];
        $message = $example[1];

        $volt = new Compiler();

        $I->expectThrowable(
            new Exception($message),
            function () use ($volt, $code) {
                $volt->compileString($code);
            }
        );
    }

    private function getVoltCompileString(): array
    {
        return [
            [
                '',
                '',
            ],
            //Comments
            [
                '{# hello #}',
                '',
            ],
            [
                '{# hello #}{# other comment #}',
                '',
            ],
            //Common Expressions
            [
                'hello',
                'hello',
            ],
            [
                '{{ "hello" }}',
                "<?= 'hello' ?>",
            ],
            [
                '{{ "hello" }}{{ "hello" }}',
                "<?= 'hello' ?><?= 'hello' ?>",
            ],
            [
                '{{ "hello" }}-{{ "hello" }}',
                "<?= 'hello' ?>-<?= 'hello' ?>",
            ],
            [
                '-{{ "hello" }}{{ "hello" }}-',
                "-<?= 'hello' ?><?= 'hello' ?>-",
            ],
            [
                '-{{ "hello" }}-{{ "hello" }}-',
                "-<?= 'hello' ?>-<?= 'hello' ?>-",
            ],
            [
                'Some = {{ 100+50 }}',
                'Some = <?= 100 + 50 ?>',
            ],
            [
                'Some = {{ 100-50 }}',
                'Some = <?= 100 - 50 ?>',
            ],
            [
                'Some = {{ 100*50 }}',
                'Some = <?= 100 * 50 ?>',
            ],
            [
                'Some = {{ 100/50 }}',
                'Some = <?= 100 / 50 ?>',
            ],
            [
                'Some = {{ 100%50 }}',
                'Some = <?= 100 % 50 ?>',
            ],
            [
                'Some = {{ 100~50 }}',
                'Some = <?= 100 . 50 ?>',
            ],
            //Unary operators
            [
                '{{ -10 }}',
                '<?= -10 ?>',
            ],
            [
                '{{ !10 }}',
                '<?= !10 ?>',
            ],
            [
                '{{ !a }}',
                '<?= !$a ?>',
            ],
            [
                '{{ not a }}',
                '<?= !$a ?>',
            ],
            //Arrays
            [
                '{% set a = [1, 2, 3, 4] %}',
                '<?php $a = [1, 2, 3, 4]; ?>',
            ],
            [
                '{% set a = ["hello", 2, 1.3, false, true, null] %}',
                '<?php $a = [\'hello\', 2, 1.3, false, true, null]; ?>',
            ],
            [
                '{% set a = ["hello", 2, 3, false, true, null, [1, 2, "hola"]] %}',
                '<?php $a = [\'hello\', 2, 3, false, true, null, [1, 2, \'hola\']]; ?>',
            ],
            [
                "{% set a = ['first': 1, 'second': 2, 'third': 3] %}",
                '<?php $a = [\'first\' => 1, \'second\' => 2, \'third\' => 3]; ?>',
            ],
            //Array access
            [
                '{{ a[0 ]}}',
                '<?= $a[0] ?>',
            ],
            [
                '{{ a[0 ] [ 1]}}',
                '<?= $a[0][1] ?>',
            ],
            [
                '{{ a[0]  [ "hello"] }}',
                '<?= $a[0][\'hello\'] ?>',
            ],
            [
                '{{ a[0] [1.2] [false] [true] }}',
                '<?= $a[0][1.2][false][true] ?>',
            ],
            //Attribute access
            [
                '{{ a.b }}',
                '<?= $a->b ?>',
            ],
            [
                '{{ a.b.c }}',
                '<?= $a->b->c ?>',
            ],
            //Ranges
            [
                '{{ 1..100 }}',
                '<?= range(1, 100) ?>',
            ],
            [
                '{{ "Z".."A" }}',
                '<?= range(\'Z\', \'A\') ?>',
            ],
            [
                "{{ 'a'..'z' }}",
                '<?= range(\'a\', \'z\') ?>',
            ],
            [
                "{{ 'a' .. 'z' }}",
                '<?= range(\'a\', \'z\') ?>',
            ],
            //Calling functions
            [
                '{{ content() }}',
                '<?= $this->getContent() ?>',
            ],
            [
                '{{ get_content() }}',
                '<?= $this->getContent() ?>',
            ],
            [
                "{{ partial('hello/x') }}",
                '<?= $this->partial(\'hello/x\') ?>',
            ],
            [
                '{{ dump(a) }}',
                '<?= var_dump($a) ?>',
            ],
            [
                "{{ date('Y-m-d', time()) }}",
                '<?= date(\'Y-m-d\', time()) ?>',
            ],
            [
                '{{ robots.getPart(a) }}',
                '<?= $robots->getPart($a) ?>',
            ],
            //Phalcon\Tag helpers
            [
                "{{ link_to('hello', 'some-link') }}",
                '<?= $this->tag->linkTo([\'hello\', \'some-link\']) ?>',
            ],
            [
                "{{ form('action': 'save/products', 'method': 'post') }}",
                '<?= $this->tag->form([\'action\' => \'save/products\', \'method\' => \'post\']) ?>',
            ],
            [
                '{{ stylesheet_link(config.cdn.css.bootstrap, config.cdn.local) }}',
                '<?= $this->tag->stylesheetLink($config->cdn->css->bootstrap, $config->cdn->local) ?>',
            ],
            [
                "{{ javascript_include('js/some.js') }}",
                '<?= $this->tag->javascriptInclude(\'js/some.js\') ?>',
            ],
            [
                "{{ image('img/logo.png', 'width': 80) }}",
                "<?= \$this->tag->image(['img/logo.png', 'width' => 80]) ?>",
            ],
            [
                "{{ email_field('email', 'class': 'form-control', 'placeholder': 'Email Address') }}",
                "<?= \$this->tag->emailField(['email', 'class' => 'form-control', " .
                "'placeholder' => 'Email Address']) ?>",
            ],
            //Filters
            [
                '{{ "hello"|e }}',
                '<?= $this->escaper->escapeHtml(\'hello\') ?>',
            ],
            [
                '{{ "hello"|escape }}',
                '<?= $this->escaper->escapeHtml(\'hello\') ?>',
            ],
            [
                '{{ "hello"|trim }}',
                '<?= trim(\'hello\') ?>',
            ],
            [
                '{{ "hello"|striptags }}',
                '<?= strip_tags(\'hello\') ?>',
            ],
            [
                '{{ "hello"|json_encode }}',
                '<?= json_encode(\'hello\') ?>',
            ],
            [
                '{{ "hello"|url_encode }}',
                '<?= urlencode(\'hello\') ?>',
            ],
            [
                '{{ "hello"|uppercase }}',
                '<?= strtoupper(\'hello\') ?>',
            ],
            [
                '{{ "hello"|lowercase }}',
                '<?= strtolower(\'hello\') ?>',
            ],
            [
                '{{ ("hello" ~ "lol")|e|length }}',
                '<?= $this->length($this->escaper->escapeHtml((\'hello\' . \'lol\'))) ?>',
            ],
            //Filters with parameters
            [
                '{{ "My name is %s, %s"|format(name, "thanks") }}',
                "<?= sprintf('My name is %s, %s', \$name, 'thanks') ?>",
            ],
            [
                '{{ "some name"|convert_encoding("utf-8", "latin1") }}',
                "<?= \$this->convertEncoding('some name', 'utf-8', 'latin1') ?>",
            ],
            //if statement
            [
                '{% if a==b %} hello {% endif %}',
                '<?php if ($a == $b) { ?> hello <?php } ?>',
            ],
            [
                '{% if a!=b %} hello {% endif %}',
                '<?php if ($a != $b) { ?> hello <?php } ?>',
            ],
            [
                '{% if a is not b %} hello {% endif %}',
                '<?php if ($a != $b) { ?> hello <?php } ?>',
            ],
            [
                '{% if a<b %} hello {% endif %}',
                '<?php if ($a < $b) { ?> hello <?php } ?>',
            ],
            [
                '{% if a>b %} hello {% endif %}',
                '<?php if ($a > $b) { ?> hello <?php } ?>',
            ],
            [
                '{% if a>=b %} hello {% endif %}',
                '<?php if ($a >= $b) { ?> hello <?php } ?>',
            ],
            [
                '{% if a<=b %} hello {% endif %}',
                '<?php if ($a <= $b) { ?> hello <?php } ?>',
            ],
            [
                '{% if a===b %} hello {% endif %}',
                '<?php if ($a === $b) { ?> hello <?php } ?>',
            ],
            [
                '{% if a!==b %} hello {% endif %}',
                '<?php if ($a !== $b) { ?> hello <?php } ?>',
            ],
            [
                '{% if a==b and c==d %} hello {% endif %}',
                '<?php if ($a == $b && $c == $d) { ?> hello <?php } ?>',
            ],
            [
                '{% if a==b or c==d %} hello {% endif %}',
                '<?php if ($a == $b || $c == $d) { ?> hello <?php } ?>',
            ],
            [
                '{% if a is odd %} hello {% endif %}',
                '<?php if (((($a) % 2) != 0)) { ?> hello <?php } ?>',
            ],
            [
                '{% if a is even %} hello {% endif %}',
                '<?php if (((($a) % 2) == 0)) { ?> hello <?php } ?>',
            ],
            [
                '{% if a is empty %} hello {% endif %}',
                '<?php if (empty($a)) { ?> hello <?php } ?>',
            ],
            [
                '{% if a is not empty %} hello {% endif %}',
                '<?php if (!empty($a)) { ?> hello <?php } ?>',
            ],
            [
                '{% if a is numeric %} hello {% endif %}',
                '<?php if (is_numeric($a)) { ?> hello <?php } ?>',
            ],
            [
                '{% if a is not numeric %} hello {% endif %}',
                '<?php if (!is_numeric($a)) { ?> hello <?php } ?>',
            ],
            [
                '{% if a is scalar %} hello {% endif %}',
                '<?php if (is_scalar($a)) { ?> hello <?php } ?>',
            ],
            [
                '{% if a is not scalar %} hello {% endif %}',
                '<?php if (!is_scalar($a)) { ?> hello <?php } ?>',
            ],
            [
                '{% if a is iterable %} hello {% endif %}',
                '<?php if ((is_array($a) || ($a) instanceof Traversable)) { ?> hello <?php } ?>',
            ],
            [
                '{% if a is not iterable %} hello {% endif %}',
                '<?php if (!(is_array($a) || ($a) instanceof Traversable)) { ?> hello <?php } ?>',
            ],
            [
                '{% if a is sameas(false) %} hello {% endif %}',
                '<?php if (($a) === (false)) { ?> hello <?php } ?>',
            ],
            [
                '{% if a is sameas(b) %} hello {% endif %}',
                '<?php if (($a) === ($b)) { ?> hello <?php } ?>',
            ],
            [
                '{% if a is divisibleby(3) %} hello {% endif %}',
                '<?php if (((($a) % (3)) == 0)) { ?> hello <?php } ?>',
            ],
            [
                '{% if a is divisibleby(b) %} hello {% endif %}',
                '<?php if (((($a) % ($b)) == 0)) { ?> hello <?php } ?>',
            ],
            [
                '{% if a is defined %} hello {% endif %}',
                '<?php if (isset($a)) { ?> hello <?php } ?>',
            ],
            [
                '{% if a is not defined %} hello {% endif %}',
                '<?php if (!isset($a)) { ?> hello <?php } ?>',
            ],
            [
                '{% if a==b %} hello {% else %} not hello {% endif %}',
                '<?php if ($a == $b) { ?> hello <?php } else { ?> not hello <?php } ?>',
            ],
            [
                '{% if a==b %} {% if c==d %} hello {% endif %} {% else %} not hello {% endif %}',
                '<?php if ($a == $b) { ?> <?php if ($c == $d) { ?> hello <?php } ?>' .
                ' <?php } else { ?> not hello <?php } ?>',
            ],
            [
                '{% if a==b %} {% if c==d %} hello {% else %} not hello {% endif %}{% endif %}',
                '<?php if ($a == $b) { ?> <?php if ($c == $d) { ?> hello <?php } ' .
                'else { ?> not hello <?php } ?><?php } ?>',
            ],
            [
                '{% if a==b %} hello {% else %} {% if c==d %} not hello {% endif %} {% endif %}',
                '<?php if ($a == $b) { ?> hello <?php } else { ?> ' .
                '<?php if ($c == $d) { ?> not hello <?php } ?> <?php } ?>',
            ],
            [
                '{% if a is empty or a is defined %} hello {% else %} not hello {% endif %}',
                '<?php if (empty($a) || isset($a)) { ?> hello <?php } else ' .
                '{ ?> not hello <?php } ?>',
            ],
            [
                '{% if a is even or b is odd %} hello {% else %} not hello {% endif %}',
                '<?php if (((($a) % 2) == 0) || ((($b) % 2) != 0)) { ?> hello ' .
                '<?php } else { ?> not hello <?php } ?>',
            ],
            //for statement
            [
                '{% for a in b %} hello {% endfor %}',
                '<?php foreach ($b as $a) { ?> hello <?php } ?>',
            ],
            [
                '{% for a in b[0] %} hello {% endfor %}',
                '<?php foreach ($b[0] as $a) { ?> hello <?php } ?>',
            ],
            [
                '{% for a in b.c %} hello {% endfor %}',
                '<?php foreach ($b->c as $a) { ?> hello <?php } ?>',
            ],
            [
                '{% for key, value in [0, 1, 3, 5, 4] %} hello {% endfor %}',
                '<?php foreach ([0, 1, 3, 5, 4] as $key => $value) { ?> hello <?php } ?>',
            ],
            [
                '{% for key, value in [0, 1, 3, 5, 4] if key!=3 %} hello {% endfor %}',
                '<?php foreach ([0, 1, 3, 5, 4] as $key => $value) { if ($key != 3) { ?> hello <?php } ?><?php } ?>',
            ],
            [
                '{% for a in 1..10 %} hello {% endfor %}',
                '<?php foreach (range(1, 10) as $a) { ?> hello <?php } ?>',
            ],
            [
                '{% for a in 1..10 if a is even %} hello {% endfor %}',
                '<?php foreach (range(1, 10) as $a) { if (((($a) % 2) == 0)) { ?> hello <?php } ?><?php } ?>',
            ],
            [
                '{% for a in 1..10 %} {% for b in 1..10 %} hello {% endfor %} {% endfor %}',
                '<?php foreach (range(1, 10) as $a) { ?> ' .
                '<?php foreach (range(1, 10) as $b) { ?> hello <?php } ?> <?php } ?>',
            ],
            [
                '{% for a in 1..10 %}{% break %}{% endfor %}',
                '<?php foreach (range(1, 10) as $a) { ?><?php break; ?><?php } ?>',
            ],
            [
                '{% for a in 1..10 %}{% continue %}{% endfor %}',
                '<?php foreach (range(1, 10) as $a) { ?><?php continue; ?><?php } ?>',
            ],
            //set statement
            [
                '{% set a = 1 %}',
                '<?php $a = 1; ?>',
            ],
            [
                '{% set a = a-1 %}',
                '<?php $a = $a - 1; ?>',
            ],
            [
                '{% set a = 1.2 %}',
                '<?php $a = 1.2; ?>',
            ],
            [
                '{% set a = 1.2+1*(20/b) and c %}',
                '<?php $a = 1.2 + 1 * (20 / $b) && $c; ?>',
            ],
            //Autoescape mode
            [
                '{{ "hello" }}{% autoescape true %}{{ "hello" }}{% autoescape false %}' .
                '{{ "hello" }}{% endautoescape %}{{ "hello" }}{% endautoescape %}{{ "hello" }}',
                "<?= 'hello' ?><?= \$this->escaper->escapeHtml('hello') ?>" .
                "<?= 'hello' ?><?= \$this->escaper->escapeHtml('hello') ?><?= 'hello' ?>",
            ],
            //Mixed
            [
                '{# some comment #}{{ "hello" }}{# other comment }}',
                "<?= 'hello' ?>",
            ],
            // join filter
            [
                "{{ [1, 2]|join(',') }}",
                "<?= join(',', [1, 2]) ?>",
            ],
        ];
    }

    private function getVoltCompileStringErrors(): array
    {
        return [
            [
                '{{ "hello"|unknown }}',
                'Unknown filter "unknown" in eval code on line 1',
            ],
            [
                '{{ "hello"|unknown(1, 2, 3) }}',
                'Unknown filter "unknown" in eval code on line 1',
            ],
            [
                '{{ "hello"|(a-1) }}',
                'Unknown filter type in eval code on line 1',
            ],
        ];
    }
}
