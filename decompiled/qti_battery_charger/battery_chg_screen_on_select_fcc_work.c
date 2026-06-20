__int64 __fastcall battery_chg_screen_on_select_fcc_work(__int64 a1)
{
  return battery_psy_set_charge_current(a1 - 792, *(unsigned int *)(a1 - 248));
}
