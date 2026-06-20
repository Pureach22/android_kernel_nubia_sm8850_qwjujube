void *__fastcall wma_decap_to_8023(__int64 a1, __int64 a2)
{
  unsigned __int8 *v4; // x24
  int v5; // w23
  int v6; // w22
  __int64 v7; // x1
  __int64 v8; // x8
  void *v9; // x21
  __int64 v10; // x8
  __int64 v11; // x25
  int v12; // w8
  void *result; // x0
  int v14; // w8
  _QWORD v15[3]; // [xsp+8h] [xbp-18h] BYREF

  v15[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int8 **)(a1 + 224);
  memset(v15, 0, 14);
  v5 = v4[6];
  v6 = v4[7];
  if ( *v4 != 170 || v4[1] != 170 || v4[2] != 3 || v4[3] || v4[4] )
    goto LABEL_6;
  if ( v4[5] == 248 )
    goto LABEL_16;
  if ( v4[5] )
  {
LABEL_6:
    v7 = 14;
    goto LABEL_7;
  }
  v14 = v6 | (v5 << 8);
  v7 = 14;
  if ( v14 != 33011 && v14 != 33079 )
  {
LABEL_16:
    v4 = nullptr;
    v7 = 6;
  }
LABEL_7:
  v8 = *(_QWORD *)(a1 + 40);
  if ( v8 )
    *(_QWORD *)(a1 + 40) = v8 - v7;
  v9 = (void *)skb_push(a1, v7);
  v10 = *(_BYTE *)(a2 + 1) & 3;
  v11 = qword_B35308[v10];
  qdf_mem_copy(v15, (const void *)(a2 + qword_B353A8[v10]), 6u);
  qdf_mem_copy((char *)v15 + 6, (const void *)(a2 + v11), 6u);
  if ( v4 )
  {
    v12 = 65522;
    if ( (*(_BYTE *)(a1 + 68) & 4) != 0 )
      v12 = *(unsigned __int16 *)(a1 + 66) + 65522;
    v6 = v12 + *(_DWORD *)(a1 + 112);
    BYTE4(v15[1]) = (unsigned __int16)(v12 + *(_WORD *)(a1 + 112)) >> 8;
  }
  else
  {
    BYTE4(v15[1]) = v5;
  }
  BYTE5(v15[1]) = v6;
  result = qdf_mem_copy(v9, v15, 0xEu);
  _ReadStatusReg(SP_EL0);
  return result;
}
