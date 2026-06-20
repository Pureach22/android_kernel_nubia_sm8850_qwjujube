__int64 __fastcall cm_list_insert_sorted(_QWORD *a1, _QWORD *a2)
{
  _QWORD *v4; // x2
  __int64 v5; // x9
  __int64 v6; // x8
  unsigned int v7; // w10
  unsigned int v8; // w11
  bool v9; // zf
  __int64 result; // x0
  _QWORD *v11; // [xsp+8h] [xbp-18h] BYREF
  _QWORD *v12[2]; // [xsp+10h] [xbp-10h] BYREF

  v12[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = nullptr;
  v12[0] = nullptr;
  qdf_list_peek_front(a1, v12);
  v4 = v12[0];
  if ( !v12[0] )
    goto LABEL_15;
  while ( 1 )
  {
    v5 = a2[3];
    v6 = v4[3];
    v7 = *(_DWORD *)(v5 + 1260);
    v8 = *(_DWORD *)(v6 + 1260);
    if ( v7 > v8 )
      break;
    if ( v7 == v8 )
    {
      if ( *(char *)(v5 + 60) > *(char *)(v6 + 60) )
        break;
      v9 = *(_DWORD *)(v5 + 1) == *(_DWORD *)(v6 + 1) && *(unsigned __int16 *)(v5 + 5) == *(unsigned __int16 *)(v6 + 5);
      if ( v9 && *(_QWORD *)(v5 + 1824) && !*(_QWORD *)(v6 + 1824) )
        break;
    }
    qdf_list_peek_next(a1, v12[0], &v11);
    v4 = v11;
    v11 = nullptr;
    v12[0] = v4;
    if ( !v4 )
      goto LABEL_15;
  }
  result = qdf_list_insert_before((__int64)a1, a2, v4);
  if ( !v12[0] )
LABEL_15:
    result = qdf_list_insert_back(a1, a2);
  _ReadStatusReg(SP_EL0);
  return result;
}
