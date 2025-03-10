
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class AbstractAdapter
 *
 * @package Phalcon\Translate\Adapter
 *
 * @property string              $defaultInterpolator
 * @property InterpolatorFactory $interpolatorFactory
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_AbstractAdapter)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Translate\\Adapter, AbstractAdapter, phalcon, translate_adapter_abstractadapter, phalcon_translate_adapter_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_translate_adapter_abstractadapter_ce, SL("defaultInterpolator"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var InterpolatorFactory
	 */
	zend_declare_property_null(phalcon_translate_adapter_abstractadapter_ce, SL("interpolatorFactory"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_translate_adapter_abstractadapter_ce, 1, phalcon_translate_adapter_adapterinterface_ce);
	return SUCCESS;
}

/**
 * AbstractAdapter constructor.
 *
 * @param InterpolatorFactory $interpolator
 * @param array               $options
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval options;
	zval *interpolator, interpolator_sub, *options_param = NULL, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&interpolator_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(interpolator, phalcon_translate_interpolatorfactory_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &interpolator, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_OBS_VAR(&value);
	if (!(zephir_array_isset_string_fetch(&value, &options, SL("defaultInterpolator"), 0))) {
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_STRING(&value, "associativeArray");
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultInterpolator"), &value);
	zephir_update_property_zval(this_ptr, ZEND_STRL("interpolatorFactory"), interpolator);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the translation string of the given key (alias of method 't')
 *
 * @param string $translateKey
 * @param array  $placeholders
 *
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, _)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval *translateKey_param = NULL, *placeholders_param = NULL;
	zval translateKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translateKey);
	ZVAL_UNDEF(&placeholders);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(translateKey)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(placeholders)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &translateKey_param, &placeholders_param);
	if (UNEXPECTED(Z_TYPE_P(translateKey_param) != IS_STRING && Z_TYPE_P(translateKey_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translateKey' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(translateKey_param) == IS_STRING)) {
		zephir_get_strval(&translateKey, translateKey_param);
	} else {
		ZEPHIR_INIT_VAR(&translateKey);
	}
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, &translateKey, &placeholders);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Check whether a translation key exists
 *
 * @param mixed $translateKey
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, offsetExists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *translateKey, translateKey_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translateKey_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(translateKey)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &translateKey);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "exists", NULL, 0, translateKey);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the translation related to the given key
 *
 * @param mixed $translateKey
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, offsetGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *translateKey, translateKey_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translateKey_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(translateKey)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &translateKey);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, translateKey);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets a translation value
 *
 * @param mixed $offset
 * @param mixed $value
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, offsetSet)
{
	zval *offset, offset_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(offset)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(2, 0, &offset, &value);


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_translate_exception_ce, "Translate is an immutable ArrayAccess object", "phalcon/Translate/Adapter/AbstractAdapter.zep", 103);
	return;
}

/**
 * Unsets a translation from the dictionary
 *
 * @param mixed $offset
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, offsetUnset)
{
	zval *offset, offset_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &offset);


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_translate_exception_ce, "Translate is an immutable ArrayAccess object", "phalcon/Translate/Adapter/AbstractAdapter.zep", 115);
	return;
}

/**
 * Returns the translation string of the given key
 *
 * @param string $translateKey
 * @param array  $placeholders
 *
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, t)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval *translateKey_param = NULL, *placeholders_param = NULL;
	zval translateKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translateKey);
	ZVAL_UNDEF(&placeholders);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(translateKey)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(placeholders)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &translateKey_param, &placeholders_param);
	if (UNEXPECTED(Z_TYPE_P(translateKey_param) != IS_STRING && Z_TYPE_P(translateKey_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translateKey' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(translateKey_param) == IS_STRING)) {
		zephir_get_strval(&translateKey, translateKey_param);
	} else {
		ZEPHIR_INIT_VAR(&translateKey);
	}
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, &translateKey, &placeholders);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Replaces placeholders by the values passed
 *
 * @param string $translation
 * @param array  $placeholders
 *
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, replacePlaceholders)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval *translation_param = NULL, *placeholders_param = NULL, interpolator, _0, _1;
	zval translation;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translation);
	ZVAL_UNDEF(&interpolator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&placeholders);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(translation)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(placeholders)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &translation_param, &placeholders_param);
	if (UNEXPECTED(Z_TYPE_P(translation_param) != IS_STRING && Z_TYPE_P(translation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translation' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(translation_param) == IS_STRING)) {
		zephir_get_strval(&translation, translation_param);
	} else {
		ZEPHIR_INIT_VAR(&translation);
	}
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("interpolatorFactory"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("defaultInterpolator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&interpolator, &_0, "newinstance", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&interpolator, "replaceplaceholders", NULL, 0, &translation, &placeholders);
	zephir_check_call_status();
	RETURN_MM();
}

