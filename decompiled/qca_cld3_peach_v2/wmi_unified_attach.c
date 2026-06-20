__int64 __fastcall wmi_unified_attach(__int64 a1, __int64 *a2)
{
  __int64 result; // x0
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x19
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  int v16; // w9
  __int64 v17; // x8
  void (__fastcall *v18)(_QWORD); // x8
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x20
  __int64 v23; // x0
  __int64 v24; // [xsp+0h] [xbp-20h] BYREF
  __int64 v25; // [xsp+8h] [xbp-18h]
  __int64 v26; // [xsp+10h] [xbp-10h]
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = _qdf_mem_malloc(0x1EB0u, "wmi_unified_attach", 3365);
  if ( !result )
    goto LABEL_13;
  v5 = result;
  v6 = _qdf_mem_malloc(0x380u, "wmi_unified_attach", 3371);
  if ( !v6 )
  {
    v23 = v5;
LABEL_12:
    _qdf_mem_free(v23);
    result = 0;
    goto LABEL_13;
  }
  v7 = v6;
  if ( (unsigned int)wmi_initialize_worker_context(v6) )
    goto LABEL_11;
  *(_QWORD *)(v7 + 760) = v5;
  *(_DWORD *)(v5 + 7792) = *((_DWORD *)a2 + 7);
  *(_BYTE *)(*(_QWORD *)(v7 + 760) + 24LL) = *((_BYTE *)a2 + 13);
  *(_QWORD *)(v7 + 40) = v5 + 40;
  *(_QWORD *)(v7 + 48) = v5 + 1064;
  *(_QWORD *)(v7 + 56) = v5 + 3116;
  *(_QWORD *)(v7 + 744) = v5 + 5252;
  *(_QWORD *)(v7 + 752) = v5 + 6424;
  *(_QWORD *)v7 = a1;
  *(_QWORD *)(v7 + 856) = v5 + 7796;
  *(_QWORD *)(v7 + 864) = v5 + 7808;
  *(_QWORD *)(v7 + 872) = v5 + 7820;
  *(_QWORD *)(v7 + 880) = v5 + 7832;
  *(_QWORD *)(v5 + 8) = a1;
  v16 = *((_DWORD *)a2 + 2);
  *(_DWORD *)(v7 + 724) = v16;
  *(_DWORD *)(v5 + 20) = v16;
  v17 = *((unsigned int *)a2 + 2);
  if ( (unsigned int)v17 > 1 )
  {
LABEL_11:
    _qdf_mem_free(v5);
    v23 = v7;
    goto LABEL_12;
  }
  v18 = (void (__fastcall *)(_QWORD))wmi_attach_register[v17];
  if ( !v18 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: wmi attach is not registered",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "wmi_unified_attach");
    goto LABEL_11;
  }
  if ( *((_DWORD *)v18 - 1) != -725170640 )
    __break(0x8228u);
  v18(v7);
  *(_DWORD *)(v7 + 24) = 0;
  *(_DWORD *)(v7 + 696) = 0;
  *(_DWORD *)(v7 + 700) = 0;
  *(_DWORD *)(v7 + 888) = 0;
  *(_DWORD *)(v7 + 716) = 0;
  *(_DWORD *)(v7 + 708) = 0;
  wmi_interface_logging_init(v7, 0);
  *(_BYTE *)(v7 + 736) = *((_BYTE *)a2 + 12);
  v19 = *a2;
  *(_BYTE *)(v7 + 737) = 0;
  *(_QWORD *)(v7 + 8) = v19;
  LOWORD(v19) = *((_WORD *)a2 + 12);
  *(_WORD *)(v7 + 768) = v19;
  *(_WORD *)(v5 + 7788) = v19;
  v20 = a2[2];
  *(_DWORD *)(v5 + 5168) = 0;
  *(_QWORD *)(v5 + 5176) = 0;
  *(_QWORD *)v5 = v20;
  v24 = 0x1000000000000LL;
  v25 = 0;
  v26 = 0x840000800000000LL;
  v21 = *(_QWORD *)(v7 + 728);
  *(_DWORD *)((char *)&v24 + 2) = 20971648;
  *(_QWORD *)(v5 + 5232) = v21;
  BYTE4(v25) = 2;
  HIWORD(v25) = 8;
  LOWORD(v26) = 1088;
  *(_QWORD *)(v5 + 5184) = v7;
  LODWORD(v25) = 37748752;
  BYTE2(v26) = 3;
  *(_QWORD *)(v7 + 16) = wbuff_module_register(&v24, 4, 64, 4, 0);
  wmi_hang_event_notifier_register(v7);
  v22 = (unsigned int)(48 * *(_DWORD *)(v7 + 464));
  _qdf_minidump_log(*(_QWORD *)(v7 + 440), v22, (__int64)"wmi_tx_cmp");
  ((void (__fastcall *)(const char *, _QWORD, __int64))qdf_ssr_driver_dump_register_region)(
    "wmi_tx_cmp",
    *(_QWORD *)(v7 + 440),
    v22);
  ((void (__fastcall *)(const char *, _QWORD, __int64))qdf_ssr_driver_dump_register_region)(
    "wmi_tx_cmp_idx",
    *(_QWORD *)(v7 + 456),
    4);
  ((void (__fastcall *)(const char *, _QWORD, _QWORD))qdf_ssr_driver_dump_register_region)(
    "wmi_command_log",
    *(_QWORD *)(v7 + 408),
    (unsigned int)(32 * *(_DWORD *)(v7 + 432)));
  ((void (__fastcall *)(const char *, _QWORD, __int64))qdf_ssr_driver_dump_register_region)(
    "wmi_command_log_idx",
    *(_QWORD *)(v7 + 424),
    4);
  ((void (__fastcall *)(const char *, _QWORD, _QWORD))qdf_ssr_driver_dump_register_region)(
    "wmi_event_log",
    *(_QWORD *)(v7 + 472),
    (unsigned int)(32 * *(_DWORD *)(v7 + 496)));
  ((void (__fastcall *)(const char *, _QWORD, __int64))qdf_ssr_driver_dump_register_region)(
    "wmi_event_log_idx",
    *(_QWORD *)(v7 + 488),
    4);
  ((void (__fastcall *)(const char *, _QWORD, _QWORD))qdf_ssr_driver_dump_register_region)(
    "wmi_rx_event",
    *(_QWORD *)(v7 + 504),
    (unsigned int)(32 * *(_DWORD *)(v7 + 528)));
  ((void (__fastcall *)(const char *, _QWORD, __int64))qdf_ssr_driver_dump_register_region)(
    "wmi_rx_event_idx",
    *(_QWORD *)(v7 + 520),
    4);
  ((void (__fastcall *)(const char *, __int64, __int64))qdf_ssr_driver_dump_register_region)(
    "wmi_debug_log_info",
    v7 + 408,
    288);
  result = v7;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
