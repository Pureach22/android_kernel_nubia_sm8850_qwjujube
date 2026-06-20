__int64 __fastcall battery_chg_get_cur_charge_cntl_limit(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 944);
  *a2 = *(int *)(v2 + 544);
  return 0;
}
