__int64 __fastcall ipa_debugfs_print_tethering_stats(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x22
  _BYTE *v8; // x9
  int teth_stats; // w0
  int v10; // w23
  __int64 v12; // x23
  unsigned int ep_mapping; // w0
  unsigned int v14; // w25
  unsigned int ep_reg_idx; // w0
  int v16; // w20
  int v17; // w0
  __int64 v18; // x26
  __int64 v19; // x0
  unsigned int v20; // w27
  unsigned int v21; // w0
  int v22; // w28
  int v23; // w0
  unsigned int v24; // w28
  unsigned int v25; // w28
  unsigned int v26; // w27
  unsigned int v27; // w27
  int v28; // w26
  __int64 v29; // [xsp+8h] [xbp-18h]
  __int64 v30; // [xsp+10h] [xbp-10h]

  v7 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 864);
  if ( !v7 )
    return -12;
  v8 = *(_BYTE **)(ipa3_ctx + 43800);
  if ( !v8 || *v8 != 1 || v8[64976] != 1 )
    return 0;
  mutex_lock(ipa3_ctx + 29472);
  teth_stats = ipa_get_teth_stats();
  if ( teth_stats )
  {
    v10 = teth_stats;
    mutex_unlock(ipa3_ctx + 29472);
    kfree(v7);
    return v10;
  }
  else
  {
    v29 = a2;
    v30 = a3;
    v12 = 0;
    LODWORD(a3) = 0;
    while ( 1 )
    {
      ep_mapping = ipa_get_ep_mapping((unsigned int)v12);
      if ( (v12 & 1) == 0 )
      {
        v14 = ep_mapping;
        if ( ep_mapping != -1 && v12 != 62 && (v12 & 0xF8) != 0x40 )
        {
          ep_reg_idx = ipahal_get_ep_reg_idx(ep_mapping);
          if ( ep_reg_idx >= 2 )
          {
LABEL_33:
            __break(0x5512u);
LABEL_34:
            mutex_unlock(ipa3_ctx + 29472);
            kfree(v7);
            return simple_read_from_buffer(v29, v30, a4, &dbg_buff_1, (int)a3);
          }
          v16 = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43800) + 4LL * ep_reg_idx + 880);
          if ( ((unsigned int)ipahal_get_ep_bit(v14) & v16) != 0 )
            break;
        }
      }
LABEL_9:
      if ( ++v12 == 134 )
        goto LABEL_34;
    }
    v17 = ((__int64 (__fastcall *)(_QWORD, __int64, _QWORD))ipa_query_teth_stats)((unsigned int)v12, v7, 0);
    if ( !v17 )
    {
      v18 = 0;
      while ( 1 )
      {
        v19 = ipa_get_ep_mapping((unsigned int)v18);
        if ( (_DWORD)v19 != -1 && (v18 & 0xFE) != 0x3E && (v18 & 0xF8) != 0x40 )
        {
          v20 = v19;
          v21 = ipahal_get_ep_reg_idx(v19);
          if ( v14 > 0x23 || v21 > 1 )
            goto LABEL_33;
          v22 = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43800) + 8LL * v14 + 4LL * v21 + 888);
          if ( ((unsigned int)ipahal_get_ep_bit(v20) & v22) != 0 )
          {
            if ( (unsigned int)a3 > 0x1000 )
              goto LABEL_33;
            v23 = scnprintf(
                    (char *)&dbg_buff_1 + (unsigned int)a3,
                    (unsigned int)(4096 - a3),
                    "%s->%s:\n",
                    ipa_clients_strings[v12],
                    ipa_clients_strings[v18]);
            if ( v20 > 0x23 )
              goto LABEL_33;
            v24 = v23 + a3;
            if ( (unsigned int)(v23 + a3) > 0x1000 )
              goto LABEL_33;
            a3 = v7 + 24LL * v20;
            v25 = scnprintf((char *)&dbg_buff_1 + v24, 4096 - v24, "num_ipv4_bytes=%llu\n", *(_QWORD *)a3) + v24;
            if ( v25 > 0x1000 )
              goto LABEL_33;
            v26 = scnprintf((char *)&dbg_buff_1 + v25, 4096 - v25, "num_ipv6_bytes=%llu\n", *(_QWORD *)(a3 + 8)) + v25;
            if ( v26 > 0x1000 )
              goto LABEL_33;
            v27 = scnprintf((char *)&dbg_buff_1 + v26, 4096 - v26, "num_ipv4_pkts=%u\n", *(_DWORD *)(a3 + 16)) + v26;
            if ( v27 > 0x1000 )
              goto LABEL_33;
            LODWORD(a3) = scnprintf((char *)&dbg_buff_1 + v27, 4096 - v27, "num_ipv6_pkts=%u\n", *(_DWORD *)(a3 + 20))
                        + v27;
            if ( (unsigned int)a3 > 0x1000 )
              goto LABEL_33;
            LODWORD(a3) = scnprintf((char *)&dbg_buff_1 + (unsigned int)a3, (unsigned int)(4096 - a3), "\n") + a3;
          }
        }
        if ( ++v18 == 134 )
          goto LABEL_9;
      }
    }
    v28 = v17;
    mutex_unlock(ipa3_ctx + 29472);
    kfree(v7);
    return v28;
  }
}
