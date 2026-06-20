unsigned __int64 __fastcall tmc_update_etr_buffer(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x23
  _QWORD *v7; // x24
  __int64 v8; // x8
  unsigned __int64 v9; // x20
  size_t v10; // x22
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x9
  __int64 v13; // x10
  unsigned __int64 v14; // x8
  __int64 (__fastcall *v15)(__int64, size_t, __int64, void **); // x9
  __int64 v16; // x2
  _QWORD *v17; // x8
  __int64 v18; // x9
  __int64 v19; // x23
  __int64 v20; // x26
  unsigned __int64 v21; // x21
  unsigned __int64 v22; // x9
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x27
  unsigned __int64 v26; // x28
  size_t v27; // x8
  __int64 v28; // x9
  size_t v29; // x22
  unsigned __int64 v30; // x8
  __int64 (__fastcall *v31)(__int64, size_t, unsigned __int64, void **); // x9
  unsigned __int64 v32; // x2
  __int64 v33; // x0
  size_t v34; // x24
  char v36; // [xsp+4h] [xbp-1Ch]
  void *src[2]; // [xsp+10h] [xbp-10h] BYREF

  src[1] = *(void **)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a3 + 8);
  v7 = *(_QWORD **)(*(_QWORD *)(a1 + 152) + 152LL);
  raw_spin_lock_irqsave(v7 + 13);
  if ( *(_DWORD *)(a1 + 976) != 1 )
  {
    raw_spin_unlock_irqrestore(v7 + 13);
    v9 = 0;
    goto LABEL_47;
  }
  if ( v7[37] != v6 )
  {
    __break(0x800u);
    raw_spin_unlock_irqrestore(v7 + 13);
    v9 = 0;
LABEL_45:
    if ( (*(_BYTE *)(a3 + 20) & 1) == 0 )
      perf_aux_output_flag(a2, 1);
    goto LABEL_47;
  }
  writel_relaxed_1(0xC5ACCE55, (unsigned int *)(v7[1] + 4016LL));
  __dsb(0xFu);
  tmc_flush_and_stop((__int64)v7);
  tmc_sync_etr_buf(v7);
  v8 = v7[1];
  __dsb(0xFu);
  writel_relaxed_1(0, (unsigned int *)(v8 + 4016));
  raw_spin_unlock_irqrestore(v7 + 13);
  v10 = *(_QWORD *)(v6 + 32);
  v9 = *(_QWORD *)(v6 + 40);
  if ( (*(_BYTE *)(a3 + 20) & 1) == 0 && v9 > *(_QWORD *)(a2 + 24) )
  {
    v9 = *(_QWORD *)(a2 + 24) & (unsigned int)tmc_get_memwidth_mask((__int64)v7);
    v11 = *(_QWORD *)(v6 + 16);
    v12 = *(_QWORD *)(v6 + 32) - v9 + *(_QWORD *)(v6 + 40);
    if ( v12 >= v11 )
      v13 = *(_QWORD *)(v6 + 16);
    else
      v13 = 0;
    v10 = v12 - v13;
LABEL_12:
    v14 = v11 - v10;
    v15 = *(__int64 (__fastcall **)(__int64, size_t, __int64, void **))(*(_QWORD *)(v6 + 48) + 16LL);
    if ( v14 >= 0x10 )
      v16 = 16;
    else
      v16 = v14;
    src[0] = nullptr;
    if ( *((_DWORD *)v15 - 1) != -256312645 )
      __break(0x8229u);
    if ( v15(v6, v10, v16, src) <= 15 )
    {
      __break(0x800u);
    }
    else
    {
      v17 = src[0];
      if ( src[0] )
      {
        v18 = coresight_barrier_pkt[1];
        *(_QWORD *)src[0] = coresight_barrier_pkt[0];
        v17[1] = v18;
      }
    }
    v36 = 0;
    if ( !v9 )
      goto LABEL_42;
    goto LABEL_23;
  }
  if ( *(_BYTE *)(v6 + 8) )
  {
    v11 = *(_QWORD *)(v6 + 16);
    goto LABEL_12;
  }
  v36 = 1;
  if ( !v9 )
    goto LABEL_42;
LABEL_23:
  v19 = *(_QWORD *)(a3 + 8);
  v20 = *(_QWORD *)(a3 + 32);
  v21 = v9;
  v22 = *(_QWORD *)(a2 + 40);
  v23 = (__int64)*(int *)(a3 + 24) << 12;
  src[0] = nullptr;
  v24 = v22 % v23;
  v25 = v24 >> 12;
  v26 = v24 & 0xFFF;
  while ( 1 )
  {
    v27 = *(_QWORD *)(v19 + 16);
    if ( v10 >= v27 )
      v28 = *(_QWORD *)(v19 + 16);
    else
      v28 = 0;
    v29 = v10 - v28;
    v30 = v27 - v29;
    v31 = *(__int64 (__fastcall **)(__int64, size_t, unsigned __int64, void **))(*(_QWORD *)(v19 + 48) + 16LL);
    if ( v30 >= v21 )
      v32 = v21;
    else
      v32 = v30;
    if ( *((_DWORD *)v31 - 1) != -256312645 )
      __break(0x8229u);
    v33 = v31(v19, v29, v32, src);
    if ( v33 <= 0 )
      break;
    if ( v33 >= (__int64)(4096 - v26) )
      v34 = 4096 - v26;
    else
      v34 = v33;
    memcpy((void *)(*(_QWORD *)(v20 + 8 * v25) + v26), src[0], v34);
    v26 += v34;
    if ( v26 == 4096 )
    {
      v26 = 0;
      if ( v25 + 1 == *(_DWORD *)(a3 + 24) )
        v25 = 0;
      else
        ++v25;
    }
    v21 -= v34;
    v10 = v34 + v29;
    if ( !v21 )
      goto LABEL_42;
  }
  __break(0x800u);
LABEL_42:
  if ( *(_BYTE *)(a3 + 20) == 1 )
    *(_QWORD *)(a2 + 40) += v9;
  __dmb(0xAu);
  if ( (v36 & 1) == 0 )
    goto LABEL_45;
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return v9;
}
