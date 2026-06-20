__int64 __fastcall sta_apply_auth_flags(__int64 a1, char a2, char a3)
{
  __int64 result; // x0
  __int64 v7; // x1

  if ( (a2 & 0x20) == 0
    || (a3 & 0x20) == 0
    || (*(_QWORD *)(a1 + 216) & 1) != 0
    || (result = sta_info_move_state(a1, 2), !(_DWORD)result) )
  {
    if ( (a2 & 0x80) == 0 || (a3 & 0x80) == 0 || (*(_QWORD *)(a1 + 216) & 2) != 0 )
      goto LABEL_11;
    if ( (*(_QWORD *)(a1 + 216) & 0x200000) == 0 )
      rate_control_rate_init(a1);
    result = sta_info_move_state(a1, 3);
    if ( !(_DWORD)result )
    {
LABEL_11:
      if ( (a2 & 2) != 0 )
      {
        if ( (a3 & 2) != 0 )
        {
          v7 = 4;
LABEL_16:
          result = sta_info_move_state(a1, v7);
          if ( (_DWORD)result )
            return result;
          goto LABEL_17;
        }
        if ( (*(_QWORD *)(a1 + 216) & 8) != 0 )
        {
          v7 = 3;
          goto LABEL_16;
        }
      }
LABEL_17:
      if ( a3 < 0
        || (a2 & 0x80) == 0
        || (*(_QWORD *)(a1 + 216) & 2) == 0
        || (result = sta_info_move_state(a1, 2), !(_DWORD)result) )
      {
        if ( (a3 & 0x20) != 0 )
          return 0;
        if ( (a2 & 0x20) == 0 )
          return 0;
        if ( (*(_QWORD *)(a1 + 216) & 1) == 0 )
          return 0;
        result = sta_info_move_state(a1, 1);
        if ( !(_DWORD)result )
          return 0;
      }
    }
  }
  return result;
}
