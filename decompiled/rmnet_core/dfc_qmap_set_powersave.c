__int64 __fastcall dfc_qmap_set_powersave(char a1, unsigned __int8 a2, const void *a3)
{
  __int64 lock; // x0
  unsigned int v7; // w25
  unsigned int v8; // w24
  __int64 v9; // x0
  __int64 v10; // x22
  __int64 v11; // x23
  unsigned int txid; // w0
  char v13; // w8
  char v14; // w8
  char v15; // w8

  lock = _rcu_read_lock();
  if ( qmap_dfc_data )
  {
    v7 = *(_DWORD *)(qmap_dfc_data + 368);
    v8 = *(_DWORD *)(qmap_dfc_data + 372);
    _rcu_read_unlock(lock);
    v9 = _alloc_skb(60, 2080, 0, 0xFFFFFFFFLL);
    if ( v9 )
    {
      v10 = v9;
      *(_WORD *)(v9 + 180) = -1792;
      v11 = skb_put(v9, 60);
      *(_QWORD *)(v11 + 4) = 0;
      *(_QWORD *)(v11 + 12) = 0;
      *(_DWORD *)v11 = 939524224;
      *(_QWORD *)(v11 + 20) = 0;
      *(_QWORD *)(v11 + 28) = 0;
      *(_QWORD *)(v11 + 36) = 0;
      *(_QWORD *)(v11 + 44) = 0;
      *(_QWORD *)(v11 + 52) = 0;
      *(_BYTE *)(v11 + 4) = 14;
      txid = rmnet_qmap_next_txid();
      v13 = *(_BYTE *)(v11 + 15);
      *(_DWORD *)(v11 + 8) = bswap32(txid);
      v14 = v13 & 0xFE;
      *(_BYTE *)(v11 + 12) = 3;
      if ( a1 )
        ++v14;
      *(_BYTE *)(v11 + 15) = v14;
      if ( a1 && a2 )
      {
        if ( a2 >= 0x21u )
          a2 = 32;
        v15 = *(_BYTE *)(v11 + 13);
        *(_BYTE *)(v11 + 24) = a2;
        *(_BYTE *)(v11 + 13) = v15 | 3;
        memcpy((void *)(v11 + 25), a3, a2);
      }
      *(_DWORD *)(v11 + 16) = bswap32(v7);
      *(_DWORD *)(v11 + 20) = bswap32(v8);
      return rmnet_qmap_send(v10, 255, 0);
    }
    else
    {
      return 4294967284LL;
    }
  }
  else
  {
    _rcu_read_unlock(lock);
    return 4294967274LL;
  }
}
