__int64 __fastcall dp_fim_init(__int64 a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x20
  __int64 v4; // x4
  __int64 v5; // x5
  __int64 v6; // x6
  __int64 v7; // x7
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7

  v2 = _qdf_mem_malloc(0x890u, "dp_fim_init", 504);
  if ( !v2 )
    return 2;
  *(_DWORD *)(v2 + 8) = 0;
  v3 = (_QWORD *)v2;
  memset((void *)(v2 + 16), 0, 0x808u);
  v3[259] = dp_fim_policy_update_notifier;
  v3[262] = a1;
  fpm_policy_event_register_notifier(a1, (__int64)(v3 + 259));
  v3[272] = dp_fim_flow_expiry_timer_cb;
  v3[273] = v3;
  init_timer_key(v3 + 267, _os_timer_shim_20, 0x80000, 0, 0);
  v4 = *(unsigned __int8 *)(a1 + 20);
  v5 = *(unsigned __int8 *)(a1 + 21);
  v6 = *(unsigned __int8 *)(a1 + 22);
  v7 = *(unsigned __int8 *)(a1 + 25);
  *(_QWORD *)(a1 + 3720) = v3;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: FIM module initialized for dp_intf:%02x:%02x:%02x:**:**:%02x",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "dp_fim_init",
    v4,
    v5,
    v6,
    v7);
  return 0;
}
