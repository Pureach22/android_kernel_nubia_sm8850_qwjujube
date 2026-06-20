__int64 __fastcall wlan_dp_lapb_flow_attach(__int64 a1)
{
  _BYTE *v2; // x20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  char v11; // w8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  v2 = (_BYTE *)(a1 + 19792);
  if ( (wlan_cfg_is_lapb_enabled(*(_QWORD *)(a1 + 40)) & 1) != 0 )
  {
    *(_QWORD *)(a1 + 19800) = &dp_lapb_flow_ops;
    v11 = *(_BYTE *)(a1 + 7153);
    *(_QWORD *)(a1 + 19896) = dp_lapb_tcl_hp_update_timer_handler;
    *(_DWORD *)(a1 + 19880) = 1;
    *(_BYTE *)(a1 + 19793) = v11 - 1;
    *(_QWORD *)(a1 + 19888) = a1 + 19816;
    hrtimer_init(a1 + 19816, 1, 5);
    *(_QWORD *)(a1 + 19856) = _qdf_hrtimer_cb_1;
    *(_QWORD *)(a1 + 19808) = a1;
    *v2 = 1;
    qdf_mem_set((void *)(a1 + 19904), 0, 12);
    qdf_trace_msg(0x45u, 5u, "%s: LAPB attach", v12, v13, v14, v15, v16, v17, v18, v19, "wlan_dp_lapb_flow_attach");
    return 0;
  }
  else
  {
    qdf_trace_msg(0x45u, 5u, "%s: LAPB: ini is disabled", v3, v4, v5, v6, v7, v8, v9, v10, "wlan_dp_lapb_flow_attach");
    *v2 = 0;
    return 11;
  }
}
