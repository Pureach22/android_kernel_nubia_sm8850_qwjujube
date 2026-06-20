__int64 __fastcall check_spr_init_feature(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 (*v4)(void); // x9
  __int64 result; // x0
  unsigned int v6; // w19
  __int64 v7; // x0

  if ( !a1 || !a2 || !a3 )
  {
    _drm_err("invalid arguments");
    return 4294967274LL;
  }
  v3 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v3 >= 3 )
  {
    __break(0x5512u);
    v7 = MEMORY[0x2527098]();
    return check_spr_udc_feature(v7);
  }
  v4 = *(__int64 (**)(void))(a1 + 8 * v3 + 904);
  if ( !v4 )
  {
    if ( (_DWORD)v3 == 1 )
      return 0;
    _drm_err("invalid spr validate op");
    return 4294967274LL;
  }
  if ( *((_DWORD *)v4 - 1) != 905945830 )
    __break(0x8229u);
  result = v4();
  if ( (_DWORD)result )
  {
    v6 = result;
    _drm_err("failed to validate spr config %d", result);
    return v6;
  }
  return result;
}
