_QWORD *__fastcall dp_configure_arch_ops(__int64 a1)
{
  _QWORD *result; // x0

  result = (_QWORD *)cdp_get_arch_type_from_devid(*(_DWORD *)(a1 + 1856));
  if ( (_DWORD)result == 1 )
    return dp_initialize_arch_ops_be((_QWORD *)(a1 + 1144));
  return result;
}
