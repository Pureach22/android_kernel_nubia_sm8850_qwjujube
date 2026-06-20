__int64 __fastcall qrtr_getname(__int64 a1, __int64 a2, int a3)
{
  __int64 v5; // x20
  __int64 v6; // x8
  __int64 *v7; // x8
  __int64 result; // x0
  __int64 v9; // [xsp+8h] [xbp-18h]
  __int16 v10; // [xsp+10h] [xbp-10h]

  _ReadStatusReg(SP_EL0);
  v5 = *(_QWORD *)(a1 + 24);
  lock_sock_nested(v5, 0);
  if ( a3 )
  {
    if ( *(_BYTE *)(v5 + 18) != 1 )
    {
      release_sock(v5);
      result = 4294967189LL;
      goto LABEL_7;
    }
    v6 = 854;
  }
  else
  {
    v6 = 842;
  }
  v7 = (__int64 *)(v5 + v6);
  v9 = *v7;
  v10 = *((_WORD *)v7 + 4);
  release_sock(v5);
  result = 12;
  *(_WORD *)a2 = 42;
  *(_QWORD *)(a2 + 2) = v9;
  *(_WORD *)(a2 + 10) = v10;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
