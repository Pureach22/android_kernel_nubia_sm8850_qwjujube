__int64 sub_384EE8()
{
  __asm { PRFM            #0xA, loc_297DE0 }
  return wlan_hdd_pktlog_enable_disable();
}
