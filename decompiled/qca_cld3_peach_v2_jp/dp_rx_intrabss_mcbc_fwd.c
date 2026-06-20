__int64 __fastcall dp_rx_intrabss_mcbc_fwd(__int64 a1, _BYTE *a2, __int64 a3, __int64 a4, __int64 a5, unsigned int a6)
{
  bool is_ipv4_eapol_pkt; // w0
  __int64 v12; // x8
  int *v13; // x9
  int v14; // w10
  int v15; // w8
  int v16; // w11
  int v17; // w9
  __int64 result; // x0
  __int64 v20; // x23
  __int64 v21; // x24
  void (__fastcall *v22)(__int64, __int64); // x8
  __int64 v23; // x0
  _DWORD *v24; // x8
  unsigned __int8 *v25; // x8
  _BYTE *v26; // x8
  __int64 v27; // x10
  _BYTE *v28; // x8
  __int64 v29; // x10

  is_ipv4_eapol_pkt = _qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(a4 + 224));
  v12 = *(_QWORD *)a2;
  if ( is_ipv4_eapol_pkt )
  {
    v13 = *(int **)(a4 + 224);
    v14 = *(_DWORD *)(v12 + 96);
    v15 = *(unsigned __int16 *)(v12 + 100);
    v16 = *v13;
    v17 = *((unsigned __int16 *)v13 + 2);
    if ( v14 != v16 || v15 != v17 )
    {
      if ( a4 )
        _qdf_nbuf_free(a4);
      if ( a1 )
        ++*(_DWORD *)(a1 + 14128);
      return 1;
    }
    v12 = *(_QWORD *)a2;
  }
  if ( *(_DWORD *)(v12 + 32) == 6 && _qdf_nbuf_data_is_ipv6_mdns_pkt(*(_QWORD *)(a4 + 224)) )
  {
    if ( a2 )
    {
      ++*(_DWORD *)&a2[3256 * (unsigned __int8)a6 + 3136];
      return 0;
    }
    return 0;
  }
  if ( (a2[88] & 4) != 0 )
    return 0;
  result = skb_copy(a4, 2080);
  if ( !result )
    return result;
  v20 = result;
  v21 = *(unsigned __int16 *)(a4 + 60);
  qdf_mem_set((void *)(result + 40), 0x30u, 0);
  v22 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)a2 + 256LL);
  if ( v22 )
  {
    v23 = *(_QWORD *)(*(_QWORD *)a2 + 88LL);
    if ( *((_DWORD *)v22 - 1) != 1328777552 )
      __break(0x8228u);
    v22(v23, v20);
  }
  v24 = *(_DWORD **)(a1 + 1392);
  if ( *(v24 - 1) != -863635079 )
    __break(0x8228u);
  if ( (((__int64 (__fastcall *)(__int64, _BYTE *, __int64, __int64, _QWORD))v24)(a1, a2, v20, a5, a6) & 1) != 0 )
    return 0;
  v25 = *(unsigned __int8 **)(v20 + 224);
  if ( *v25 == 255 && v25[1] == 255 && v25[2] == 255 && v25[3] == 255 && v25[4] == 255 && v25[5] == 255 )
    *(_BYTE *)(v20 + 128) = *(_BYTE *)(v20 + 128) & 0xF8 | 1;
  if ( (*(_BYTE *)(a1 + 20092) & 1) != 0 || dp_tx_send(a1, *(unsigned __int8 *)(*(_QWORD *)a2 + 59LL), v20) )
  {
    if ( a2 )
    {
      v26 = &a2[3256 * (unsigned __int8)a6];
      v27 = *((_QWORD *)v26 + 391) + v21;
      ++*((_QWORD *)v26 + 390);
      *((_QWORD *)v26 + 391) = v27;
    }
    ++*(_QWORD *)(a5 + 296);
    _qdf_nbuf_free(v20);
    return 0;
  }
  if ( a2 )
  {
    v28 = &a2[3256 * (unsigned __int8)a6];
    v29 = *((_QWORD *)v28 + 389) + v21;
    ++*((_QWORD *)v28 + 388);
    *((_QWORD *)v28 + 389) = v29;
  }
  ++*(_QWORD *)(a5 + 264);
  return 0;
}
