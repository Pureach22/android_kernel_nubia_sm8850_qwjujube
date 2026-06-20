__int64 __fastcall mlo_mgr_standby_link_csa_notify(unsigned __int8 *a1)
{
  __int64 mlo_ctx; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 (__fastcall *v11)(_QWORD); // x8
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w20
  __int64 v22; // x4
  __int64 v23; // x5
  __int64 v24; // x6
  __int64 v25; // x7
  const char *v26; // x2

  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  if ( !mlo_ctx )
  {
    v26 = "%s: mlo context is NULL";
LABEL_10:
    qdf_trace_msg(0x8Fu, 2u, v26, v3, v4, v5, v6, v7, v8, v9, v10, "mlo_mgr_standby_link_csa_notify");
    return 29;
  }
  v11 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(mlo_ctx + 360) + 56LL);
  if ( !v11 )
  {
    v26 = "%s: chan_switch_hdd_cb is NULL";
    goto LABEL_10;
  }
  if ( *((_DWORD *)v11 - 1) != -1659280568 )
    __break(0x8228u);
  result = v11(a1);
  if ( (_DWORD)result )
  {
    v21 = result;
    if ( a1 )
    {
      v22 = *a1;
      v23 = a1[1];
      v24 = a1[2];
      v25 = a1[5];
    }
    else
    {
      v24 = 0;
      v22 = 0;
      v23 = 0;
      v25 = 0;
    }
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Standby link csa notify to user space failed BSSID: %02x:%02x:%02x:**:**:%02x",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "mlo_mgr_standby_link_csa_notify",
      v22,
      v23,
      v24,
      v25);
    return v21;
  }
  return result;
}
