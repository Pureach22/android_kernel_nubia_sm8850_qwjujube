__int64 __fastcall cam_vfe_bus_ver3_handle_rup_top_half(int a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v5; // x0
  unsigned int evt_payload; // w0
  __int64 v7; // x3
  unsigned int v8; // w22
  __int64 v9; // x0
  __int64 result; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  int v13; // w9
  unsigned __int64 StatusReg; // x20
  __int64 v15; // x0
  __int64 v16; // x8
  _QWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)a2 )
  {
    v2 = *(_QWORD *)(*(_QWORD *)a2 + 24LL);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_bus_ver3_handle_rup_top_half",
        666,
        "VFE:%u Bus IRQ status_0: 0x%X",
        *(_DWORD *)(*(_QWORD *)(v2 + 16) + 8LL),
        **(_DWORD **)(a2 + 16));
    v5 = *(_QWORD *)(v2 + 16);
    v17[0] = 0;
    evt_payload = cam_vfe_bus_ver3_get_evt_payload(v5, v17);
    if ( evt_payload )
    {
      v8 = evt_payload;
      if ( (unsigned int)__ratelimit(
                           &cam_vfe_bus_ver3_handle_rup_top_half__rs_118,
                           "cam_vfe_bus_ver3_handle_rup_top_half") )
        v9 = 3;
      else
        v9 = 2;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
        v9,
        8,
        3,
        "cam_vfe_bus_ver3_handle_rup_top_half",
        675,
        "VFE:%u Bus IRQ status_0: 0x%X",
        *(unsigned int *)(*(_QWORD *)(v2 + 16) + 8LL),
        **(unsigned int **)(a2 + 16));
      result = v8;
    }
    else
    {
      v12 = v17[0];
      v13 = *(_DWORD *)(*(_QWORD *)(v2 + 16) + 8LL);
      *(int *)((char *)&_ksymtab_cam_cdm_flush_hw + v17[0]) = a1;
      *(_DWORD *)((char *)&qword_10 + v12) = v13;
      if ( *(_DWORD *)(a2 + 8) )
      {
        *(_DWORD *)((char *)&qword_28 + v12) = **(_DWORD **)(a2 + 16);
        if ( *(_DWORD *)(a2 + 8) > 1u )
        {
          *(_DWORD *)((char *)&qword_28 + v12 + 4) = *(_DWORD *)(*(_QWORD *)(a2 + 16) + 4LL);
          if ( *(_DWORD *)(a2 + 8) >= 3u )
          {
            *(_DWORD *)((char *)&_ksymtab_cam_cdm_get_iommu_handle + v12) = *(_DWORD *)(*(_QWORD *)(a2 + 16) + 8LL);
            if ( *(_DWORD *)(a2 + 8) >= 4u )
            {
              *(_DWORD *)((char *)&_ksymtab_cam_cdm_get_iommu_handle + v12 + 4) = *(_DWORD *)(*(_QWORD *)(a2 + 16) + 12LL);
              if ( *(_DWORD *)(a2 + 8) >= 5u )
              {
                *(int *)((char *)&dword_38 + v12) = *(_DWORD *)(*(_QWORD *)(a2 + 16) + 16LL);
                if ( *(_DWORD *)(a2 + 8) >= 6u )
                {
                  *(int *)((char *)&_ksymtab_cam_cdm_handle_error + v12) = *(_DWORD *)(*(_QWORD *)(a2 + 16) + 20LL);
                  if ( *(_DWORD *)(a2 + 8) >= 7u )
                  {
                    *(_DWORD *)((char *)&qword_40 + v12) = *(_DWORD *)(*(_QWORD *)(a2 + 16) + 24LL);
                    if ( *(_DWORD *)(a2 + 8) > 7u )
                    {
                      __break(0x5512u);
                      StatusReg = _ReadStatusReg(SP_EL0);
                      if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                                       + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
                          & 1) != 0 )
                      {
                        ++*(_DWORD *)(StatusReg + 16);
                        v15 = _traceiter_cam_log_event(0, (__int64)"RUP", (__int64)"RUP_IRQ", v7, 0);
                        v16 = *(_QWORD *)(StatusReg + 16) - 1LL;
                        *(_DWORD *)(StatusReg + 16) = v16;
                        if ( !v16 || !*(_QWORD *)(StatusReg + 16) )
                          preempt_schedule_notrace(v15);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      result = 0;
      *(_QWORD *)(a2 + 24) = v17[0];
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&cam_vfe_bus_ver3_handle_rup_top_half__rs, "cam_vfe_bus_ver3_handle_rup_top_half") )
      v11 = 3;
    else
      v11 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      v11,
      8,
      1,
      "cam_vfe_bus_ver3_handle_rup_top_half",
      658,
      "No resource");
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
