__int64 __fastcall msm_vidc_init_platform_canoe(__int64 a1)
{
  __int64 mem_ops_ext; // x0
  __int64 res_ops_ext; // x0
  __int64 node_opts_by_path; // x0
  int v5; // w5
  __int64 result; // x0
  void *v7; // x0
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_9684C, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_init_platform_canoe");
  mem_ops_ext = get_mem_ops_ext();
  *(_QWORD *)(a1 + 6568) = mem_ops_ext;
  if ( !mem_ops_ext )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v7 = &unk_848DD;
LABEL_17:
      printk(v7, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_init_platform_canoe");
    }
LABEL_20:
    result = 4294967274LL;
    goto LABEL_21;
  }
  res_ops_ext = get_res_ops_ext(a1);
  *(_QWORD *)(a1 + 6552) = res_ops_ext;
  if ( !res_ops_ext )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v7 = &unk_82841;
      goto LABEL_17;
    }
    goto LABEL_20;
  }
  v8 = 0;
  node_opts_by_path = of_find_node_opts_by_path("/memory", 0);
  if ( !node_opts_by_path
    || ((int)of_property_read_variable_u32_array(node_opts_by_path, "ddr_device_type", &v8, 1, 0) >= 0
      ? (v5 = v8)
      : (v5 = -2),
        (unsigned int)(v5 - 10) <= 0xFFFFFFFD) )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_87C3D, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_canoe_check_ddr_type");
    goto LABEL_20;
  }
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_7F411, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_canoe_check_ddr_type");
  result = 0;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
