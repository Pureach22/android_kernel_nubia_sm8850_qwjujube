__int64 wlan_hdd_state_ctrl_param_release()
{
  unsigned int v6; // w10

  _X9 = &wlan_hdd_state_fops_ref;
  __asm { PRFM            #0x11, [X9] }
  do
    v6 = __ldxr((unsigned int *)&wlan_hdd_state_fops_ref);
  while ( __stxr(v6 - 1, (unsigned int *)&wlan_hdd_state_fops_ref) );
  return 0;
}
