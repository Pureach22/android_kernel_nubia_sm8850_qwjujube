__int64 __fastcall hif_bus_open(_QWORD *a1, int a2)
{
  unsigned int v3; // w19
  const char *v4; // x3
  __int64 v6; // x20
  _QWORD *v7; // x0
  _DWORD **v8; // x24
  char v9; // w8
  bool v10; // zf
  _DWORD *v12; // x8

  v3 = 11;
  a1[44] = hif_dummy_display_stats;
  a1[45] = hif_dummy_clear_stats;
  a1[46] = hif_dummy_set_bundle_mode;
  a1[47] = hif_dummy_bus_reset_resume;
  a1[11] = 0;
  a1[18] = hif_dummy_bus_suspend_noirq;
  a1[19] = hif_dummy_bus_resume_noirq;
  a1[14] = hif_dummy_bus_suspend;
  a1[15] = hif_dummy_bus_resume;
  a1[48] = hif_dummy_map_ce_to_irq;
  a1[34] = hif_dummy_grp_irq_configure;
  a1[35] = hif_dummy_grp_irq_deconfigure;
  a1[51] = hif_dummy_config_irq_affinity;
  a1[52] = hif_dummy_config_irq_by_ceid;
  a1[55] = hif_dummy_enable_grp_irqs;
  a1[56] = hif_dummy_enable_grp_irqs;
  a1[53] = hif_dummy_config_irq_clear_cpu_affinity;
  a1[57] = hif_dummy_set_grp_intr_affinity;
  a1[58] = hif_dummy_affinity_mgr_set_affinity;
  a1[59] = hif_dummy_bus_get_device_handle;
  if ( a2 > 3 )
  {
    switch ( a2 )
    {
      case 4:
        v4 = "hif_initialize_sdio_ops";
        goto LABEL_21;
      case 5:
        v4 = "hif_initialize_usb_ops";
        goto LABEL_21;
      case 6:
        v4 = "hif_initialize_ipci_ops";
        goto LABEL_21;
    }
LABEL_22:
    qdf_trace_msg(61, 2, "%s: bus_type: %d not supported", "hif_bus_open", a2);
    return v3;
  }
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      v4 = "hif_initialize_ahb_ops";
      goto LABEL_21;
    }
    if ( a2 == 2 )
    {
      v4 = "hif_initialize_snoc_ops";
LABEL_21:
      qdf_trace_msg(61, 3, "%s: not supported", v4);
      goto LABEL_22;
    }
    goto LABEL_22;
  }
  v3 = hif_initialize_pci_ops();
  if ( v3 )
    goto LABEL_22;
  v6 = 0;
  v7 = a1;
  v8 = (_DWORD **)(a1 + 10);
  v9 = 1;
  do
  {
    while ( !v8[v6] )
    {
      qdf_trace_msg(61, 2, "%s: ops_array[%d] is null", "hif_verify_basic_ops", v6);
      v7 = a1;
      v9 = 0;
      v10 = v6++ == 49;
      v3 = 11;
      if ( v10 )
        return v3;
    }
    ++v6;
  }
  while ( v6 != 50 );
  if ( (v9 & 1) != 0 )
  {
    v12 = *v8;
    if ( *(*v8 - 1) != 1793837078 )
      __break(0x8228u);
    return ((unsigned int (__fastcall *)(_QWORD *, _QWORD))v12)(v7, 0);
  }
  return v3;
}
