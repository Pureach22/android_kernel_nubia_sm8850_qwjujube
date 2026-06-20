__int64 __fastcall qptm_channel_unregister(_QWORD *a1)
{
  _QWORD *v2; // x8
  _QWORD *v3; // x0
  __int64 v4; // x9

  if ( *a1 )
    destroy_qptm();
  mutex_lock(&powerzone_list_lock);
  v2 = (_QWORD *)a1[5];
  v3 = a1 + 4;
  if ( (_QWORD *)*v2 == a1 + 4 && (v4 = *v3, *(_QWORD **)(*v3 + 8LL) == v3) )
  {
    *(_QWORD *)(v4 + 8) = v2;
    *v2 = v4;
  }
  else
  {
    _list_del_entry_valid_or_report();
  }
  a1[4] = 0xDEAD000000000100LL;
  a1[5] = 0xDEAD000000000122LL;
  return mutex_unlock(&powerzone_list_lock);
}
