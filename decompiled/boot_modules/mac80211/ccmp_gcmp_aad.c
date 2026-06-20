__int64 __fastcall ccmp_gcmp_aad(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // x8
  int v4; // w9
  __int16 v5; // w11
  __int16 v6; // w11
  unsigned int v7; // w10
  __int16 v8; // w11
  __int64 v9; // x12
  int v10; // w12
  int v11; // w13
  __int64 result; // x0
  __int64 v13; // x11
  __int64 v14; // x12
  char v15; // w10
  __int16 v16; // w9
  int v17; // w8

  v3 = *(_QWORD *)(a1 + 224);
  v4 = *(_WORD *)v3 & 0x300;
  if ( (*(_WORD *)v3 & 0xC) != 0 )
    v5 = -30833;
  else
    v5 = -30721;
  v6 = v5 & *(_WORD *)v3;
  if ( v4 == 768 )
    v7 = 28;
  else
    v7 = 22;
  v8 = v6 | 0x4000;
  if ( (*(_WORD *)v3 & 0x8C) == 0x88 )
  {
    v9 = 24;
    if ( v4 == 768 )
      v9 = 30;
    v10 = *(unsigned __int8 *)(v3 + v9);
    v7 += 2;
    if ( (a3 & 1) != 0 )
      v11 = -113;
    else
      v11 = 15;
    result = v10 & (unsigned int)v11;
    v8 &= 0x47FBu;
  }
  else
  {
    result = 0;
  }
  *(_WORD *)(a2 + 2) = v8;
  *(_WORD *)a2 = __rev16(v7);
  v13 = *(_QWORD *)(v3 + 12);
  v14 = *(_QWORD *)(v3 + 4);
  *(_WORD *)(a2 + 20) = *(_WORD *)(v3 + 20);
  *(_QWORD *)(a2 + 12) = v13;
  *(_QWORD *)(a2 + 4) = v14;
  v15 = *(_BYTE *)(v3 + 22);
  *(_BYTE *)(a2 + 23) = 0;
  *(_BYTE *)(a2 + 22) = v15 & 0xF;
  if ( v4 == 768 )
  {
    v16 = *(_WORD *)(v3 + 28);
    v17 = *(_DWORD *)(v3 + 24);
    *(_BYTE *)(a2 + 30) = result;
    *(_BYTE *)(a2 + 31) = 0;
    *(_WORD *)(a2 + 28) = v16;
    *(_DWORD *)(a2 + 24) = v17;
  }
  else
  {
    *(_QWORD *)(a2 + 24) = 0;
    *(_BYTE *)(a2 + 24) = result;
  }
  return result;
}
