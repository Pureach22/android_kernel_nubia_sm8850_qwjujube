_QWORD *__fastcall get_matching_swr_slave_device(__int64 a1)
{
  _UNKNOWN **v2; // x20
  _QWORD *v3; // x9
  _QWORD *v4; // x19

  mutex_lock(&board_lock);
  v2 = (_UNKNOWN **)swr_master_list;
  if ( swr_master_list != (_UNKNOWN *)&swr_master_list )
  {
    do
    {
      mutex_lock(v2 + 3);
      v3 = v2 + 9;
      while ( 1 )
      {
        v3 = (_QWORD *)*v3;
        if ( v3 == v2 + 9 )
          break;
        if ( v3[96] == a1 )
        {
          v4 = v3 - 6;
          mutex_unlock(v2 + 3);
          goto LABEL_8;
        }
      }
      mutex_unlock(v2 + 3);
      v2 = (_UNKNOWN **)*v2;
    }
    while ( v2 != &swr_master_list );
  }
  v4 = nullptr;
LABEL_8:
  mutex_unlock(&board_lock);
  return v4;
}
