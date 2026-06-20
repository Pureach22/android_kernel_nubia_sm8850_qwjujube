__int64 __fastcall ipa_translate_flt_tbl_to_hw_fmt(
        unsigned int a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5)
{
  __int64 v5; // x21
  unsigned __int64 v8; // x23
  unsigned int v9; // w24
  __int64 v11; // x19
  __int64 *v12; // x28
  int v13; // w25
  __int64 v14; // x25
  __int64 v15; // x26
  __int64 *v16; // x8
  __int64 *v17; // x9
  __int64 v18; // x10
  __int64 v19; // x11
  __int64 v20; // x9
  __int64 v21; // x11
  __int64 v22; // x25
  int v23; // w21
  __int64 result; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
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
  __int64 v40; // [xsp+0h] [xbp-30h]
  __int64 v42; // [xsp+10h] [xbp-20h] BYREF
  __int64 v43; // [xsp+18h] [xbp-18h]
  __int64 v44; // [xsp+20h] [xbp-10h]
  __int64 v45; // [xsp+28h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_DWORD *)(ipa3_ctx + 34308) )
  {
LABEL_33:
    result = 0;
    goto LABEL_34;
  }
  v5 = a3;
  v8 = 0;
  v9 = 0;
  v11 = a2;
  v43 = 0;
  v44 = 0;
  v42 = 0;
  v40 = a5 - a3;
  while ( 1 )
  {
    if ( (ipa_is_ep_support_flt((unsigned int)v8) & 1) == 0 )
      goto LABEL_4;
    if ( a1 > 2 || v8 >= 0x24 )
      __break(0x5512u);
    v12 = (__int64 *)(ipa3_ctx + 304 * v8 + 152LL * a1 + 17640);
    v13 = *((_DWORD *)v12 + v11 + 6);
    if ( !v13 )
    {
      ++v9;
      goto LABEL_4;
    }
    if ( (*((_BYTE *)v12 + v11 + 20) & 1) == 0 && *((_BYTE *)v12 + v11 + 144) != 1 )
      break;
    LODWORD(v44) = v13 - ((__int64 (*)(void))ipahal_get_hw_tbl_hdr_width)();
    LODWORD(v44) = v44 + ((__int64 (*)(void))ipahal_get_hw_prefetch_buf_size)();
    if ( (unsigned int)ipahal_fltrt_allocate_hw_sys_tbl(&v42) )
    {
      printk(&unk_3BB221, "ipa_translate_flt_tbl_to_hw_fmt");
      v31 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v32 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v32 )
        {
          ipc_log_string(
            v32,
            "ipa %s:%d fail to alloc sys tbl of size %d\n",
            "ipa_translate_flt_tbl_to_hw_fmt",
            233,
            v44);
          v31 = ipa3_ctx;
        }
        v33 = *(_QWORD *)(v31 + 34160);
        if ( v33 )
        {
          ipc_log_string(
            v33,
            "ipa %s:%d fail to alloc sys tbl of size %d\n",
            "ipa_translate_flt_tbl_to_hw_fmt",
            233,
            v44);
          result = 0xFFFFFFFFLL;
          goto LABEL_34;
        }
      }
      goto LABEL_41;
    }
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))ipahal_fltrt_write_addr_to_hdr)(
                         v43,
                         a4,
                         v9,
                         1) )
    {
      printk(&unk_3BDFE1, "ipa_translate_flt_tbl_to_hw_fmt");
      v34 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v35 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v35 )
        {
          ipc_log_string(v35, "ipa %s:%d fail to wrt sys tbl addr to hdr\n", "ipa_translate_flt_tbl_to_hw_fmt", 239);
          v34 = ipa3_ctx;
        }
        v36 = *(_QWORD *)(v34 + 34160);
        if ( v36 )
          ipc_log_string(v36, "ipa %s:%d fail to wrt sys tbl addr to hdr\n", "ipa_translate_flt_tbl_to_hw_fmt", 239);
      }
LABEL_40:
      ipahal_free_dma_mem(&v42);
      goto LABEL_41;
    }
    v14 = *v12;
    if ( (__int64 *)*v12 != v12 )
    {
      v15 = v42;
      do
      {
        if ( (*(_BYTE *)(v14 + 374) == 0) == a2 )
        {
          if ( (unsigned int)ipa3_generate_flt_hw_rule(a1, v14) )
          {
            printk(&unk_3E0F6D, "ipa_translate_flt_tbl_to_hw_fmt");
            v25 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v26 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v26 )
              {
                ipc_log_string(v26, "ipa %s:%d failed to gen HW FLT rule\n", "ipa_translate_flt_tbl_to_hw_fmt", 253);
                v25 = ipa3_ctx;
              }
              v27 = *(_QWORD *)(v25 + 34160);
              if ( v27 )
                ipc_log_string(v27, "ipa %s:%d failed to gen HW FLT rule\n", "ipa_translate_flt_tbl_to_hw_fmt", 253);
            }
            goto LABEL_40;
          }
          v15 += *(unsigned int *)(v14 + 408);
        }
        v14 = *(_QWORD *)v14;
      }
      while ( (__int64 *)v14 != v12 );
    }
    v16 = &v12[3 * (unsigned int)v11];
    if ( v16[5] )
    {
      v17 = &v12[3 * (unsigned int)v11];
      if ( v17[11] )
        __break(0x800u);
      v18 = v16[4];
      v19 = v16[5];
      v17[12] = v16[6];
      v17[10] = v18;
      v17[11] = v19;
    }
    v20 = v44;
    v21 = v42;
    v16[5] = v43;
    v16[6] = v20;
    v16[4] = v21;
LABEL_32:
    ++v9;
LABEL_4:
    if ( ++v8 >= *(unsigned int *)(ipa3_ctx + 34308) )
      goto LABEL_33;
  }
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))ipahal_fltrt_write_addr_to_hdr)(
                       v40 + v5,
                       a4,
                       v9,
                       0) )
  {
    printk(&unk_3BE00E, "ipa_translate_flt_tbl_to_hw_fmt");
    v37 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v38 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v38 )
      {
        ipc_log_string(v38, "ipa %s:%d fail to wrt lcl tbl ofst to hdr\n", "ipa_translate_flt_tbl_to_hw_fmt", 270);
        v37 = ipa3_ctx;
      }
      v39 = *(_QWORD *)(v37 + 34160);
      if ( v39 )
        ipc_log_string(v39, "ipa %s:%d fail to wrt lcl tbl ofst to hdr\n", "ipa_translate_flt_tbl_to_hw_fmt", 270);
    }
    goto LABEL_40;
  }
  v22 = *v12;
  while ( 2 )
  {
    if ( (__int64 *)v22 == v12 )
    {
      v23 = v5 + ((__int64 (*)(void))ipahal_get_lcl_tbl_addr_alignment)();
      v5 = v23 & ~(unsigned int)((__int64 (*)(void))ipahal_get_lcl_tbl_addr_alignment)();
      goto LABEL_32;
    }
    if ( (*(_BYTE *)(v22 + 374) == 0) != a2 )
    {
LABEL_26:
      v22 = *(_QWORD *)v22;
      continue;
    }
    break;
  }
  if ( !(unsigned int)ipa3_generate_flt_hw_rule(a1, v22) )
  {
    LODWORD(v5) = v5 + *(_DWORD *)(v22 + 408);
    goto LABEL_26;
  }
  printk(&unk_3E0F6D, "ipa_translate_flt_tbl_to_hw_fmt");
  v28 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v29 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v29 )
    {
      ipc_log_string(v29, "ipa %s:%d failed to gen HW FLT rule\n", "ipa_translate_flt_tbl_to_hw_fmt", 282);
      v28 = ipa3_ctx;
    }
    v30 = *(_QWORD *)(v28 + 34160);
    if ( v30 )
    {
      ipc_log_string(v30, "ipa %s:%d failed to gen HW FLT rule\n", "ipa_translate_flt_tbl_to_hw_fmt", 282);
      result = 0xFFFFFFFFLL;
      goto LABEL_34;
    }
  }
LABEL_41:
  result = 0xFFFFFFFFLL;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
