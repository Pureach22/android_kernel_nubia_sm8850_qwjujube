__int64 __fastcall ieee80211_rate_control_unregister(void *a1)
{
  _UNKNOWN **v2; // x0
  _QWORD *v3; // x8
  _QWORD *v4; // x9
  _UNKNOWN **v6; // x9

  mutex_lock(&rate_ctrl_mutex);
  v2 = &rate_ctrl_algs;
  while ( 1 )
  {
    v2 = (_UNKNOWN **)*v2;
    if ( v2 == &rate_ctrl_algs )
      break;
    if ( v2[2] == a1 )
    {
      v3 = v2[1];
      if ( (_UNKNOWN **)*v3 == v2 && (v4 = *v2, *((_UNKNOWN ***)*v2 + 1) == v2) )
      {
        v4[1] = v3;
        *v3 = v4;
      }
      else
      {
        _list_del_entry_valid_or_report(v2);
        v2 = v6;
      }
      *v2 = (_UNKNOWN *)0xDEAD000000000100LL;
      v2[1] = (_UNKNOWN *)0xDEAD000000000122LL;
      kfree(v2);
      return mutex_unlock(&rate_ctrl_mutex);
    }
  }
  return mutex_unlock(&rate_ctrl_mutex);
}
