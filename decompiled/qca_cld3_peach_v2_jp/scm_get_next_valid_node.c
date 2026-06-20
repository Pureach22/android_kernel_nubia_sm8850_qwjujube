__int64 __fastcall scm_get_next_valid_node(_QWORD *a1, _QWORD *a2)
{
  __int64 v3; // x1
  __int64 v5; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v6[2]; // [xsp+10h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  v6[0] = 0;
  if ( a2 )
  {
    qdf_list_peek_next(a1, a2, v6);
    v3 = v6[0];
    if ( !v6[0] )
      goto LABEL_7;
  }
  else
  {
    qdf_list_peek_front(a1, v6);
    v3 = v6[0];
    if ( !v6[0] )
      goto LABEL_7;
  }
  do
  {
    if ( *(_DWORD *)(v3 + 20) == 306772034 )
      break;
    qdf_list_peek_next(a1, (_QWORD *)v3, &v5);
    v3 = v5;
    v5 = 0;
    v6[0] = v3;
  }
  while ( v3 );
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return v3;
}
