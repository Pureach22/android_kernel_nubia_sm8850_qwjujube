__int64 __fastcall ll_qmap_send_switch(char a1, unsigned __int8 a2, __int16 a3, char *a4, _DWORD *a5)
{
  __int64 result; // x0
  char *v7; // x23
  __int16 v8; // w27
  unsigned __int8 v9; // w20
  size_t v12; // x26
  __int64 v13; // x0
  __int64 v14; // x19
  char *v15; // x21
  char v16; // w8
  char v17; // w11
  unsigned int txid; // w0
  unsigned int v19; // w11
  char v20; // w8
  char v21; // w2
  _BYTE *v22; // x8
  __int64 v23; // x9
  char v24; // t1

  result = 4294967274LL;
  if ( (unsigned __int8)a3 <= 0xFu )
  {
    v7 = a4;
    if ( a4 )
    {
      v8 = 4 * a3;
      v9 = a3;
      v12 = (unsigned __int8)(4 * a3 + 16) & 0xFC;
      v13 = _alloc_skb(v12, 2080, 0, 0xFFFFFFFFLL);
      if ( v13 )
      {
        v14 = v13;
        *(_WORD *)(v13 + 180) = -1792;
        v15 = (char *)skb_put(v13, (unsigned int)v12);
        memset(v15, 0, v12);
        v16 = *v15;
        v17 = v15[5];
        v15[1] = a1;
        v15[4] = 25;
        *v15 = v16 | 0x80;
        *((_WORD *)v15 + 1) = (v8 << 8) + 3072;
        v15[5] = v17 & 0xFC;
        txid = rmnet_qmap_next_txid();
        v15[12] = 1;
        v19 = bswap32(txid);
        if ( a2 == 1 )
          v20 = 1;
        else
          v20 = 2;
        *((_DWORD *)v15 + 2) = v19;
        if ( a2 == 255 )
          v21 = 3;
        else
          v21 = v20;
        v15[15] = v9;
        v15[14] = v21;
        if ( v9 )
        {
          v22 = v15 + 16;
          v23 = v9;
          do
          {
            v24 = *v7++;
            --v23;
            *v22 = v24;
            v22 += 4;
          }
          while ( v23 );
        }
        if ( a5 )
          *a5 = *((_DWORD *)v15 + 2);
        return rmnet_qmap_send(v14, 0xFFu, 0);
      }
      else
      {
        return 4294967284LL;
      }
    }
  }
  return result;
}
