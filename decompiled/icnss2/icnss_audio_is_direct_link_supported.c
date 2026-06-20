__int64 __fastcall icnss_audio_is_direct_link_supported(__int64 a1)
{
  __int64 v1; // x20
  __int64 device_by_node; // x0
  __int64 v3; // x19
  const char *v5; // x19

  v1 = *(_QWORD *)(a1 + 152);
  if ( v1 )
  {
    if ( of_find_compatible_node(0, 0, "qcom,msm-audio-ion") )
    {
      device_by_node = of_find_device_by_node();
      if ( device_by_node )
      {
        v3 = device_by_node;
        *(_QWORD *)(v1 + 6176) = iommu_get_domain_for_dev(device_by_node + 16);
        put_device(v3 + 16);
        if ( *(_QWORD *)(v1 + 6176) )
          return 1;
        v5 = "%sicnss2: Unable to get Audio ion iommu domain";
        printk("%sicnss2: Unable to get Audio ion iommu domain", byte_130B32);
      }
      else
      {
        v5 = "%sicnss2: Unable to get Audio ion platform device";
        printk("%sicnss2: Unable to get Audio ion platform device", byte_130B32);
      }
    }
    else
    {
      v5 = "%sicnss2: Unable to get Audio ion node";
      printk("%sicnss2: Unable to get Audio ion node", byte_130B32);
    }
  }
  else
  {
    v5 = "%sicnss2: plat_priv not available to check audio direct link cap\n";
    printk("%sicnss2: plat_priv not available to check audio direct link cap\n", byte_130B32);
  }
  ipc_log_string(icnss_ipc_log_context, v5, &unk_12DBF3);
  return 0;
}
