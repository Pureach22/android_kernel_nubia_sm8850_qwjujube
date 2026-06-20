__int64 __fastcall qcom_icc_debug_unregister(__int64 a1)
{
  _QWORD *v2; // x0
  _QWORD *v3; // x9
  _QWORD *v4; // x22
  _QWORD *v5; // x8

  mutex_lock(&debug_lock);
  v2 = icc_providers;
  if ( icc_providers != (_UNKNOWN *)&icc_providers )
  {
    do
    {
      v4 = (_QWORD *)*v2;
      if ( v2[2] == a1 )
      {
        v5 = (_QWORD *)v2[1];
        if ( (_QWORD *)*v5 == v2 && (_QWORD *)v4[1] == v2 )
        {
          v4[1] = v5;
          *v5 = v4;
        }
        else
        {
          _list_del_entry_valid_or_report();
          v2 = v3;
        }
        *v2 = 0xDEAD000000000100LL;
        v2[1] = 0xDEAD000000000122LL;
        kfree();
      }
      v2 = v4;
    }
    while ( v4 != &icc_providers );
  }
  mutex_unlock(&debug_lock);
  return 0;
}
