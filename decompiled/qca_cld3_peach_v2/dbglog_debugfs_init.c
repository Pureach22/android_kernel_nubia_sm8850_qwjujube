__int64 __fastcall dbglog_debugfs_init(__int64 a1)
{
  __int64 v1; // x19
  __int64 dir; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  v1 = a1 + 336;
  *(_DWORD *)(a1 + 360) = 0;
  *(_QWORD *)(a1 + 344) = a1 + 336;
  *(_QWORD *)(a1 + 352) = 0;
  *(_QWORD *)(a1 + 336) = a1 + 336;
  _init_swait_queue_head(a1 + 368, "&x->wait", &init_completion___key_2);
  dir = qdf_debugfs_create_dir("cldpeach_v2", 0);
  *(_QWORD *)(a1 + 400) = dir;
  if ( dir )
    return qdf_debugfs_create_entry("dbglog_block", 256, dir, v1, &fops_dbglog_block);
  else
    return qdf_trace_msg(
             0x38u,
             2u,
             "%s: Failed to create WMI debug fs",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "dbglog_debugfs_init");
}
