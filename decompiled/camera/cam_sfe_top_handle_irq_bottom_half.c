__int64 __fastcall cam_sfe_top_handle_irq_bottom_half(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x21
  int v3; // w23
  _DWORD *v4; // x8
  __int64 v5; // x19
  int v7; // w8
  __int64 v8; // x27
  __int16 v9; // w22
  int v10; // w0
  const char *v11; // x10
  const char *v12; // x9
  unsigned int v13; // w20
  __int64 v15; // [xsp+18h] [xbp-18h] BYREF
  int v16; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+28h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a1 + 24);
  v3 = *(_DWORD *)(a2 + 24);
  v16 = 0;
  v15 = a2;
  v4 = (_DWORD *)v2[6];
  v5 = v2[2];
  if ( (v4[2] & v3) != 0 )
  {
    if ( (*v4 & v3) != 0 )
    {
      if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x40000000,
          4,
          "cam_sfe_top_handle_irq_bottom_half",
          1896,
          "SFE:%d Received %s SOF",
          *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
          (const char *)(a1 + 128));
      v7 = *(_DWORD *)(v5 + 32228);
      if ( (v7 & 2) != 0 )
      {
        v8 = *(unsigned int *)(v2[3] + 36LL);
        v9 = cam_io_r(*v2 + *(unsigned int *)(v2[3] + 32LL));
        v10 = cam_io_r(*v2 + v8);
        v11 = "TRUE";
        if ( (v9 & 0x4000) != 0 )
          v12 = "TRUE";
        else
          v12 = "FALSE";
        if ( (v9 & 0x8000) == 0 )
          v11 = "FALSE";
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          3,
          "cam_sfe_top_handle_irq_bottom_half",
          1910,
          "SFE:%d HBI: 0x%x VBI: 0x%x NEQ_HBI: %s HBI_MIN_ERR: %s",
          *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
          v9 & 0x3FFF,
          v10,
          v12,
          v11);
        v7 = *(_DWORD *)(v5 + 32228);
      }
      if ( (v7 & 4) != 0 )
        cam_sfe_top_sel_frame_counter(*(_DWORD *)(a1 + 4), &v16, 1, v2);
      cam_sfe_top_dump_perf_counters("SOF", a1 + 128, v5);
      v4 = (_DWORD *)v2[6];
    }
    if ( (v4[1] & v3) != 0 )
    {
      if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x40000000,
          4,
          "cam_sfe_top_handle_irq_bottom_half",
          1926,
          "SFE:%d Received %s EOF",
          *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
          (const char *)(a1 + 128));
      cam_sfe_top_dump_perf_counters("EOF", a1 + 128, v5);
    }
    v13 = 0;
  }
  else
  {
    v13 = 4;
  }
  cam_sfe_top_put_evt_payload(v5, &v15);
  _ReadStatusReg(SP_EL0);
  return v13;
}
