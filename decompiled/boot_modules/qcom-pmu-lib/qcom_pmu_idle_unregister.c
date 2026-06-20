__int64 __fastcall qcom_pmu_idle_unregister(void **a1)
{
  _UNKNOWN **v2; // x9
  _QWORD *v3; // x8
  _QWORD *v4; // x10
  unsigned int v5; // w19

  if ( a1 && *a1 )
  {
    raw_spin_lock(&idle_list_lock);
    v2 = &idle_notif_list;
    do
    {
      v2 = (_UNKNOWN **)*v2;
      if ( v2 == &idle_notif_list )
      {
        v5 = -22;
        goto LABEL_12;
      }
    }
    while ( *(v2 - 1) != *a1 );
    v3 = v2[1];
    if ( (_UNKNOWN **)*v3 == v2 && (v4 = *v2, *((_UNKNOWN ***)*v2 + 1) == v2) )
    {
      v4[1] = v3;
      *v3 = v4;
    }
    else
    {
      _list_del_entry_valid_or_report(v2);
    }
    v5 = 0;
    *v2 = (_UNKNOWN *)0xDEAD000000000100LL;
    v2[1] = (_UNKNOWN *)0xDEAD000000000122LL;
LABEL_12:
    raw_spin_unlock(&idle_list_lock);
  }
  else
  {
    return (unsigned int)-22;
  }
  return v5;
}
