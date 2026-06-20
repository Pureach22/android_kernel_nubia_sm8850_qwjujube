__int64 __fastcall mlo_get_mlpeer(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  char v5; // w9
  __int64 v6; // x20
  int i; // w0
  int v8; // w8
  _QWORD *v9; // x1
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  result = 0;
  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v5 = *(_BYTE *)(a2 + 5);
    v11[0] = 0;
    v6 = a1 + 24LL * (v5 & 0x3F);
    for ( i = qdf_list_peek_front((_QWORD *)(v6 + 48), v11); ; i = qdf_list_peek_next((_QWORD *)(v6 + 48), v9, v11) )
    {
      v8 = i;
      result = 0;
      if ( v8 )
        break;
      v9 = (_QWORD *)v11[0];
      if ( !v11[0] )
        break;
      if ( *(int *)((char *)&dword_68 + v11[0]) == *(_DWORD *)a2
        && *(unsigned __int16 *)((char *)&dword_6C + v11[0]) == *(unsigned __int16 *)(a2 + 4) )
      {
        result = v11[0];
        break;
      }
      v11[0] = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
