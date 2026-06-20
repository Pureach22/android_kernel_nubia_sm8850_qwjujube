__int64 __fastcall dp_fim_deinit(__int64 a1)
{
  _BYTE *v1; // x20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  v1 = *(_BYTE **)(a1 + 3720);
  *v1 = 0;
  timer_delete(v1 + 2136);
  timer_delete_sync(v1 + 2136);
  fpm_policy_event_unregister_notifier(a1, (__int64)(v1 + 2072));
  dp_fim_hash_table_delete_node((__int64)v1, nullptr, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 3720));
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: FIM module uninitialized for dp_intf:%02x:%02x:%02x:**:**:%02x",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "dp_fim_deinit",
    *(unsigned __int8 *)(a1 + 20),
    *(unsigned __int8 *)(a1 + 21),
    *(unsigned __int8 *)(a1 + 22),
    *(unsigned __int8 *)(a1 + 25));
  return 0;
}
