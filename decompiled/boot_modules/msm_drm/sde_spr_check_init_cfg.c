__int64 __fastcall sde_spr_check_init_cfg(__int64 a1, unsigned __int16 **a2)
{
  __int64 result; // x0
  unsigned __int16 *v4; // x8
  int v5; // w1
  _BOOL4 v6; // w2
  int v7; // w9

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    v4 = *a2;
    if ( *a2 && v4[146] )
    {
      if ( v4[16] != 1 || v4[17] )
      {
        v5 = v4[8];
        v6 = 1;
LABEL_8:
        _drm_err("CFG18 can't be enabled with this config. CFG4: %u CFG11: %u\n", v5, v6);
        return 4294967274LL;
      }
      v7 = v4[18];
      v5 = v4[8];
      v6 = v7 != 1;
      if ( v4[8] || v7 != 1 )
        goto LABEL_8;
    }
    return 0;
  }
  return result;
}
