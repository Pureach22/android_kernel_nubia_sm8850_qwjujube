__int64 __fastcall dp_tx_multipass_process(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x21
  unsigned int v6; // w22
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  _DWORD *v18; // x8
  __int64 *v19; // x8
  __int64 v20; // x8
  __int64 v23; // x24
  __int64 v25; // x9
  unsigned int v26; // w22
  int v27; // w8

  if ( *(_BYTE *)(a3 + 64) == 12 || !*(_DWORD *)(a2 + 40) )
    return 1;
  v4 = *(_QWORD *)(a3 + 224);
  if ( *(_WORD *)(v4 + 12) != 129 )
    return 1;
  v6 = bswap32(*(_WORD *)(v4 + 14) & 0xFF0F) >> 16;
  if ( (*(_BYTE *)v4 & 1) == 0 )
  {
    v9 = dp_peer_find_hash_find(a1, *(unsigned __int16 **)(a3 + 224), 0, 0xFFu, 9u);
    if ( v9 )
      goto LABEL_30;
    v18 = *(_DWORD **)(a1 + 1536);
    if ( v18 )
    {
      if ( *(v18 - 1) != 69695039 )
        __break(0x8228u);
      v9 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, __int64))v18)(a1, v4, 0, 9, 255);
      if ( v9 )
      {
LABEL_30:
        if ( *(_DWORD *)(v9 + 408) != 1 || (v19 = *(__int64 **)(v9 + 416)) == nullptr )
          v19 = (__int64 *)v9;
        v20 = *v19;
        if ( v20 && v6 == *(unsigned __int16 *)(v20 + 168) )
        {
          dp_peer_unref_delete(v9, 9u, v10, v11, v12, v13, v14, v15, v16, v17);
          dp_tx_remove_vlan_tag(a2, a3);
        }
        else
        {
          dp_peer_unref_delete(v9, 9u, v10, v11, v12, v13, v14, v15, v16, v17);
        }
      }
    }
    return 1;
  }
  v23 = a2 + 40960;
  qdf_spin_lock_bh_9(a2 + 43312);
  v25 = *(_QWORD *)(v23 + 2336);
  if ( !v25 )
  {
LABEL_22:
    qdf_spin_unlock_bh_10(a2 + 43312);
    return 1;
  }
  while ( v6 != *(unsigned __int16 *)(v25 + 168) )
  {
    v25 = *(_QWORD *)(v25 + 152);
    if ( !v25 )
      goto LABEL_22;
  }
  qdf_spin_unlock_bh_10(a2 + 43312);
  v26 = *(unsigned __int16 *)(*(_QWORD *)(v23 + 2328) + 2LL * v6);
  if ( !v26 )
    return 0;
  dp_tx_remove_vlan_tag(a2, a3);
  qdf_mem_set((void *)(a4 + 56), 0x24u, 0);
  *(_DWORD *)(a4 + 56) |= 0x200u;
  if ( v26 >= 0x100 )
    printk(
      &unk_94DB9D,
      "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_tx.c",
      9592,
      "!((group_key) & ~((HTT_TX_MSDU_EXT2_DESC_KEY_FLAGS_M) >> (HTT_TX_MSDU_EXT2_DESC_KEY_FLAGS_S)))");
  v27 = *(_DWORD *)(a4 + 64);
  *(_BYTE *)(a4 + 13) = 1;
  *(_DWORD *)(a4 + 64) = v27 | (v26 << 8);
  return 1;
}
