__int64 __fastcall qcom_icc_bcm_voter_add(__int64 result, _QWORD *a2)
{
  __int64 v2; // x19
  _UNKNOWN **v4; // x22
  _QWORD *v5; // x0
  __int64 v6; // x2
  _QWORD *v7; // x1
  _QWORD *v8; // x0
  __int64 v9; // x2
  _QWORD *v10; // x1

  if ( result )
  {
    v2 = result;
    mutex_lock(&bcm_voter_lock);
    v4 = &bcm_voters;
    do
      v4 = (_UNKNOWN **)*v4;
    while ( v4 != &bcm_voters && v4 - 13 != (_UNKNOWN **)v2 );
    result = mutex_unlock(&bcm_voter_lock);
    if ( v4 != &bcm_voters )
    {
      mutex_lock(v2 + 24);
      v5 = a2 + 16;
      if ( (_QWORD *)a2[16] == a2 + 16 )
      {
        v6 = v2 + 72;
        v7 = *(_QWORD **)(v2 + 80);
        if ( v5 == (_QWORD *)(v2 + 72) || v7 == v5 || *v7 != v6 )
        {
          _list_add_valid_or_report();
        }
        else
        {
          *(_QWORD *)(v2 + 80) = v5;
          a2[16] = v6;
          a2[17] = v7;
          *v7 = v5;
        }
      }
      v8 = a2 + 18;
      if ( (_QWORD *)a2[18] == a2 + 18 )
      {
        v9 = v2 + 88;
        v10 = *(_QWORD **)(v2 + 96);
        if ( v8 == (_QWORD *)(v2 + 88) || v10 == v8 || *v10 != v9 )
        {
          _list_add_valid_or_report();
        }
        else
        {
          *(_QWORD *)(v2 + 96) = v8;
          a2[18] = v9;
          a2[19] = v10;
          *v10 = v8;
        }
      }
      return mutex_unlock(v2 + 24);
    }
  }
  return result;
}
