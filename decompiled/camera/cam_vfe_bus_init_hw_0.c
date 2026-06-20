__int64 __fastcall cam_vfe_bus_init_hw_0(__int64 a1)
{
  char v1; // w8
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 v5; // t2
  int v6; // w0
  __int64 result; // x0
  int v8; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v9; // [xsp+10h] [xbp-10h]
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 640);
    v5 = a1 + 32;
    v3 = *(_QWORD *)(a1 + 32);
    v4 = *(_QWORD *)(v5 + 8);
    v8 = 1 << v1;
    v6 = cam_irq_controller_subscribe_irq(
           v3,
           2u,
           (__int64)&v8,
           a1,
           (__int64)cam_vfe_bus_rd_ver1_handle_irq,
           0,
           0,
           nullptr,
           0);
    *(_DWORD *)(a1 + 624) = v6;
    if ( v6 <= 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_bus_init_hw",
        1147,
        "Failed to subscribe BUS IRQ");
      *(_DWORD *)(a1 + 624) = 0;
      result = 4294967282LL;
    }
    else
    {
      cam_io_w_mb(1, *(_QWORD *)(a1 + 8) + *(unsigned int *)(v4 + 12));
      cam_io_w_mb(0, *(_QWORD *)(a1 + 8) + *(unsigned int *)(v4 + 24));
      result = 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_init_hw",
      1129,
      "Invalid args");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
