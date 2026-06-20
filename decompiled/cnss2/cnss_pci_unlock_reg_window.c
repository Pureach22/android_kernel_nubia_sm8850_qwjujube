__int64 cnss_pci_unlock_reg_window()
{
  return raw_spin_unlock_bh(&pci_reg_window_lock);
}
