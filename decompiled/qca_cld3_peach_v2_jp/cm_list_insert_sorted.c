__int64 __fastcall cm_list_insert_sorted(_QWORD *a1, _QWORD *a2)
{
  _QWORD *v4; // x1
  __int64 v5; // x8
  __int64 v6; // x9
  unsigned int v7; // w10
  unsigned int v8; // w11
  __int64 result; // x0
  _QWORD *v10; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v11[2]; // [xsp+10h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = nullptr;
  v11[0] = 0;
  qdf_list_peek_front(a1, v11);
  v4 = (_QWORD *)v11[0];
  if ( !v11[0] )
    goto LABEL_9;
  while ( 1 )
  {
    v5 = a2[3];
    v6 = v4[3];
    v7 = *(_DWORD *)(v5 + 1132);
    v8 = *(_DWORD *)(v6 + 1132);
    if ( v7 > v8 )
      break;
    if ( v7 == v8 )
    {
      if ( *(char *)(v5 + 60) > *(char *)(v6 + 60) )
        break;
      v4 = (_QWORD *)v11[0];
    }
    qdf_list_peek_next(a1, v4, &v10);
    v4 = v10;
    v10 = nullptr;
    v11[0] = v4;
    if ( !v4 )
      goto LABEL_9;
  }
  result = qdf_list_insert_before((__int64)a1, a2, v4);
  if ( !v11[0] )
LABEL_9:
    result = qdf_list_insert_back(a1, a2);
  _ReadStatusReg(SP_EL0);
  return result;
}
