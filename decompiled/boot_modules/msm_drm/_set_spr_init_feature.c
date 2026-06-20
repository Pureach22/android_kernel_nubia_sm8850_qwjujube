__int64 __fastcall set_spr_init_feature(__int64 a1, _QWORD *a2, __int64 a3)
{
  __int64 v3; // x8
  void (*v4)(void); // x8
  int v7; // w9
  __int64 result; // x0
  unsigned int v9; // w9
  __int64 v10; // x0

  if ( a1 && a3 )
  {
    v3 = *(unsigned int *)(a1 + 28);
    if ( (unsigned int)v3 >= 3 )
    {
      __break(0x5512u);
      v10 = MEMORY[0x2526CB4]();
      return set_spr_udc_feature(v10);
    }
    else
    {
      v4 = *(void (**)(void))(a1 + 8 * v3 + 952);
      if ( v4 )
      {
        if ( *((_DWORD *)v4 - 1) != 1841204718 )
          __break(0x8228u);
        v4();
        v7 = *(_DWORD *)(a3 + 7588);
        result = 0;
        if ( *a2 )
          v9 = v7 | 2;
        else
          v9 = v7 & 0xFFFFFFFD;
        *(_DWORD *)(a3 + 7588) = v9;
      }
      else
      {
        return 0;
      }
    }
  }
  else
  {
    _drm_err("invalid arguments\n");
    return 4294967274LL;
  }
  return result;
}
