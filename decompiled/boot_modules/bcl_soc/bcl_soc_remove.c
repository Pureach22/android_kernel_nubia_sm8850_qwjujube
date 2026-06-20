__int64 bcl_soc_remove()
{
  power_supply_unreg_notifier(bcl_perph + 8);
  return flush_work(bcl_perph + 32);
}
