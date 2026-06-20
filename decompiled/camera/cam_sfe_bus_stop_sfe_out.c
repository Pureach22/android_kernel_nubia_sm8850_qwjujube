__int64 __fastcall cam_sfe_bus_stop_sfe_out(__int64 a1)
{
  int v1; // w8
  __int64 v2; // x24
  __int64 result; // x0
  __int64 v4; // x9
  unsigned int v5; // w26
  __int64 v6; // x23
  __int64 v7; // x22
  __int64 v8; // x19
  unsigned int v9; // w19
  unsigned int v10; // w19
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // [xsp+8h] [xbp-18h]
  __int64 v14; // [xsp+10h] [xbp-10h]

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_stop_sfe_out",
      1586,
      "Invalid input");
    return 4294967274LL;
  }
  v1 = *(_DWORD *)(a1 + 8);
  v2 = *(_QWORD *)(a1 + 24);
  if ( (unsigned int)(v1 - 1) > 1 )
  {
    v4 = *(_QWORD *)(v2 + 16);
    v13 = *(_QWORD *)(v2 + 8);
    *(_DWORD *)(*(_QWORD *)(v2 + 40) + 8LL) = 2;
    v14 = v4;
    if ( *(_DWORD *)(v2 + 24) )
    {
      v5 = 0;
      do
      {
        v6 = *(_QWORD *)(v2 + 32) + 152LL * (int)v5;
        v7 = *(_QWORD *)(v6 + 24);
        v8 = *(_QWORD *)(v7 + 8);
        cam_io_w_mb(0, *(_QWORD *)(v8 + 8) + **(unsigned int **)(v7 + 16));
        if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x40000000,
            4,
            "cam_sfe_bus_stop_wm",
            938,
            "Stop SFE:%d WM:%d %s",
            **(_DWORD **)(v7 + 8),
            *(_DWORD *)v7,
            (const char *)(v6 + 128));
        *(_DWORD *)(v6 + 8) = 2;
        ++v5;
        *(_WORD *)(v7 + 121) = 0;
        *(_BYTE *)(v8 + 27540) = 0;
      }
      while ( v5 < *(_DWORD *)(v2 + 24) );
    }
    if ( *(_DWORD *)(a1 + 64) )
    {
      ((void (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v13 + 32));
      *(_DWORD *)(a1 + 64) = 0;
    }
    if ( *(_BYTE *)(v14 + 27448) != 1 )
    {
      result = 0;
LABEL_27:
      *(_DWORD *)(a1 + 8) = 2;
      return result;
    }
    if ( *(_DWORD *)(v14 + 27588) )
    {
      result = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v14 + 40));
      if ( (_DWORD)result )
      {
        v9 = result;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x40000000,
          2,
          "cam_sfe_bus_stop_sfe_out",
          1624,
          "failed to unsubscribe error irqs");
        result = v9;
      }
      *(_DWORD *)(v14 + 27588) = 0;
      if ( !*(_DWORD *)(v14 + 27584) )
        goto LABEL_26;
    }
    else
    {
      result = 0;
      if ( !*(_DWORD *)(v14 + 27584) )
      {
LABEL_26:
        *(_BYTE *)(v14 + 27448) = 0;
        goto LABEL_27;
      }
    }
    v10 = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v14 + 24));
    if ( v10 )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x40000000,
        2,
        "cam_sfe_bus_stop_sfe_out",
        1633,
        "failed to unsubscribe top irq");
    v11 = *(_QWORD *)(v14 + 24);
    v12 = *(_QWORD *)(v14 + 40);
    *(_DWORD *)(v14 + 27584) = 0;
    ((void (__fastcall *)(__int64, __int64))cam_irq_controller_unregister_dependent)(v11, v12);
    result = v10;
    goto LABEL_26;
  }
  result = 0;
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_bus_stop_sfe_out",
      1598,
      "Stop SFE:%d out_type:0x%X state:%d",
      **(_DWORD **)(v2 + 8),
      *(_DWORD *)v2,
      v1);
    return 0;
  }
  return result;
}
