__int64 __fastcall aiqe_get_common_values(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 (*v3)(void); // x8

  v3 = (__int64 (*)(void))aiqe_get_common_values_func;
  if ( !aiqe_get_common_values_func )
    return _drm_err("Get common values function is invalid!");
  if ( !a1 || !a2 || !a3 )
    return _drm_err("Invalid params!\n");
  if ( *((_DWORD *)aiqe_get_common_values_func - 1) != -1512498853 )
    __break(0x8228u);
  return v3();
}
