__int64 __fastcall hdd_nan_register_callbacks(__int64 *a1)
{
  __int64 v1; // x0
  __int64 result; // x0
  _QWORD v3[3]; // [xsp+8h] [xbp-C8h] BYREF
  __int64 (__fastcall *v4)(); // [xsp+20h] [xbp-B0h]
  __int64 (__fastcall *v5)(); // [xsp+28h] [xbp-A8h]
  __int64 (__fastcall *v6)(); // [xsp+30h] [xbp-A0h]
  __int64 (__fastcall *v7)(); // [xsp+38h] [xbp-98h]
  void *v8; // [xsp+40h] [xbp-90h]
  __int64 (__fastcall *v9)(); // [xsp+48h] [xbp-88h]
  __int64 (__fastcall *v10)(); // [xsp+50h] [xbp-80h]
  __int64 (__fastcall *v11)(); // [xsp+58h] [xbp-78h]
  __int64 v12; // [xsp+60h] [xbp-70h]
  __int64 (__fastcall *v13)(); // [xsp+68h] [xbp-68h]
  __int64 v14; // [xsp+70h] [xbp-60h]
  __int64 v15; // [xsp+78h] [xbp-58h]
  __int64 v16; // [xsp+80h] [xbp-50h]
  __int64 (__fastcall *v17)(); // [xsp+88h] [xbp-48h]
  __int64 (__fastcall *v18)(); // [xsp+90h] [xbp-40h]
  __int64 (__fastcall *v19)(); // [xsp+98h] [xbp-38h]
  __int64 v20; // [xsp+A0h] [xbp-30h]
  __int64 v21; // [xsp+A8h] [xbp-28h]
  __int64 v22; // [xsp+B0h] [xbp-20h]
  __int64 v23; // [xsp+B8h] [xbp-18h]
  void *v24; // [xsp+C0h] [xbp-10h]
  __int64 v25; // [xsp+C8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = nullptr;
  v5 = nullptr;
  v1 = *a1;
  v4 = hdd_ndi_open;
  v5 = hdd_ndi_set_mode;
  v7 = hdd_ndi_close;
  v8 = &hdd_ndi_delete;
  v9 = hdd_ndi_drv_ndi_create_rsp_handler;
  v10 = hdd_ndi_drv_ndi_delete_rsp_handler;
  v11 = hdd_ndp_new_peer_handler;
  v12 = 0;
  v14 = 0;
  v13 = hdd_ndp_peer_departed_handler;
  v16 = 0;
  v17 = hdd_nan_concurrency_update;
  v18 = hdd_update_multicast_list;
  v19 = hdd_nan_sr_concurrency_update;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  memset(v3, 0, sizeof(v3));
  v6 = hdd_ndi_start;
  v15 = 0;
  v23 = 0;
  v24 = &hdd_ndp_update_peer_bw;
  result = os_if_nan_register_hdd_callbacks(v1, v3);
  _ReadStatusReg(SP_EL0);
  return result;
}
