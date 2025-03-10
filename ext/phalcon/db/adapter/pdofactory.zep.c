
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_PdoFactory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter, PdoFactory, phalcon, db_adapter_pdofactory, phalcon_factory_abstractfactory_ce, phalcon_db_adapter_pdofactory_method_entry, 0);

	return SUCCESS;
}

/**
 * Constructor
 */
PHP_METHOD(Phalcon_Db_Adapter_PdoFactory, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *services_param = NULL;
	zval services;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&services);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(services)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &services_param);
	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&services, services_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Factory to create an instance from a Config object
 *
 * @param array|\Phalcon\Config\Config config = [
 *     'adapter' => 'mysql',
 *     'options' => [
 *         'host' => 'localhost',
 *         'port' => '3306',
 *         'dbname' => 'blog',
 *         'username' => 'sigma'
 *         'password' => 'secret',
 *         'dialectClass' => null,
 *         'options' => [],
 *         'dsn' => null,
 *         'charset' => 'utf8mb4'
 *     ]
 * ]
 */
PHP_METHOD(Phalcon_Db_Adapter_PdoFactory, load)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, name, options, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);
	ZEPHIR_SEPARATE_PARAM(config);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkconfig", NULL, 0, config);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(config, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "adapter");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkconfigelement", NULL, 0, config, &_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(config, &_0);
	ZEPHIR_OBS_VAR(&name);
	zephir_array_fetch_string(&name, config, SL("adapter"), PH_NOISY, "phalcon/Db/Adapter/PdoFactory.zep", 50);
	zephir_array_unset_string(config, SL("adapter"), PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_support_helper_arr_get_ce);
	if (zephir_has_constructor(&_1)) {
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "options");
	ZEPHIR_CALL_METHOD(&options, &_1, "__invoke", NULL, 172, config, &_3, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, &name, &options);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Create a new instance of the adapter
 */
PHP_METHOD(Phalcon_Db_Adapter_PdoFactory, newInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, _0;
	zval *name_param = NULL, *options_param = NULL, definition;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &options_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_CALL_METHOD(&definition, this_ptr, "getservice", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	zephir_array_fast_append(&_0, &options);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(return_value, &definition, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_PdoFactory, getExceptionClass)
{
	zval *this_ptr = getThis();



	RETURN_STRING("Phalcon\\Db\\Exception");
}

/**
 * Returns the available adapters
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Db_Adapter_PdoFactory, getServices)
{
	zval *this_ptr = getThis();



	zephir_create_array(return_value, 3, 0);
	add_assoc_stringl_ex(return_value, SL("mysql"), SL("Phalcon\\Db\\Adapter\\Pdo\\Mysql"));
	add_assoc_stringl_ex(return_value, SL("postgresql"), SL("Phalcon\\Db\\Adapter\\Pdo\\Postgresql"));
	add_assoc_stringl_ex(return_value, SL("sqlite"), SL("Phalcon\\Db\\Adapter\\Pdo\\Sqlite"));
	return;
}

