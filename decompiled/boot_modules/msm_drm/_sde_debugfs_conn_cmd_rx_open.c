__int64 __fastcall sde_debugfs_conn_cmd_rx_open(__int64 a1, __int64 a2)
{
  *(_QWORD *)(a2 + 32) = *(_QWORD *)(a1 + 696);
  return nonseekable_open();
}
