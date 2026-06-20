__int64 __fastcall dp_rx_intrabss_mcbc_fwd(__int64 a1, _BYTE *a2, __int64 a3, __int64 a4, __int64 a5, unsigned int a6)
{
  bool is_ipv4_eapol_pkt; // w0
  __int64 v12; // x8
  int *v13; // x9
  int v14; // w10
  int v15; // w8
  int v16; // w11
  int v17; // w9
  bool v18; // zf
  int *v19; // x9
  int v20; // w10
  int v21; // w8
  int v22; // w11
  int v23; // w9
  __int64 result; // x0
  __int64 v26; // x23
  __int64 v27; // x24
  void (__fastcall *v28)(__int64, __int64); // x8
  __int64 v29; // x0
  _DWORD *v30; // x8
  unsigned __int8 *v31; // x8
  _BYTE *v32; // x8
  __int64 v33; // x10
  _BYTE *v34; // x8
  __int64 v35; // x10

  is_ipv4_eapol_pkt = _qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(a4 + 224));
  v12 = *(_QWORD *)a2;
  if ( is_ipv4_eapol_pkt )
  {
    v13 = *(int **)(a4 + 224);
    v14 = *(_DWORD *)(v12 + 96);
    v15 = *(unsigned __int16 *)(v12 + 100);
    v16 = *v13;
    v17 = *((unsigned __int16 *)v13 + 2);
    v18 = v14 == v16 && v15 == v17;
    v12 = *(_QWORD *)a2;
    if ( !v18 )
    {
      v19 = *(int **)(a4 + 224);
      v20 = *(_DWORD *)(v12 + 104);
      v21 = *(unsigned __int16 *)(v12 + 108);
      v22 = *v19;
      v23 = *((unsigned __int16 *)v19 + 2);
      if ( v20 != v22 || v21 != v23 )
      {
        if ( a4 )
          _qdf_nbuf_free(a4);
        if ( a1 )
          ++*(_DWORD *)(a1 + 14184);
        return 1;
      }
      v12 = *(_QWORD *)a2;
    }
  }
  if ( *(_DWORD *)(v12 + 32) == 6 && _qdf_nbuf_data_is_ipv6_mdns_pkt(*(_QWORD *)(a4 + 224)) )
  {
    if ( a2 )
    {
      ++*(_DWORD *)&a2[4072 * (unsigned __int8)a6 + 3200];
      return 0;
    }
    return 0;
  }
  if ( (a2[88] & 4) != 0 )
    return 0;
  result = skb_copy(a4, 2080);
  if ( !result )
    return result;
  v26 = result;
  v27 = *(unsigned __int16 *)(a4 + 60);
  qdf_mem_set((void *)(result + 40), 0x30u, 0);
  v28 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)a2 + 264LL);
  if ( v28 )
  {
    v29 = *(_QWORD *)(*(_QWORD *)a2 + 88LL);
    if ( *((_DWORD *)v28 - 1) != 1328777552 )
      __break(0x8228u);
    v28(v29, v26);
  }
  v30 = *(_DWORD **)(a1 + 1392);
  if ( *(v30 - 1) != -863635079 )
    __break(0x8228u);
  if ( (((__int64 (__fastcall *)(__int64, _BYTE *, __int64, __int64, _QWORD))v30)(a1, a2, v26, a5, a6) & 1) != 0 )
    return 0;
  v31 = *(unsigned __int8 **)(v26 + 224);
  if ( *v31 == 255 && v31[1] == 255 && v31[2] == 255 && v31[3] == 255 && v31[4] == 255 && v31[5] == 255 )
    *(_BYTE *)(v26 + 128) = *(_BYTE *)(v26 + 128) & 0xF8 | 1;
  if ( (*(_BYTE *)(a1 + 20148) & 1) != 0 || dp_tx_send(a1, *(unsigned __int8 *)(*(_QWORD *)a2 + 59LL), v26) )
  {
    if ( a2 )
    {
      v32 = &a2[4072 * (unsigned __int8)a6];
      v33 = *((_QWORD *)v32 + 399) + v27;
      ++*((_QWORD *)v32 + 398);
      *((_QWORD *)v32 + 399) = v33;
    }
    ++*(_QWORD *)(a5 + 296);
    _qdf_nbuf_free(v26);
    return 0;
  }
  if ( a2 )
  {
    v34 = &a2[4072 * (unsigned __int8)a6];
    v35 = *((_QWORD *)v34 + 397) + v27;
    ++*((_QWORD *)v34 + 396);
    *((_QWORD *)v34 + 397) = v35;
  }
  ++*(_QWORD *)(a5 + 264);
  return 0;
}
