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

namespace Phalcon\Tests\Integration\Mvc\View\Engine\Volt;

use IntegrationTester;
use Phalcon\Di;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Volt;

class GetSetDICest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt :: getDI() / setDI()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcViewEngineVoltGetSetDI(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Volt - getDI()');

        $view = new View();

        $di1 = new Di();
        $di2 = new Di();

        $engine = new Volt($view, $di1);

        $I->assertSame(
            $di1,
            $engine->getDI()
        );

        $engine->setDI($di2);

        $I->assertSame(
            $di2,
            $engine->getDI()
        );
    }
}
