__int64 __fastcall dfc_send_ack(__int64 a1, unsigned int a2, unsigned int a3, char a4, char a5)
{
  __int64 result; // x0
  __int64 v10; // x24
  __int64 v11; // x23
  __int64 v12; // x0
  __int64 v13; // x9

  result = rmnet_get_qos_pt(a1);
  if ( result )
  {
    if ( dfc_qmap )
    {
      return dfc_qmap_send_ack(result, a2, a3, a5);
    }
    else
    {
      v10 = result;
      result = _alloc_skb(20, 2080, 0, 0xFFFFFFFFLL);
      if ( result )
      {
        v11 = result;
        v12 = skb_put(result, 20);
        *(_QWORD *)(v12 + 4) = 0;
        *(_BYTE *)v12 = 0x80;
        *(_WORD *)(v12 + 2) = 4096;
        *(_BYTE *)(v12 + 4) = 4;
        *(_QWORD *)(v12 + 12) = 0;
        *(_WORD *)(v12 + 14) = bswap32(a3) >> 16;
        *(_BYTE *)(v12 + 1) = a4;
        *(_BYTE *)(v12 + 19) = a2;
        *(_WORD *)(v12 + 12) = ((a5 & 3) << 8) | 2;
        *(_DWORD *)(v12 + 8) = bswap32(*(_DWORD *)(v10 + 328));
        v13 = *(_QWORD *)(v10 + 24);
        *(_WORD *)(v11 + 180) = -1792;
        *(_QWORD *)(v11 + 16) = v13;
        ++*(_DWORD *)(v10 + 328);
        return rmnet_map_tx_qmap_cmd(v11, 0, 1);
      }
    }
  }
  return result;
}
