__int64 __fastcall msm_vidc_remove(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  __int64 v4; // x4
  __int64 v5; // x8
  __int64 (__fastcall *v6)(_QWORD); // x8
  __int64 v7; // x8
  __int64 (__fastcall *v8)(_QWORD); // x8
  char v9; // w8
  void *v10; // x0
  const char *v11; // x1
  __int64 v12; // x20

  result = is_video_device(a1 + 16);
  if ( (result & 1) != 0 )
  {
    if ( a1 )
    {
      v3 = *(_QWORD *)(a1 + 168);
      if ( v3 )
      {
        if ( (msm_vidc_debug & 2) != 0 )
          printk(&unk_90476, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_remove_video_device");
        component_master_del(a1 + 16, msm_vidc_component_master_ops);
        if ( (msm_vidc_debug & 2) != 0 )
          printk(&unk_90CAA, "high", 0xFFFFFFFFLL, "codec", v4);
        of_platform_depopulate(a1 + 16);
        result = sysfs_remove_group(a1 + 16, &msm_vidc_core_attr_group);
        v5 = *(_QWORD *)(v3 + 6584);
        if ( v5 )
        {
          v6 = *(__int64 (__fastcall **)(_QWORD))(v5 + 8);
          if ( v6 )
          {
            if ( *((_DWORD *)v6 - 1) != -1850880742 )
              __break(0x8228u);
            result = v6(v3);
          }
        }
        v7 = *(_QWORD *)(v3 + 6592);
        if ( v7 )
        {
          v8 = *(__int64 (__fastcall **)(_QWORD))(v7 + 8);
          if ( v8 )
          {
            if ( *((_DWORD *)v8 - 1) != -1850880742 )
              __break(0x8228u);
            result = v8(v3);
          }
        }
        v9 = msm_vidc_debug;
        *(_QWORD *)(a1 + 168) = 0;
        g_core = 0;
        if ( (v9 & 2) != 0 )
        {
          v10 = &unk_838C0;
          v11 = "high";
          return printk(v10, v11, 0xFFFFFFFFLL, "codec", "msm_vidc_remove_video_device");
        }
      }
      else if ( (msm_vidc_debug & 1) != 0 )
      {
        v10 = &unk_807F4;
        v11 = "err ";
        return printk(v10, v11, 0xFFFFFFFFLL, "codec", "msm_vidc_remove_video_device");
      }
    }
    else if ( (msm_vidc_debug & 1) != 0 )
    {
      return printk(&unk_93E5B, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_remove_video_device");
    }
  }
  else
  {
    v12 = *(_QWORD *)(a1 + 760);
    if ( (unsigned int)of_device_is_compatible(v12, "qcom,vidc,cb-sec-pxl")
      || (unsigned int)of_device_is_compatible(v12, "qcom,vidc,cb-sec-bitstream")
      || (unsigned int)of_device_is_compatible(v12, "qcom,vidc,cb-sec-non-pxl")
      || (unsigned int)of_device_is_compatible(v12, "qcom,vidc,cb-ns")
      || (unsigned int)of_device_is_compatible(v12, "qcom,vidc,cb-ns-bitstream")
      || (result = of_device_is_compatible(v12, "qcom,vidc,cb-ns-pxl"), (_DWORD)result) )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_96554, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_remove_context_bank");
      return component_del(a1 + 16, msm_vidc_component_ops);
    }
    else
    {
      __break(0x800u);
    }
  }
  return result;
}
