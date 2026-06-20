__int64 __fastcall wlan_hdd_lpc_del_monitor_interface(__int64 result, char a2)
{
  __int64 v2; // x19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 (*v21)(void); // x8
  __int64 adapter; // x0
  __int64 v23; // x20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x1
  const char *v41; // x2
  const char *v42; // x3
  unsigned int v43; // w0

  if ( result )
  {
    v2 = result;
    result = ucfg_dp_is_local_pkt_capture_enabled();
    if ( (result & 1) != 0 )
    {
      result = (__int64)_cds_get_context(
                          71,
                          (__int64)"wlan_hdd_lpc_del_monitor_interface",
                          v4,
                          v5,
                          v6,
                          v7,
                          v8,
                          v9,
                          v10,
                          v11);
      if ( result )
      {
        if ( !*(_QWORD *)result )
        {
          v41 = "%s: Invalid Instance";
          v42 = "cdp_is_local_pkt_capture_running";
          v43 = 137;
          return qdf_trace_msg(v43, 8u, v41, v12, v13, v14, v15, v16, v17, v18, v19, v42);
        }
        v20 = *(_QWORD *)(*(_QWORD *)result + 24LL);
        if ( v20 )
        {
          v21 = *(__int64 (**)(void))(v20 + 120);
          if ( v21 )
          {
            if ( *((_DWORD *)v21 - 1) != -1653155309 )
              __break(0x8228u);
            result = v21();
            if ( (result & 1) != 0 )
            {
              adapter = hdd_get_adapter(v2, 6);
              if ( adapter )
              {
                v23 = adapter;
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: lpc: Delete monitor interface",
                  v12,
                  v13,
                  v14,
                  v15,
                  v16,
                  v17,
                  v18,
                  v19,
                  "wlan_hdd_lpc_del_monitor_interface");
                hdd_stop_adapter(v2, v23);
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: enter(%s)",
                  v24,
                  v25,
                  v26,
                  v27,
                  v28,
                  v29,
                  v30,
                  v31,
                  "hdd_deinit_adapter",
                  *(_QWORD *)(v23 + 32) + 296LL);
                hdd_deinit_session(v23);
                qdf_trace_msg(0x33u, 8u, "%s: exit", v32, v33, v34, v35, v36, v37, v38, v39, "hdd_deinit_adapter");
                v40 = system_wq;
                *(_BYTE *)(v23 + 52797) = a2 & 1;
                *(_QWORD *)(v2 + 8272) = v23;
                *(_BYTE *)(v2 + 8264) = 1;
                return queue_work_on(32, v40, v2 + 8216);
              }
              v41 = "%s: There is no monitor adapter";
              v42 = "wlan_hdd_lpc_del_monitor_interface";
              v43 = 51;
              return qdf_trace_msg(v43, 8u, v41, v12, v13, v14, v15, v16, v17, v18, v19, v42);
            }
          }
        }
      }
    }
  }
  return result;
}
