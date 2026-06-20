__int64 __fastcall cam_jpeg_enc_init_soc_resources(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x20
  __int64 result; // x0
  int v9; // w8
  unsigned int v10; // w21
  __int64 v11; // x24
  int v12; // w0
  int v13; // w19
  int v14; // w6
  int v15; // w19
  unsigned __int64 StatusReg; // x23
  __int64 v17; // x24
  __int64 v18; // [xsp+8h] [xbp-18h] BYREF
  __int64 v19; // [xsp+10h] [xbp-10h]
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v19 = 0;
  if ( mem_trace_en == 1 )
    v6 = cam_mem_trace_alloc(20, 0xCC0u, 0, "cam_jpeg_enc_init_soc_resources", 0x1Cu);
  else
    v6 = _kvmalloc_node_noprof(20, 0, 3520, 0xFFFFFFFFLL);
  v7 = v6;
  if ( v6 )
  {
    while ( 1 )
    {
      *(_QWORD *)(a1 + 3296) = v7;
      result = cam_soc_util_get_dt_properties(a1);
      if ( (_DWORD)result )
        break;
      v9 = *(_DWORD *)(a1 + 104);
      if ( !v9 || (v18 = a3, v9 == 1) || (v19 = a3, v9 == 2) )
      {
        v10 = cam_soc_util_request_platform_resource(a1, a2, &v18);
        if ( v10 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            512,
            1,
            "cam_jpeg_enc_init_soc_resources",
            45,
            "init soc failed %d",
            v10);
        *(_DWORD *)v7 = 0;
        *(_QWORD *)(v7 + 12) = -1;
        v11 = *(_QWORD *)a1;
        v12 = of_property_count_elems_of_size(*(_QWORD *)(*(_QWORD *)a1 + 760LL), "cam_hw_pid", 4);
        if ( (debug_mdl & 0x200) != 0 && !debug_priority )
        {
          v14 = *(_DWORD *)(a1 + 20);
          v15 = v12;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x200,
            4,
            "cam_jpeg_enc_init_soc_resources",
            53,
            "jpeg enc:%d pid count %d",
            v14,
            v12);
          v12 = v15;
        }
        if ( (unsigned int)(v12 - 3) >= 0xFFFFFFFE )
        {
          *(_DWORD *)v7 = v12;
          v13 = v12;
          of_property_read_u32_index(*(_QWORD *)(v11 + 760), "cam_hw_pid", 0, v7 + 4);
          if ( v13 != 1 )
            of_property_read_u32_index(*(_QWORD *)(v11 + 760), "cam_hw_pid", 1, v7 + 8);
          of_property_read_variable_u32_array(*(_QWORD *)(v11 + 760), "cam_hw_rd_mid", v7 + 12, 1, 0);
          of_property_read_variable_u32_array(*(_QWORD *)(v11 + 760), "cam_hw_wr_mid", v7 + 16, 1, 0);
        }
        result = v10;
        break;
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v17 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &cam_jpeg_enc_init_soc_resources__alloc_tag;
      v7 = _kvmalloc_node_noprof(20, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(StatusReg + 80) = v17;
      if ( !v7 )
        goto LABEL_20;
    }
  }
  else
  {
LABEL_20:
    result = 4294967284LL;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_jpeg_enc_init_soc_resources",
        30,
        "Error! soc_private Alloc Failed");
      result = 4294967284LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
