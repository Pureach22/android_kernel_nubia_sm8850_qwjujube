__int64 __fastcall wma_register_nan_callbacks(__int64 a1)
{
  __int64 v1; // x0
  __int64 result; // x0
  _QWORD v3[15]; // [xsp+8h] [xbp-C8h] BYREF
  __int64 (__fastcall *v4)(); // [xsp+80h] [xbp-50h]
  __int64 v5; // [xsp+88h] [xbp-48h]
  __int64 v6; // [xsp+90h] [xbp-40h]
  __int64 v7; // [xsp+98h] [xbp-38h]
  __int64 (__fastcall *v8)(); // [xsp+A0h] [xbp-30h]
  __int64 (__fastcall *v9)(); // [xsp+A8h] [xbp-28h]
  __int64 (*v10)(void); // [xsp+B0h] [xbp-20h]
  __int64 (__fastcall *v11)(); // [xsp+B8h] [xbp-18h]
  __int64 v12; // [xsp+C0h] [xbp-10h]
  __int64 v13; // [xsp+C8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = nullptr;
  v1 = *(_QWORD *)(a1 + 24);
  v4 = wma_ndi_update_connection_info;
  v5 = 0;
  v7 = 0;
  v8 = wma_pasn_peer_create;
  v9 = wma_nan_pasn_peer_remove;
  v12 = 0;
  v6 = 0;
  memset(v3, 0, sizeof(v3));
  v10 = wma_delete_all_pasn_peers;
  v11 = wma_pasn_peer_delete_all_complete;
  result = ucfg_nan_register_wma_callbacks(v1, v3);
  _ReadStatusReg(SP_EL0);
  return result;
}
