__int64 __fastcall ipa_debugfs_print_quota_stats(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  char *v7; // x22
  _BYTE *v8; // x9
  int quota_stats; // w0
  int v10; // w23
  __int64 v12; // x23
  char *v13; // x27
  __int64 ep_mapping; // x0
  unsigned int v15; // w25
  unsigned int ep_reg_idx; // w0
  int v17; // w19
  int v18; // w0
  unsigned int v19; // w19
  unsigned int v20; // w19
  unsigned int v21; // w19
  unsigned int v22; // w19
  unsigned int v23; // w19

  v7 = (char *)_kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 864);
  if ( !v7 )
    return -12;
  v8 = *(_BYTE **)(ipa3_ctx + 43800);
  if ( !v8 || *v8 != 1 )
    return 0;
  mutex_lock(ipa3_ctx + 29472);
  quota_stats = ipa_get_quota_stats(v7);
  if ( quota_stats )
  {
    v10 = quota_stats;
    mutex_unlock(ipa3_ctx + 29472);
    kfree(v7);
    return v10;
  }
  v12 = 0;
  LODWORD(v13) = 0;
  while ( 1 )
  {
    ep_mapping = ipa_get_ep_mapping((unsigned int)v12);
    if ( (_DWORD)ep_mapping != -1 && (v12 & 0xFE) != 0x3E && (v12 & 0xF8) != 0x40 )
    {
      v15 = ep_mapping;
      ep_reg_idx = ipahal_get_ep_reg_idx(ep_mapping);
      if ( ep_reg_idx >= 2 )
        goto LABEL_22;
      v17 = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43800) + 4LL * ep_reg_idx + 8);
      if ( ((unsigned int)ipahal_get_ep_bit(v15) & v17) != 0 )
        break;
    }
LABEL_9:
    if ( ++v12 == 134 )
      goto LABEL_23;
  }
  if ( (unsigned int)v13 <= 0x1000 )
  {
    v18 = scnprintf(
            (char *)&dbg_buff_1 + (unsigned int)v13,
            (unsigned int)(4096 - (_DWORD)v13),
            "%s:\n",
            ipa_clients_strings[v12]);
    if ( v15 <= 0x23 )
    {
      v19 = v18 + (_DWORD)v13;
      if ( (unsigned int)(v18 + (_DWORD)v13) <= 0x1000 )
      {
        v13 = &v7[24 * v15];
        v20 = scnprintf((char *)&dbg_buff_1 + v19, 4096 - v19, "num_ipv4_bytes=%llu\n", *(_QWORD *)v13) + v19;
        if ( v20 <= 0x1000 )
        {
          v21 = scnprintf((char *)&dbg_buff_1 + v20, 4096 - v20, "num_ipv6_bytes=%llu\n", *((_QWORD *)v13 + 1)) + v20;
          if ( v21 <= 0x1000 )
          {
            v22 = scnprintf((char *)&dbg_buff_1 + v21, 4096 - v21, "num_ipv4_pkts=%u\n", *((_DWORD *)v13 + 4)) + v21;
            if ( v22 <= 0x1000 )
            {
              v23 = scnprintf((char *)&dbg_buff_1 + v22, 4096 - v22, "num_ipv6_pkts=%u\n", *((_DWORD *)v13 + 5)) + v22;
              if ( v23 <= 0x1000 )
              {
                LODWORD(v13) = scnprintf((char *)&dbg_buff_1 + v23, 4096 - v23, "\n") + v23;
                goto LABEL_9;
              }
            }
          }
        }
      }
    }
  }
LABEL_22:
  __break(0x5512u);
LABEL_23:
  mutex_unlock(ipa3_ctx + 29472);
  kfree(v7);
  return simple_read_from_buffer(a2, a3, a4, &dbg_buff_1, (int)v13);
}
