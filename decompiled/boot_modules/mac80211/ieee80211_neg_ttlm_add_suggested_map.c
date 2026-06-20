_BYTE *__fastcall ieee80211_neg_ttlm_add_suggested_map(__int64 a1, __int16 *a2)
{
  __int64 v4; // x22
  bool v5; // w23
  char v6; // w24
  _BYTE *result; // x0
  _BYTE *v8; // x21
  __int16 v9; // w25
  char v10; // w24
  char v11; // w25
  __int16 v12; // w26
  __int16 v13; // w26
  __int16 v14; // w26
  __int16 v15; // w26
  __int16 v16; // w26
  __int16 v17; // w26
  __int16 v18; // w26
  _BYTE *v19; // x21
  __int16 v20; // w24
  char v21; // w23
  char v22; // w24
  __int16 v23; // w25
  __int16 v24; // w25
  __int16 v25; // w25
  __int16 v26; // w25
  __int16 v27; // w25
  __int16 v28; // w25
  int v29; // w20

  v4 = *(_QWORD *)a2 ^ *((_QWORD *)a2 + 2) | *((_QWORD *)a2 + 1) ^ *((_QWORD *)a2 + 3);
  v5 = *(_OWORD *)a2 != *((_OWORD *)a2 + 1);
  v6 = 2 * (*(_OWORD *)a2 == *((_OWORD *)a2 + 1));
  result = (_BYTE *)skb_put(a1, 5);
  result[3] = v6;
  *result = -1;
  v8 = result;
  result[2] = 109;
  v9 = *a2;
  if ( *a2 )
  {
    result = (_BYTE *)skb_put(a1, 2);
    v10 = 1;
    *(_WORD *)result = v9;
    v11 = 5;
    v12 = a2[1];
    if ( !v12 )
      goto LABEL_4;
    goto LABEL_3;
  }
  v10 = 0;
  v11 = 3;
  v12 = a2[1];
  if ( v12 )
  {
LABEL_3:
    v11 += 2;
    v10 |= 2u;
    result = (_BYTE *)skb_put(a1, 2);
    *(_WORD *)result = v12;
  }
LABEL_4:
  v13 = a2[2];
  if ( v13 )
  {
    v11 += 2;
    v10 |= 4u;
    result = (_BYTE *)skb_put(a1, 2);
    *(_WORD *)result = v13;
  }
  v14 = a2[3];
  if ( v14 )
  {
    v11 += 2;
    v10 |= 8u;
    result = (_BYTE *)skb_put(a1, 2);
    *(_WORD *)result = v14;
  }
  v15 = a2[4];
  if ( v15 )
  {
    v11 += 2;
    v10 |= 0x10u;
    result = (_BYTE *)skb_put(a1, 2);
    *(_WORD *)result = v15;
  }
  v16 = a2[5];
  if ( v16 )
  {
    v11 += 2;
    v10 |= 0x20u;
    result = (_BYTE *)skb_put(a1, 2);
    *(_WORD *)result = v16;
  }
  v17 = a2[6];
  if ( v17 )
  {
    v11 += 2;
    v10 |= 0x40u;
    result = (_BYTE *)skb_put(a1, 2);
    *(_WORD *)result = v17;
  }
  v18 = a2[7];
  if ( v18 )
  {
    v11 += 2;
    v10 |= 0x80u;
    result = (_BYTE *)skb_put(a1, 2);
    *(_WORD *)result = v18;
  }
  v8[4] = v10;
  v8[1] = v11;
  if ( v4 )
  {
    result = (_BYTE *)skb_put(a1, 5);
    result[3] = v5;
    *result = -1;
    v19 = result;
    result[2] = 109;
    v20 = a2[8];
    if ( v20 )
    {
      result = (_BYTE *)skb_put(a1, 2);
      v21 = 1;
      *(_WORD *)result = v20;
      v22 = 5;
    }
    else
    {
      v21 = 0;
      v22 = 3;
    }
    v23 = a2[9];
    if ( v23 )
    {
      v22 += 2;
      v21 |= 2u;
      result = (_BYTE *)skb_put(a1, 2);
      *(_WORD *)result = v23;
    }
    v24 = a2[10];
    if ( v24 )
    {
      v22 += 2;
      v21 |= 4u;
      result = (_BYTE *)skb_put(a1, 2);
      *(_WORD *)result = v24;
    }
    v25 = a2[11];
    if ( v25 )
    {
      v22 += 2;
      v21 |= 8u;
      result = (_BYTE *)skb_put(a1, 2);
      *(_WORD *)result = v25;
    }
    v26 = a2[12];
    if ( v26 )
    {
      v22 += 2;
      v21 |= 0x10u;
      result = (_BYTE *)skb_put(a1, 2);
      *(_WORD *)result = v26;
    }
    v27 = a2[13];
    if ( v27 )
    {
      v22 += 2;
      v21 |= 0x20u;
      result = (_BYTE *)skb_put(a1, 2);
      *(_WORD *)result = v27;
    }
    v28 = a2[14];
    if ( v28 )
    {
      v22 += 2;
      v21 |= 0x40u;
      result = (_BYTE *)skb_put(a1, 2);
      *(_WORD *)result = v28;
    }
    v29 = (unsigned __int16)a2[15];
    if ( v29 )
    {
      v22 += 2;
      v21 |= 0x80u;
      result = (_BYTE *)skb_put(a1, 2);
      *(_WORD *)result = v29;
    }
    v19[4] = v21;
    v19[1] = v22;
  }
  return result;
}
