__int64 __fastcall hif_initialize_pci_ops(_QWORD *a1)
{
  int conparam; // w0
  __int64 (*v3)(); // x8

  a1[10] = hif_pci_open;
  a1[11] = hif_pci_close;
  a1[12] = hif_pci_prevent_linkdown;
  a1[13] = hif_pci_reset_soc;
  a1[16] = hif_pci_bus_suspend;
  a1[17] = hif_pci_bus_resume;
  a1[18] = hif_pci_bus_suspend_noirq;
  a1[19] = hif_pci_bus_resume_noirq;
  conparam = hif_get_conparam((__int64)a1);
  v3 = hif_dummy_target_sleep_state_adjust;
  if ( conparam != 8 )
    v3 = hif_pci_target_sleep_state_adjust;
  a1[20] = v3;
  a1[21] = hif_pci_disable_isr;
  a1[22] = hif_pci_nointrs;
  a1[23] = hif_pci_enable_bus;
  a1[24] = hif_pci_disable_bus;
  a1[25] = hif_pci_bus_configure;
  a1[26] = hif_dummy_get_config_item;
  a1[27] = hif_dummy_set_mailbox_swap;
  a1[28] = hif_dummy_claim_device;
  a1[29] = hif_ce_stop;
  a1[30] = hif_ce_stop;
  a1[31] = hif_pci_cancel_deferred_target_sleep;
  a1[32] = hif_pci_irq_disable;
  a1[33] = hif_pci_irq_enable;
  a1[36] = hif_pci_dump_registers;
  a1[37] = hif_ce_dump_target_memory;
  a1[38] = hif_pci_reg_read32;
  a1[39] = hif_pci_reg_write32;
  a1[40] = hif_ce_ipa_get_ce_resource;
  a1[41] = hif_dummy_mask_interrupt_call;
  a1[42] = hif_pci_enable_power_management;
  a1[43] = hif_pci_disable_power_management;
  a1[34] = hif_pci_configure_grp_irq;
  a1[35] = hif_pci_deconfigure_grp_irq;
  a1[44] = hif_pci_display_stats;
  a1[45] = hif_pci_clear_stats;
  a1[48] = hif_pci_legacy_map_ce_to_irq;
  a1[49] = hif_pci_addr_in_boundary;
  a1[50] = hif_pci_needs_bmi;
  a1[51] = &hif_pci_config_irq_affinity;
  a1[52] = hif_ce_msi_configure_irq_by_ceid;
  a1[53] = hif_pci_config_irq_clear_cpu_affinity;
  a1[54] = hif_log_pcie_info;
  a1[57] = hif_pci_set_grp_intr_affinity;
  a1[58] = hif_affinity_mgr_affine_irq;
  a1[59] = hif_pci_get_device_handle;
  return 0;
}
