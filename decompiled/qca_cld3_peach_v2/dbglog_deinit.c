__int64 __fastcall dbglog_deinit(_QWORD *a1)
{
  __int64 v2; // x1
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  skb_queue_purge_reason(a1 + 42, 85);
  complete(a1 + 45, v2);
  v3 = qdf_debugfs_remove_dir_recursive(a1[50]);
  tgt_assert_enable = 0;
  if ( (unsigned int)wmi_unified_unregister_event_handler(a1, 2u, v3, v4, v5, v6, v7, v8, v9, v10) )
    return 0xFFFFFFFFLL;
  else
    return 0;
}
