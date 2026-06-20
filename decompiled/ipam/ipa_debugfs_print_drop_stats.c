__int64 __fastcall ipa_debugfs_print_drop_stats(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _DWORD *v7; // x22
  _BYTE *v8; // x9
  int drop_stats; // w0
  int v10; // w23
  __int64 v12; // x23
  unsigned int v13; // w19
  _DWORD *v14; // x25
  unsigned int ep_mapping; // w0
  unsigned int v16; // w28
  unsigned int ep_reg_idx; // w0
  int v18; // w20
  int v19; // w0
  __int64 v20; // [xsp+0h] [xbp-10h]
  __int64 v21; // [xsp+8h] [xbp-8h]

  v7 = (_DWORD *)_kmalloc_cache_noprof(__ratelimit, 3520, 1072);
  if ( !v7 )
    return -12;
  v8 = *(_BYTE **)(ipa3_ctx + 43800);
  if ( !v8 || *v8 != 1 )
    return 0;
  mutex_lock(ipa3_ctx + 29472);
  drop_stats = ipa_get_drop_stats(v7);
  if ( drop_stats )
  {
    v10 = drop_stats;
    mutex_unlock(ipa3_ctx + 29472);
    kfree(v7);
    return v10;
  }
  v20 = a3;
  v21 = a4;
  v12 = 0;
  v13 = 0;
  v14 = v7 + 1;
  while ( 1 )
  {
    ep_mapping = ipa_get_ep_mapping((unsigned int)v12);
    if ( (v12 & 1) != 0 )
    {
      v16 = ep_mapping;
      if ( ep_mapping != -1 && (v12 & 0xFE) != 0x3E && (v12 & 0xF8) != 0x40 )
      {
        ep_reg_idx = ipahal_get_ep_reg_idx(ep_mapping);
        if ( ep_reg_idx >= 2 )
          goto LABEL_27;
        v18 = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43800) + 4LL * ep_reg_idx + 63896);
        if ( ((unsigned int)ipahal_get_ep_bit(v16) & v18) != 0 )
          break;
      }
    }
LABEL_9:
    ++v12;
    v14 += 2;
    if ( v12 == 134 )
      goto LABEL_28;
  }
  if ( (unsigned __int8)v12 == 119 )
  {
    if ( v13 > 0x1000 )
      goto LABEL_27;
    v19 = scnprintf((char *)&dbg_buff_1 + v13, 4096 - v13, " IPA_CLIENT_WLAN2_LOWSPEED_CONS:\n");
  }
  else if ( (unsigned __int8)v12 == 13 )
  {
    if ( v13 > 0x1000 )
      goto LABEL_27;
    v19 = scnprintf((char *)&dbg_buff_1 + v13, 4096 - v13, "IPA_CLIENT_WLAN2_HIGHSPEED_CONS:\n");
  }
  else
  {
    if ( v13 > 0x1000 )
      goto LABEL_27;
    v19 = scnprintf((char *)&dbg_buff_1 + v13, 4096 - v13, "%s:\n", ipa_clients_strings[v12]);
  }
  v13 += v19;
  if ( v13 <= 0x1000 )
  {
    v13 += scnprintf((char *)&dbg_buff_1 + v13, 4096 - v13, "drop_byte_cnt=%u\n", *v14);
    if ( v13 <= 0x1000 )
    {
      v13 += scnprintf((char *)&dbg_buff_1 + v13, 4096 - v13, "drop_packet_cnt=%u\n", *(v14 - 1));
      if ( v13 <= 0x1000 )
      {
        v13 += scnprintf((char *)&dbg_buff_1 + v13, 4096 - v13, "\n");
        goto LABEL_9;
      }
    }
  }
LABEL_27:
  __break(0x5512u);
LABEL_28:
  mutex_unlock(ipa3_ctx + 29472);
  kfree(v7);
  return simple_read_from_buffer(a2, v20, v21, &dbg_buff_1, (int)v13);
}
