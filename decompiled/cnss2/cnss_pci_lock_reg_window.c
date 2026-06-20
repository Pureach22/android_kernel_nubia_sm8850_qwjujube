__int64 cnss_pci_lock_reg_window()
{
  return raw_spin_lock_bh(&pci_reg_window_lock);
}
