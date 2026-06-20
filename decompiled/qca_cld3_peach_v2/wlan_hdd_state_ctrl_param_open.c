__int64 wlan_hdd_state_ctrl_param_open()
{
  unsigned int v6; // w9

  _X8 = &wlan_hdd_state_fops_ref;
  __asm { PRFM            #0x11, [X8] }
  do
    v6 = __ldxr((unsigned int *)&wlan_hdd_state_fops_ref);
  while ( __stxr(v6 + 1, (unsigned int *)&wlan_hdd_state_fops_ref) );
  return 0;
}
