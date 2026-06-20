__int64 __fastcall dfc_qmap_send_ack(__int64 result, unsigned int a2, __int64 a3, char a4)
{
  char v4; // w19
  __int64 v5; // x20
  char v6; // w22
  __int64 v7; // x20
  __int64 v8; // x21
  unsigned int txid; // w0

  v4 = a2;
  if ( a4 == 2 )
  {
    v6 = *(_BYTE *)(result + 16);
    result = _alloc_skb(20, 2080, 0, 0xFFFFFFFFLL);
    if ( result )
    {
      v7 = result;
      *(_WORD *)(result + 180) = -1792;
      v8 = skb_put(result, 20);
      *(_QWORD *)(v8 + 4) = 0;
      *(_BYTE *)v8 = 0x80;
      *(_WORD *)(v8 + 2) = 4096;
      *(_QWORD *)(v8 + 12) = 0;
      *(_BYTE *)(v8 + 1) = v6;
      *(_BYTE *)(v8 + 4) = 12;
      txid = rmnet_qmap_next_txid();
      *(_BYTE *)(v8 + 12) = 1;
      *(_DWORD *)(v8 + 8) = bswap32(txid);
      *(_BYTE *)(v8 + 14) = v4;
      return rmnet_qmap_send(v7, 255, 0);
    }
  }
  else if ( a4 == 1 )
  {
    v5 = result;
    result = qmi_rmnet_get_bearer_map(result, a2);
    if ( result )
      return dfc_qmap_send_end_marker_cnf(v5, result);
  }
  return result;
}
