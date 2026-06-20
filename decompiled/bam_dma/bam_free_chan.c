__int64 __fastcall bam_free_chan(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x0
  __int64 result; // x0
  __int64 v5; // x1
  __int64 v6; // x9
  _QWORD *v7; // x10
  _QWORD *v8; // x11
  __int64 v9; // x9
  _QWORD *v10; // x10
  _QWORD *v11; // x11
  __int64 v12; // x9
  _QWORD *v13; // x10
  _QWORD *v14; // x11
  __int64 v15; // x9
  _QWORD *v16; // x10
  _QWORD *v17; // x11
  __int64 v18; // x9
  _QWORD *v19; // x10
  _QWORD *v20; // x11
  _QWORD *i; // x8
  __int64 v22; // x0
  __int64 v23; // x22
  __int64 v24; // x20
  unsigned int *v25; // x8
  __int64 v26; // x9
  _QWORD *v27; // x10
  int v28; // w0
  unsigned int *v29; // x8
  __int64 v30; // x0
  int v31; // w8
  int v32; // w0
  __int64 v33; // x19
  _QWORD *v34; // [xsp+8h] [xbp-18h] BYREF
  _QWORD *v35; // [xsp+10h] [xbp-10h]
  __int64 v36; // [xsp+18h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 256);
  v3 = *(_QWORD *)(v2 + 536);
  if ( v3 )
    ipc_log_string(v3, "%s chan id:%d\n", "bam_free_chan", *(_DWORD *)(a1 + 264));
  _ftrace_dbg(*(_QWORD *)(v2 + 8), "%s chan id:%d\n");
  result = _pm_runtime_resume(*(_QWORD *)(v2 + 8), 4);
  if ( (result & 0x80000000) == 0 )
  {
    v34 = &v34;
    v35 = &v34;
    v5 = raw_spin_lock_irqsave(a1 + 160);
    v6 = *(_QWORD *)(a1 + 168);
    if ( v6 != a1 + 168 )
    {
      v7 = v35;
      v8 = *(_QWORD **)(a1 + 176);
      *(_QWORD *)(v6 + 8) = v35;
      *v7 = v6;
      *v8 = &v34;
      v35 = v8;
      *(_QWORD *)(a1 + 168) = a1 + 168;
      *(_QWORD *)(a1 + 176) = a1 + 168;
    }
    v9 = *(_QWORD *)(a1 + 184);
    if ( v9 != a1 + 184 )
    {
      v10 = v35;
      v11 = *(_QWORD **)(a1 + 192);
      *(_QWORD *)(v9 + 8) = v35;
      *v10 = v9;
      *v11 = &v34;
      v35 = v11;
      *(_QWORD *)(a1 + 184) = a1 + 184;
      *(_QWORD *)(a1 + 192) = a1 + 184;
    }
    v12 = *(_QWORD *)(a1 + 200);
    if ( v12 != a1 + 200 )
    {
      v13 = v35;
      v14 = *(_QWORD **)(a1 + 208);
      *(_QWORD *)(v12 + 8) = v35;
      *v13 = v12;
      *v14 = &v34;
      v35 = v14;
      *(_QWORD *)(a1 + 200) = a1 + 200;
      *(_QWORD *)(a1 + 208) = a1 + 200;
    }
    v15 = *(_QWORD *)(a1 + 216);
    if ( v15 != a1 + 216 )
    {
      v16 = v35;
      v17 = *(_QWORD **)(a1 + 224);
      *(_QWORD *)(v15 + 8) = v35;
      *v16 = v15;
      *v17 = &v34;
      v35 = v17;
      *(_QWORD *)(a1 + 216) = a1 + 216;
      *(_QWORD *)(a1 + 224) = a1 + 216;
    }
    v18 = *(_QWORD *)(a1 + 232);
    if ( v18 != a1 + 232 )
    {
      v19 = v35;
      v20 = *(_QWORD **)(a1 + 240);
      *(_QWORD *)(v18 + 8) = v35;
      *v19 = v18;
      *v20 = &v34;
      v35 = v20;
      *(_QWORD *)(a1 + 232) = a1 + 232;
      *(_QWORD *)(a1 + 240) = a1 + 232;
    }
    for ( i = v34; i != &v34; i = (_QWORD *)*i )
      *((_DWORD *)i - 37) &= ~0x40u;
    raw_spin_unlock_irqrestore(a1 + 160, v5);
    vchan_dma_desc_free_list(a1, &v34);
    if ( *(_QWORD *)(a1 + 376) == a1 + 376 )
    {
      v22 = raw_spin_lock_irqsave(a1 + 160);
      v23 = *(_QWORD *)(a1 + 256);
      v24 = v22;
      writel_relaxed(
        1,
        *(_QWORD *)v23
      + *(unsigned int *)(*(_QWORD *)(v23 + 440) + 224LL)
      + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v23 + 440) + 228LL) * *(_DWORD *)(a1 + 264))
      + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v23 + 440) + 232LL) * *(_DWORD *)(a1 + 264))
      + (unsigned __int64)(unsigned int)(*(_DWORD *)(v23 + 424) * *(_DWORD *)(*(_QWORD *)(v23 + 440) + 236LL)));
      v25 = *(unsigned int **)(v23 + 440);
      writel_relaxed(
        0,
        *(_QWORD *)v23
      + v25[56]
      + v25[57] * *(_DWORD *)(a1 + 264)
      + v25[58] * *(_DWORD *)(a1 + 264)
      + (unsigned __int64)(*(_DWORD *)(v23 + 424) * v25[59]));
      __dsb(0xEu);
      *(_DWORD *)(a1 + 364) = 0;
      raw_spin_unlock_irqrestore(a1 + 160, v24);
      if ( (*(_BYTE *)(v2 + 532) & 1) != 0 )
      {
        v26 = *(unsigned int *)(v2 + 528);
        v27 = *(_QWORD **)(v2 + 504);
        *(_QWORD *)(v2 + 512) = *(_QWORD *)(v2 + 520);
        *v27 = v26;
      }
      else
      {
        dma_free_attrs(*(_QWORD *)(v2 + 8), 0x8000);
      }
      *(_QWORD *)(a1 + 344) = 0;
      *(_QWORD *)(a1 + 352) = 0;
      v28 = readl_relaxed(
              *(_QWORD *)v2
            + *(unsigned int *)(*(_QWORD *)(v2 + 440) + 192LL)
            + (unsigned int)(*(_DWORD *)(v2 + 424) * *(_DWORD *)(*(_QWORD *)(v2 + 440) + 204LL)));
      writel_relaxed(
        v28 & ~(unsigned int)(1LL << *(_DWORD *)(a1 + 264)),
        *(_QWORD *)v2
      + *(unsigned int *)(*(_QWORD *)(v2 + 440) + 192LL)
      + (unsigned int)(*(_DWORD *)(v2 + 424) * *(_DWORD *)(*(_QWORD *)(v2 + 440) + 204LL)));
      v29 = *(unsigned int **)(v2 + 440);
      v30 = writel_relaxed(
              0,
              *(_QWORD *)v2
            + v29[72]
            + v29[73] * *(_DWORD *)(a1 + 264)
            + v29[74] * *(_DWORD *)(a1 + 264)
            + (unsigned __int64)(*(_DWORD *)(v2 + 424) * v29[75]));
      v31 = *(_DWORD *)(v2 + 432) - 1;
      *(_DWORD *)(v2 + 432) = v31;
      if ( !v31 && *(_BYTE *)(v2 + 429) == 1 )
      {
        v32 = readl_relaxed(
                *(_QWORD *)v2
              + **(unsigned int **)(v2 + 440)
              + (unsigned int)(*(_DWORD *)(v2 + 424) * *(_DWORD *)(*(_QWORD *)(v2 + 440) + 12LL)));
        v30 = writel_relaxed(
                v32 | 1u,
                *(_QWORD *)v2
              + **(unsigned int **)(v2 + 440)
              + (unsigned int)(*(_DWORD *)(v2 + 424) * *(_DWORD *)(*(_QWORD *)(v2 + 440) + 12LL)));
      }
    }
    else
    {
      v30 = dev_err(*(_QWORD *)(*(_QWORD *)(a1 + 256) + 8LL), "Cannot free busy channel\n");
    }
    v33 = *(_QWORD *)(v2 + 8);
    *(_QWORD *)(v33 + 520) = ktime_get_mono_fast_ns(v30);
    result = _pm_runtime_suspend(*(_QWORD *)(v2 + 8), 13);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
