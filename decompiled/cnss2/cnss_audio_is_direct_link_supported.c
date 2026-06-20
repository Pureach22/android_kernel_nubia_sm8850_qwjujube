__int64 __fastcall cnss_audio_is_direct_link_supported(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x6
  __int64 v4; // x7
  __int64 v5; // x19
  __int64 device_by_node; // x0
  __int64 v7; // x20
  unsigned __int64 v9; // x8
  __int64 v10; // x0
  const char *v11; // x1
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x8
  __int16 v14; // w9
  const char *v15; // x8
  const char *v16; // x2
  const char *v17; // x5
  unsigned __int64 StatusReg; // x8
  __int16 v19; // w9
  const char *v20; // x8
  __int16 v21; // w9
  const char *v22; // x8
  __int16 v23; // w9
  const char *v24; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v2 = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( v2 )
  {
    v5 = v2;
    if ( of_find_compatible_node(0, 0, "qcom,msm-audio-ion") )
    {
      device_by_node = of_find_device_by_node();
      if ( device_by_node )
      {
        v7 = device_by_node;
        *(_QWORD *)(v5 + 7544) = iommu_get_domain_for_dev(device_by_node + 16);
        put_device(v7 + 16);
        if ( *(_QWORD *)(v5 + 7544) )
          return 1;
        StatusReg = _ReadStatusReg(SP_EL0);
        v10 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v11 = "irq";
        }
        else
        {
          v23 = *(_DWORD *)(StatusReg + 16);
          v24 = (const char *)(StatusReg + 2320);
          if ( (v23 & 0xFF00) != 0 )
            v11 = "soft_irq";
          else
            v11 = v24;
        }
        v16 = "cnss_get_audio_iommu_domain";
        v17 = "Unable to get Audio ion iommu domain";
      }
      else
      {
        v13 = _ReadStatusReg(SP_EL0);
        v10 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(v13 + 16) & 0xF0000) != 0 )
        {
          v11 = "irq";
        }
        else
        {
          v21 = *(_DWORD *)(v13 + 16);
          v22 = (const char *)(v13 + 2320);
          if ( (v21 & 0xFF00) != 0 )
            v11 = "soft_irq";
          else
            v11 = v22;
        }
        v16 = "cnss_get_audio_iommu_domain";
        v17 = "Unable to get Audio ion platform device";
      }
    }
    else
    {
      v12 = _ReadStatusReg(SP_EL0);
      v10 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
      {
        v11 = "irq";
      }
      else
      {
        v19 = *(_DWORD *)(v12 + 16);
        v20 = (const char *)(v12 + 2320);
        if ( (v19 & 0xFF00) != 0 )
          v11 = "soft_irq";
        else
          v11 = v20;
      }
      v16 = "cnss_get_audio_iommu_domain";
      v17 = "Unable to get Audio ion node";
    }
  }
  else
  {
    v9 = _ReadStatusReg(SP_EL0);
    v10 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v11 = "irq";
    }
    else
    {
      v14 = *(_DWORD *)(v9 + 16);
      v15 = (const char *)(v9 + 2320);
      if ( (v14 & 0xFF00) != 0 )
        v11 = "soft_irq";
      else
        v11 = v15;
    }
    v16 = "cnss_audio_is_direct_link_supported";
    v17 = "plat_priv not available to check audio direct link cap\n";
  }
  cnss_debug_ipc_log_print(v10, v11, v16, 3u, 3u, v17, v3, v4, vars0);
  return 0;
}
