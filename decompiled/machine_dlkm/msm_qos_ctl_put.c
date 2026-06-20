__int64 __fastcall msm_qos_ctl_put(__int64 a1, __int64 a2)
{
  int v4; // w8
  __int64 v6; // x0
  int v7; // w9

  v4 = *(_DWORD *)(a2 + 72);
  qos_vote_status = v4;
  if ( cluster_first_cpu[0] < 0x20u )
  {
    if ( v4 )
    {
      if ( qword_D980 )
        dev_pm_qos_remove_request(&latency_pm_qos_req);
      if ( qos_client_active_cnt++ )
        return 0;
      v6 = 300;
    }
    else
    {
      v7 = qos_client_active_cnt;
      v6 = 2000000000;
      if ( qos_client_active_cnt )
      {
        --qos_client_active_cnt;
        if ( v7 != 1 )
          return 0;
      }
    }
    ((void (__fastcall *)(__int64))msm_audio_update_qos_request)(v6);
    return 0;
  }
  __break(0x5512u);
  __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
  return msm_lpi_logging_enable_get();
}
