__int64 __fastcall _dp_bus_bw_compute_timer_stop(__int64 a1)
{
  __int64 comp_private_obj; // x20
  __int64 context; // x21
  __int64 result; // x0
  __int64 v5; // x0
  __int64 (__fastcall *v6)(_QWORD); // x8
  char v7; // w22
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x8
  void (*v18)(void); // x8
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  void (*v29)(void); // x8
  __int64 v30; // x8
  _DWORD *v31; // x8
  __int64 v32; // [xsp+Ch] [xbp-14h] BYREF
  int v33; // [xsp+14h] [xbp-Ch]
  __int64 v34; // [xsp+18h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  context = _cds_get_context(71, "__dp_bus_bw_compute_timer_stop");
  v33 = 0;
  result = cds_get_conparam();
  if ( (_DWORD)result != 5 )
  {
    result = cds_get_conparam();
    if ( (_DWORD)result != 8 && comp_private_obj && context )
    {
      v5 = *(_QWORD *)(comp_private_obj + 376);
      v6 = *(__int64 (__fastcall **)(_QWORD))(comp_private_obj + 536);
      if ( *((_DWORD *)v6 - 1) != 859392181 )
        __break(0x8228u);
      v7 = v6(v5);
      if ( qdf_periodic_work_stop_sync(comp_private_obj + 896) )
      {
        ucfg_ipa_set_perf_level(*(_QWORD *)(comp_private_obj + 8), 0, 0);
        dp_reset_tcp_delack(a1);
        v8 = _cds_get_context(71, "__dp_bus_bw_compute_timer_stop");
        if ( v8 && *(_QWORD *)v8 && (v17 = *(_QWORD *)(*(_QWORD *)v8 + 64LL)) != 0 )
        {
          v18 = *(void (**)(void))(v17 + 200);
          if ( v18 )
          {
            if ( *((_DWORD *)v18 - 1) != -251540498 )
              __break(0x8228u);
            v18();
          }
        }
        else
        {
          qdf_trace_msg(
            0x45u,
            1u,
            "%s invalid instance",
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            "cdp_pdev_reset_driver_del_ack");
        }
        v19 = _cds_get_context(71, "__dp_bus_bw_compute_timer_stop");
        if ( v19 && *(_QWORD *)v19 && (v28 = *(_QWORD *)(*(_QWORD *)v19 + 64LL)) != 0 )
        {
          v29 = *(void (**)(void))(v28 + 224);
          if ( v29 )
          {
            if ( *((_DWORD *)v29 - 1) != -251540498 )
              __break(0x8228u);
            v29();
          }
        }
        else
        {
          qdf_trace_msg(
            0x45u,
            1u,
            "%s invalid instance",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "cdp_pdev_reset_bundle_require_flag");
        }
        if ( *(_QWORD *)context
          && (v30 = *(_QWORD *)(*(_QWORD *)context + 64LL)) != 0
          && (v31 = *(_DWORD **)(v30 + 304)) != nullptr )
        {
          if ( *(v31 - 1) != -251540498 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD))v31)(context, 0);
        }
        else
        {
          qdf_trace_msg(
            0x89u,
            8u,
            "%s: Invalid Instance:",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "cdp_set_bus_vote_lvl_high");
        }
        *(_QWORD *)(comp_private_obj + 888) = 0;
      }
      if ( (v7 & 1) == 0 )
      {
        *(_DWORD *)(comp_private_obj + 876) = 0;
        dp_pld_request_bus_bandwidth(comp_private_obj, 0, 0);
      }
      v32 = 1;
      result = dp_bbm_apply_independent_policy(a1, (__int64)&v32);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
