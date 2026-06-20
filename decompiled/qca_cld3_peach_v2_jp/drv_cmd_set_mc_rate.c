__int64 __fastcall drv_cmd_set_mc_rate(__int64 *a1, __int64 a2, __int64 a3, unsigned __int8 a4)
{
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0
  unsigned int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  kstrtouint(a3 + a4 + 1, 10, &v14);
  result = wlan_hdd_set_mc_rate(a1, v14, v5, v6, v7, v8, v9, v10, v11, v12);
  _ReadStatusReg(SP_EL0);
  return result;
}
