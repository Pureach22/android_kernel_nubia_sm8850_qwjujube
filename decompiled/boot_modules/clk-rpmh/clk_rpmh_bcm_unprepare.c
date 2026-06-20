__int64 __fastcall clk_rpmh_bcm_unprepare(__int64 a1)
{
  __int64 v2; // x0
  int v3; // w0
  __int64 result; // x0
  __int64 v5; // [xsp+8h] [xbp-18h] BYREF
  int v6; // [xsp+10h] [xbp-10h]
  __int64 v7; // [xsp+18h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  v5 = 0;
  mutex_lock(&rpmh_clk_lock);
  if ( *(_DWORD *)(a1 + 52) )
  {
    v2 = *(_QWORD *)(a1 + 64);
    LODWORD(v5) = *(_DWORD *)(a1 + 36);
    HIDWORD(v5) = 0x40000000;
    v3 = rpmh_write_async(v2, 2, &v5, 1);
    if ( v3 )
      dev_err(*(_QWORD *)(a1 + 64), "set active state of %s failed: (%d)\n", *(const char **)(a1 + 24), v3);
    else
      *(_DWORD *)(a1 + 52) = 0;
  }
  result = mutex_unlock(&rpmh_clk_lock);
  _ReadStatusReg(SP_EL0);
  return result;
}
