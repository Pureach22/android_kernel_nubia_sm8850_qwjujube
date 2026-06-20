__int64 __fastcall dp_aux_add_bridge(__int64 a1)
{
  _UNKNOWN **v2; // x0
  _QWORD *v3; // x1

  mutex_lock(&dp_aux_bridge_lock);
  v2 = (_UNKNOWN **)(a1 + 32);
  v3 = off_5B50;
  if ( (_UNKNOWN **)(a1 + 32) == &du_aux_bridge_list || off_5B50 == v2 || *off_5B50 != (_UNKNOWN *)&du_aux_bridge_list )
  {
    _list_add_valid_or_report();
  }
  else
  {
    off_5B50 = (_UNKNOWN **)(a1 + 32);
    *(_QWORD *)(a1 + 32) = &du_aux_bridge_list;
    *(_QWORD *)(a1 + 40) = v3;
    *v3 = v2;
  }
  mutex_unlock(&dp_aux_bridge_lock);
  return 0;
}
