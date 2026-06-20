__int64 __fastcall qcom_icc_bcm_voter_remove(__int64 a1)
{
  __int64 v1; // x19
  _QWORD *v2; // x8
  __int64 v3; // x11
  _QWORD *v4; // x9
  _QWORD *v5; // x10

  v1 = *(_QWORD *)(a1 + 760);
  mutex_lock(&bcm_voter_lock);
  v2 = bcm_voters;
  while ( v2 != &bcm_voters )
  {
    v3 = *(v2 - 12);
    v4 = v2;
    v2 = (_QWORD *)*v2;
    if ( v3 == v1 )
    {
      v5 = (_QWORD *)v4[1];
      if ( (_QWORD *)*v5 == v4 && (_QWORD *)v2[1] == v4 )
      {
        v2[1] = v5;
        *v5 = v2;
      }
      else
      {
        _list_del_entry_valid_or_report(v4);
      }
      *v4 = 0xDEAD000000000100LL;
      v4[1] = 0xDEAD000000000122LL;
      return mutex_unlock(&bcm_voter_lock);
    }
  }
  return mutex_unlock(&bcm_voter_lock);
}
