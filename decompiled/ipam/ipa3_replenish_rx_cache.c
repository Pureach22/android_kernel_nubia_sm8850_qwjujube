unsigned int *__fastcall ipa3_replenish_rx_cache(unsigned int *result)
{
  unsigned int v1; // w21
  unsigned int v2; // w20
  unsigned int *v3; // x19
  unsigned int v4; // w20
  unsigned int v5; // w26
  _QWORD *v6; // x0
  _QWORD *v7; // x21
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x25
  __int64 v13; // x23
  const char **v14; // x24
  char v15; // w0
  __int64 v16; // x0
  unsigned int v17; // w9
  __int64 *v18; // x8
  int v19; // w0
  const char *v20; // x0
  const char *v21; // x2
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  const void **v25; // x22
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  void (__fastcall *v29)(_QWORD); // x8
  __int64 v30; // x0
  int v31; // w19
  __int64 v32; // x8
  __int64 v33; // x0
  int v34; // w20
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x0
  char v38; // [xsp+4h] [xbp-37Ch]
  _QWORD s[110]; // [xsp+10h] [xbp-370h] BYREF

  s[108] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *result;
  v2 = result[41];
  if ( v2 - *result >= 0x14 )
  {
    v3 = result;
    memset(s, 0, 0x360u);
    if ( v2 <= v1 )
    {
      v4 = 0;
      v5 = v1;
LABEL_39:
      result = (unsigned int *)gsi_queue_xfer(*(_QWORD *)(*((_QWORD *)v3 + 203) + 8LL), v4, s, 1);
      if ( (_DWORD)result )
      {
        v31 = (int)result;
        result = (unsigned int *)printk(&unk_3D5757, "ipa3_replenish_rx_cache");
        v32 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v33 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v33 )
          {
            ipc_log_string(v33, "ipa %s:%d failed to provide buffer: %d\n", "ipa3_replenish_rx_cache", 3591, v31);
            v32 = ipa3_ctx;
          }
          result = *(unsigned int **)(v32 + 34160);
          if ( result )
            result = (unsigned int *)ipc_log_string(
                                       result,
                                       "ipa %s:%d failed to provide buffer: %d\n",
                                       "ipa3_replenish_rx_cache",
                                       3591,
                                       v31);
        }
        __break(0x800u);
      }
      else
      {
        *v3 = v5;
      }
    }
    else
    {
      v4 = 0;
      _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v5 = v1;
        v6 = (_QWORD *)kmem_cache_alloc_noprof(*(_QWORD *)(ipa3_ctx + 29448), 10496);
        v7 = v6;
        if ( !v6 )
          break;
        v6[6] = 0xFFFFFFFE00000LL;
        v6[7] = v6 + 7;
        v6[8] = v6 + 7;
        v8 = *((__int64 (__fastcall **)(__int64, __int64))v3 + 17);
        v9 = v3[40];
        v7[9] = ipa3_wq_rx_avail;
        v7[10] = v3;
        if ( *((_DWORD *)v8 - 1) != 993109518 )
          __break(0x8228u);
        v10 = v8(v9, 10240);
        v7[2] = v10;
        if ( !v10 )
        {
          printk(&unk_3CC773, "ipa3_replenish_rx_cache");
          v22 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v23 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v23 )
            {
              ipc_log_string(v23, "ipa %s:%d failed to alloc skb\n", "ipa3_replenish_rx_cache", 3533);
              v22 = ipa3_ctx;
            }
            v24 = *(_QWORD *)(v22 + 34160);
            if ( v24 )
              ipc_log_string(v24, "ipa %s:%d failed to alloc skb\n", "ipa3_replenish_rx_cache", 3533);
          }
          goto LABEL_37;
        }
        v11 = skb_put(v10, v3[40]);
        v12 = v3[40];
        v13 = v11;
        v14 = *(const char ***)(ipa3_ctx + 34216);
        v15 = is_vmalloc_addr(v11);
        if ( (v15 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
        {
          v38 = v15;
          dma_map_single_attrs___already_done = 1;
          v20 = (const char *)dev_driver_string(v14);
          v21 = v14[14];
          if ( !v21 )
            v21 = *v14;
          _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v20, v21);
          __break(0x800u);
          if ( (v38 & 1) != 0 )
          {
LABEL_28:
            v7[3] = -1;
            v25 = (const void **)(v7 + 3);
LABEL_29:
            printk(&unk_3D288A, "ipa3_replenish_rx_cache");
            v26 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v27 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v27 )
              {
                ipc_log_string(
                  v27,
                  "ipa %s:%d dma_map_single failure %pK for %pK\n",
                  "ipa3_replenish_rx_cache",
                  3542,
                  *v25,
                  (const void *)v13);
                v26 = ipa3_ctx;
              }
              v28 = *(_QWORD *)(v26 + 34160);
              if ( v28 )
                ipc_log_string(
                  v28,
                  "ipa %s:%d dma_map_single failure %pK for %pK\n",
                  "ipa3_replenish_rx_cache",
                  3542,
                  *v25,
                  (const void *)v13);
            }
            v29 = *((void (__fastcall **)(_QWORD))v3 + 18);
            v30 = v7[2];
            if ( *((_DWORD *)v29 - 1) != 303786302 )
              __break(0x8228u);
            v29(v30);
LABEL_37:
            kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29448), v7);
            break;
          }
        }
        else if ( (v15 & 1) != 0 )
        {
          goto LABEL_28;
        }
        v16 = dma_map_page_attrs(
                v14,
                ((unsigned __int64)((v13 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
                v13 & 0xFFF,
                v12,
                2,
                0);
        v7[3] = v16;
        if ( v16 == -1 )
        {
          v25 = (const void **)(v7 + 3);
          goto LABEL_29;
        }
        if ( v4 > 0x23 )
          __break(1u);
        v17 = v3[40];
        v18 = &s[3 * v4++];
        *v18 = v16;
        *((_WORD *)v18 + 4) = v17;
        *((_WORD *)v18 + 5) = 1792;
        *((_DWORD *)v18 + 3) = 0;
        v18[2] = (__int64)v7;
        if ( v4 == 36 )
        {
          v19 = gsi_queue_xfer(*(_QWORD *)(*((_QWORD *)v3 + 203) + 8LL), 36, s, 0);
          v4 = 0;
          if ( v19 )
          {
            v34 = v19;
            printk(&unk_3D5757, "ipa3_replenish_rx_cache");
            v35 = ipa3_ctx;
            ++v5;
            if ( ipa3_ctx )
            {
              v36 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v36 )
              {
                ipc_log_string(v36, "ipa %s:%d failed to provide buffer: %d\n", "ipa3_replenish_rx_cache", 3564, v34);
                v35 = ipa3_ctx;
              }
              v37 = *(_QWORD *)(v35 + 34160);
              if ( v37 )
                ipc_log_string(v37, "ipa %s:%d failed to provide buffer: %d\n", "ipa3_replenish_rx_cache", 3564, v34);
            }
            __break(0x800u);
            v4 = 36;
            goto LABEL_39;
          }
        }
        v1 = v5 + 1;
        if ( v5 + 1 >= v3[41] )
        {
          ++v5;
          goto LABEL_39;
        }
      }
      if ( v5 )
        goto LABEL_39;
      result = (unsigned int *)queue_delayed_work_on(32, *((_QWORD *)v3 + 219), v3 + 56, 1);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
