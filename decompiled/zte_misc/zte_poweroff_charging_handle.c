__int64 __fastcall zte_poweroff_charging_handle(const char *a1)
{
  _BOOL8 v2; // x2

  v2 = strncmp(a1, "charger", 7u) == 0;
  zte_poweroff_charging = v2;
  printk(&unk_7B98, a1, v2);
  return 0;
}
