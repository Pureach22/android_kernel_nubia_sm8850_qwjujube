__int64 __fastcall wlan_sap_enable_phy_error_logs(__int64 a1, int a2)
{
  __int64 v2; // x8
  __int64 result; // x0
  int v4; // [xsp+0h] [xbp-10h] BYREF
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 21560);
  v4 = 0;
  v5 = a2;
  *(_BYTE *)(a1 + 14913) = a2 != 0;
  result = tgt_dfs_control(v2, 13, &v5, 4, 0, 0, &v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
