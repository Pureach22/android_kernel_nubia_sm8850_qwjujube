__int64 __fastcall dp_rx_deliver_raw(_QWORD *a1, __int64 *a2, __int64 a3, unsigned __int8 a4)
{
  _QWORD *v5; // x13
  __int64 v6; // x9
  __int64 *v7; // x10
  _QWORD *v8; // x8
  _QWORD *v9; // x9
  __int64 *v10; // x12
  __int64 v11; // x14
  int v12; // w13
  unsigned __int64 v13; // x14
  unsigned __int64 v14; // x13
  __int64 v15; // x10
  __int64 v16; // x13
  int v17; // w13
  _DWORD *v18; // x8
  __int64 v19; // x0
  __int64 (__fastcall *v20)(__int64, __int64); // x8
  __int64 v21; // x0
  __int64 v22; // x1
  __int64 result; // x0
  __int64 *v24; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v25[2]; // [xsp+10h] [xbp-10h] BYREF

  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = nullptr;
  v25[0] = 0;
  if ( a2 )
  {
    v5 = nullptr;
    v6 = a3 + 4072LL * a4;
    v7 = nullptr;
    v8 = (_QWORD *)(v6 + 3104);
    v9 = (_QWORD *)(v6 + 3112);
    do
    {
      v10 = (__int64 *)*a2;
      if ( v7 )
      {
        *v5 = a2;
        v7 = (__int64 *)v25[0];
        v11 = *(_QWORD *)(v25[0] + 72LL);
        v12 = v11 + 0x1000000;
        v13 = v11 & 0xFFFFFFFF00FFFFFFLL;
        v14 = v12 & 0xFF000000;
      }
      else
      {
        v15 = a2[9];
        v25[0] = a2;
        v13 = 0x1000000;
        v14 = v15 & 0xFFFFFFFF00FFFFFFLL;
        v7 = a2;
      }
      v24 = a2;
      v7[9] = v14 | v13;
      *a2 = 0;
      v16 = a1[3];
      if ( v16 )
        ++*(_DWORD *)(v16 + 464);
      if ( a3 )
      {
        ++*v8;
        if ( (*((_BYTE *)a2 + 68) & 4) != 0 )
          v17 = *((unsigned __int16 *)a2 + 33);
        else
          v17 = 0;
        *v9 += (unsigned int)(*((_DWORD *)a2 + 28) + v17);
      }
      v5 = a2;
      a2 = v10;
    }
    while ( v10 );
  }
  v18 = (_DWORD *)a1[26];
  v19 = a1[11];
  if ( *(v18 - 1) != 1488343003 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD *, __int64 **))v18)(v19, v25, &v24);
  v20 = (__int64 (__fastcall *)(__int64, __int64))a1[21];
  v21 = a1[11];
  v22 = v25[0];
  if ( *((_DWORD *)v20 - 1) != 424933381 )
    __break(0x8228u);
  result = v20(v21, v22);
  _ReadStatusReg(SP_EL0);
  return result;
}
