__int64 __fastcall drv_switch_vif_chanctx(__int64 a1, __int64 a2, int a3, int a4)
{
  __int64 v7; // x23
  __int64 *v8; // x8
  __int64 i; // x9
  __int64 v10; // x10
  __int64 (*v11)(void); // x8
  __int64 result; // x0
  __int64 *v13; // x8
  __int64 v14; // x10
  __int64 v15; // x11

  if ( !*(_QWORD *)(*(_QWORD *)(a1 + 464) + 632LL) )
    return 4294967201LL;
  v7 = (unsigned int)a3;
  if ( a3 >= 1 )
  {
    v8 = (__int64 *)(a2 + 24);
    for ( i = (unsigned int)a3; i; --i )
    {
      v10 = *v8;
      if ( (*(_BYTE *)(*(v8 - 1) - 68) & 1) != 0 )
      {
        if ( a4 )
          goto LABEL_8;
      }
      else
      {
        __break(0x800u);
        if ( a4 )
        {
LABEL_8:
          if ( a4 != 1 || (*(_BYTE *)(v10 - 68) & 1) == 0 )
            goto LABEL_5;
LABEL_10:
          __break(0x800u);
          goto LABEL_5;
        }
      }
      if ( (*(_BYTE *)(v10 - 68) & 1) == 0 )
        goto LABEL_10;
LABEL_5:
      v8 += 4;
    }
  }
  v11 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 464) + 632LL);
  if ( *((_DWORD *)v11 - 1) != 1963383266 )
    __break(0x8228u);
  result = v11();
  if ( a4 == 1 && !(_DWORD)result && a3 >= 1 )
  {
    v13 = (__int64 *)(a2 + 24);
    do
    {
      v15 = *(v13 - 1);
      v14 = *v13;
      --v7;
      v13 += 4;
      *(_BYTE *)(v14 - 68) = 1;
      *(_BYTE *)(v15 - 68) = 0;
    }
    while ( v7 );
    return 0;
  }
  return result;
}
