__int64 __fastcall swr_master_add_boarddevices(__int64 a1)
{
  _UNKNOWN **v2; // x0
  _QWORD *v3; // x1
  const char **v4; // x22

  mutex_lock(&board_lock);
  v2 = (_UNKNOWN **)(a1 + 912);
  v3 = off_7A0[0];
  if ( (_UNKNOWN **)(a1 + 912) == &swr_master_list || off_7A0[0] == v2 || *(_UNKNOWN ***)off_7A0[0] != &swr_master_list )
  {
    _list_add_valid_or_report(v2, off_7A0[0]);
  }
  else
  {
    off_7A0[0] = (_UNKNOWN **)(a1 + 912);
    *(_QWORD *)(a1 + 912) = &swr_master_list;
    *(_QWORD *)(a1 + 920) = v3;
    *v3 = v2;
  }
  v4 = (const char **)board_list;
  if ( board_list != (_UNKNOWN *)&board_list )
  {
    do
    {
      if ( *(_DWORD *)(a1 + 928) == *((_DWORD *)v4 + 12) && !swr_new_device(a1, (__int64)(v4 + 2)) )
        dev_err(a1, "can't create new device for %s\n", v4[9]);
      v4 = (const char **)*v4;
    }
    while ( v4 != (const char **)&board_list );
  }
  return mutex_unlock(&board_lock);
}
