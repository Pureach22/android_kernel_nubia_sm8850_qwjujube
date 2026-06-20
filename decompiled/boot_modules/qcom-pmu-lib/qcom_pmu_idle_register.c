__int64 __fastcall qcom_pmu_idle_register(__int64 a1)
{
  _UNKNOWN **v2; // x9
  _UNKNOWN **v4; // x0
  _QWORD *v5; // x1

  if ( !a1 )
    return 4294967274LL;
  if ( !*(_QWORD *)a1 )
    return 4294967274LL;
  raw_spin_lock(&idle_list_lock);
  v2 = &idle_notif_list;
  while ( 1 )
  {
    v2 = (_UNKNOWN **)*v2;
    if ( v2 == &idle_notif_list )
      break;
    if ( *(v2 - 1) == *(_UNKNOWN **)a1 )
      goto LABEL_13;
  }
  v4 = (_UNKNOWN **)(a1 + 8);
  v5 = off_128;
  if ( (_UNKNOWN **)(a1 + 8) == &idle_notif_list || off_128 == v4 || *off_128 != (_UNKNOWN *)&idle_notif_list )
  {
    _list_add_valid_or_report();
  }
  else
  {
    off_128 = (_UNKNOWN **)(a1 + 8);
    *(_QWORD *)(a1 + 8) = &idle_notif_list;
    *(_QWORD *)(a1 + 16) = v5;
    *v5 = v4;
  }
LABEL_13:
  raw_spin_unlock(&idle_list_lock);
  return 0;
}
