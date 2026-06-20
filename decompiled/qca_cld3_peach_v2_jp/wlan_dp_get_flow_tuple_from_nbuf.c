__int64 __fastcall wlan_dp_get_flow_tuple_from_nbuf(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v8; // x8
  __int64 v9; // x23
  __int64 (__fastcall *v10)(_QWORD); // x8
  int v11; // w0
  __int64 v12; // x8
  int v13; // w21
  _DWORD *v14; // x8
  __int64 v15; // x8
  __int64 v16; // x1
  __int64 v17; // x10
  int v18; // w11
  __int64 v19; // x8
  unsigned int v20; // w9
  unsigned __int16 *v21; // x10
  unsigned int v22; // w9
  unsigned int v23; // w9
  unsigned int v24; // w13
  unsigned int v25; // w10
  unsigned int v26; // w12
  bool v28; // w9
  __int64 v29; // x8
  __int64 v30; // x1
  __int64 result; // x0
  _QWORD v32[2]; // [xsp+0h] [xbp-10h] BYREF

  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 256);
  v9 = *(_QWORD *)(a1 + 1480);
  v32[0] = 0;
  v10 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v8 + 74392) + 536LL);
  if ( *((_DWORD *)v10 - 1) != 855462014 )
    __break(0x8228u);
  v11 = v10(a4);
  v12 = *(_QWORD *)(a1 + 256);
  v13 = v11;
  v14 = *(_DWORD **)(*(_QWORD *)(v12 + 74392) + 1296LL);
  if ( *(v14 - 1) != 348550285 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, char *, _QWORD *))v14)(a4, (char *)v32 + 4, v32);
  *(_BYTE *)a2 = 1;
  v15 = *(_QWORD *)(a3 + 40);
  v16 = v13 + (unsigned int)*(unsigned __int16 *)(v9 + 632);
  if ( v15 )
    *(_QWORD *)(a3 + 40) = v15 + (unsigned int)v16;
  skb_pull(a3, v16);
  v17 = LODWORD(v32[0]);
  LOBYTE(v18) = 1;
  v19 = *(_QWORD *)(a3 + 224) + HIDWORD(v32[0]);
  v20 = *(_DWORD *)(v19 + 16);
  *(_QWORD *)(a2 + 4) = 0;
  v21 = (unsigned __int16 *)(v19 + v17);
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = bswap32(v20);
  v22 = *(_DWORD *)(v19 + 12);
  *(_QWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = bswap32(v22);
  v23 = v21[1];
  v24 = __rev16(v23);
  *(_WORD *)(a2 + 36) = v24;
  v25 = *v21;
  v26 = __rev16(v25);
  *(_WORD *)(a2 + 38) = v26;
  if ( v24 != 500 && v24 != 4500 && v26 != 500 && v26 != 4500 )
    v18 = (*(unsigned __int8 *)(a3 + 72) >> 1) & 1;
  *(_BYTE *)(a2 + 1) = v18;
  v28 = v23 == 13568 || v25 == 13568;
  *(_BYTE *)(a2 + 2) = v28;
  *(_WORD *)(a2 + 40) = *(unsigned __int8 *)(v19 + 9);
  v29 = *(_QWORD *)(a3 + 40);
  v30 = v13 + (unsigned int)*(unsigned __int16 *)(v9 + 632);
  if ( v29 )
    *(_QWORD *)(a3 + 40) = v29 - (unsigned int)v30;
  result = skb_push(a3, v30);
  _ReadStatusReg(SP_EL0);
  return result;
}
