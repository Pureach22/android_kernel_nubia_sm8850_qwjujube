__int64 __fastcall hdd_nud_failure_work(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _QWORD *context; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x20
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  const char *v47; // x2
  __int64 v48; // x19
  int v49; // w0
  __int64 *v50[2]; // [xsp+0h] [xbp-10h] BYREF

  v50[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 2720);
  v50[0] = nullptr;
  result = _osif_vdev_sync_op_start(v3, v50, (__int64)"hdd_nud_failure_work");
  if ( !(_DWORD)result )
  {
    context = _cds_get_context(71, (__int64)"__hdd_nud_failure_work", v5, v6, v7, v8, v9, v10, v11, v12);
    qdf_trace_msg(0x33u, 8u, "%s: enter", v14, v15, v16, v17, v18, v19, v20, v21, "__hdd_nud_failure_work");
    if ( (unsigned int)_hdd_validate_adapter(
                         a2 + 2688,
                         (__int64)"__hdd_nud_failure_work",
                         v22,
                         v23,
                         v24,
                         v25,
                         v26,
                         v27,
                         v28,
                         v29) )
      goto LABEL_19;
    v38 = *(_QWORD *)(a2 + 2712);
    if ( (unsigned int)_wlan_hdd_validate_context(
                         v38,
                         (__int64)"__hdd_nud_failure_work",
                         v30,
                         v31,
                         v32,
                         v33,
                         v34,
                         v35,
                         v36,
                         v37) )
      goto LABEL_19;
    if ( hdd_cm_is_vdev_associated(*(_DWORD **)(a2 + 55520)) )
    {
      if ( *(_BYTE *)(v38 + 185) == 1 )
      {
        v47 = "%s: wlan is suspended, ignore NUD failure event";
      }
      else
      {
        if ( context && ucfg_dp_nud_fail_data_stall_evt_enabled() )
        {
          qdf_trace_msg(
            0x3Bu,
            2u,
            "%s: Data stall due to NUD failure",
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            "__hdd_nud_failure_work");
          cdp_post_data_stall_event(context);
        }
        if ( !*(_DWORD *)(a2 + 2728) && ucfg_dp_is_roam_after_nud_enabled(*(_QWORD *)v38) )
        {
          hdd_handle_nud_fail_sta(v38, a2 + 2688);
LABEL_19:
          result = _osif_vdev_sync_op_stop((__int64)v50[0], (__int64)"hdd_nud_failure_work");
          goto LABEL_20;
        }
        v48 = *(_QWORD *)(a2 + 55520);
        v49 = mlo_mgr_link_switch_defer_disconnect_req(
                *(_QWORD *)(v48 + 32),
                5u,
                0xFFF1u,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                v46);
        if ( v49 && v49 != 6 )
          wlan_hdd_cm_issue_disconnect(v48, 65521, 0);
        v47 = "%s: exit";
      }
    }
    else
    {
      v47 = "%s: Not in Connected State";
    }
    qdf_trace_msg(0x33u, 8u, v47, v39, v40, v41, v42, v43, v44, v45, v46, "__hdd_nud_failure_work");
    goto LABEL_19;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
