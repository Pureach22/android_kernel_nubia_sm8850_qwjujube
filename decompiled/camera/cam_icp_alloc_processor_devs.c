__int64 __fastcall cam_icp_alloc_processor_devs(__int64 a1, unsigned int *a2, __int64 *a3, __int64 a4)
{
  int v7; // w0
  unsigned int device_num; // w19
  unsigned int v9; // w9
  unsigned int v10; // w8
  __int64 result; // x0
  unsigned int v12; // w0
  __int64 v13; // x10
  __int64 v14; // x20
  unsigned int v15; // w7
  __int64 v16; // x0
  int v17; // w6
  const char *v18; // x6
  unsigned int v19; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_alloc_processor_devs",
      38,
      "Invalid device node");
    result = 4294967274LL;
    goto LABEL_25;
  }
  v7 = of_property_read_variable_u32_array(a1, "num-icp", &v19, 1, 0);
  if ( v7 < 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_alloc_processor_devs",
      44,
      "read num-icp failed rc=%d",
      v7);
LABEL_8:
    result = 4294967277LL;
    goto LABEL_25;
  }
  if ( !v19 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_alloc_processor_devs",
      49,
      "No ICP device %d",
      0);
    result = 4294967274LL;
    goto LABEL_25;
  }
  device_num = cam_icp_v1_get_device_num();
  if ( device_num )
  {
    v9 = 0;
    v10 = device_num;
    goto LABEL_12;
  }
  v12 = cam_icp_v2_get_device_num();
  if ( !v12 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_alloc_processor_devs",
      66,
      "No ICP device probed");
    goto LABEL_8;
  }
  v10 = v12;
  v9 = 1;
LABEL_12:
  *a2 = v9;
  v13 = v19;
  v14 = v9;
  v15 = icp_request_cnt[v9] + v19;
  icp_request_cnt[v9] = v15;
  if ( v15 <= v10 )
  {
    if ( mem_trace_en == 1 )
      v16 = cam_mem_trace_alloc(8 * v13, 0xCC0u, 0, "cam_icp_alloc_processor_devs", 0x4Fu);
    else
      v16 = _kvmalloc_node_noprof(8LL * v19, 0, 3520, 0xFFFFFFFFLL);
    v17 = v19;
    *a3 = v16;
    if ( v16 )
    {
      *(_DWORD *)(a4 + 4 * v14) = v17;
      result = 0;
      if ( (debug_mdl & 0x100) != 0 && !debug_priority )
      {
        if ( device_num )
          v18 = "ICP_V1";
        else
          v18 = "ICP_V2";
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x100,
          4,
          "cam_icp_alloc_processor_devs",
          90,
          "allocated device iface for %s",
          v18);
        result = 0;
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_alloc_processor_devs",
        83,
        "ICP device memory allocation failed. Num devices: %u",
        v17);
      result = 4294967284LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_alloc_processor_devs",
      75,
      "number of ICP_V%u total requested: %u exceeds number of icp hw available: %u",
      v9 + 1);
    result = 4294967274LL;
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
