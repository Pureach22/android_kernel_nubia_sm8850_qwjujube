__int64 __fastcall ipa_set_flt_rt_stats(int a1, __int64 a2, __int64 a3)
{
  _BYTE *v3; // x9
  _BYTE *v7; // x19
  __int64 v8; // x8
  __int64 v9; // x8
  int v10; // w24
  unsigned int v11; // w0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  int v16; // w8
  _WORD *v17; // x0
  __int16 v18; // w8
  _WORD *v19; // x21
  __int16 v20; // w8
  unsigned int v21; // w20
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 result; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x8
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
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // [xsp+8h] [xbp-A8h] BYREF
  _WORD *v49; // [xsp+10h] [xbp-A0h]
  __int64 v50; // [xsp+18h] [xbp-98h]
  __int64 v51; // [xsp+20h] [xbp-90h]
  __int64 v52; // [xsp+28h] [xbp-88h]
  __int64 v53; // [xsp+30h] [xbp-80h]
  __int64 v54; // [xsp+38h] [xbp-78h]
  __int64 v55; // [xsp+40h] [xbp-70h]
  __int64 v56; // [xsp+48h] [xbp-68h]
  __int64 v57; // [xsp+50h] [xbp-60h]
  __int64 v58; // [xsp+58h] [xbp-58h]
  __int64 v59; // [xsp+60h] [xbp-50h]
  __int64 v60; // [xsp+68h] [xbp-48h]
  __int64 v61; // [xsp+70h] [xbp-40h]
  __int64 v62; // [xsp+78h] [xbp-38h] BYREF
  __int64 v63; // [xsp+80h] [xbp-30h]
  __int64 v64; // [xsp+88h] [xbp-28h] BYREF
  __int64 v65; // [xsp+90h] [xbp-20h]
  __int64 v66; // [xsp+98h] [xbp-18h]
  _QWORD v67[2]; // [xsp+A0h] [xbp-10h] BYREF

  v67[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_BYTE **)(ipa3_ctx + 43800);
  if ( !v3 || (*v3 & 1) == 0 )
  {
    printk(&unk_3CFCED, "ipa_set_flt_rt_stats");
    v25 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v26 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v26 )
      {
        ipc_log_string(v26, "ipa %s:%d hw_stats is not enabled\n", "ipa_set_flt_rt_stats", 1848);
        v25 = ipa3_ctx;
      }
      result = *(_QWORD *)(v25 + 34160);
      if ( result )
      {
        ipc_log_string(result, "ipa %s:%d hw_stats is not enabled\n", "ipa_set_flt_rt_stats", 1848);
        result = 0;
      }
      goto LABEL_60;
    }
LABEL_35:
    result = 0;
    goto LABEL_60;
  }
  if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x10u )
  {
    printk(&unk_3A3912, "ipa_set_flt_rt_stats");
    v27 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v28 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v28 )
      {
        ipc_log_string(
          v28,
          "ipa %s:%d FnR stats not supported in %d hw_type\n",
          "ipa_set_flt_rt_stats",
          1854,
          *(_DWORD *)(ipa3_ctx + 32240));
        v27 = ipa3_ctx;
      }
      v29 = v27 + 32240;
      result = *(_QWORD *)(v29 + 1920);
      if ( result )
      {
        ipc_log_string(
          result,
          "ipa %s:%d FnR stats not supported in %d hw_type\n",
          "ipa_set_flt_rt_stats",
          1854,
          *(_DWORD *)v29);
        result = 0;
      }
      goto LABEL_60;
    }
    goto LABEL_35;
  }
  if ( a1 >= 33 )
  {
    printk(&unk_3A9D8F, "ipa_set_flt_rt_stats");
    v30 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v31 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v31 )
      {
        ipc_log_string(v31, "ipa %s:%d index %d out of range\n", "ipa_set_flt_rt_stats", 1859, a1);
        v30 = ipa3_ctx;
      }
      v32 = *(_QWORD *)(v30 + 34160);
      if ( v32 )
      {
        ipc_log_string(v32, "ipa %s:%d index %d out of range\n", "ipa_set_flt_rt_stats", 1859, (unsigned int)a1);
LABEL_46:
        result = 4294967274LL;
        goto LABEL_60;
      }
    }
LABEL_47:
    result = 4294967274LL;
    goto LABEL_60;
  }
  if ( a1 <= 24 )
  {
    printk(&unk_3EF278, "ipa_set_flt_rt_stats");
    v33 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v34 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v34 )
      {
        ipc_log_string(
          v34,
          "ipa %s:%d index %d invalid, only support sw counter set\n",
          "ipa_set_flt_rt_stats",
          1865,
          a1);
        v33 = ipa3_ctx;
      }
      v35 = *(_QWORD *)(v33 + 34160);
      if ( v35 )
      {
        ipc_log_string(
          v35,
          "ipa %s:%d index %d invalid, only support sw counter set\n",
          "ipa_set_flt_rt_stats",
          1865,
          (unsigned int)a1);
        goto LABEL_46;
      }
    }
    goto LABEL_47;
  }
  v66 = 0;
  v67[0] = 0;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  v61 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = nullptr;
  v50 = 0;
  v48 = 0;
  v7 = (_BYTE *)_kmalloc_cache_noprof(sg_next, 3520, 2);
  v8 = ipa3_ctx;
  if ( v7 )
  {
    v9 = *(_QWORD *)(ipa3_ctx + 34176);
    *v7 = a1;
    v10 = *(_DWORD *)(*(_QWORD *)v9 + 320LL);
    v7[1] = a1;
    v11 = ((__int64 (__fastcall *)(__int64, _BYTE *, _QWORD *))ipahal_stats_get_offset)(2, v7, v67);
    if ( v11 )
    {
      v21 = v11;
      printk(&unk_3F543B, "__ipa_set_flt_rt_stats");
      v36 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v37 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v37 )
        {
          ipc_log_string(v37, "ipa %s:%d failed to get offset from hal %d\n", "__ipa_set_flt_rt_stats", 1787, v21);
          v36 = ipa3_ctx;
        }
        v38 = *(_QWORD *)(v36 + 34160);
        if ( v38 )
          ipc_log_string(v38, "ipa %s:%d failed to get offset from hal %d\n", "__ipa_set_flt_rt_stats", 1787, v21);
      }
      goto LABEL_59;
    }
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(
          v13,
          "ipa %s:%d offset = %d size = %d\n",
          "__ipa_set_flt_rt_stats",
          1791,
          LODWORD(v67[0]),
          WORD2(v67[0]));
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(
          v14,
          "ipa %s:%d offset = %d size = %d\n",
          "__ipa_set_flt_rt_stats",
          1791,
          LODWORD(v67[0]),
          WORD2(v67[0]));
    }
    if ( WORD2(v67[0]) )
    {
      LODWORD(v63) = WORD2(v67[0]);
      v15 = dma_alloc_attrs(*(_QWORD *)(ipa3_ctx + 34216), WORD2(v67[0]), &v62, 3264, 0);
      v61 = v15;
      if ( v15 )
      {
        ipahal_set_flt_rt_sw_stats(v15, a2, a3);
        v16 = *(unsigned __int16 *)(ipa3_ctx + 29522);
        *(_WORD *)((char *)&v66 + 1) = 0;
        HIDWORD(v66) = 0;
        v64 = v62;
        LODWORD(v65) = v63;
        HIDWORD(v65) = v10 + v16 + LODWORD(v67[0]);
        v17 = (_WORD *)((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(11, &v64, 0);
        if ( v17 )
        {
          v18 = v17[1];
          v19 = v17;
          v49 = v17 + 2;
          WORD2(v52) = v18;
          v20 = *v17;
          LODWORD(v48) = 3;
          WORD1(v52) = v20;
          v21 = ((__int64 (__fastcall *)(__int64, __int64 *))ipa3_send_cmd)(1, &v48);
          if ( v21 )
          {
            printk(&unk_3B18DA, "__ipa_set_flt_rt_stats");
            v45 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v46 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v46 )
              {
                ipc_log_string(
                  v46,
                  "ipa %s:%d failed to send immediate command (error %d)\n",
                  "__ipa_set_flt_rt_stats",
                  1830,
                  v21);
                v45 = ipa3_ctx;
              }
              v47 = *(_QWORD *)(v45 + 34160);
              if ( v47 )
                ipc_log_string(
                  v47,
                  "ipa %s:%d failed to send immediate command (error %d)\n",
                  "__ipa_set_flt_rt_stats",
                  1830,
                  v21);
            }
          }
          kfree(v19);
        }
        else
        {
          printk(&unk_3A8EB0, "__ipa_set_flt_rt_stats");
          v42 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_71;
          v43 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v43 )
          {
            ipc_log_string(
              v43,
              "ipa %s:%d failed to construct dma_shared_mem imm cmd\n",
              "__ipa_set_flt_rt_stats",
              1819);
            v42 = ipa3_ctx;
          }
          v44 = *(_QWORD *)(v42 + 34160);
          if ( v44 )
          {
            ipc_log_string(
              v44,
              "ipa %s:%d failed to construct dma_shared_mem imm cmd\n",
              "__ipa_set_flt_rt_stats",
              1819);
            v21 = -12;
          }
          else
          {
LABEL_71:
            v21 = -12;
          }
        }
        dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), (unsigned int)v63, v61, v62, 0);
        goto LABEL_59;
      }
      printk(&unk_3DB7B7, "__ipa_set_flt_rt_stats");
      v39 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v40 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v40 )
        {
          ipc_log_string(v40, "ipa %s:%d fail to alloc DMA memory\n", "__ipa_set_flt_rt_stats", 1804);
          v39 = ipa3_ctx;
        }
        v41 = *(_QWORD *)(v39 + 34160);
        if ( v41 )
          ipc_log_string(v41, "ipa %s:%d fail to alloc DMA memory\n", "__ipa_set_flt_rt_stats", 1804);
      }
    }
    v21 = 0;
LABEL_59:
    kfree(v7);
    result = v21;
    goto LABEL_60;
  }
  if ( !ipa3_ctx )
    goto LABEL_24;
  v22 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v22 )
  {
    ipc_log_string(v22, "ipa %s:%d no mem\n", "__ipa_set_flt_rt_stats", 1775);
    v8 = ipa3_ctx;
  }
  v23 = *(_QWORD *)(v8 + 34160);
  if ( v23 )
  {
    ipc_log_string(v23, "ipa %s:%d no mem\n", "__ipa_set_flt_rt_stats", 1775);
    result = 4294967284LL;
  }
  else
  {
LABEL_24:
    result = 4294967284LL;
  }
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return result;
}
