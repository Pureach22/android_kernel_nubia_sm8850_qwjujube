__int64 __fastcall ieee80211_check_fast_rx(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x22
  __int16 v4; // w8
  __int64 v5; // x21
  __int64 v6; // x10
  __int16 v7; // w11
  int v8; // w9
  int v9; // w8
  __int64 v10; // x20
  int v11; // w8
  int v12; // w8
  int v13; // w13
  char v14; // w9
  __int16 v15; // w10
  char v16; // w11
  __int64 v17; // x9
  int v18; // w3
  __int64 v19; // x8
  __int64 lock; // x0
  unsigned __int64 v21; // x8
  __int64 v22; // x8
  unsigned int v23; // w9
  void (__fastcall *v24)(__int64, __int64, __int64); // x8
  __int64 v25; // x20
  __int64 result; // x0
  __int64 v27; // x9
  __int64 v28; // x1
  unsigned __int64 v31; // x8
  unsigned __int64 v38; // x8
  __int64 v39; // [xsp+8h] [xbp-38h] BYREF
  int v40; // [xsp+10h] [xbp-30h]
  int v41; // [xsp+14h] [xbp-2Ch]
  __int16 v42; // [xsp+18h] [xbp-28h]
  int v43; // [xsp+1Ah] [xbp-26h]
  __int16 v44; // [xsp+1Eh] [xbp-22h]
  __int16 v45; // [xsp+20h] [xbp-20h]
  __int64 v46; // [xsp+22h] [xbp-1Eh]
  _WORD v47[11]; // [xsp+2Ah] [xbp-16h]

  *(_QWORD *)&v47[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *((_WORD *)&rfc1042_header + 2);
  v5 = *(_QWORD *)(a1 + 80);
  v46 = 0;
  v44 = v4;
  v6 = *(_QWORD *)(v5 + 1608);
  v43 = rfc1042_header;
  v7 = *(_WORD *)(v5 + 1940);
  v8 = *(_DWORD *)(v5 + 4720);
  v9 = *(_DWORD *)(v5 + 5842);
  *(_QWORD *)v47 = 0;
  v10 = *(_QWORD *)(v5 + 1616);
  *(_QWORD *)&v47[3] = 0;
  v39 = v6;
  v45 = v7;
  v40 = v8;
  v41 = v9;
  v42 = *(_WORD *)(v5 + 5846);
  v11 = HIDWORD(*(_QWORD *)(v10 + 96)) & 4;
  BYTE3(v46) = HIDWORD(*(_QWORD *)(v10 + 96)) & 4;
  if ( (*(_QWORD *)(v10 + 96) & 0x80) != 0 && (*(_QWORD *)(v10 + 96) & 0x200000000LL) == 0 )
    goto LABEL_31;
  if ( (unsigned int)(v8 - 3) >= 2 )
  {
    if ( v8 == 7 )
    {
      LOWORD(v46) = 768;
      WORD2(v46) = 6160;
      if ( (*(_QWORD *)(a1 + 216) & 8) == 0 )
        goto LABEL_31;
      goto LABEL_37;
    }
    if ( v8 != 2 )
      goto LABEL_31;
    v12 = *(unsigned __int8 *)(a1 + 2712);
    v13 = *(unsigned __int8 *)(v5 + 2524);
    BYTE4(v46) = 4;
    if ( v12 )
      v14 = 10;
    else
      v14 = 16;
    if ( v12 )
      v15 = 0;
    else
      v15 = 512;
    BYTE5(v46) = v14;
    LOWORD(v46) = v15;
    if ( v13 && (v12 & 1) == 0 )
    {
      LOWORD(v46) = 768;
      WORD2(v46) = 6160;
    }
    if ( *(_BYTE *)(v5 + 2496) == 1
      && ((*(_QWORD *)(v10 + 96) & 0x200) != 0
       || (*(_QWORD *)(v10 + 96) & 0x100) != 0 && (*(_QWORD *)(v10 + 96) & 0x400) == 0) )
    {
LABEL_31:
      v18 = 0;
      v2 = 0;
      if ( v5 )
        goto LABEL_32;
      goto LABEL_44;
    }
    goto LABEL_30;
  }
  if ( (*(_QWORD *)(v10 + 96) & 0x100000) == 0 )
    goto LABEL_31;
  v16 = *(_BYTE *)(v5 + 1624);
  WORD2(v46) = 2576;
  LOWORD(v46) = 256;
  if ( (v16 & 8) != 0 )
  {
    BYTE3(v46) = v11;
    if ( v8 != 4 )
      goto LABEL_30;
    v17 = *(_QWORD *)(v5 + 2280);
LABEL_28:
    if ( v17 )
    {
      BYTE3(v46) = v11;
      LOWORD(v46) = 768;
      BYTE5(v46) = 24;
    }
LABEL_30:
    if ( (*(_QWORD *)(a1 + 216) & 8) == 0 )
      goto LABEL_31;
    goto LABEL_37;
  }
  if ( v8 == 4 )
  {
    v17 = *(_QWORD *)(v5 + 2280);
    BYTE3(v46) = v11 | (2 * (v17 == 0));
    goto LABEL_28;
  }
  BYTE3(v46) = v11 | 2;
  if ( (*(_QWORD *)(a1 + 216) & 8) == 0 )
    goto LABEL_31;
LABEL_37:
  lock = _rcu_read_lock(a1, a2);
  v21 = *(unsigned __int8 *)(a1 + 120);
  if ( v21 >= 5 )
  {
    __break(0x5512u);
    goto LABEL_69;
  }
  v22 = *(_QWORD *)(a1 + 8 * v21 + 88);
  if ( v22 || (v22 = *(_QWORD *)(v5 + 1928)) != 0 )
  {
    v23 = *(_DWORD *)(v22 + 544) - 1027076;
    if ( v23 > 6 || ((1 << v23) & 0x71) == 0 )
    {
      _rcu_read_unlock(lock);
      goto LABEL_31;
    }
    WORD1(v46) = __PAIR16__(BYTE3(v46), *(_BYTE *)(v22 + 548)) | 0x100;
  }
  _rcu_read_unlock(lock);
  v2 = kmemdup_noprof(&v39, 48);
  v18 = 1;
  if ( v5 )
  {
LABEL_32:
    v19 = v5;
    if ( *(_DWORD *)(v5 + 4720) == 4 )
      v19 = *(_QWORD *)(v5 + 2032) - 2264LL;
    if ( !v18 )
      goto LABEL_69;
    goto LABEL_45;
  }
LABEL_44:
  v19 = 0;
  if ( !v18 )
    goto LABEL_69;
LABEL_45:
  if ( (*(_BYTE *)(v19 + 5876) & 4) != 0 )
  {
    _X9 = (unsigned __int64 *)(a1 + 216);
    __asm { PRFM            #0x11, [X9] }
    do
      v38 = __ldxr(_X9);
    while ( __stlxr(v38 | 0x8000000, _X9) );
    __dmb(0xBu);
    if ( (v38 & 0x8000000) != 0 )
      goto LABEL_59;
    goto LABEL_48;
  }
LABEL_69:
  _X9 = (unsigned __int64 *)(a1 + 216);
  __asm { PRFM            #0x11, [X9] }
  do
    v31 = __ldxr(_X9);
  while ( __stlxr(v31 & 0xFFFFFFFFF7FFFFFFLL, _X9) );
  __dmb(0xBu);
  if ( (v31 & 0x8000000) == 0 )
    goto LABEL_59;
LABEL_48:
  if ( v5 && *(_DWORD *)(v5 + 4720) == 4 )
    v5 = *(_QWORD *)(v5 + 2032) - 2264LL;
  if ( (*(_BYTE *)(*(_QWORD *)(v5 + 1616) + 1471LL) & 1) != 0
    || (*(_DWORD *)(v5 + 1624) & 0x20) != 0
    || (drv_sta_set_decap_offload___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(v5 + 1624) & 0x20) == 0 )
      goto LABEL_59;
  }
  else
  {
    v27 = *(_QWORD *)(v5 + 1608);
    drv_sta_set_decap_offload___already_done = 1;
    if ( v27 )
      v28 = v27 + 296;
    else
      v28 = v5 + 1640;
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v28);
    __break(0x800u);
    if ( (*(_BYTE *)(v5 + 1624) & 0x20) == 0 )
      goto LABEL_59;
  }
  v24 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v10 + 464) + 880LL);
  if ( v24 )
  {
    if ( *((_DWORD *)v24 - 1) != 1437441928 )
      __break(0x8228u);
    v24(v10, v5 + 4720, a1 + 2688);
  }
LABEL_59:
  raw_spin_lock_bh(a1 + 148);
  v25 = *(_QWORD *)(a1 + 160);
  atomic_store(v2, (unsigned __int64 *)(a1 + 160));
  result = raw_spin_unlock_bh(a1 + 148);
  if ( v25 )
    result = kvfree_call_rcu(v25 + 32, v25);
  _ReadStatusReg(SP_EL0);
  return result;
}
