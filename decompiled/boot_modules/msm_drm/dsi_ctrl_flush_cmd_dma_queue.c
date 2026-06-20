size_t __fastcall dsi_ctrl_flush_cmd_dma_queue(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  size_t result; // x0
  int v10; // w6
  int v11; // w7
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  sde_evtlog_log(sde_dbg_base_evtlog, "dsi_ctrl_flush_cmd_dma_queue", 506, -1, 4369, -1059143953, a7, a8, vars0);
  if ( *(_DWORD *)(a1 + 2852) )
  {
    result = cancel_work_sync(a1 + 2808);
    if ( (result & 1) != 0 )
    {
      result = dsi_ctrl_post_cmd_transfer(a1);
      *(_BYTE *)(a1 + 2848) = 0;
    }
  }
  else
  {
    _flush_workqueue(*(_QWORD *)(a1 + 2840));
    return sde_evtlog_log(
             sde_dbg_base_evtlog,
             "dsi_ctrl_flush_cmd_dma_queue",
             515,
             -1,
             17476,
             -1059143953,
             v10,
             v11,
             vars0a);
  }
  return result;
}
