__int64 __fastcall ipa_translate_rt_tbl_to_hw_fmt(
        unsigned int a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        int a6)
{
  __int64 v7; // x8
  __int64 *v8; // x19
  __int64 v9; // x28
  __int64 v12; // x23
  __int64 v14; // x26
  int v15; // w23
  int v16; // w24
  __int64 v17; // x24
  __int64 v18; // x25
  __int64 v19; // x24
  __int64 *v20; // x8
  __int64 *v21; // x9
  __int64 v22; // x10
  __int64 v23; // x11
  __int64 v24; // x9
  __int64 v25; // x10
  __int64 result; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // [xsp+0h] [xbp-30h]
  __int64 v43; // [xsp+8h] [xbp-28h]
  __int64 v44; // [xsp+10h] [xbp-20h] BYREF
  __int64 v45; // [xsp+18h] [xbp-18h]
  __int64 v46; // [xsp+20h] [xbp-10h]
  __int64 v47; // [xsp+28h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  v46 = 0;
  v44 = 0;
  if ( a1 >= 3 )
    __break(0x5512u);
  v7 = ipa3_ctx + 48LL * a1;
  v8 = *(__int64 **)(v7 + 29184);
  v9 = v7 + 29184;
  if ( v8 == (__int64 *)(v7 + 29184) )
  {
LABEL_28:
    result = 0;
    goto LABEL_45;
  }
  v12 = a3;
  v14 = a2;
  v42 = v7 + 29184;
  v43 = a5 - a3;
  while ( 1 )
  {
    v16 = *((_DWORD *)v8 + v14 + 25);
    if ( !v16 )
      goto LABEL_5;
    if ( *((_BYTE *)v8 + v14 + 96) != 1 )
      break;
    LODWORD(v46) = v16 - ((__int64 (*)(void))ipahal_get_hw_tbl_hdr_width)();
    LODWORD(v46) = v46 + ((__int64 (*)(void))ipahal_get_hw_prefetch_buf_size)();
    if ( (unsigned int)ipahal_fltrt_allocate_hw_sys_tbl(&v44) )
    {
      if ( (unsigned int)__ratelimit(&ipa_translate_rt_tbl_to_hw_fmt__rs, "ipa_translate_rt_tbl_to_hw_fmt") )
        printk(&unk_3BB221, "ipa_translate_rt_tbl_to_hw_fmt");
      v33 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v34 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v34 )
        {
          ipc_log_string(
            v34,
            "ipa %s:%d fail to alloc sys tbl of size %d\n",
            "ipa_translate_rt_tbl_to_hw_fmt",
            179,
            v46);
          v33 = ipa3_ctx;
        }
        v35 = *(_QWORD *)(v33 + 34160);
        if ( v35 )
          ipc_log_string(
            v35,
            "ipa %s:%d fail to alloc sys tbl of size %d\n",
            "ipa_translate_rt_tbl_to_hw_fmt",
            179,
            v46);
      }
      goto LABEL_44;
    }
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))ipahal_fltrt_write_addr_to_hdr)(
                         v45,
                         a4,
                         (unsigned int)(*((_DWORD *)v8 + 18) - a6),
                         1) )
    {
      if ( (unsigned int)__ratelimit(&ipa_translate_rt_tbl_to_hw_fmt__rs_180, "ipa_translate_rt_tbl_to_hw_fmt") )
        printk(&unk_3BDFE1, "ipa_translate_rt_tbl_to_hw_fmt");
      v39 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v40 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v40 )
        {
          ipc_log_string(v40, "ipa %s:%d fail to wrt sys tbl addr to hdr\n", "ipa_translate_rt_tbl_to_hw_fmt", 185);
          v39 = ipa3_ctx;
        }
        v41 = *(_QWORD *)(v39 + 34160);
        if ( v41 )
          ipc_log_string(v41, "ipa %s:%d fail to wrt sys tbl addr to hdr\n", "ipa_translate_rt_tbl_to_hw_fmt", 185);
      }
LABEL_43:
      ipahal_free_dma_mem(&v44);
      goto LABEL_44;
    }
    v17 = v8[3];
    if ( (__int64 *)v17 != v8 + 3 )
    {
      v18 = v44;
      do
      {
        if ( (*(_BYTE *)(v17 + 185) == 0) == a2 )
        {
          if ( (unsigned int)ipa_generate_rt_hw_rule(a1, v17, v18) )
          {
            if ( (unsigned int)__ratelimit(&ipa_translate_rt_tbl_to_hw_fmt__rs_183, "ipa_translate_rt_tbl_to_hw_fmt") )
              printk(&unk_3CA288, "ipa_translate_rt_tbl_to_hw_fmt");
            v30 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v31 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v31 )
              {
                ipc_log_string(v31, "ipa %s:%d failed to gen HW RT rule\n", "ipa_translate_rt_tbl_to_hw_fmt", 199);
                v30 = ipa3_ctx;
              }
              v32 = *(_QWORD *)(v30 + 34160);
              if ( v32 )
                ipc_log_string(v32, "ipa %s:%d failed to gen HW RT rule\n", "ipa_translate_rt_tbl_to_hw_fmt", 199);
            }
            goto LABEL_43;
          }
          v18 += *(unsigned int *)(v17 + 224);
        }
        v17 = *(_QWORD *)v17;
      }
      while ( (__int64 *)v17 != v8 + 3 );
    }
    v20 = &v8[3 * (unsigned int)v14];
    v9 = v42;
    if ( v20[15] )
    {
      v21 = &v8[3 * (unsigned int)v14];
      if ( v21[21] )
        __break(0x800u);
      v22 = v20[14];
      v23 = v20[15];
      v21[22] = v20[16];
      v21[20] = v22;
      v21[21] = v23;
    }
    v25 = v45;
    v24 = v46;
    v20[14] = v44;
    v20[15] = v25;
    v20[16] = v24;
LABEL_5:
    v8 = (__int64 *)*v8;
    if ( v8 == (__int64 *)v9 )
      goto LABEL_28;
  }
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))ipahal_fltrt_write_addr_to_hdr)(
                       v43 + v12,
                       a4,
                       *((unsigned int *)v8 + 18),
                       0) )
  {
    if ( (unsigned int)__ratelimit(&ipa_translate_rt_tbl_to_hw_fmt__rs_186, "ipa_translate_rt_tbl_to_hw_fmt") )
      printk(&unk_3BE00E, "ipa_translate_rt_tbl_to_hw_fmt");
    v36 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v37 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v37 )
      {
        ipc_log_string(v37, "ipa %s:%d fail to wrt lcl tbl ofst to hdr\n", "ipa_translate_rt_tbl_to_hw_fmt", 216);
        v36 = ipa3_ctx;
      }
      v38 = *(_QWORD *)(v36 + 34160);
      if ( v38 )
        ipc_log_string(v38, "ipa %s:%d fail to wrt lcl tbl ofst to hdr\n", "ipa_translate_rt_tbl_to_hw_fmt", 216);
    }
    goto LABEL_43;
  }
  v19 = v8[3];
  while ( 2 )
  {
    if ( (__int64 *)v19 == v8 + 3 )
    {
      v15 = v12 + ((__int64 (*)(void))ipahal_get_lcl_tbl_addr_alignment)();
      v12 = v15 & ~(unsigned int)((__int64 (*)(void))ipahal_get_lcl_tbl_addr_alignment)();
      goto LABEL_5;
    }
    if ( (*(_BYTE *)(v19 + 185) == 0) != a2 )
    {
LABEL_18:
      v19 = *(_QWORD *)v19;
      continue;
    }
    break;
  }
  if ( !(unsigned int)ipa_generate_rt_hw_rule(a1, v19, v12) )
  {
    v12 += *(unsigned int *)(v19 + 224);
    goto LABEL_18;
  }
  if ( (unsigned int)__ratelimit(&ipa_translate_rt_tbl_to_hw_fmt__rs_189, "ipa_translate_rt_tbl_to_hw_fmt") )
    printk(&unk_3CA288, "ipa_translate_rt_tbl_to_hw_fmt");
  v27 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v28 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v28 )
    {
      ipc_log_string(v28, "ipa %s:%d failed to gen HW RT rule\n", "ipa_translate_rt_tbl_to_hw_fmt", 228);
      v27 = ipa3_ctx;
    }
    v29 = *(_QWORD *)(v27 + 34160);
    if ( v29 )
      ipc_log_string(v29, "ipa %s:%d failed to gen HW RT rule\n", "ipa_translate_rt_tbl_to_hw_fmt", 228);
  }
LABEL_44:
  result = 0xFFFFFFFFLL;
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
