__int64 __fastcall get_key_callback(_DWORD *a1, __int64 a2)
{
  __int64 v4; // x3
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // x21
  __int64 v8; // x22
  _WORD *v9; // x21
  __int64 v10; // x3
  __int64 v11; // x0
  __int64 v12; // x0
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 8);
  if ( v4 )
  {
    result = nla_put(*(_QWORD *)a1, 10, *(unsigned int *)(a2 + 20), v4);
    if ( (_DWORD)result )
      goto LABEL_12;
  }
  if ( *(_DWORD *)(a2 + 28) )
  {
    v6 = *(_QWORD *)a1;
    v13 = *(_DWORD *)(a2 + 28);
    result = nla_put(v6, 9, 4, &v13);
    if ( (_DWORD)result )
      goto LABEL_12;
  }
  v7 = *(_QWORD *)(*(_QWORD *)a1 + 216LL);
  v8 = *(unsigned int *)(*(_QWORD *)a1 + 208LL);
  result = nla_put(*(_QWORD *)a1, 80, 0, 0);
  if ( (result & 0x80000000) != 0 )
    goto LABEL_12;
  v9 = (_WORD *)(v7 + v8);
  if ( !v9 )
    goto LABEL_12;
  v10 = *(_QWORD *)(a2 + 8);
  if ( v10 )
  {
    result = nla_put(*(_QWORD *)a1, 4, *(unsigned int *)(a2 + 20), v10);
    if ( (_DWORD)result )
      goto LABEL_12;
  }
  if ( *(_DWORD *)(a2 + 28)
    && (v11 = *(_QWORD *)a1, v13 = *(_DWORD *)(a2 + 28), result = nla_put(v11, 3, 4, &v13), (_DWORD)result)
    || (v12 = *(_QWORD *)a1, LOBYTE(v13) = a1[3], result = nla_put(v12, 2, 1, &v13), (_DWORD)result) )
  {
LABEL_12:
    a1[2] = 1;
  }
  else
  {
    *v9 = *(_DWORD *)(*(_QWORD *)a1 + 216LL) + *(_WORD *)(*(_QWORD *)a1 + 208LL) - (_WORD)v9;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
