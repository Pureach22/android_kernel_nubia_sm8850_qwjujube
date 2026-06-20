__int64 __fastcall ipa3_ioctl_add_rt_rule_after_v2(unsigned __int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x20
  unsigned __int64 v6; // x27
  __int64 v7; // x21
  unsigned int v8; // w22
  unsigned __int64 v9; // x22
  unsigned __int64 v10; // x26
  __int64 v11; // x24
  unsigned __int64 v12; // x0
  unsigned __int64 v14; // x0
  unsigned __int64 v15; // x25
  unsigned __int64 v16; // x27
  __int64 v17; // x19
  size_t v18; // x26
  unsigned int v19; // w28
  unsigned int v20; // w23
  size_t v21; // x1
  size_t v22; // x8
  int v23; // w23
  __int64 v24; // x2
  __int64 v25; // x8
  unsigned __int64 v26; // x1
  unsigned __int64 v27; // x8
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x8
  __int64 v41; // x0
  __int64 v42; // x0
  unsigned __int64 StatusReg; // x19
  __int64 v44; // x23
  unsigned int v45; // [xsp+8h] [xbp-98h]
  unsigned __int64 v46; // [xsp+10h] [xbp-90h]
  _QWORD v47[5]; // [xsp+18h] [xbp-88h] BYREF
  __int64 v48; // [xsp+40h] [xbp-60h]
  size_t n; // [xsp+48h] [xbp-58h]
  unsigned __int64 v50; // [xsp+50h] [xbp-50h]
  __int64 v51; // [xsp+58h] [xbp-48h]
  __int64 v52; // [xsp+60h] [xbp-40h]
  __int64 v53; // [xsp+68h] [xbp-38h]
  __int64 v54; // [xsp+70h] [xbp-30h]
  __int64 v55; // [xsp+78h] [xbp-28h]
  __int64 v56; // [xsp+80h] [xbp-20h]
  __int64 v57; // [xsp+88h] [xbp-18h]
  __int64 v58; // [xsp+90h] [xbp-10h]
  __int64 v59; // [xsp+98h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  n = 0;
  v50 = 0;
  v48 = 0;
  memset(v47, 0, sizeof(v47));
  if ( inline_copy_from_user((__int64)v47, a1, 0x40u) )
  {
    if ( (unsigned int)__ratelimit(&ipa3_ioctl_add_rt_rule_after_v2__rs, "ipa3_ioctl_add_rt_rule_after_v2") )
      printk(&unk_3F47D5, "ipa3_ioctl_add_rt_rule_after_v2");
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(v3, "ipa %s:%d copy_from_user fails\n", "ipa3_ioctl_add_rt_rule_after_v2", 1809);
        v2 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v2 + 34160);
      if ( v4 )
        ipc_log_string(v4, "ipa %s:%d copy_from_user fails\n", "ipa3_ioctl_add_rt_rule_after_v2", 1809);
    }
    v5 = 0;
    v6 = 0;
    goto LABEL_10;
  }
  if ( (unsigned int)n >= 0xBD )
  {
    if ( (unsigned int)__ratelimit(&ipa3_ioctl_add_rt_rule_after_v2__rs_556, "ipa3_ioctl_add_rt_rule_after_v2") )
      printk(&unk_3E2FB4, "ipa3_ioctl_add_rt_rule_after_v2");
    v34 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v35 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v35 )
      {
        ipc_log_string(v35, "ipa %s:%d unexpected rule_add_size %d\n", "ipa3_ioctl_add_rt_rule_after_v2", 1821, n);
        v34 = ipa3_ctx;
      }
      v36 = *(_QWORD *)(v34 + 34160);
      if ( v36 )
        ipc_log_string(v36, "ipa %s:%d unexpected rule_add_size %d\n", "ipa3_ioctl_add_rt_rule_after_v2", 1821, n);
    }
    goto LABEL_77;
  }
  v9 = v50;
  if ( !v50 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_ioctl_add_rt_rule_after_v2__rs_557, "ipa3_ioctl_add_rt_rule_after_v2") )
      printk(&unk_3DAAB1, "ipa3_ioctl_add_rt_rule_after_v2");
    v37 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v38 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v38 )
      {
        ipc_log_string(v38, "ipa %s:%d unexpected NULL rules\n", "ipa3_ioctl_add_rt_rule_after_v2", 1834);
        v37 = ipa3_ctx;
      }
      v39 = *(_QWORD *)(v37 + 34160);
      if ( v39 )
        ipc_log_string(v39, "ipa %s:%d unexpected NULL rules\n", "ipa3_ioctl_add_rt_rule_after_v2", 1834);
    }
LABEL_77:
    v5 = 0;
    v6 = 0;
    v7 = 0;
    v8 = -1;
    goto LABEL_11;
  }
  LODWORD(v10) = (unsigned __int8)v48;
  v11 = (unsigned int)n * (unsigned __int8)v48;
  v12 = memdup_user(v50, v11);
  if ( v12 <= 0xFFFFFFFFFFFFF000LL )
  {
    v5 = v12;
    v14 = memdup_user(a1, 64);
    v6 = v14;
    if ( v14 > 0xFFFFFFFFFFFFF000LL )
    {
LABEL_10:
      v7 = 0;
      v8 = -14;
      goto LABEL_11;
    }
    if ( *(unsigned __int8 *)(v14 + 40) != (_DWORD)v10 )
    {
      if ( (unsigned int)__ratelimit(&ipa3_ioctl_add_rt_rule_after_v2__rs_558, "ipa3_ioctl_add_rt_rule_after_v2") )
        printk(&unk_3A8F59, "ipa3_ioctl_add_rt_rule_after_v2");
      v40 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v41 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v41 )
        {
          ipc_log_string(
            v41,
            "ipa %s:%d current %d pre %d\n",
            "ipa3_ioctl_add_rt_rule_after_v2",
            1858,
            *(unsigned __int8 *)(v6 + 40),
            v10);
          v40 = ipa3_ctx;
        }
        v42 = *(_QWORD *)(v40 + 34160);
        if ( v42 )
          ipc_log_string(
            v42,
            "ipa %s:%d current %d pre %d\n",
            "ipa3_ioctl_add_rt_rule_after_v2",
            1858,
            *(unsigned __int8 *)(v6 + 40),
            v10);
      }
      goto LABEL_10;
    }
    v15 = (unsigned int)(188 * v10);
    v7 = _kmalloc_noprof(v15, 3520);
    if ( v7 )
    {
      while ( (_DWORD)v10 )
      {
        v45 = v10;
        v46 = v6;
        v16 = 0;
        v17 = 188LL * (unsigned int)v10;
        v18 = (unsigned int)n;
        v19 = 0;
        v20 = 0;
        do
        {
          if ( v15 >= v16 )
            v21 = v15 - v16;
          else
            v21 = 0;
          if ( v19 <= (unsigned int)v11 )
            v22 = v11 - v19;
          else
            v22 = 0;
          if ( v21 < v18 )
          {
            _fortify_panic(17, v21, v18);
LABEL_86:
            _fortify_panic(16, v21, v18);
          }
          if ( v22 < v18 )
            goto LABEL_86;
          memcpy((void *)(v7 + v16), (const void *)(v5 + v20), v18);
          v16 += 188LL;
          v20 += v18;
          v19 += v18;
        }
        while ( v17 != v16 );
        v50 = v7;
        v6 = v46;
        if ( (unsigned int)ipa3_add_rt_rule_after_v2(v47) )
          goto LABEL_45;
        v10 = 0;
        v23 = 0;
        while ( 1 )
        {
          v24 = (unsigned int)n;
          v25 = (unsigned int)(n * v23);
          v26 = (unsigned int)v25 <= (unsigned int)v11 ? v11 - v25 : 0LL;
          if ( v26 < (unsigned int)n )
            break;
          v27 = v15 - v10;
          if ( v15 < v10 )
            v27 = 0;
          if ( v27 < (unsigned int)n )
            goto LABEL_88;
          memcpy((void *)(v5 + (unsigned int)(n * v23)), (const void *)(v7 + v10), (unsigned int)n);
          v10 += 188LL;
          ++v23;
          if ( 188LL * v45 == v10 )
            goto LABEL_53;
        }
        _fortify_panic(17, v26, (unsigned int)n);
LABEL_88:
        _fortify_panic(16, v26, v24);
        StatusReg = _ReadStatusReg(SP_EL0);
        v44 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &ipa3_ioctl_add_rt_rule_after_v2__alloc_tag;
        v7 = _kmalloc_noprof(v15, 3520);
        *(_QWORD *)(StatusReg + 80) = v44;
        if ( !v7 )
          goto LABEL_89;
      }
      v50 = v7;
      if ( !(unsigned int)ipa3_add_rt_rule_after_v2(v47) )
      {
LABEL_53:
        _check_object_size(v5, v11, 1);
        if ( inline_copy_to_user(v9, v5, v11) )
        {
          if ( (unsigned int)__ratelimit(&ipa3_ioctl_add_rt_rule_after_v2__rs_565, "ipa3_ioctl_add_rt_rule_after_v2") )
            printk(&unk_3F1771, "ipa3_ioctl_add_rt_rule_after_v2");
          v31 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v32 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v32 )
            {
              ipc_log_string(v32, "ipa %s:%d copy_to_user fails\n", "ipa3_ioctl_add_rt_rule_after_v2", 1893);
              v31 = ipa3_ctx;
            }
            v33 = *(_QWORD *)(v31 + 34160);
            if ( v33 )
              ipc_log_string(v33, "ipa %s:%d copy_to_user fails\n", "ipa3_ioctl_add_rt_rule_after_v2", 1893);
          }
          v8 = -14;
        }
        else
        {
          v8 = 0;
        }
        goto LABEL_11;
      }
LABEL_45:
      if ( (unsigned int)__ratelimit(&ipa3_ioctl_add_rt_rule_after_v2__rs_560, "ipa3_ioctl_add_rt_rule_after_v2") )
        printk(&unk_3C0198, "ipa3_ioctl_add_rt_rule_after_v2");
      v28 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v29 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v29 )
        {
          ipc_log_string(v29, "ipa %s:%d ipa3_add_rt_rule_after_v2 fails\n", "ipa3_ioctl_add_rt_rule_after_v2", 1880);
          v28 = ipa3_ctx;
        }
        v30 = *(_QWORD *)(v28 + 34160);
        if ( v30 )
          ipc_log_string(v30, "ipa %s:%d ipa3_add_rt_rule_after_v2 fails\n", "ipa3_ioctl_add_rt_rule_after_v2", 1880);
      }
      v8 = -1;
    }
    else
    {
LABEL_89:
      v8 = -12;
    }
LABEL_11:
    kfree(v5);
    if ( v6 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_18;
    goto LABEL_17;
  }
  v7 = 0;
  v6 = 0;
  v8 = -14;
LABEL_17:
  kfree(v6);
LABEL_18:
  kfree(v7);
  _ReadStatusReg(SP_EL0);
  return v8;
}
