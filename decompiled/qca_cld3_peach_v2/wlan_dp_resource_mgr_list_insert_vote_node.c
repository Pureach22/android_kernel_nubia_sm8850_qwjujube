__int64 __fastcall wlan_dp_resource_mgr_list_insert_vote_node(_QWORD *a1, _QWORD *a2, int a3)
{
  __int64 result; // x0
  _QWORD *v7; // x1
  _QWORD *v8; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v9[2]; // [xsp+10h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = nullptr;
  v9[0] = 0;
  result = qdf_list_peek_front(a1, v9);
  if ( (_DWORD)result )
  {
LABEL_11:
    if ( !v9[0] )
LABEL_12:
      result = qdf_list_insert_back(a1, a2 + 7);
  }
  else
  {
    v7 = (_QWORD *)v9[0];
    do
    {
      if ( a3 == 11 )
      {
        if ( a2[10] > v7[3] )
          goto LABEL_10;
      }
      else if ( a2[9] > v7[2] )
      {
LABEL_10:
        result = qdf_list_insert_before((__int64)a1, a2 + 7, v7);
        goto LABEL_11;
      }
      result = qdf_list_peek_next(a1, v7, &v8);
      v7 = v8;
      v8 = nullptr;
      v9[0] = v7;
    }
    while ( !(_DWORD)result );
    if ( !v7 )
      goto LABEL_12;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
