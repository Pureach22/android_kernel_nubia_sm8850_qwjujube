__int64 __fastcall clk_rpmh_bcm_prepare(__int64 a1)
{
  unsigned int v2; // w8
  unsigned int v3; // w20
  int v4; // w21
  __int64 v5; // x0
  __int64 v7; // [xsp+8h] [xbp-18h] BYREF
  int v8; // [xsp+10h] [xbp-10h]
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  v7 = 0;
  mutex_lock(&rpmh_clk_lock);
  v2 = *(_DWORD *)(a1 + 48);
  v3 = 0;
  if ( v2 <= 1 )
    v2 = 1;
  if ( v2 >= 0x3FFF )
    v4 = 0x3FFF;
  else
    v4 = v2;
  if ( *(_DWORD *)(a1 + 52) != v4 )
  {
    v5 = *(_QWORD *)(a1 + 64);
    LODWORD(v7) = *(_DWORD *)(a1 + 36);
    HIDWORD(v7) = v4 | 0x60000000;
    v3 = rpmh_write(v5, 2, &v7, 1);
    if ( v3 )
      dev_err(*(_QWORD *)(a1 + 64), "set active state of %s failed: (%d)\n", *(const char **)(a1 + 24), v3);
    else
      *(_DWORD *)(a1 + 52) = v4;
  }
  mutex_unlock(&rpmh_clk_lock);
  _ReadStatusReg(SP_EL0);
  return v3;
}
