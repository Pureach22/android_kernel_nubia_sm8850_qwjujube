__int64 __fastcall drm_dp_check_and_send_link_address(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  char v5; // w21
  _QWORD *v6; // x19
  _QWORD *i; // x22
  _QWORD *v8; // t1
  __int64 v9; // x1

  if ( (*(_BYTE *)(a2 + 72) & 1) == 0 )
  {
    result = drm_dp_send_link_address(a1, a2);
    if ( (_DWORD)result == 1 )
    {
      v5 = 1;
      goto LABEL_6;
    }
    if ( (result & 0x80000000) != 0 )
      return result;
  }
  v5 = 0;
LABEL_6:
  v8 = *(_QWORD **)(a2 + 40);
  v6 = (_QWORD *)(a2 + 40);
  for ( i = v8; i != v6; v5 = 1 )
  {
    while ( 1 )
    {
      if ( (*((_BYTE *)i - 15) & 1) == 0 && *((_BYTE *)i - 13) == 1 )
      {
        v9 = i[2];
        if ( v9 )
          break;
      }
LABEL_9:
      i = (_QWORD *)*i;
      if ( i == v6 )
        return v5 & 1;
    }
    result = drm_dp_check_and_send_link_address(a1, v9);
    if ( (_DWORD)result != 1 )
    {
      if ( (result & 0x80000000) != 0 )
        return result;
      goto LABEL_9;
    }
    i = (_QWORD *)*i;
  }
  return v5 & 1;
}
