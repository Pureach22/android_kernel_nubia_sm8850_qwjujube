__int64 __fastcall aiqe_init(__int64 result, __int64 a2)
{
  if ( a2 && ((_DWORD)result == 0x20000 || (_DWORD)result == 0x10000) )
    aiqe_get_common_values_func = aiqe_get_common_values_v1;
  return result;
}
