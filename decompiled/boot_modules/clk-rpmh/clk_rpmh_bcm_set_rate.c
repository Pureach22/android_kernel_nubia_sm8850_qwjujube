__int64 __fastcall clk_rpmh_bcm_set_rate(__int64 a1, unsigned __int64 a2)
{
  unsigned int v3; // w8
  int v4; // w20
  __int64 v5; // x0
  int v6; // w0
  __int64 v8; // [xsp+8h] [xbp-18h] BYREF
  int v9; // [xsp+10h] [xbp-10h]
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_DWORD *)(a1 + 48) = a2 / *(unsigned int *)(a1 + 60);
  if ( (clk_hw_is_prepared() & 1) != 0 )
  {
    v9 = 0;
    v8 = 0;
    mutex_lock(&rpmh_clk_lock);
    v3 = *(_DWORD *)(a1 + 48);
    if ( v3 <= 1 )
      v3 = 1;
    if ( v3 >= 0x3FFF )
      v4 = 0x3FFF;
    else
      v4 = v3;
    if ( *(_DWORD *)(a1 + 52) != v4 )
    {
      v5 = *(_QWORD *)(a1 + 64);
      LODWORD(v8) = *(_DWORD *)(a1 + 36);
      HIDWORD(v8) = v4 | 0x60000000;
      v6 = rpmh_write(v5, 2, &v8, 1);
      if ( v6 )
        dev_err(*(_QWORD *)(a1 + 64), "set active state of %s failed: (%d)\n", *(const char **)(a1 + 24), v6);
      else
        *(_DWORD *)(a1 + 52) = v4;
    }
    mutex_unlock(&rpmh_clk_lock);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
