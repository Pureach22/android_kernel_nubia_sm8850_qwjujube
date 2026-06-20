__int64 __fastcall mlo_mgr_remove_link_switch_cmd(__int64 a1)
{
  int v2; // w21
  char is_link_recfg_in_progress; // w0
  __int64 v4; // x22
  char v5; // w20
  int v6; // w23
  __int64 result; // x0
  __int64 v8; // x22
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w9
  int v26; // w10
  __int64 v27; // [xsp+8h] [xbp-28h] BYREF
  int v28; // [xsp+10h] [xbp-20h]
  int v29; // [xsp+14h] [xbp-1Ch]
  __int64 v30; // [xsp+18h] [xbp-18h]
  __int64 v31; // [xsp+20h] [xbp-10h]
  __int64 v32; // [xsp+28h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int8 *)(a1 + 168);
  v31 = 0;
  is_link_recfg_in_progress = mlo_is_link_recfg_in_progress(a1);
  v4 = *(_QWORD *)(a1 + 1360);
  v5 = is_link_recfg_in_progress;
  qdf_mutex_acquire(v4 + 1656);
  v6 = *(_DWORD *)(*(_QWORD *)(v4 + 3880) + 164LL);
  result = qdf_mutex_release(v4 + 1656);
  if ( v6 )
  {
    v8 = *(_QWORD *)(*(_QWORD *)(a1 + 1360) + 3880LL);
    mlo_mgr_link_switch_notify(a1, v8 + 144);
    if ( (v6 & 0xFFFFFFFB) != 1 && !wlan_cm_is_vdev_connected(a1, v9, v10, v11, v12, v13, v14, v15, v16) )
      mlo_mgr_link_switch_defer_disconnect_req(a1, 8, 65517);
    mlo_handle_pending_disconnect(a1, v9, v10, v11, v12, v13, v14, v15, v16);
    mlo_mgr_link_switch_complete(a1);
    if ( (*(_DWORD *)(v8 + 168) == 4) | v5 & 1 )
    {
      result = qdf_trace_msg(
                 0x8Fu,
                 8u,
                 "%s: Link switch not serialized reason %d link_recfg_in_prog %d",
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 "mlo_mgr_remove_link_switch_cmd");
    }
    else
    {
      v25 = *(unsigned __int8 *)(v8 + 146);
      v26 = *(unsigned __int8 *)(v8 + 145);
      v30 = a1;
      LOBYTE(v31) = 1;
      v28 = (v2 << 16) | (v25 << 8) | v26;
      v29 = 8;
      v27 = 0x1E00000028LL;
      result = wlan_serialization_remove_cmd((unsigned int *)&v27, v17, v18, v19, v20, v21, v22, v23, v24);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
