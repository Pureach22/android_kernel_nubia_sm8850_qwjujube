__int64 __fastcall wlan_cm_disconnect_sync(__int64 a1, __int64 a2, int a3)
{
  unsigned __int8 v3; // w8
  __int64 result; // x0
  __int64 v5; // [xsp+0h] [xbp-20h] BYREF
  int v6; // [xsp+8h] [xbp-18h]
  int v7; // [xsp+Ch] [xbp-14h]
  int v8; // [xsp+10h] [xbp-10h]
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_BYTE *)(a1 + 168);
  v7 = 0;
  v6 = a3;
  v8 = 0;
  v5 = v3;
  result = cm_disconnect_start_req_sync(a1, (__int64)&v5);
  _ReadStatusReg(SP_EL0);
  return result;
}
