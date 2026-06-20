__int64 __fastcall msm_vidc_close(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x19
  __int64 v7; // x22

  v5 = *(_QWORD *)(a1 + 320);
  v7 = a1 + 38408;
  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_9602D, "high", a1 + 340, "msm_vidc_close", a5);
  client_lock(a1, "msm_vidc_close");
  inst_lock(a1, "msm_vidc_close");
  msm_vidc_print_stats(a1);
  msm_vidc_print_memory_stats(a1);
  msm_vidc_print_residency_stats(v5);
  msm_vidc_session_close(a1);
  msm_vidc_change_state(a1, 4, "msm_vidc_close");
  *(_DWORD *)(a1 + 176) = 0;
  *(_BYTE *)v7 = 0;
  strcpy((char *)(a1 + 180), "SUB_STATE_NONE");
  *(_DWORD *)(v7 + 292) = 0;
  *(_DWORD *)(v7 + 24) = 0;
  msm_vidc_scale_clocks(a1);
  msm_vidc_scale_buses(a1);
  inst_unlock(a1, "msm_vidc_close");
  client_unlock(a1, "msm_vidc_close");
  cancel_stability_work_sync(a1);
  cancel_stats_work_sync(a1);
  msm_vidc_show_stats(a1);
  put_inst(a1);
  msm_vidc_schedule_core_deinit(v5);
  return 0;
}
