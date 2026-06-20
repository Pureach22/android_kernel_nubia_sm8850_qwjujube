__int64 __fastcall cam_sfe_bus_handle_sfe_out_done_top_half(int a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v5; // x22
  __int64 v6; // x0
  unsigned int evt_payload; // w0
  unsigned int v8; // w22
  __int64 v9; // x0
  __int64 result; // x0
  __int64 v11; // x0
  __int64 v12; // x23
  __int64 v13; // x4
  int v14; // w8
  _DWORD *v15; // x8
  unsigned __int64 StatusReg; // x20
  __int64 v17; // x0
  __int64 v18; // x8
  _QWORD v19[2]; // [xsp+0h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)a2 )
  {
    v2 = *(_QWORD *)(*(_QWORD *)a2 + 24LL);
    v5 = *(_QWORD *)(*(_QWORD *)(v2 + 40) + 24LL);
    if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40000000,
        4,
        "cam_sfe_bus_handle_sfe_out_done_top_half",
        1671,
        "SFE:%d Bus IRQ status_0: 0x%X",
        **(_DWORD **)(v2 + 8),
        **(_DWORD **)(a2 + 16));
    v6 = *(_QWORD *)(v2 + 8);
    v19[0] = 0;
    evt_payload = cam_sfe_bus_wr_get_evt_payload(v6, v19);
    if ( evt_payload )
    {
      v8 = evt_payload;
      if ( (unsigned int)__ratelimit(
                           &cam_sfe_bus_handle_sfe_out_done_top_half__rs_76,
                           "cam_sfe_bus_handle_sfe_out_done_top_half") )
        v9 = 3;
      else
        v9 = 2;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
        v9,
        0x40000000,
        3,
        "cam_sfe_bus_handle_sfe_out_done_top_half",
        1679,
        "Failed to get payload for SFE:%d Bus IRQ status_0: 0x%X",
        **(unsigned int **)(v2 + 8),
        **(unsigned int **)(a2 + 16));
      result = v8;
    }
    else
    {
      v12 = v19[0];
      cam_isp_hw_get_timestamp(v19[0] + 48LL);
      v14 = **(_DWORD **)(v2 + 8);
      *(_DWORD *)((char *)&qword_28 + v12) = a1;
      *(_DWORD *)((char *)&qword_10 + v12) = v14;
      if ( *(_DWORD *)(a2 + 8)
        && (*(_DWORD *)((char *)&qword_10 + v12 + 4) = **(_DWORD **)(a2 + 16), *(_DWORD *)(a2 + 8) >= 2u) )
      {
        __break(0x5512u);
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                         + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
            & 1) != 0 )
        {
          ++*(_DWORD *)(StatusReg + 16);
          v17 = _traceiter_cam_log_event(0, (__int64)"bufdone", (__int64)"bufdone_IRQ", a2, v13);
          v18 = *(_QWORD *)(StatusReg + 16) - 1LL;
          *(_DWORD *)(StatusReg + 16) = v18;
          if ( !v18 || !*(_QWORD *)(StatusReg + 16) )
            preempt_schedule_notrace(v17);
        }
      }
      else
      {
        v15 = *(_DWORD **)(a2 + 16);
        *(_QWORD *)(a2 + 24) = v12;
        if ( (*(_DWORD *)(v5 + 4) & *v15) != 0 )
          *(int *)((char *)&_ksymtab_cam_cdm_reset_hw + v12) = cam_io_r_mb(
                                                                 *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 32) + 24LL)
                                                                                       + 8LL)
                                                                           + 8LL)
                                                               + *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 32) + 24LL)
                                                                                             + 16LL)
                                                                                 + 68LL));
      }
      result = 0;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(
                         &cam_sfe_bus_handle_sfe_out_done_top_half__rs,
                         "cam_sfe_bus_handle_sfe_out_done_top_half") )
      v11 = 3;
    else
      v11 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      v11,
      0x40000000,
      1,
      "cam_sfe_bus_handle_sfe_out_done_top_half",
      1662,
      "No resource");
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
