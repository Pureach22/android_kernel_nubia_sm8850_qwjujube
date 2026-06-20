__int64 __fastcall cam_vfe_bus_start_vfe_bus_rd(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x21
  int v4; // w6
  __int64 started; // x0
  int v6; // w0
  __int64 result; // x0
  int v8; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 6;
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_start_vfe_bus_rd",
      689,
      "Invalid input");
    result = 4294967274LL;
LABEL_16:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v1 = *(_QWORD *)(a1 + 24);
  v3 = *(_QWORD *)(v1 + 8);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_bus_start_vfe_bus_rd",
      696,
      "VFE:%d start RD type:0x%x",
      *(unsigned int *)(a1 + 4));
  v4 = *(_DWORD *)(a1 + 8);
  if ( v4 != 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_start_vfe_bus_rd",
      700,
      "Invalid resource state:%d",
      v4);
    result = 4294967283LL;
    goto LABEL_16;
  }
  if ( (*(_BYTE *)(v1 + 116) & 1) == 0 )
    cam_io_w_mb(
      (16 * *(_DWORD *)(v3 + 300)) | (unsigned int)(32 * *(_DWORD *)(v3 + 296)),
      *(_QWORD *)(v3 + 8) + *(unsigned int *)(*(_QWORD *)(v3 + 40) + 20LL));
  if ( !*(_DWORD *)(v1 + 16)
    || (cam_vfe_bus_start_rm(*(_QWORD *)(v1 + 24)), *(_DWORD *)(v1 + 16) <= 1u)
    || (started = cam_vfe_bus_start_rm(*(_QWORD *)(v1 + 32)), *(_DWORD *)(v1 + 16) <= 2u) )
  {
    v6 = cam_irq_controller_subscribe_irq(
           *(_QWORD *)(v3 + 24),
           1u,
           (__int64)&v8,
           a1,
           (__int64)cam_vfe_bus_rd_handle_irq_top_half,
           (__int64)cam_vfe_bus_rd_handle_irq_bottom_half,
           *(_QWORD *)(a1 + 56),
           tasklet_bh_api,
           0);
    *(_DWORD *)(v1 + 100) = v6;
    if ( v6 <= 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_bus_start_vfe_bus_rd",
        726,
        "Failed to subscribe BUS RD IRQ");
      *(_DWORD *)(v1 + 100) = 0;
      result = 4294967282LL;
    }
    else
    {
      result = 0;
      *(_DWORD *)(a1 + 8) = 4;
    }
    goto LABEL_16;
  }
  __break(0x5512u);
  return cam_vfe_bus_stop_vfe_bus_rd(started);
}
