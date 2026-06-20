__int64 __fastcall batched_hyp_assign(
        __int64 *a1,
        unsigned int a2,
        _DWORD *a3,
        unsigned __int64 a4,
        __int64 a5,
        __int64 a6,
        char a7)
{
  __int64 v7; // x22
  __int64 v15; // x19
  __int64 v16; // x0
  unsigned int v17; // w10
  unsigned int v18; // w26
  __int64 v19; // x23
  __int64 v20; // x8
  unsigned __int64 v21; // x9
  __int64 v22; // x26
  __int64 v23; // x21
  unsigned __int64 v24; // x20
  _QWORD *v25; // x9
  __int64 v26; // x0
  __int64 v27; // x23
  __int64 v28; // x26
  unsigned int v29; // w23
  unsigned int v30; // w26
  const char *v31; // x0
  const char *v32; // x2
  __int64 v33; // x2
  __int64 v34; // x3
  unsigned int v35; // w0
  __int64 v36; // x2
  __int64 v37; // x3
  __int64 v39; // [xsp+28h] [xbp-38h]
  _DWORD *v40; // [xsp+30h] [xbp-30h]
  unsigned int v41; // [xsp+3Ch] [xbp-24h]
  unsigned __int64 v42; // [xsp+40h] [xbp-20h]
  unsigned int v43; // [xsp+5Ch] [xbp-4h]

  v7 = *a1;
  v15 = _kmalloc_cache_noprof(trace_event_raw_init, 3520, 512);
  if ( v15 )
  {
    v42 = a4;
    v16 = ((__int64 (*)(void))ktime_get)();
    if ( a2 )
    {
      v17 = 0;
      v39 = a6;
      v40 = a3;
      v18 = 0;
      _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v19 = *(unsigned int *)(v7 + 12);
        v43 = v18;
        v20 = 0;
        v21 = 0;
        v22 = 0;
        v41 = v17;
        do
        {
          v23 = v20;
          v24 = v21;
          if ( v15 + v20 )
          {
            v25 = (_QWORD *)(v15 + v20);
            *v25 = ((*(_QWORD *)v7 & 0x3FFFFFFFFFFFFFCLL) + ((memstart_addr >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6;
            v25[1] = v19;
            v19 = *(unsigned int *)(v7 + 12);
          }
          v26 = sg_next(v7);
          v7 = v26;
          if ( v24 > 0x1E )
            break;
          if ( !v26 )
            break;
          v22 += v19;
          v19 = *(unsigned int *)(v26 + 12);
          v21 = v24 + 1;
          v20 = v23 + 16;
        }
        while ( (unsigned __int64)(v22 + v19) < 0x200000 );
        v27 = qcom_secure_buffer_dev;
        v16 = is_vmalloc_addr(v15);
        if ( (v16 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
        {
          v30 = v16;
          dma_map_single_attrs___already_done = 1;
          v31 = (const char *)dev_driver_string(v27);
          v32 = *(const char **)(v27 + 112);
          if ( !v32 )
            v32 = *(const char **)v27;
          _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v31, v32);
          v16 = v30;
          __break(0x800u);
          if ( (v30 & 1) != 0 )
            goto LABEL_29;
        }
        else if ( (v16 & 1) != 0 )
        {
          goto LABEL_29;
        }
        v16 = dma_map_page_attrs(
                v27,
                ((unsigned __int64)((v15 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
                v15 & 0xFF8,
                v23 + 16,
                1,
                0);
        if ( v16 == -1 )
          goto LABEL_29;
        v28 = v16;
        ktime_get(v16);
        v29 = qcom_scm_assign_mem_regions(v15, v23 + 16, v40, v42, a5, v39);
        ((void (*)(void))ktime_get)();
        v16 = dma_unmap_page_attrs(qcom_secure_buffer_dev, v28, v23 + 16, 1, 0);
        if ( v29 )
          break;
        v17 = v41 + v24 + 1;
        v18 = v43 + 1;
        if ( v17 >= a2 )
          goto LABEL_30;
      }
      v16 = printk(&unk_9175, "batched_hyp_assign", v29, v43);
      if ( v41 && (a7 & 1) != 0 )
      {
        if ( v42 <= 4 && *v40 == 3 )
        {
          v35 = rollback_batched_assign(a1, v41 - 1, a5, v39);
          if ( !v35 )
          {
            v16 = printk(&unk_938F, "batched_hyp_assign", v36, v37);
            goto LABEL_30;
          }
          v16 = printk(&unk_931C, "batched_hyp_assign", v35, v37);
        }
        else
        {
          v16 = printk(&unk_9453, "batched_hyp_assign", v33, v34);
        }
LABEL_29:
        v29 = -99;
      }
    }
    else
    {
      v29 = 0;
    }
LABEL_30:
    ktime_get(v16);
    kfree(v15);
  }
  else
  {
    return (unsigned int)-12;
  }
  return v29;
}
