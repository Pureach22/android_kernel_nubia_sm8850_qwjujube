__int64 __fastcall ipa3_ioctl_fnr_counter_query(unsigned __int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 v3; // x0
  unsigned __int64 v4; // x19
  __int64 v5; // x20
  unsigned int v6; // w21
  unsigned int v7; // w25
  unsigned int v8; // w20
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned __int64 v13; // x26
  __int64 v14; // x22
  unsigned __int64 v15; // x0
  unsigned __int64 v16; // x24
  size_t v17; // x21
  unsigned __int64 v18; // x26
  unsigned int v19; // w27
  unsigned int v20; // w28
  __int64 v21; // x23
  size_t v22; // x1
  size_t v23; // x8
  unsigned int flt_rt_stats; // w0
  unsigned __int64 v25; // x23
  __int64 v26; // x26
  __int64 v27; // x25
  __int64 v28; // x2
  __int64 v29; // x8
  unsigned __int64 v30; // x1
  unsigned __int64 v31; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v33; // x9
  unsigned __int64 v34; // x9
  unsigned __int64 v40; // x8
  unsigned __int64 v41; // x8
  unsigned __int64 v43; // x9
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x8
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x8
  __int64 v54; // x0
  __int64 v55; // x0
  unsigned __int64 v56; // [xsp+0h] [xbp-90h]
  size_t n[2]; // [xsp+8h] [xbp-88h] BYREF
  __int64 v58; // [xsp+18h] [xbp-78h]
  __int64 v59; // [xsp+20h] [xbp-70h]
  __int64 v60; // [xsp+28h] [xbp-68h]
  __int64 v61; // [xsp+30h] [xbp-60h]
  __int64 v62; // [xsp+38h] [xbp-58h]
  __int64 v63; // [xsp+40h] [xbp-50h]
  __int64 v64; // [xsp+48h] [xbp-48h]
  __int64 v65; // [xsp+50h] [xbp-40h]
  __int64 v66; // [xsp+58h] [xbp-38h]
  __int64 v67; // [xsp+60h] [xbp-30h]
  __int64 v68; // [xsp+68h] [xbp-28h]
  __int64 v69; // [xsp+70h] [xbp-20h]
  __int64 v70; // [xsp+78h] [xbp-18h]
  __int64 v71; // [xsp+80h] [xbp-10h]
  __int64 v72; // [xsp+88h] [xbp-8h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  v60 = 0;
  v61 = 0;
  v58 = 0;
  v59 = 0;
  n[0] = 0;
  n[1] = 0;
  if ( inline_copy_from_user((__int64)n, a1, 0x18u) )
  {
    if ( (unsigned int)__ratelimit(&ipa3_ioctl_fnr_counter_query__rs, "ipa3_ioctl_fnr_counter_query") )
      printk(&unk_3F47D5, "ipa3_ioctl_fnr_counter_query");
    v1 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v2 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v2 )
      {
        ipc_log_string(v2, "ipa %s:%d copy_from_user fails\n", "ipa3_ioctl_fnr_counter_query", 2419);
        v1 = ipa3_ctx;
      }
      v3 = *(_QWORD *)(v1 + 34160);
      if ( v3 )
        ipc_log_string(v3, "ipa %s:%d copy_from_user fails\n", "ipa3_ioctl_fnr_counter_query", 2419);
    }
    v4 = 0;
    v5 = 0;
    v6 = -14;
    goto LABEL_20;
  }
  v7 = BYTE1(n[0]) - LOBYTE(n[0]);
  v8 = v7 + 1;
  if ( v7 >= 0x20 )
  {
    printk(&unk_3C91DC, "ipa3_ioctl_fnr_counter_query");
    v47 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v48 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v48 )
      {
        ipc_log_string(
          v48,
          "ipa %s:%d IPA_IOC_FNR_COUNTER_QUERY failed: num %d\n",
          "ipa3_ioctl_fnr_counter_query",
          2429,
          v8);
        v47 = ipa3_ctx;
      }
      v49 = *(_QWORD *)(v47 + 34160);
      if ( v49 )
        ipc_log_string(
          v49,
          "ipa %s:%d IPA_IOC_FNR_COUNTER_QUERY failed: num %d\n",
          "ipa3_ioctl_fnr_counter_query",
          2429,
          v8);
    }
    goto LABEL_19;
  }
  if ( HIDWORD(n[0]) >= 0x11 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_ioctl_fnr_counter_query__rs_618, "ipa3_ioctl_fnr_counter_query") )
      printk(&unk_3FA7CC, "ipa3_ioctl_fnr_counter_query");
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d unexpected stats_size %d\n", "ipa3_ioctl_fnr_counter_query", 2436, HIDWORD(n[0]));
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(v11, "ipa %s:%d unexpected stats_size %d\n", "ipa3_ioctl_fnr_counter_query", 2436, HIDWORD(n[0]));
    }
LABEL_19:
    v4 = 0;
    v5 = 0;
    v6 = -1;
    goto LABEL_20;
  }
  v13 = v58;
  if ( !v58 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_ioctl_fnr_counter_query__rs_621, "ipa3_ioctl_fnr_counter_query") )
      printk(&unk_3DAAB1, "ipa3_ioctl_fnr_counter_query");
    v53 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v54 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v54 )
      {
        ipc_log_string(v54, "ipa %s:%d unexpected NULL rules\n", "ipa3_ioctl_fnr_counter_query", 2448);
        v53 = ipa3_ctx;
      }
      v55 = *(_QWORD *)(v53 + 34160);
      if ( v55 )
        ipc_log_string(v55, "ipa %s:%d unexpected NULL rules\n", "ipa3_ioctl_fnr_counter_query", 2448);
    }
    goto LABEL_19;
  }
  v14 = HIDWORD(n[0]) * v8;
  v15 = memdup_user(v58, v14);
  if ( v15 > 0xFFFFFFFFFFFFF000LL )
  {
    v5 = 0;
    v6 = -14;
    goto LABEL_21;
  }
  v16 = 16 * v8;
  v4 = v15;
  v5 = _kmalloc_noprof(v16, 3520);
  if ( v5 )
  {
    v17 = HIDWORD(n[0]);
    v56 = v13;
    v18 = 0;
    v19 = 0;
    v20 = 0;
    v21 = v7 + 1;
    do
    {
      if ( v16 >= v18 )
        v22 = v16 - v18;
      else
        v22 = 0;
      if ( v19 <= (unsigned int)v14 )
        v23 = v14 - v19;
      else
        v23 = 0;
      if ( v22 < v17 )
      {
        _fortify_panic(17, v22, v17);
LABEL_80:
        _fortify_panic(16, v22, v17);
LABEL_81:
        _fortify_panic(17, v30, v28);
LABEL_82:
        _fortify_panic(16, v30, v28);
      }
      if ( v23 < v17 )
        goto LABEL_80;
      memcpy((void *)(v5 + v18), (const void *)(v4 + v20), v17);
      --v21;
      v20 += v17;
      v19 += v17;
      v18 += 16LL;
    }
    while ( v21 );
    v58 = v5;
    flt_rt_stats = ipa_get_flt_rt_stats(n);
    if ( (flt_rt_stats & 0x80000000) != 0 )
    {
      printk(&unk_3A6047, "ipa3_ioctl_fnr_counter_query");
      v50 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_71;
      v51 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v51 )
      {
        ipc_log_string(v51, "ipa %s:%d ipa_get_flt_rt_stats failed\n", "ipa3_ioctl_fnr_counter_query", 2478);
        v50 = ipa3_ctx;
      }
      v52 = *(_QWORD *)(v50 + 34160);
      if ( v52 )
      {
        ipc_log_string(v52, "ipa %s:%d ipa_get_flt_rt_stats failed\n", "ipa3_ioctl_fnr_counter_query", 2478);
        v6 = -1;
      }
      else
      {
LABEL_71:
        v6 = -1;
      }
    }
    else
    {
      v6 = flt_rt_stats;
      v25 = 0;
      v26 = 0;
      v27 = v7 + 1;
      do
      {
        v28 = HIDWORD(n[0]);
        v29 = (unsigned int)(HIDWORD(n[0]) * v26);
        if ( (unsigned int)v29 <= (unsigned int)v14 )
          v30 = v14 - v29;
        else
          v30 = 0;
        if ( v30 < HIDWORD(n[0]) )
          goto LABEL_81;
        v31 = v16 - v25;
        if ( v16 < v25 )
          v31 = 0;
        if ( v31 < HIDWORD(n[0]) )
          goto LABEL_82;
        memcpy((void *)(v4 + (unsigned int)(HIDWORD(n[0]) * v26++)), (const void *)(v5 + v25), HIDWORD(n[0]));
        v25 += 16LL;
      }
      while ( v27 != v26 );
      _check_object_size(v4, v14, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v33 = v56, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v33 = v56 & ((__int64)(v56 << 8) >> 8);
      if ( 0x8000000000LL - v14 >= v33 )
      {
        v34 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v40 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v40 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v40);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v34);
        v14 = _arch_copy_to_user(v56 & 0xFF7FFFFFFFFFFFFFLL, v4, v14);
        v41 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v43 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v43 - 4096);
        _WriteStatusReg(TTBR1_EL1, v43);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v41);
      }
      if ( v14 )
      {
        if ( (unsigned int)__ratelimit(&ipa3_ioctl_fnr_counter_query__rs_627, "ipa3_ioctl_fnr_counter_query") )
          printk(&unk_3F1771, "ipa3_ioctl_fnr_counter_query");
        v44 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v45 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v45 )
          {
            ipc_log_string(v45, "ipa %s:%d copy_to_user fails\n", "ipa3_ioctl_fnr_counter_query", 2491);
            v44 = ipa3_ctx;
          }
          v46 = *(_QWORD *)(v44 + 34160);
          if ( v46 )
            ipc_log_string(v46, "ipa %s:%d copy_to_user fails\n", "ipa3_ioctl_fnr_counter_query", 2491);
        }
        v6 = -14;
      }
    }
  }
  else
  {
    v6 = -12;
  }
LABEL_20:
  kfree(v4);
LABEL_21:
  kfree(v5);
  _ReadStatusReg(SP_EL0);
  return v6;
}
