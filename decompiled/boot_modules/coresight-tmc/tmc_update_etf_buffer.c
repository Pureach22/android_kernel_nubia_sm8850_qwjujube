unsigned __int64 __fastcall tmc_update_etf_buffer(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x19
  __int64 v7; // x23
  __int64 v8; // x8
  int v9; // w0
  __int64 v10; // x8
  int v11; // w23
  __int64 v12; // x24
  __int64 v13; // x8
  unsigned int v14; // w0
  __int64 v15; // x8
  __int64 v16; // x24
  __int64 v17; // x25
  int v18; // w26
  unsigned __int64 v19; // x23
  __int64 v20; // x20
  unsigned int memwidth_mask; // w0
  __int64 v22; // x25
  __int64 v23; // x8
  unsigned __int64 v24; // x0
  unsigned __int64 v25; // x24
  unsigned __int64 v26; // x24
  int v27; // w27
  int *v28; // x25
  int v29; // w28
  bool v30; // cc
  __int64 v31; // x20
  int v32; // w0
  char v33; // w8
  int v34; // t1
  __int64 v35; // x8
  int v37; // w0
  _DWORD *v38; // x8
  __int64 v39; // x0
  _DWORD *v40; // x8
  _DWORD *v41; // x8
  _DWORD *v42; // x8

  if ( a3 )
  {
    v4 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
    if ( (unsigned int)*(_QWORD *)(a1 + 968) != 2 )
    {
      v19 = 0;
      __break(0x800u);
      return v19;
    }
    raw_spin_lock_irqsave(v4 + 104);
    if ( *(_BYTE *)(v4 + 408) != 1 || *(_DWORD *)(a1 + 976) != 1 )
    {
      v19 = 0;
LABEL_37:
      raw_spin_unlock_irqrestore(v4 + 104);
      return v19;
    }
    writel_relaxed_0(3316436565LL, *(_QWORD *)(v4 + 8) + 4016LL);
    __dsb(0xFu);
    tmc_flush_and_stop(v4);
    v7 = *(_QWORD *)(v4 + 16);
    v8 = *(_QWORD *)(v7 + 40);
    if ( *(_BYTE *)(v7 + 32) == 1 )
    {
      v9 = readl_relaxed_0((unsigned int *)(v8 + 20));
      v10 = *(_QWORD *)(v7 + 40);
      v11 = v9;
      readl_relaxed_0((unsigned int *)(v10 + 56));
    }
    else
    {
      if ( *(_DWORD *)(v8 - 4) != -340433967 )
        __break(0x8228u);
      v37 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v8)(20, 1, 0);
      v38 = *(_DWORD **)(v7 + 40);
      v11 = v37;
      if ( *(v38 - 1) != -340433967 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v38)(56, 1, 0);
    }
    v12 = *(_QWORD *)(v4 + 16);
    v13 = *(_QWORD *)(v12 + 40);
    if ( *(_BYTE *)(v12 + 32) == 1 )
    {
      v14 = readl_relaxed_0((unsigned int *)(v13 + 24));
      v15 = *(_QWORD *)(v12 + 40);
      v16 = v14;
      v17 = (unsigned int)readl_relaxed_0((unsigned int *)(v15 + 60));
    }
    else
    {
      if ( *(_DWORD *)(v13 - 4) != -340433967 )
        __break(0x8228u);
      v39 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v13)(24, 1, 0);
      v40 = *(_DWORD **)(v12 + 40);
      v16 = v39;
      if ( *(v40 - 1) != -340433967 )
        __break(0x8228u);
      v17 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v40)(60, 1, 0);
    }
    v18 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v4 + 8) + 12LL)) & 1;
    if ( v18 )
      v19 = *(unsigned int *)(v4 + 132);
    else
      v19 = ((_DWORD)v16 - v11) & (unsigned int)(*(_DWORD *)(v4 + 132) - 1);
    if ( (*(_BYTE *)(a3 + 32) & 1) == 0 && v19 > *(_QWORD *)(a2 + 24) )
    {
      v20 = v16 | (v17 << 32);
      memwidth_mask = tmc_get_memwidth_mask(v4);
      v22 = *(_QWORD *)(v4 + 16);
      v19 = *(_QWORD *)(a2 + 24) & memwidth_mask;
      v23 = *(unsigned int *)(v4 + 132);
      if ( v20 - v19 + v23 <= (unsigned int)(v23 - 1) )
        v24 = v20 - v19 + v23;
      else
        v24 = v20 - v19;
      v25 = HIDWORD(v24);
      if ( *(_BYTE *)(v22 + 32) != 1 )
      {
        v41 = *(_DWORD **)(v22 + 48);
        LOBYTE(v18) = 1;
        if ( *(v41 - 1) != -166272269 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD, __int64, __int64, _QWORD))v41)((unsigned int)v24, 20, 1, 0);
        v42 = *(_DWORD **)(v22 + 48);
        if ( *(v42 - 1) != -166272269 )
          __break(0x8228u);
        ((void (__fastcall *)(unsigned __int64, __int64, __int64, _QWORD))v42)(v25, 56, 1, 0);
        goto LABEL_22;
      }
      writel_relaxed_0(v24, *(_QWORD *)(v22 + 40) + 20LL);
      writel_relaxed_0((unsigned int)v25, *(_QWORD *)(v22 + 40) + 56LL);
      v18 = 1;
    }
    if ( !v18 )
    {
LABEL_24:
      if ( v19 )
      {
        v26 = *(_QWORD *)(a3 + 16);
        v27 = *(_DWORD *)a3;
        v28 = (int *)coresight_barrier_pkt;
        v29 = 4;
        do
        {
          v31 = *(_QWORD *)(*(_QWORD *)(a3 + 40) + 8LL * v27);
          v32 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v4 + 8) + 16LL));
          v33 = v18 ^ 1;
          *(_DWORD *)(v31 + v26) = v32;
          if ( (unsigned int)(v29 - 4) > 0xF )
            v33 = 1;
          if ( (v33 & 1) == 0 )
          {
            v34 = *v28++;
            *(_DWORD *)(v31 + v26) = v34;
          }
          v26 += 4LL;
          if ( v26 >= 0x1000 )
          {
            v26 = 0;
            v27 = (*(_DWORD *)(a3 + 4) - 1) & (v27 + 1);
          }
          v30 = v19 > v29;
          v29 += 4;
        }
        while ( v30 );
      }
      if ( *(_BYTE *)(a3 + 32) == 1 )
        *(_QWORD *)(a2 + 40) += v19;
      v35 = *(_QWORD *)(v4 + 8);
      __dsb(0xFu);
      writel_relaxed_0(0, v35 + 4016);
      goto LABEL_37;
    }
LABEL_22:
    if ( (*(_BYTE *)(a3 + 32) & 1) == 0 )
      perf_aux_output_flag(a2, 1);
    goto LABEL_24;
  }
  return 0;
}
