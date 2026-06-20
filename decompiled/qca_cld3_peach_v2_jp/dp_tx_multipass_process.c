__int64 __fastcall dp_tx_multipass_process(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  unsigned int v6; // w21
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v18; // x23
  __int64 v20; // x9
  unsigned int v21; // w21
  int v22; // w9

  if ( *(_BYTE *)(a3 + 64) == 12 || !*(_DWORD *)(a2 + 40) )
    return 1;
  v4 = *(_QWORD *)(a3 + 224);
  if ( *(_WORD *)(v4 + 12) != 129 )
    return 1;
  v6 = bswap32(*(_WORD *)(v4 + 14) & 0xFF0F) >> 16;
  if ( (*(_BYTE *)v4 & 1) == 0 )
  {
    v8 = dp_peer_find_hash_find(a1, *(unsigned __int16 **)(a3 + 224), 0, 0xFFu, 9u);
    if ( v8 )
    {
      if ( *(_QWORD *)v8 && v6 == *(unsigned __int16 *)(*(_QWORD *)v8 + 168LL) )
      {
        dp_peer_unref_delete(v8, 9u, v9, v10, v11, v12, v13, v14, v15, v16);
        dp_tx_remove_vlan_tag(a2, a3);
      }
      else
      {
        dp_peer_unref_delete(v8, 9u, v9, v10, v11, v12, v13, v14, v15, v16);
      }
    }
    return 1;
  }
  v18 = a2 + 40960;
  qdf_spin_lock_bh_9(a2 + 42488);
  v20 = *(_QWORD *)(v18 + 1512);
  if ( !v20 )
  {
LABEL_15:
    qdf_spin_unlock_bh_9(a2 + 42488);
    return 1;
  }
  while ( v6 != *(unsigned __int16 *)(v20 + 168) )
  {
    v20 = *(_QWORD *)(v20 + 152);
    if ( !v20 )
      goto LABEL_15;
  }
  qdf_spin_unlock_bh_9(a2 + 42488);
  v21 = *(unsigned __int16 *)(*(_QWORD *)(v18 + 1504) + 2LL * v6);
  if ( !v21 )
    return 0;
  dp_tx_remove_vlan_tag(a2, a3);
  qdf_mem_set((void *)(a4 + 56), 0x24u, 0);
  *(_DWORD *)(a4 + 56) |= 0x200u;
  if ( v21 >= 0x100 )
    printk(
      &unk_881311,
      "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_tx.c",
      9592,
      "!((group_key) & ~((HTT_TX_MSDU_EXT2_DESC_KEY_FLAGS_M) >> (HTT_TX_MSDU_EXT2_DESC_KEY_FLAGS_S)))");
  v22 = *(_DWORD *)(a4 + 64);
  *(_BYTE *)(a4 + 13) = 1;
  *(_DWORD *)(a4 + 64) = v22 | (v21 << 8);
  return 1;
}
