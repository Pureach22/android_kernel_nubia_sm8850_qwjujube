__int64 __fastcall ipa_get_generic_stats(unsigned __int64 a1)
{
  unsigned __int64 v1; // x24
  __int64 v3; // x21
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x19
  __int64 v6; // x8
  int v7; // w10
  _DWORD *v8; // x8
  int v9; // w8
  _DWORD *v10; // x22
  unsigned int drop_stats; // w0
  unsigned int v12; // w20
  __int64 v14; // x23
  _DWORD *v15; // x28
  _DWORD *v16; // x20
  __int64 ep_mapping; // x0
  unsigned int ep_reg_idx; // w0
  __int64 v19; // x8
  int v20; // w27
  unsigned __int64 v21; // x8
  _DWORD *v22; // x9
  __int64 v23; // x15
  _QWORD *v24; // x14
  _DWORD *v25; // x12
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x9
  unsigned __int64 v28; // x9
  unsigned __int64 v34; // x8
  __int64 v35; // x0
  unsigned __int64 v36; // x8
  unsigned __int64 v38; // x9
  __int64 v39; // x0
  __int64 ipc_logbuf; // x0
  __int64 v41; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v55; // x23
  unsigned __int64 v56; // [xsp+8h] [xbp-8h]

  if ( (dword_2011F8 & 1) == 0 )
  {
    v39 = printk(&unk_3ECB0D, "ipa_get_generic_stats");
    ipc_logbuf = ipa3_get_ipc_logbuf(v39);
    if ( ipc_logbuf )
    {
      v41 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(
                     v41,
                     "ipa-lnx-stats %s:%d Log type GENERIC mask not set\n",
                     "ipa_get_generic_stats",
                     142);
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( ipc_logbuf_low )
    {
      v43 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_log_string(v43, "ipa-lnx-stats %s:%d Log type GENERIC mask not set\n", "ipa_get_generic_stats", 142);
    }
    return 4294967282LL;
  }
  v3 = 16 * (dword_201200 + dword_2011FC) + 136;
  v4 = memdup_user(a1, v3);
  if ( v4 >= 0xFFFFFFFFFFFFF001LL )
  {
    v44 = printk(&unk_3C7866, "ipa_get_generic_stats");
    v45 = ipa3_get_ipc_logbuf(v44);
    if ( v45 )
    {
      v46 = ipa3_get_ipc_logbuf(v45);
      v45 = ipc_log_string(v46, "ipa-lnx-stats %s:%d copy from user failed", "ipa_get_generic_stats", 155);
    }
    v47 = ipa3_get_ipc_logbuf_low(v45);
    if ( v47 )
    {
      v48 = ipa3_get_ipc_logbuf_low(v47);
      ipc_log_string(v48, "ipa-lnx-stats %s:%d copy from user failed", "ipa_get_generic_stats", 155);
    }
    return 4294967284LL;
  }
  v5 = v4;
  v56 = a1;
  *(_DWORD *)v4 = *(_DWORD *)(ipa3_ctx + 32280);
  *(_DWORD *)(v4 + 4) = *(_DWORD *)(ipa3_ctx + 32284);
  if ( (_DWORD)v3 == 8 )
    goto LABEL_78;
  v6 = ipa3_ctx + 30552;
  *(_DWORD *)(v4 + 8) = *(_DWORD *)(ipa3_ctx + 32888);
  if ( (unsigned int)v3 < 0xC )
    goto LABEL_78;
  *(_DWORD *)(v4 + 12) = *(_DWORD *)(v6 + 1804);
  if ( (unsigned int)v3 < 0x10 )
    goto LABEL_78;
  *(_DWORD *)(v4 + 16) = *(_DWORD *)(v6 + 2276);
  if ( (unsigned int)v3 < 0x14 )
    goto LABEL_78;
  *(_DWORD *)(v4 + 20) = *(_DWORD *)v6;
  if ( (unsigned int)v3 < 0x19 )
    goto LABEL_78;
  *(_DWORD *)(v4 + 24) = *(_DWORD *)(v6 + 2288);
  if ( (unsigned int)v3 < 0x1C )
    goto LABEL_78;
  *(_DWORD *)(v4 + 28) = *(_DWORD *)(v6 + 2296);
  if ( (unsigned int)v3 < 0x20 )
    goto LABEL_78;
  *(_DWORD *)(v4 + 32) = *(_DWORD *)(v6 + 2308);
  if ( (unsigned int)v3 < 0x24 )
    goto LABEL_78;
  *(_DWORD *)(v4 + 36) = *(_DWORD *)(v6 + 2316);
  if ( (unsigned int)v3 < 0x29 )
    goto LABEL_78;
  *(_QWORD *)(v4 + 40) = *(_QWORD *)(v6 + 2360);
  if ( (unsigned int)v3 < 0x30 )
    goto LABEL_78;
  *(_QWORD *)(v4 + 48) = *(_QWORD *)(v6 + 2376);
  if ( (unsigned int)v3 < 0x39 )
    goto LABEL_78;
  *(_QWORD *)(v4 + 56) = *(_QWORD *)(v6 + 2384);
  if ( (unsigned int)v3 < 0x40 )
    goto LABEL_78;
  *(_QWORD *)(v4 + 64) = *(_QWORD *)(v6 + 2400);
  if ( (unsigned int)v3 < 0x49 )
    goto LABEL_78;
  *(_DWORD *)(v4 + 72) = *(_DWORD *)(v6 + 1740);
  if ( (unsigned int)v3 < 0x4C )
    goto LABEL_78;
  *(_DWORD *)(v4 + 76) = *(_DWORD *)(v6 + 1744);
  if ( (unsigned int)v3 < 0x50 )
    goto LABEL_78;
  *(_DWORD *)(v4 + 80) = *(_DWORD *)(v6 + 1748);
  if ( (unsigned int)v3 < 0x54 )
    goto LABEL_78;
  *(_DWORD *)(v4 + 84) = *(_DWORD *)(v6 + 1752);
  if ( (unsigned int)v3 < 0x59 )
    goto LABEL_78;
  *(_DWORD *)(v4 + 88) = *(_DWORD *)(v6 + 1756);
  if ( (unsigned int)v3 < 0x5C )
    goto LABEL_78;
  *(_DWORD *)(v4 + 92) = *(_DWORD *)(v6 + 1764);
  if ( (unsigned int)v3 < 0x60 )
    goto LABEL_78;
  *(_DWORD *)(v4 + 96) = *(_DWORD *)(v6 + 1768);
  if ( (unsigned int)v3 < 0x64 )
    goto LABEL_78;
  *(_DWORD *)(v4 + 100) = *(_DWORD *)(v6 + 1772);
  if ( (unsigned int)v3 < 0x69 )
    goto LABEL_78;
  *(_DWORD *)(v4 + 104) = *(_DWORD *)(v6 + 1776);
  if ( (unsigned int)v3 < 0x6C )
    goto LABEL_78;
  v7 = *(_DWORD *)(v6 + 1796);
  v8 = (_DWORD *)ipa3_odl_ctx;
  *(_DWORD *)(v4 + 108) = v7;
  if ( v8 )
  {
    if ( (unsigned int)v3 < 0x70 )
      goto LABEL_78;
    *(_DWORD *)(v4 + 112) = v8[175];
    if ( (unsigned int)v3 < 0x74 )
      goto LABEL_78;
    *(_DWORD *)(v4 + 116) = v8[176];
    if ( (unsigned int)v3 < 0x79 )
      goto LABEL_78;
    *(_DWORD *)(v4 + 120) = v8[177];
    v9 = v8[178];
    if ( (unsigned int)v3 < 0x7C )
      goto LABEL_78;
    *(_DWORD *)(v4 + 124) = v9;
  }
  if ( (unsigned int)v3 < 0x80
    || (v1 = (unsigned __int64)&unk_201000, *(_DWORD *)(v4 + 128) = dword_2011FC, (unsigned int)v3 < 0x84) )
  {
LABEL_78:
    __break(1u);
    goto LABEL_79;
  }
  *(_DWORD *)(v4 + 132) = dword_201200;
  v10 = (_DWORD *)_kmalloc_cache_noprof(__ratelimit, 3520, 1072);
  if ( v10 )
  {
    while ( 1 )
    {
      drop_stats = ipa_get_drop_stats(v10);
      if ( drop_stats )
      {
        v12 = drop_stats;
        kfree(v10);
        kfree(v5);
        return v12;
      }
      if ( *(_DWORD *)(v1 + 508) )
      {
        v14 = 0;
        v15 = (_DWORD *)(v5 + 136);
        v16 = v10 + 1;
        do
        {
          ep_mapping = ipa_get_ep_mapping((unsigned int)v14);
          if ( (_DWORD)ep_mapping != -1 && (v14 & 0xF9) != 0x41 && v14 != 63 && (v14 & 1) != 0 )
          {
            v1 = (unsigned int)ep_mapping;
            ep_reg_idx = ipahal_get_ep_reg_idx(ep_mapping);
            v19 = *(_QWORD *)(ipa3_ctx + 43800);
            if ( v19 )
            {
              if ( ep_reg_idx > 1 )
                goto LABEL_79;
              v20 = *(_DWORD *)(v19 + 4LL * ep_reg_idx + 63896);
              if ( ((unsigned int)ipahal_get_ep_bit((unsigned int)v1) & v20) != 0 )
              {
                *v15 = v14;
                v15[1] = *(v16 - 1);
                v15[2] = *v16;
                v15 += 4;
              }
            }
          }
          ++v14;
          v16 += 2;
        }
        while ( v14 != 134 );
      }
      if ( !dword_201200 || !*(_DWORD *)(v5 + 132) )
        break;
      v21 = 0;
      v22 = (_DWORD *)(v5 + 16LL * (unsigned int)dword_2011FC + 136);
      while ( v21 != 31 )
      {
        v23 = 36;
        v24 = (_QWORD *)(ipa3_ctx + 176);
        v25 = (_DWORD *)(ipa3_ctx + 272 * v21 + 34932);
        while ( *v24 != *(unsigned __int16 *)v25 )
        {
          --v23;
          v24 += 60;
          if ( !v23 )
            goto LABEL_51;
        }
        *v22 = *((_DWORD *)v24 - 1);
LABEL_51:
        ++v21;
        v22[1] = v25[65];
        v22[2] = v25[66];
        v22[3] = v25[67];
        v22 += 4;
        if ( v21 >= *(unsigned int *)(v5 + 132) )
          goto LABEL_57;
      }
LABEL_79:
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v55 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &ipa_get_generic_stats__alloc_tag;
      v10 = (_DWORD *)_kmalloc_cache_noprof(__ratelimit, 3520, 1072);
      *(_QWORD *)(StatusReg + 80) = v55;
      if ( !v10 )
        goto LABEL_80;
    }
LABEL_57:
    if ( (v3 & 0x80000000) != 0 )
    {
      __break(0x800u);
    }
    else
    {
      _check_object_size(v5, v3, 1);
      v26 = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(v26 + 70) & 0x20) != 0 || (v27 = v56, (*(_QWORD *)v26 & 0x4000000) != 0) )
        v27 = v56 & ((__int64)(v56 << 8) >> 8);
      if ( 0x8000000000LL - v3 >= v27 )
      {
        v28 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v34 = *(_QWORD *)(v26 + 8);
        _WriteStatusReg(TTBR1_EL1, v34 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v34);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v28);
        v35 = _arch_copy_to_user(v56 & 0xFF7FFFFFFFFFFFFFLL, v5, v3);
        v36 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v38 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v38 - 4096);
        _WriteStatusReg(TTBR1_EL1, v38);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v36);
        if ( !v35 )
        {
          kfree(v10);
          kfree(v5);
          return 0;
        }
      }
    }
    kfree(v5);
    kfree(v10);
    v49 = printk(&unk_3B576A, "ipa_get_generic_stats");
    v50 = ipa3_get_ipc_logbuf(v49);
    if ( v50 )
    {
      v51 = ipa3_get_ipc_logbuf(v50);
      v50 = ipc_log_string(v51, "ipa-lnx-stats %s:%d copy to user failed", "ipa_get_generic_stats", 289);
    }
    v52 = ipa3_get_ipc_logbuf_low(v50);
    if ( v52 )
    {
      v53 = ipa3_get_ipc_logbuf_low(v52);
      ipc_log_string(v53, "ipa-lnx-stats %s:%d copy to user failed", "ipa_get_generic_stats", 289);
    }
    return 4294967282LL;
  }
LABEL_80:
  kfree(v5);
  return 4294967284LL;
}
