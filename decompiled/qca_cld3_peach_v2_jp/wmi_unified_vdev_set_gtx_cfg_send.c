__int64 __fastcall wmi_unified_vdev_set_gtx_cfg_send(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w9
  __int64 v4; // x10
  int v5; // w8
  __int64 v6; // x9
  int v7; // w8
  __int64 result; // x0
  _DWORD v9[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v10; // [xsp+10h] [xbp-20h]
  int v11; // [xsp+18h] [xbp-18h]
  __int64 v12; // [xsp+1Ch] [xbp-14h]
  int v13; // [xsp+24h] [xbp-Ch]
  __int64 v14; // [xsp+28h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a3 + 4);
  v4 = *(_QWORD *)(a3 + 8);
  v9[0] = *(_DWORD *)a3;
  v9[1] = v3;
  v5 = *(_DWORD *)(a3 + 16);
  v6 = *(_QWORD *)(a3 + 20);
  v10 = v4;
  v11 = v5;
  v7 = *(_DWORD *)(a3 + 28);
  v12 = v6;
  v13 = v7;
  result = wmi_unified_vdev_set_gtx_cfg_cmd(a1, a2, v9);
  _ReadStatusReg(SP_EL0);
  return result;
}
