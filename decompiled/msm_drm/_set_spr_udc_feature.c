__int64 __fastcall set_spr_udc_feature(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  void (*v4)(void); // x8
  __int64 v6; // x0

  if ( a1 && a3 )
  {
    v3 = *(unsigned int *)(a1 + 28);
    if ( (unsigned int)v3 >= 3 )
    {
      __break(0x5512u);
      v6 = MEMORY[0x2526D28]();
      return set_dspp_spr_dither_feature(v6);
    }
    else
    {
      v4 = *(void (**)(void))(a1 + 8 * v3 + 976);
      if ( v4 )
      {
        if ( *((_DWORD *)v4 - 1) != 1841204718 )
          __break(0x8228u);
        v4();
      }
      return 0;
    }
  }
  else
  {
    _drm_err("invalid arguments\n");
    return 4294967274LL;
  }
}
