__int64 zte_poweroff_charging_status()
{
  printk(&unk_7CF3, (unsigned int)zte_poweroff_charging, (unsigned __int8)zte_poweroff_charging_param);
  return zte_poweroff_charging | (unsigned int)(unsigned __int8)zte_poweroff_charging_param;
}
