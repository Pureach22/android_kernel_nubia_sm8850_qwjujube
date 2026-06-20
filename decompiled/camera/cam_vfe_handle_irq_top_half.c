__int64 __fastcall cam_vfe_handle_irq_top_half(__int64 a1, __int64 *a2)
{
  __int64 v3; // x25
  unsigned int v4; // w9
  _QWORD *v5; // x21
  unsigned int v6; // w20
  char v7; // w8
  int v8; // w10
  unsigned int evt_payload; // w20
  unsigned int v10; // w21
  __int64 v11; // x0
  __int64 v12; // x22
  __int64 v13; // x3
  __int64 v14; // x4
  __int64 v15; // x9
  __int64 v16; // x0
  __int64 v17; // x23
  unsigned __int64 StatusReg; // x22
  __int64 v20; // x0
  __int64 v21; // x8
  _QWORD v22[2]; // [xsp+10h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a2;
  v4 = *((_DWORD *)a2 + 2);
  v5 = *(_QWORD **)(*a2 + 24);
  if ( v4 )
  {
    v6 = 0;
    v7 = debug_mdl;
    v8 = debug_priority;
    do
    {
      if ( (v7 & 8) != 0 && !v8 )
      {
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v7 & 8,
          4,
          "cam_vfe_handle_irq_top_half",
          2160,
          "VFE:%u IRQ status_%u: 0x%X",
          *(_DWORD *)(*(_QWORD *)(v3 + 16) + 4LL),
          v6,
          *(_DWORD *)(a2[2] + 4LL * (int)v6));
        v7 = debug_mdl;
        v8 = debug_priority;
        v4 = *((_DWORD *)a2 + 2);
      }
      ++v6;
    }
    while ( v6 < v4 );
  }
  v22[0] = 0;
  evt_payload = cam_vfe_get_evt_payload(v5, v22);
  if ( evt_payload )
  {
    if ( *((_DWORD *)a2 + 2) )
    {
      v10 = 0;
      do
      {
        if ( (unsigned int)__ratelimit(&cam_vfe_handle_irq_top_half__rs, "cam_vfe_handle_irq_top_half") )
          v11 = 3;
        else
          v11 = 2;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          v11,
          8,
          3,
          "cam_vfe_handle_irq_top_half",
          2168,
          "VFE:%u IRQ status_%u: 0x%X",
          *(_DWORD *)(*(_QWORD *)(v3 + 16) + 4LL),
          v10,
          *(_DWORD *)(a2[2] + 4LL * (int)v10));
        ++v10;
      }
      while ( v10 < *((_DWORD *)a2 + 2) );
    }
  }
  else
  {
    v12 = v22[0];
    cam_isp_hw_get_timestamp((__int64 *)(v22[0] + 40LL));
    *(int *)((char *)&_ksymtab_cam_cdm_flush_hw + v12) = 0;
    if ( *((_DWORD *)a2 + 2)
      && (*(_DWORD *)((char *)&qword_10 + v12) = *(_DWORD *)a2[2], *((_DWORD *)a2 + 2) > 1u)
      && (*(_DWORD *)((char *)&qword_10 + v12 + 4) = *(_DWORD *)(a2[2] + 4), *((_DWORD *)a2 + 2) >= 3u)
      && (*(_DWORD *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v12) = *(_DWORD *)(a2[2] + 8),
          *((_DWORD *)a2 + 2) >= 4u)
      && (*(_DWORD *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v12 + 4) = *(_DWORD *)(a2[2] + 12),
          *((_DWORD *)a2 + 2) >= 5u)
      && (*(int *)((char *)&dword_20 + v12) = *(_DWORD *)(a2[2] + 16), *((_DWORD *)a2 + 2) > 5u) )
    {
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                       + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
          & 1) != 0 )
      {
        ++*(_DWORD *)(StatusReg + 16);
        v20 = _traceiter_cam_log_event(0, (__int64)"SOF", (__int64)"TOP_HALF", v13, v14);
        v21 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v21;
        if ( !v21 || !*(_QWORD *)(StatusReg + 16) )
          preempt_schedule_notrace(v20);
      }
    }
    else
    {
      a2[3] = v12;
      if ( (*(_DWORD *)(v5[8] + 4LL) & *(_DWORD *)(a2[2] + 4LL * *(unsigned int *)(v5[3] + 776LL))) != 0 )
      {
        v15 = v5[9];
        if ( *(_QWORD *)(v15 + 10904) )
        {
          v16 = *(_QWORD *)(v15 + 10912);
          if ( v16 )
          {
            v17 = (unsigned int)cam_io_r_mb(v16);
            *(_QWORD *)((char *)&unk_50 + v12) = v17;
            *(_QWORD *)((char *)&unk_50 + v12) = (unsigned int)cam_io_r_mb(*(_QWORD *)(v5[9] + 10904LL))
                                               | (unsigned __int64)(v17 << 32);
          }
        }
      }
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_handle_irq_top_half",
        2209,
        "VFE:%u Exit",
        *(_DWORD *)(*(_QWORD *)(v3 + 16) + 4LL));
  }
  _ReadStatusReg(SP_EL0);
  return evt_payload;
}
