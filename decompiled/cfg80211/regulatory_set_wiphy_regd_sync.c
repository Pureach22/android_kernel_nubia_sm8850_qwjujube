__int64 __fastcall regulatory_set_wiphy_regd_sync(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  if ( !(unsigned int)rtnl_is_locked(a1) && (regulatory_set_wiphy_regd_sync___already_done & 1) == 0 )
  {
    regulatory_set_wiphy_regd_sync___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/reg.c", 4088);
    __break(0x800u);
  }
  result = _regulatory_set_wiphy_regd(a1, a2);
  if ( !(_DWORD)result )
  {
    reg_process_self_managed_hint(a1);
    mod_delayed_work_on(32, system_power_efficient_wq, &reg_check_chans, 15000);
    return 0;
  }
  return result;
}
