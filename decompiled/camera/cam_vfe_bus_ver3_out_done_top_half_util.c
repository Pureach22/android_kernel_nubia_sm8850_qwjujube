__int64 __fastcall cam_vfe_bus_ver3_out_done_top_half_util(int a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v8; // x25
  __int64 v9; // x4
  int v10; // w8
  unsigned int v11; // w6
  __int64 *v12; // x26
  __int64 v13; // x27
  __int64 v14; // x22
  int v16; // w22
  int v17; // w8
  unsigned __int64 StatusReg; // x23
  __int64 v19; // x0
  __int64 v20; // x8

  v8 = *(_QWORD *)(*(_QWORD *)(a4 + 56) + 24LL);
  cam_isp_hw_get_timestamp((__int64 *)(a3 + 72));
  v10 = *(_DWORD *)(*(_QWORD *)(a4 + 16) + 8LL);
  *(_DWORD *)(a3 + 36) = a1;
  *(_DWORD *)(a3 + 16) = v10;
  v11 = *(_DWORD *)(a2 + 8);
  if ( v11 > 7 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_out_done_top_half_util",
      2615,
      "Index out of bounds for num of registers %d, max allowed is %d",
      v11,
      7);
    return 4294967274LL;
  }
  v12 = *(__int64 **)(*(_QWORD *)(a4 + 40) + 24LL);
  v13 = *v12;
  if ( v11 )
  {
    v14 = 0;
    while ( v14 != 7 )
    {
      *(_DWORD *)(a3 + 40 + 4 * v14) = *(_DWORD *)(*(_QWORD *)(a2 + 16) + 4 * v14);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_ver3_out_done_top_half_util",
          2611,
          "VFE:%u Bus IRQ status_%d: 0x%X",
          *(_DWORD *)(*(_QWORD *)(a4 + 16) + 8LL),
          v14,
          *(_DWORD *)(*(_QWORD *)(a2 + 16) + 4 * v14));
      if ( ++v14 >= (unsigned __int64)*(unsigned int *)(a2 + 8) )
        goto LABEL_10;
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v19 = _traceiter_cam_log_event(0, (__int64)"bufdone", (__int64)"bufdone_IRQ", 7, v9);
      v20 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v20;
      if ( !v20 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v19);
    }
    goto LABEL_18;
  }
LABEL_10:
  *(_QWORD *)(a2 + 24) = a3;
  v16 = **(_DWORD **)(a2 + 16);
  if ( *(_BYTE *)(a3 + 124) != 1 )
  {
    if ( (*(_DWORD *)(v8 + 24) & v16) == 0 )
      goto LABEL_18;
LABEL_15:
    if ( *(_BYTE *)(*(_QWORD *)(a4 + 16) + 34673LL) != 1 || *(_BYTE *)(*(_QWORD *)(a4 + 16) + 34674LL) == 1 )
      *(_DWORD *)(a3 + 120) = cam_io_r_mb(*(_QWORD *)(v13 + 16) + *((unsigned int *)v12 + 39) + *(unsigned int *)(v12[1] + 96));
    goto LABEL_18;
  }
  v17 = *(_DWORD *)(v8 + 28);
  if ( !v17 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_out_done_top_half_util",
      2624,
      "Invalid configuration for hw ctxt comp buf done");
    return 0xFFFFFFFFLL;
  }
  if ( (v16 & (*(_DWORD *)(v8 + 24) | v17)) != 0 )
    goto LABEL_15;
LABEL_18:
  if ( *(_DWORD *)(a2 + 8) >= 2u && (*(_DWORD *)(a4 + 116) & *(_DWORD *)(*(_QWORD *)(a2 + 16) + 4LL)) != 0 )
    *(_BYTE *)(a3 + 125) = 1;
  return 0;
}
