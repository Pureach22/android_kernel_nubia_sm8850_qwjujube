__int64 __fastcall gsi_alloc_evt_ring(_DWORD *a1, __int64 a2, unsigned __int64 *a3)
{
  unsigned __int64 v3; // x21
  __int64 v4; // x23
  unsigned __int64 v5; // x24
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x4
  unsigned __int64 v12; // x20
  __int64 v13; // x9
  __int64 (__fastcall *v14)(); // x9
  __int64 v15; // x8
  long double v16; // q0
  __int64 v17; // x1
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x4
  unsigned __int64 first_zero_bit; // x0
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x9
  __int64 v24; // x8
  __int64 v25; // x8
  __int64 v26; // x9
  __int64 v27; // x9
  __int64 v28; // x8
  __int64 v29; // x10
  __int64 v30; // x11
  __int64 v31; // x8
  __int64 v32; // x9
  __int64 v33; // x10
  __int64 v34; // x11
  __int64 v35; // x8
  __int64 v36; // x10
  __int64 v37; // x11
  __int64 v38; // x8
  __int64 v39; // x10
  __int64 v40; // x11
  __int64 v41; // x8
  int v42; // w5
  __int64 v43; // x8
  unsigned int v44; // w9
  __int64 v45; // x11
  _QWORD *v46; // x9
  __int64 v47; // x22
  __int64 v48; // x2
  unsigned __int64 v49; // x3
  __int64 v50; // x1
  __int64 v51; // x2
  __int64 v52; // x3
  __int64 v53; // x4
  __int64 v54; // x22
  unsigned int ch_reg_idx; // w24
  __int64 v56; // x0
  __int64 v57; // x1
  __int64 v58; // x2
  unsigned int v59; // w19
  unsigned int v60; // w21
  __int64 v61; // x0
  __int64 v62; // x1
  __int64 v63; // x2
  __int64 result; // x0
  unsigned int v67; // w9
  unsigned __int64 v74; // x10
  unsigned __int64 v77; // x10
  unsigned __int64 v80; // x10
  unsigned __int64 v83; // x10
  unsigned __int64 v86; // x10
  unsigned __int64 v89; // x10
  _QWORD v90[2]; // [xsp+0h] [xbp-10h] BYREF

  v90[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v90[0] = 0;
  if ( !gsi_ctx )
  {
    printk(&unk_2DEB9, "gsi_alloc_evt_ring", 2233);
    result = 4294967288LL;
    goto LABEL_44;
  }
  if ( !a1 || !a3 || gsi_ctx != a2 )
  {
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d bad params props=%pK dev_hdl=0x%lx evt_ring_hdl=%pK\n",
      "gsi_alloc_evt_ring",
      2239,
      a1,
      a2,
      a3);
    result = 4294967290LL;
    goto LABEL_44;
  }
  if ( (unsigned int)gsi_validate_evt_ring_props(a1) )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d invalid params\n", "gsi_alloc_evt_ring", 2244);
    result = 4294967290LL;
    goto LABEL_44;
  }
  if ( (a1[28] & 1) != 0 )
  {
    v12 = *((unsigned __int8 *)a1 + 113);
  }
  else
  {
    mutex_lock(gsi_ctx + 28512, v8, v9, v10, v11);
    v13 = *(_QWORD *)(gsi_ctx + 28568);
    if ( v13 == -1 )
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d failed to alloc event ID\n", "gsi_alloc_evt_ring", 2253);
      goto LABEL_54;
    }
    v12 = __clz(__rbit64(~v13));
    _X8 = (unsigned __int64 *)(gsi_ctx + 28568);
    __asm { PRFM            #0x11, [X8] }
    do
      v74 = __ldxr(_X8);
    while ( __stxr(v74 | (1LL << v12), _X8) );
    mutex_unlock(gsi_ctx + 28512);
  }
  v14 = gsi_read_event_ring_rp_ddr;
  v15 = gsi_ctx;
  if ( !*((_QWORD *)a1 + 9) )
    v14 = gsi_read_event_ring_rp_reg;
  *((_QWORD *)a1 + 15) = v14;
  if ( v12 >= 0x20 )
    goto LABEL_59;
  v4 = v15 + 328LL * (unsigned int)v12;
  v3 = v4 + 18328;
  memset((void *)(v4 + 18328), 0, 0x148u);
  _mutex_init(v4 + 18536, "&ctx->mlock", &gsi_alloc_evt_ring___key, v16);
  *(_DWORD *)(v4 + 18584) = 0;
  _init_swait_queue_head(v4 + 18592, "&x->wait", &init_completion___key);
  *(_DWORD *)(v4 + 18636) = 0;
  *(_BYTE *)(v4 + 18632) = 0;
  *(_BYTE *)(v4 + 18460) = v12;
  mutex_lock(gsi_ctx + 28512, v17, v18, v19, v20);
  if ( *a1 != 2 )
    goto LABEL_26;
  v15 = (unsigned int)a1[1];
  if ( (_DWORD)v15 )
    goto LABEL_26;
  if ( (unsigned __int64)a1 > 0xFFFFFFFFFFFFF000LL
    || v4 == -18328
    || v3 > 0xFFFFFFFFFFFFF000LL
    || (v15 = gsi_ctx) == 0
    || (unsigned __int64)gsi_ctx >= 0xFFFFFFFFFFFFF001LL )
  {
LABEL_60:
    __break(0x800u);
LABEL_61:
    _X8 = (unsigned int *)(v15 + 28584);
    __asm { PRFM            #0x11, [X8] }
    do
      v67 = __ldxr(_X8);
    while ( __stxr(v67 + 1, _X8) );
    if ( *a1 == 4 )
    {
      v47 = raw_spin_lock_irqsave(v5, v8, v9, v10, v11);
      if ( *(_QWORD *)(v3 + 144) )
        memset(*(void **)(v3 + 144), 0, *(unsigned int *)(v3 + 192));
      v48 = *(unsigned __int8 *)(v3 + 132);
      v49 = *(_QWORD *)(v3 + 152)
          + ((unsigned int)*(unsigned __int16 *)(v3 + 198) + 2) * (unsigned __int64)*(unsigned __int8 *)(v3 + 196);
      *(_QWORD *)(v3 + 176) = v49;
      *(_QWORD *)(v3 + 160) = v49;
      gsihal_write_reg_nk(17, *(unsigned int *)(gsi_ctx + 20), v48);
      raw_spin_unlock_irqrestore(v5, v47);
    }
    else if ( *a1 == 2 )
    {
      gsi_prime_evt_ring(v3);
    }
    mutex_unlock(gsi_ctx + 28512);
    v54 = raw_spin_lock_irqsave(gsi_ctx + 28560, v50, v51, v52, v53);
    if ( *(_DWORD *)(gsi_ctx + 16) < 0xAu )
    {
      v56 = 20;
      v57 = (unsigned int)v4;
      v58 = 0;
    }
    else
    {
      ch_reg_idx = gsihal_get_ch_reg_idx((unsigned int)v12);
      gsihal_get_ch_reg_mask((unsigned int)v12);
      v56 = 133;
      v57 = (unsigned int)v4;
      v58 = ch_reg_idx;
    }
    gsihal_write_reg_nk(v56, v57, v58);
    v59 = *(_DWORD *)(gsi_ctx + 20);
    if ( *(_DWORD *)(gsi_ctx + 16) < 0xAu )
    {
      gsihal_read_reg_nk(3, v59, 0);
      v61 = 3;
      v62 = v59;
      v63 = 0;
    }
    else
    {
      v60 = gsihal_get_ch_reg_idx((unsigned int)v12);
      gsihal_get_ch_reg_mask((unsigned int)v12);
      gsihal_read_reg_nk(132, v59, v60);
      v61 = 132;
      v62 = v59;
      v63 = v60;
    }
    gsihal_write_reg_nk(v61, v62, v63);
    raw_spin_unlock_irqrestore(gsi_ctx + 28560, v54);
    result = 0;
    goto LABEL_44;
  }
  LODWORD(v4) = 28680;
  first_zero_bit = find_first_zero_bit(gsi_ctx + 28696, *(unsigned int *)(gsi_ctx + 28680));
  v15 = gsi_ctx;
  if ( first_zero_bit >= *(unsigned int *)(gsi_ctx + 28680) )
  {
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d No free MSIs for evt %u\n",
      "__gsi_pair_msi",
      2190,
      *(unsigned __int8 *)(v3 + 132));
    v15 = gsi_ctx;
    goto LABEL_56;
  }
  if ( ((*(_QWORD *)(gsi_ctx + 8 * ((unsigned __int64)(int)first_zero_bit >> 6) + 28688) >> first_zero_bit) & 1) == 0 )
  {
LABEL_56:
    dev_err(*(_QWORD *)(v15 + 8), "%s:%d evt_id=%lu failed to pair MSI\n", "gsi_alloc_evt_ring", 2292, v12);
    if ( (a1[28] & 1) == 0 )
    {
      _X9 = (unsigned __int64 *)(gsi_ctx + 28568);
      __asm { PRFM            #0x11, [X9] }
      do
        v89 = __ldxr(_X9);
      while ( __stxr(v89 & ~(1LL << v12), _X9) );
    }
    mutex_unlock(gsi_ctx + 28512);
    result = 4294967288LL;
    goto LABEL_44;
  }
  if ( first_zero_bit >= 2 )
  {
LABEL_59:
    __break(0x5512u);
    goto LABEL_60;
  }
  *(_DWORD *)(gsi_ctx + 4 * first_zero_bit + 28736) = *(unsigned __int8 *)(v3 + 132);
  v22 = *(unsigned __int8 *)(v3 + 132);
  v23 = v22 >> 6;
  v24 = 1LL << v22;
  _X9 = (unsigned __int64 *)(gsi_ctx + 28744 + 8 * v23);
  __asm { PRFM            #0x11, [X9] }
  do
    v77 = __ldxr(_X9);
  while ( __stxr(v77 | v24, _X9) );
  v25 = gsi_ctx;
  v26 = gsi_ctx + 12 * first_zero_bit;
  a1[9] = *(_DWORD *)(v26 + 28712);
  v27 = *(_QWORD *)(v26 + 28704);
  *((_QWORD *)a1 + 6) = v27;
  if ( v27 )
    v27 = 1LL << first_zero_bit;
  else
    __break(0x800u);
  _X8 = (unsigned __int64 *)(v25 + 28696);
  __asm { PRFM            #0x11, [X8] }
  do
    v80 = __ldxr(_X8);
  while ( __stxr(v80 | v27, _X8) );
LABEL_26:
  v28 = *((_QWORD *)a1 + 3);
  v29 = *(_QWORD *)a1;
  v30 = *((_QWORD *)a1 + 1);
  *(_QWORD *)(v3 + 16) = *((_QWORD *)a1 + 2);
  *(_QWORD *)(v3 + 24) = v28;
  *(_QWORD *)v3 = v29;
  *(_QWORD *)(v3 + 8) = v30;
  v32 = *((_QWORD *)a1 + 6);
  v31 = *((_QWORD *)a1 + 7);
  LODWORD(v90[0]) = 0;
  HIDWORD(v90[0]) = v12;
  v33 = *((_QWORD *)a1 + 4);
  v34 = *((_QWORD *)a1 + 5);
  *(_QWORD *)(v3 + 48) = v32;
  *(_QWORD *)(v3 + 56) = v31;
  *(_QWORD *)(v3 + 32) = v33;
  *(_QWORD *)(v3 + 40) = v34;
  v35 = *((_QWORD *)a1 + 11);
  v36 = *((_QWORD *)a1 + 8);
  v37 = *((_QWORD *)a1 + 9);
  *(_QWORD *)(v3 + 80) = *((_QWORD *)a1 + 10);
  *(_QWORD *)(v3 + 88) = v35;
  *(_QWORD *)(v3 + 64) = v36;
  *(_QWORD *)(v3 + 72) = v37;
  v38 = *((_QWORD *)a1 + 15);
  v39 = *((_QWORD *)a1 + 12);
  v40 = *((_QWORD *)a1 + 13);
  *(_QWORD *)(v3 + 112) = *((_QWORD *)a1 + 14);
  *(_QWORD *)(v3 + 120) = v38;
  v41 = gsi_ctx;
  *(_QWORD *)(v3 + 96) = v39;
  *(_QWORD *)(v3 + 104) = v40;
  LODWORD(v4) = *(_DWORD *)(v41 + 20);
  ((void (__fastcall *)(__int64, _QWORD, _QWORD *))gsihal_write_reg_n_fields)(47, (unsigned int)v4, v90);
  if ( (unsigned int)wait_for_completion_timeout(v3 + 256, 1250) )
  {
    v42 = *(_DWORD *)(v3 + 128);
    if ( v42 == 1 )
    {
      gsi_program_evt_ring_ctx(a1, (unsigned int)v12, *(unsigned int *)(gsi_ctx + 20));
      *(_DWORD *)(v3 + 136) = 0;
      v5 = v3 + 136;
      *(_QWORD *)(v3 + 144) = *((_QWORD *)a1 + 3);
      v43 = *((_QWORD *)a1 + 2);
      *(_QWORD *)(v3 + 152) = v43;
      *(_QWORD *)(v3 + 160) = v43;
      *(_QWORD *)(v3 + 168) = v43;
      *(_QWORD *)(v3 + 176) = v43;
      *(_QWORD *)(v3 + 184) = v43;
      v44 = a1[3];
      *(_DWORD *)(v3 + 192) = v44;
      v45 = (unsigned __int8)a1[2];
      *(_BYTE *)(v3 + 196) = a1[2];
      LOWORD(v44) = v44 / (unsigned int)v45 - 1;
      *(_WORD *)(v3 + 198) = v44;
      *(_QWORD *)(v3 + 200) = v45 + (unsigned int)v45 * (unsigned __int64)(unsigned __int16)v44 + v43;
      v46 = *((_QWORD **)a1 + 10);
      if ( v46 )
        *v46 = v43;
      *(_BYTE *)(v3 + 132) = v12;
      *a3 = v12;
      v15 = gsi_ctx;
      goto LABEL_61;
    }
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d evt_id=%lu allocation failed state=%u\n",
      "gsi_alloc_evt_ring",
      2317,
      v12,
      v42);
    if ( (a1[28] & 1) == 0 )
    {
      _X9 = (unsigned __int64 *)(gsi_ctx + 28568);
      __asm { PRFM            #0x11, [X9] }
      do
        v86 = __ldxr(_X9);
      while ( __stxr(v86 & ~(1LL << v12), _X9) );
    }
LABEL_54:
    mutex_unlock(gsi_ctx + 28512);
    result = 4294967292LL;
    goto LABEL_44;
  }
  dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d evt_id=%lu timed out\n", "gsi_alloc_evt_ring", 2308, v12);
  if ( (a1[28] & 1) == 0 )
  {
    _X9 = (unsigned __int64 *)(gsi_ctx + 28568);
    __asm { PRFM            #0x11, [X9] }
    do
      v83 = __ldxr(_X9);
    while ( __stxr(v83 & ~(1LL << v12), _X9) );
  }
  mutex_unlock(gsi_ctx + 28512);
  result = 4294967285LL;
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
