__int64 __fastcall sde_setup_ucsc_gcv1_1(_QWORD *a1, unsigned int a2)
{
  __int64 v4; // x9
  unsigned int v5; // w20
  __int64 result; // x0
  __int64 v7; // x2

  sde_setup_ucsc_gcv1_common();
  if ( !a1 || a2 == 3 )
    return _drm_err("invalid parameter\tctx: %pK\tindex: %d\n", a1, a2);
  v4 = 1048;
  if ( a2 < 2 )
    v4 = 1012;
  v5 = *(_DWORD *)(*(_QWORD *)(a1[7] + 48LL) + v4);
  result = sde_reg_read(a1, v5);
  if ( (result & 0x17) != 0 )
  {
    if ( (~(_DWORD)result & 0x300000) == 0 )
      return result;
    v7 = (unsigned int)result | 0x300000;
  }
  else
  {
    v7 = (unsigned int)result & 0xFFCFFFE8;
  }
  return sde_reg_write(a1, v5, v7, "ucsc_base");
}
