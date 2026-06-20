__int64 __fastcall wlan_mlme_set_sap_suspend_resume(__int64 a1, unsigned __int8 *a2)
{
  unsigned int v3; // w8
  int v4; // w9
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0
  unsigned int v14; // [xsp+8h] [xbp-18h] BYREF
  __int64 v15; // [xsp+Ch] [xbp-14h] BYREF
  int v16; // [xsp+14h] [xbp-Ch]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a2;
  v4 = a2[1];
  v15 = 0;
  v14 = v3;
  v16 = v4;
  qdf_mem_copy(&v15, a2 + 2, 6u);
  result = tgt_sap_suspend_param_send(a1, &v14, v5, v6, v7, v8, v9, v10, v11, v12);
  _ReadStatusReg(SP_EL0);
  return result;
}
