__int64 __fastcall sde_encoder_phys_cmd_handle_post_kickoff(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x9
  int v3; // w19
  __int64 v4; // x22
  int v5; // w20
  int v6; // w21
  int v7; // w0

  if ( !result )
    return printk(&unk_26FCAB, "sde_encoder_phys_cmd_handle_post_kickoff");
  if ( *(_DWORD *)(result + 664) != 3 )
  {
    v1 = *(_QWORD *)result;
    if ( *(_BYTE *)(*(_QWORD *)result + 700LL) == 1 )
    {
      if ( *(_DWORD *)(v1 + 4808) )
      {
        v2 = *(_QWORD *)(result + 8);
        if ( v2 )
          v3 = *(_DWORD *)(v2 + 4676);
        else
          v3 = 0;
        v4 = result;
        v5 = sde_dbg_base_evtlog;
        if ( v1 )
          v6 = *(_DWORD *)(v1 + 24);
        else
          v6 = -1;
        v7 = ktime_get(result);
        result = sde_evtlog_log(
                   v5,
                   "_sde_encoder_phys_cmd_process_sim_qsync_event",
                   405,
                   2,
                   v6,
                   (unsigned int)(*(_QWORD *)(v4 + 864) / -1000LL) + v7 / 1000,
                   v3,
                   *(_DWORD *)(v4 + 2340),
                   0);
        if ( v3 )
          return ((__int64 (__fastcall *)(__int64, __int64))sde_encoder_phys_cmd_setup_sim_qsync_frame)(v4, 1);
      }
    }
  }
  return result;
}
