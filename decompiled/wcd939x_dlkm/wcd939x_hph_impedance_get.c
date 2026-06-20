__int64 __fastcall wcd939x_hph_impedance_get(__int64 a1, __int64 a2)
{
  __int64 v4; // x20
  __int64 mbhc; // x0
  int v6; // w20
  __int64 result; // x0
  unsigned int *v8; // x8
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 128);
  v9[0] = 0;
  mbhc = wcd939x_soc_get_mbhc(v4);
  if ( mbhc )
  {
    v6 = *(_DWORD *)(*(_QWORD *)(a1 + 120) + 20LL);
    wcd_mbhc_get_impedance(mbhc, (char *)v9 + 4, v9);
    result = 0;
    if ( v6 )
      v8 = (unsigned int *)v9;
    else
      v8 = (unsigned int *)v9 + 1;
    *(_QWORD *)(a2 + 72) = *v8;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&wcd939x_hph_impedance_get__rs, "wcd939x_hph_impedance_get") )
      dev_err(*(_QWORD *)(v4 + 24), "%s: mbhc not initialized!\n", "wcd939x_hph_impedance_get");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
