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

namespace Phalcon\Tests\Integration\Forms\Element\Password;

use IntegrationTester;

/**
 * Class SetMessagesCest
 */
class SetMessagesCest
{
    /**
     * Tests Phalcon\Forms\Element\Password :: setMessages()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function formsElementPasswordSetMessages(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Password - setMessages()');
        $I->skipTest('Need implementation');
    }
}
