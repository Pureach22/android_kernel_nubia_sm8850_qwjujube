__int64 __fastcall cam_vfe_bus_ver3_stop_vfe_out(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 v3; // x21
  int v4; // w8
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x21
  unsigned int v8; // w20
  __int64 v9; // x0
  __int64 v10; // x1

  if ( !result )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_stop_vfe_out",
      2532,
      "Invalid input");
    return 4294967274LL;
  }
  v1 = *(_QWORD *)(result + 24);
  v2 = result;
  v3 = *(_QWORD *)(v1 + 16);
  *(_BYTE *)(v3 + 34674) = 0;
  v4 = *(_DWORD *)(result + 8);
  if ( (unsigned int)(v4 - 1) <= 1 )
  {
    result = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_bus_ver3_stop_vfe_out",
        2545,
        "Stop VFE:%u out_type:0x%X state:%d",
        *(_DWORD *)(*(_QWORD *)(v1 + 16) + 8LL),
        *(_DWORD *)(v1 + 8),
        v4);
      return 0;
    }
    return result;
  }
  *(_DWORD *)(*(_QWORD *)(v1 + 56) + 8LL) = 2;
  if ( *(_DWORD *)(v1 + 32) )
  {
    result = cam_vfe_bus_ver3_stop_wm(*(_QWORD *)(v1 + 40));
    if ( *(_DWORD *)(v1 + 32) > 1u )
    {
      result = cam_vfe_bus_ver3_stop_wm(*(_QWORD *)(v1 + 48));
      if ( *(_DWORD *)(v1 + 32) > 2u )
        goto LABEL_39;
    }
  }
  v5 = *(unsigned int *)(v1 + 12);
  if ( (unsigned int)v5 > 6 )
    goto LABEL_39;
  if ( !*(_DWORD *)(v3 + 34688 + 4 * v5) )
  {
    result = 0;
    if ( !*(_DWORD *)(v2 + 64) )
      goto LABEL_15;
    goto LABEL_14;
  }
  result = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v3 + 32));
  v6 = *(unsigned int *)(v1 + 12);
  if ( (unsigned int)v6 > 6 )
  {
LABEL_39:
    __break(0x5512u);
    return cam_vfe_bus_ver3_handle_vfe_out_done_top_half(result);
  }
  *(_DWORD *)(v3 + 34688 + 4 * v6) = 0;
  if ( *(_DWORD *)(v2 + 64) )
  {
LABEL_14:
    result = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v3 + 48));
    *(_DWORD *)(v2 + 64) = 0;
  }
LABEL_15:
  if ( *(_DWORD *)(v1 + 124) )
  {
    result = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v3 + 56));
    *(_DWORD *)(v1 + 124) = 0;
  }
  if ( *(_DWORD *)(v1 + 128) )
  {
    result = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v3 + 32));
    *(_DWORD *)(v1 + 128) = 0;
  }
  if ( *(_BYTE *)(*(_QWORD *)(v1 + 16) + 34670LL) == 1 )
  {
    v7 = *(_QWORD *)(v1 + 24);
    v8 = result;
    if ( *(_DWORD *)(v7 + 34952) )
    {
      if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v7 + 32)) )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          2,
          "cam_vfe_bus_ver3_unsubscribe_init_irq",
          3589,
          "VFE:%u failed to unsubscribe error irqs",
          *(_DWORD *)(v7 + 8));
      result = v8;
      *(_DWORD *)(v7 + 34952) = 0;
    }
    if ( *(_DWORD *)(v7 + 34944) )
    {
      if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v7 + 40)) )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          2,
          "cam_vfe_bus_ver3_unsubscribe_init_irq",
          3600,
          "VFE:%u failed to unsubscribe top irq",
          *(_DWORD *)(v7 + 8));
      v10 = *(_QWORD *)(v7 + 32);
      v9 = *(_QWORD *)(v7 + 40);
      *(_DWORD *)(v7 + 34944) = 0;
      ((void (__fastcall *)(__int64, __int64))cam_irq_controller_unregister_dependent)(v9, v10);
      result = v8;
    }
    if ( *(_DWORD *)(v7 + 34948) )
    {
      if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v7 + 40)) )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          2,
          "cam_vfe_bus_ver3_unsubscribe_init_irq",
          3613,
          "VFE:%u failed to unsubscribe rup done irq",
          *(_DWORD *)(v7 + 8));
      result = v8;
      *(_DWORD *)(v7 + 34948) = 0;
    }
    *(_BYTE *)(v7 + 34670) = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_bus_ver3_unsubscribe_init_irq",
        3619,
        "BUS init irq unsubscribed, VFE:%u",
        *(_DWORD *)(v7 + 8));
      result = v8;
    }
  }
  *(_DWORD *)(v2 + 8) = 2;
  return result;
}
