__int64 __fastcall msm_vidc_init_platform_capabilities(__int64 *a1)
{
  __int64 v2; // x0
  char v3; // w8
  __int64 v4; // x22
  char **v5; // x8
  __int64 result; // x0
  __int64 (__fastcall *v7)(__int64); // x8
  unsigned int v8; // w19
  __int64 mem_ops; // x0
  __int64 resources_ops; // x0
  __int64 dma_fence_ops; // x0
  void *v12; // x0

  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_90476, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_init_platform_capabilities");
  v2 = devm_kmalloc(*a1 + 16, 648, 3520);
  if ( v2 )
  {
    v3 = msm_vidc_debug;
    v4 = *a1;
    a1[489] = v2;
    if ( (v3 & 2) != 0 )
      printk(&unk_90476, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_get_platform_data");
    if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(v4 + 760), "qcom,canoe-vidc") )
    {
      v5 = &compat_handle;
    }
    else if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(v4 + 760), "qcom,canoe-vidc-v2") )
    {
      v5 = &off_99300;
    }
    else
    {
      if ( !(unsigned int)of_device_is_compatible(*(_QWORD *)(v4 + 760), "qcom,alor-vidc") )
      {
        if ( (msm_vidc_debug & 1) != 0 )
          printk(&unk_80D43, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_get_platform_data");
        return 4294967274LL;
      }
      v5 = &off_99320;
    }
    v7 = (__int64 (__fastcall *)(__int64))v5[1];
    if ( *((_DWORD *)v7 - 1) != -1850880742 )
      __break(0x8228u);
    result = v7((__int64)a1);
    if ( (_DWORD)result )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v8 = result;
        printk(&unk_951EC, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_get_platform_data");
        return v8;
      }
      return result;
    }
    result = msm_vidc_init_core_caps(a1);
    if ( !(_DWORD)result )
    {
      result = msm_vidc_init_instance_caps(a1);
      if ( !(_DWORD)result )
      {
        if ( (msm_vidc_debug & 2) != 0 )
          printk(&unk_83E36, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_init_ops");
        a1[811] = (__int64)&msm_v4l2_file_operations;
        a1[812] = (__int64)msm_v4l2_ioctl_ops_enc;
        a1[813] = (__int64)msm_v4l2_ioctl_ops_dec;
        a1[814] = (__int64)&msm_v4l2_ctrl_ops;
        a1[815] = (__int64)&msm_vb2_ops;
        a1[816] = (__int64)msm_vb2_mem_ops;
        a1[822] = (__int64)&msm_v4l2_media_ops;
        a1[817] = (__int64)&msm_v4l2_m2m_ops;
        a1[824] = get_md_ops();
        mem_ops = get_mem_ops();
        a1[821] = mem_ops;
        if ( mem_ops )
        {
          resources_ops = get_resources_ops();
          a1[819] = resources_ops;
          if ( resources_ops )
          {
            dma_fence_ops = get_dma_fence_ops();
            a1[823] = dma_fence_ops;
            if ( dma_fence_ops )
            {
              result = msm_vidc_init_platform(a1);
              if ( !(_DWORD)result )
                return msm_vidc_init_vpu(a1);
              return result;
            }
            if ( (msm_vidc_debug & 1) != 0 )
            {
              v12 = &unk_7F567;
              goto LABEL_37;
            }
            return 4294967274LL;
          }
          if ( (msm_vidc_debug & 1) == 0 )
            return 4294967274LL;
          v12 = &unk_83076;
        }
        else
        {
          if ( (msm_vidc_debug & 1) == 0 )
            return 4294967274LL;
          v12 = &unk_8C6F9;
        }
LABEL_37:
        printk(v12, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_init_ops");
        return 4294967274LL;
      }
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8D336, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_init_platform_capabilities");
    return 4294967284LL;
  }
  return result;
}
