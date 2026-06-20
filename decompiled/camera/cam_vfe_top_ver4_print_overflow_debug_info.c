__int64 __fastcall cam_vfe_top_ver4_print_overflow_debug_info(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x23
  unsigned int v5; // w20
  __int64 v6; // x24
  unsigned int v7; // w0
  __int64 v8; // x8
  __int64 v9; // x9
  unsigned int v10; // w21
  __int64 v11; // x10
  __int64 v12; // x0
  __int64 v13; // x6
  const char *v14; // x8
  const char *v15; // x11
  __int64 v16; // x8
  const char *v17; // x9
  __int64 v18; // x12
  __int64 v19; // x8
  const char *v20; // x13
  __int64 result; // x0
  unsigned int v22[2]; // [xsp+30h] [xbp-10h] BYREF
  __int64 v23; // [xsp+38h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 10432);
  v5 = *a2;
  v6 = *(_QWORD *)(v4 + 3296);
  v7 = cam_io_r(
         *(_QWORD *)(v4 + 288)
       + *(_QWORD *)(*(_QWORD *)(a1 + 16) + 288LL)
       + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 228LL));
  v9 = *(_QWORD *)(a1 + 8);
  v8 = *(_QWORD *)(a1 + 16);
  v10 = v7;
  v11 = *(_QWORD *)(v4 + 288);
  v22[0] = v7;
  v12 = cam_io_r(v11 + *(_QWORD *)(v8 + 288) + *(unsigned int *)(v9 + 224));
  v22[1] = v12;
  if ( v10 )
    *((_BYTE *)a2 + 4) = 1;
  v13 = *(unsigned int *)(v4 + 20);
  if ( *(_BYTE *)(v6 + 24) == 1 )
  {
    v14 = "Y";
    if ( v10 )
      v15 = "Y";
    else
      v15 = "N";
    if ( !(_DWORD)v12 )
      v14 = "N";
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, _QWORD, const char *, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver4_print_overflow_debug_info",
      1102,
      "VFE[%u] sof_cnt:%d src_clk:%lu overflow:%s violation:%s",
      v13,
      *(unsigned int *)(a1 + 10772),
      *(_QWORD *)(v4 + 2800),
      v15,
      v14);
  }
  else
  {
    if ( (unsigned int)v13 > 2 )
    {
      __break(0x5512u);
      return cam_vfe_core_config_control(v12);
    }
    v16 = v4 + 16 * v13;
    v17 = "Y";
    v18 = *(_QWORD *)(v16 + 2808);
    v19 = *(_QWORD *)(v16 + 2816);
    if ( v10 )
      v20 = "Y";
    else
      v20 = "N";
    if ( !(_DWORD)v12 )
      v17 = "N";
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, _QWORD, __int64, __int64, const char *, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver4_print_overflow_debug_info",
      1111,
      "VFE[%u] sof_cnt:%d src_clk sw_client:%lu hw_client:[%lu %lu] overflow:%s violation:%s",
      v13,
      *(unsigned int *)(a1 + 10772),
      *(_QWORD *)(v4 + 2800),
      v18,
      v19,
      v20,
      v17);
  }
  if ( *(_QWORD *)(*(_QWORD *)(a1 + 16) + 56LL) )
    cam_vfe_top_ver4_print_bus_debug_info(a1, v22);
  else
    cam_vfe_core_debug_handler(*(_QWORD *)(*(_QWORD *)a1 + 112LL), 1);
  cam_cpas_dump_camnoc_buff_fill_info();
  cam_cpas_log_votes(0);
  ((void (__fastcall *)(__int64, _QWORD))cam_vfe_top_ver4_dump_timestamps)(a1, v5);
  result = cam_vfe_top_ver4_print_debug_regs(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
