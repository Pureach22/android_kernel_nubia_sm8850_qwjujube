__int64 __fastcall store_sdhci_msm_pm_qos(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x21
  int v8; // w2
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  v9 = 0;
  if ( !(unsigned int)kstrtouint(a3, 0, &v9) )
  {
    v8 = v9;
    *(_DWORD *)(v6 + 2004) = v9;
    dev_info(a1, "set pm qos work delay (%u)\n", v8);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
