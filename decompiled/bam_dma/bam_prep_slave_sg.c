__int64 __fastcall bam_prep_slave_sg(__int64 a1, __int64 a2, int a3, int a4, int a5)
{
  __int64 v5; // x19
  __int64 v11; // x0
  unsigned int v12; // w19
  int v13; // w26
  __int64 v14; // x0
  unsigned __int64 v15; // x23
  __int64 v16; // x0
  _QWORD *v17; // x1
  __int64 v18; // x22
  __int64 v19; // x0
  __int64 v20; // x25
  int v21; // w24
  __int64 v22; // x26
  __int64 v23; // x19
  __int64 v24; // x9
  _QWORD *v25; // x8
  int v26; // w10
  unsigned __int64 i; // x11
  unsigned __int64 v28; // x13
  char *v29; // x12
  bool v30; // cf
  bool v31; // w13
  __int64 v32; // x0
  __int64 v33; // x2
  __int64 v34; // x9

  v5 = *(_QWORD *)(a1 + 256);
  v11 = *(_QWORD *)(v5 + 536);
  if ( v11 )
    ipc_log_string(v11, "%s DMA direction:%d\n", "bam_prep_slave_sg", a4);
  _ftrace_dbg(*(_QWORD *)(v5 + 8), "%s DMA direction:%d\n");
  if ( (unsigned int)(a4 - 1) > 2 )
  {
    dev_err(*(_QWORD *)(v5 + 8), "invalid dma direction\n");
    return 0;
  }
  else
  {
    v12 = 0;
    if ( a3 )
    {
      v13 = a3;
      v14 = a2;
      do
      {
        v12 += (*(_DWORD *)(v14 + 24) + 32759) / 0x7FF8u;
        v14 = sg_next();
        --v13;
      }
      while ( v13 );
    }
    v15 = 8LL * v12 + 224;
    v16 = _kmalloc_noprof(v15, 10496);
    v18 = v16;
    if ( v16 )
    {
      if ( (a5 & 0x20) != 0 )
        *(_WORD *)(v16 + 176) |= 0x1000u;
      v19 = a2;
      if ( (a5 & 1) != 0 )
        *(_WORD *)(v18 + 176) |= 0x4000u;
      v20 = v18 + 224;
      *(_DWORD *)(v18 + 168) = v12;
      *(_QWORD *)(v18 + 184) = v18 + 224;
      *(_DWORD *)(v18 + 208) = a4;
      if ( a3 )
      {
        v21 = 0;
        v22 = 224;
        v23 = -32760;
        while ( 2 )
        {
          v24 = *(unsigned int *)(v19 + 24);
          v25 = nullptr;
          v26 = 0;
          for ( i = v15 - v22; ; i -= 8LL )
          {
            v28 = (unsigned __int64)v25 + v22;
            v29 = (char *)v25 + v20;
            if ( (a5 & 0x80) != 0 )
            {
              if ( v15 < v28 + 6 || i - 6 < 2 )
                goto LABEL_39;
              *((_WORD *)v29 + 3) |= 0x800u;
            }
            if ( v15 < v28 || i < 4 )
              goto LABEL_39;
            v30 = v15 >= v28 + 4 && i - 4 >= 2;
            v31 = !v30;
            *(_DWORD *)v29 = v26 + *(_DWORD *)(v19 + 16);
            if ( (unsigned int)v24 < 0x7FF9 )
              break;
            if ( v31 )
              goto LABEL_39;
            *((_WORD *)v29 + 2) = 32760;
            v26 += 32760;
            ++v25;
            v24 -= 32760;
            *(_QWORD *)(v18 + 216) += 32760LL;
          }
          if ( v31 )
          {
LABEL_39:
            __break(1u);
            goto LABEL_40;
          }
          ++v21;
          *(_WORD *)((char *)v25 + v20 + 4) = v24;
          v22 += (__int64)(v25 + 1);
          v20 += (__int64)(v25 + 1);
          *(_QWORD *)(v18 + 216) += v24;
          v19 = sg_next();
          if ( v21 != a3 )
            continue;
          break;
        }
      }
      v23 = a1;
      dma_async_tx_descriptor_init(v18, a1);
      *(_DWORD *)(v18 + 4) = a5;
      *(_QWORD *)(v18 + 24) = &vchan_tx_submit;
      *(_QWORD *)(v18 + 32) = &vchan_tx_desc_free;
      *(_QWORD *)(v18 + 144) = 0;
      v32 = raw_spin_lock_irqsave(a1 + 160);
      v25 = (_QWORD *)(v18 + 152);
      v33 = a1 + 168;
      v17 = *(_QWORD **)(a1 + 176);
      v34 = v32;
      if ( v18 + 152 == a1 + 168 || v17 == v25 || *v17 != v33 )
      {
LABEL_40:
        _list_add_valid_or_report(v25, v17);
      }
      else
      {
        *(_QWORD *)(a1 + 176) = v25;
        *(_QWORD *)(v18 + 152) = v33;
        *(_QWORD *)(v18 + 160) = v17;
        *v17 = v25;
      }
      raw_spin_unlock_irqrestore(v23 + 160, v34);
    }
  }
  return v18;
}
