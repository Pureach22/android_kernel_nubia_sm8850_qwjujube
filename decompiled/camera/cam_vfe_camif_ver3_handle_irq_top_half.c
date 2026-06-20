__int64 __fastcall cam_vfe_camif_ver3_handle_irq_top_half(__int64 a1, __int64 *a2)
{
  __int64 v3; // x24
  __int64 v4; // x21
  unsigned int evt_payload; // w19
  __int64 v6; // x0
  __int64 v7; // x25
  __int64 v8; // x3
  __int64 v9; // x4
  __int64 v10; // x8
  unsigned __int64 StatusReg; // x25
  __int64 v13; // x0
  __int64 v14; // x8
  _QWORD v15[2]; // [xsp+10h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a2;
  v4 = *(_QWORD *)(*a2 + 24);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_camif_ver3_handle_irq_top_half",
      1300,
      "VFE:%d CAMIF IRQ status_0: 0x%X status_1: 0x%X status_2: 0x%X",
      *(_DWORD *)(*(_QWORD *)(v3 + 16) + 4LL),
      *(_DWORD *)a2[2],
      *(_DWORD *)(a2[2] + 4),
      *(_DWORD *)(a2[2] + 8));
  v15[0] = 0;
  evt_payload = cam_vfe_camif_ver3_get_evt_payload(v4, v15);
  if ( evt_payload )
  {
    if ( (unsigned int)__ratelimit(
                         &cam_vfe_camif_ver3_handle_irq_top_half__rs,
                         "cam_vfe_camif_ver3_handle_irq_top_half") )
      v6 = 3;
    else
      v6 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, _DWORD))cam_print_log)(
      v6,
      8,
      3,
      "cam_vfe_camif_ver3_handle_irq_top_half",
      1307,
      "VFE:%d CAMIF IRQ status_0: 0x%X status_1: 0x%X status_2: 0x%X",
      *(unsigned int *)(*(_QWORD *)(v3 + 16) + 4LL),
      *(unsigned int *)a2[2],
      *(_DWORD *)(a2[2] + 4),
      *(_DWORD *)(a2[2] + 8));
  }
  else
  {
    v7 = v15[0];
    cam_isp_hw_get_timestamp((__int64 *)(v15[0] + 40LL));
    *(int *)((char *)&_ksymtab_cam_cdm_flush_hw + v7) = 0;
    if ( *((_DWORD *)a2 + 2)
      && (*(_DWORD *)((char *)&qword_10 + v7) = *(_DWORD *)a2[2], *((_DWORD *)a2 + 2) > 1u)
      && (*(_DWORD *)((char *)&qword_10 + v7 + 4) = *(_DWORD *)(a2[2] + 4), *((_DWORD *)a2 + 2) >= 3u)
      && (*(_DWORD *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v7) = *(_DWORD *)(a2[2] + 8),
          *((_DWORD *)a2 + 2) >= 4u)
      && (*(_DWORD *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v7 + 4) = *(_DWORD *)(a2[2] + 12),
          *((_DWORD *)a2 + 2) >= 5u)
      && (*(int *)((char *)&dword_20 + v7) = *(_DWORD *)(a2[2] + 16), *((_DWORD *)a2 + 2) > 5u) )
    {
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                       + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
          & 1) != 0 )
      {
        ++*(_DWORD *)(StatusReg + 16);
        v13 = _traceiter_cam_log_event(0, (__int64)"SOF", (__int64)"TOP_HALF", v8, v9);
        v14 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v14;
        if ( !v14 || !*(_QWORD *)(StatusReg + 16) )
          preempt_schedule_notrace(v13);
      }
    }
    else
    {
      if ( (*(_DWORD *)(*(_QWORD *)(v4 + 32) + 64LL) & *(_DWORD *)((_BYTE *)&qword_10 + v7 + 4)) != 0 )
      {
        v10 = *(unsigned int *)(*(_QWORD *)(v4 + 24) + 72LL);
        if ( (_DWORD)v10 )
        {
          if ( (*(_BYTE *)(v4 + 84) & 3) != 0 )
            *(int *)((char *)&_ksymtab_cam_cdm_flush_hw + v7) = cam_io_r_mb(*(_QWORD *)v4 + v10);
        }
      }
      a2[3] = v7;
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_ver3_handle_irq_top_half",
        1350,
        "Exit");
  }
  _ReadStatusReg(SP_EL0);
  return evt_payload;
}
