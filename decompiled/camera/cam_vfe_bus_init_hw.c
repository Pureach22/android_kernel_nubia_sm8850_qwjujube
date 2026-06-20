__int64 __fastcall cam_vfe_bus_init_hw(__int64 a1)
{
  __int64 v2; // x20
  __int64 result; // x0
  __int64 v4; // x0
  int v5; // w0
  __int64 v6; // x6
  int v7; // w0
  _QWORD v8[2]; // [xsp+10h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  if ( a1 )
  {
    v2 = a1 + 33608;
    if ( (*(_BYTE *)(a1 + 33608) & 1) == 0 )
    {
      v4 = *(_QWORD *)(a1 + 32);
      LODWORD(v8[0]) = 1 << *(_DWORD *)(v2 + 16);
      v5 = cam_irq_controller_subscribe_irq(
             v4,
             2u,
             (__int64)v8,
             a1,
             (__int64)cam_vfe_bus_ver2_handle_irq,
             0,
             0,
             nullptr,
             0);
      *(_DWORD *)(a1 + 42648) = v5;
      if ( v5 <= 0 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_init_hw",
          3565,
          "Failed to subscribe BUS IRQ");
        *(_DWORD *)(a1 + 42648) = 0;
      }
      else
      {
        v6 = *(_QWORD *)(a1 + 42656);
        if ( !v6
          || (v7 = cam_irq_controller_subscribe_irq(
                     *(_QWORD *)(a1 + 24),
                     0,
                     (__int64)&bus_error_irq_mask,
                     a1,
                     (__int64)&cam_vfe_bus_error_irq_top_half,
                     (__int64)cam_vfe_bus_err_bottom_half,
                     v6,
                     tasklet_bh_api,
                     0),
              *(_DWORD *)(a1 + 42652) = v7,
              v7 > 0) )
        {
          cam_io_w_mb(130, *(_QWORD *)(a1 + 8) + *(unsigned int *)(*(_QWORD *)(a1 + 40) + 84LL));
          cam_io_w_mb(0, *(_QWORD *)(a1 + 8) + *(unsigned int *)(*(_QWORD *)(a1 + 40) + 76LL));
          cam_io_w_mb(0xFFFFF, *(_QWORD *)(a1 + 8) + 8204LL);
          cam_io_w_mb(0, *(_QWORD *)(a1 + 8) + 8476LL);
          cam_io_w_mb(0xFFFFFF, *(_QWORD *)(a1 + 8) + *(unsigned int *)(*(_QWORD *)(a1 + 40) + 80LL));
          result = 0;
          *(_BYTE *)v2 = 1;
          goto LABEL_12;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_init_hw",
          3584,
          "Failed to subscribe BUS error IRQ %d",
          v7);
        *(_DWORD *)(a1 + 42652) = 0;
      }
      result = 4294967282LL;
      goto LABEL_12;
    }
    result = 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_init_hw",
      3544,
      "Invalid args");
    result = 4294967274LL;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
