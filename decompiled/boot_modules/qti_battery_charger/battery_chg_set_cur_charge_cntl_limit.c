__int64 __fastcall battery_chg_set_cur_charge_cntl_limit(__int64 a1, unsigned int a2, __int64 a3)
{
  return battery_psy_set_charge_current(*(_QWORD *)(a1 + 944), a2, a3);
}
