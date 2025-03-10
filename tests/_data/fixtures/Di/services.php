<?php

use Phalcon\Config\Config;
use Phalcon\Tests\Module\UnitTest;

return [
    'unit-test' => [
        'className' => UnitTest::class,
    ],
    'config'    => [
        'className' => Config::class,
        'shared'    => true,
    ],
    'component' => [
        'className' => SomeComponent::class,
        'arguments' => [
            [
                'type' => 'service',
                'name' => 'config',
            ],
        ],
    ],
];
