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

namespace Phalcon\Tests\Unit\Di\Service;

use UnitTester;

class ResolveCest
{
    /**
     * Unit Tests Phalcon\Di\Service :: resolve()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diServiceResolve(UnitTester $I)
    {
        $I->wantToTest('Di\Service - resolve()');

        $I->skipTest('Need implementation');
    }
}
