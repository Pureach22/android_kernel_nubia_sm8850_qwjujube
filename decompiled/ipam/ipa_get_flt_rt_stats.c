__int64 __fastcall ipa_get_flt_rt_stats(unsigned __int8 *a1)
{
  _BYTE *v1; // x9
  unsigned int v2; // w4
  unsigned int v4; // w3
  int v5; // w8
  bool v6; // w21
  unsigned __int8 *v7; // x19
  __int64 v8; // x8
  unsigned __int8 v9; // w10
  __int64 v10; // x8
  int v11; // w23
  unsigned int v12; // w0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  int ep_mapping; // w0
  __int64 v17; // x8
  unsigned int v18; // w24
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 result; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  int v30; // w8
  __int64 v31; // x0
  int v32; // w21
  unsigned int v33; // w0
  unsigned int v34; // w0
  unsigned int v35; // w20
  __int64 v36; // x8
  __int64 v37; // x0
  __int64 v38; // x8
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x8
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x8
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x8
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x8
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x8
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x8
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x8
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // [xsp+0h] [xbp-120h]
  __int64 v70; // [xsp+8h] [xbp-118h] BYREF
  __int64 v71; // [xsp+10h] [xbp-110h]
  __int64 v72; // [xsp+18h] [xbp-108h] BYREF
  __int64 v73; // [xsp+20h] [xbp-100h]
  __int64 v74; // [xsp+28h] [xbp-F8h]
  __int64 v75; // [xsp+30h] [xbp-F0h] BYREF
  _QWORD v76[26]; // [xsp+38h] [xbp-E8h] BYREF
  __int64 v77; // [xsp+108h] [xbp-18h] BYREF
  __int64 v78; // [xsp+110h] [xbp-10h]
  __int64 v79; // [xsp+118h] [xbp-8h]

  v79 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_BYTE **)(ipa3_ctx + 43800);
  if ( !v1 || (*v1 & 1) == 0 )
  {
    printk(&unk_3CFCED, "ipa_get_flt_rt_stats");
    v22 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v23 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v23 )
      {
        ipc_log_string(v23, "ipa %s:%d hw_stats is not enabled\n", "ipa_get_flt_rt_stats", 1719);
        v22 = ipa3_ctx;
      }
      result = *(_QWORD *)(v22 + 34160);
      if ( !result )
        goto LABEL_93;
      ipc_log_string(result, "ipa %s:%d hw_stats is not enabled\n", "ipa_get_flt_rt_stats", 1719);
    }
LABEL_57:
    result = 0;
    goto LABEL_93;
  }
  if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x10u )
  {
    printk(&unk_3A3912, "ipa_get_flt_rt_stats");
    v36 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v37 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v37 )
      {
        ipc_log_string(
          v37,
          "ipa %s:%d FnR stats not supported in %d hw_type\n",
          "ipa_get_flt_rt_stats",
          1725,
          *(_DWORD *)(ipa3_ctx + 32240));
        v36 = ipa3_ctx;
      }
      v38 = v36 + 32240;
      result = *(_QWORD *)(v38 + 1920);
      if ( !result )
        goto LABEL_93;
      ipc_log_string(
        result,
        "ipa %s:%d FnR stats not supported in %d hw_type\n",
        "ipa_get_flt_rt_stats",
        1725,
        *(_DWORD *)v38);
    }
    goto LABEL_57;
  }
  v2 = *a1;
  if ( !*a1 || (v4 = a1[1]) == 0 )
  {
    printk(&unk_3ACD44, "ipa_get_flt_rt_stats");
    v24 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v25 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v25 )
      {
        ipc_log_string(v25, "ipa %s:%d Invalid start_id/end_id, must be not 0\n", "ipa_get_flt_rt_stats", 1730);
        v24 = ipa3_ctx;
      }
      v26 = *(_QWORD *)(v24 + 34160);
      if ( v26 )
        ipc_log_string(v26, "ipa %s:%d Invalid start_id/end_id, must be not 0\n", "ipa_get_flt_rt_stats", 1730);
    }
    printk(&unk_3B8236, "ipa_get_flt_rt_stats");
    v27 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v28 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v28 )
      {
        ipc_log_string(v28, "ipa %s:%d start_id %d, end_id %d\n", "ipa_get_flt_rt_stats", 1732, *a1, a1[1]);
        v27 = ipa3_ctx;
      }
      v29 = *(_QWORD *)(v27 + 34160);
      if ( v29 )
        ipc_log_string(v29, "ipa %s:%d start_id %d, end_id %d\n", "ipa_get_flt_rt_stats", 1732, *a1, a1[1]);
    }
    goto LABEL_80;
  }
  if ( v2 >= 0x21 )
  {
    printk(&unk_3C0F02, "ipa_get_flt_rt_stats");
    v39 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v40 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v40 )
      {
        ipc_log_string(v40, "ipa %s:%d start_cnt_id %d out of range\n", "ipa_get_flt_rt_stats", 1737, *a1);
        v39 = ipa3_ctx;
      }
      v41 = *(_QWORD *)(v39 + 34160);
      if ( v41 )
        ipc_log_string(v41, "ipa %s:%d start_cnt_id %d out of range\n", "ipa_get_flt_rt_stats", 1737, *a1);
    }
    goto LABEL_80;
  }
  if ( v4 >= 0x21 )
  {
    printk(&unk_3D2CFB, "ipa_get_flt_rt_stats");
    v42 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v43 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v43 )
      {
        ipc_log_string(v43, "ipa %s:%d end_cnt_id %d out of range\n", "ipa_get_flt_rt_stats", 1742, a1[1]);
        v42 = ipa3_ctx;
      }
      v44 = *(_QWORD *)(v42 + 34160);
      if ( v44 )
        ipc_log_string(v44, "ipa %s:%d end_cnt_id %d out of range\n", "ipa_get_flt_rt_stats", 1742, a1[1]);
    }
    goto LABEL_80;
  }
  if ( v4 < v2 )
  {
    printk(&unk_3A3945, "ipa_get_flt_rt_stats");
    v45 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v46 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v46 )
      {
        ipc_log_string(v46, "ipa %s:%d end_id %d < start_id %d\n", "ipa_get_flt_rt_stats", 1748, a1[1], *a1);
        v45 = ipa3_ctx;
      }
      v47 = *(_QWORD *)(v45 + 34160);
      if ( v47 )
        ipc_log_string(v47, "ipa %s:%d end_id %d < start_id %d\n", "ipa_get_flt_rt_stats", 1748, a1[1], *a1);
    }
    goto LABEL_80;
  }
  if ( *((_DWORD *)a1 + 1) >= 0x11u )
  {
    printk(&unk_3FE0AF, "ipa_get_flt_rt_stats");
    v48 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v49 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v49 )
      {
        ipc_log_string(
          v49,
          "ipa %s:%d stats_size %d > ipa_flt_rt_stats %lu\n",
          "ipa_get_flt_rt_stats",
          1754,
          *((_DWORD *)a1 + 1),
          16);
        v48 = ipa3_ctx;
      }
      v50 = *(_QWORD *)(v48 + 34160);
      if ( v50 )
        ipc_log_string(
          v50,
          "ipa %s:%d stats_size %d > ipa_flt_rt_stats %lu\n",
          "ipa_get_flt_rt_stats",
          1754,
          *((_DWORD *)a1 + 1),
          16);
    }
LABEL_80:
    result = 4294967274LL;
    goto LABEL_93;
  }
  v5 = a1[2];
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v6 = v5 != 0;
  memset(v76, 0, sizeof(v76));
  v77 = 0;
  v78 = 0;
  v7 = (unsigned __int8 *)_kmalloc_cache_noprof(sg_next, 3520, 2);
  v8 = ipa3_ctx;
  if ( v7 )
  {
    v9 = a1[1];
    v10 = **(_QWORD **)(ipa3_ctx + 34176);
    *v7 = *a1;
    v11 = *(_DWORD *)(v10 + 320);
    v7[1] = v9;
    v12 = ((__int64 (__fastcall *)(__int64, unsigned __int8 *, __int64 *))ipahal_stats_get_offset)(2, v7, &v75);
    if ( v12 )
    {
      v35 = v12;
      printk(&unk_3F543B, "__ipa_get_flt_rt_stats");
      v51 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v52 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v52 )
        {
          ipc_log_string(v52, "ipa %s:%d failed to get offset from hal %d\n", "__ipa_get_flt_rt_stats", 1640, v35);
          v51 = ipa3_ctx;
        }
        v53 = *(_QWORD *)(v51 + 34160);
        if ( v53 )
          ipc_log_string(v53, "ipa %s:%d failed to get offset from hal %d\n", "__ipa_get_flt_rt_stats", 1640, v35);
      }
      goto LABEL_92;
    }
    v13 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v14 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d offset = %d size = %d\n", "__ipa_get_flt_rt_stats", 1644, v75, WORD2(v75));
        v13 = ipa3_ctx;
      }
      v15 = *(_QWORD *)(v13 + 34160);
      if ( v15 )
        ipc_log_string(v15, "ipa %s:%d offset = %d size = %d\n", "__ipa_get_flt_rt_stats", 1644, v75, WORD2(v75));
    }
    if ( WORD2(v75) )
    {
      LODWORD(v71) = WORD2(v75);
      v69 = dma_alloc_attrs(*(_QWORD *)(ipa3_ctx + 34216), WORD2(v75), &v70, 3264, 0);
      if ( v69 )
      {
        ep_mapping = ipa_get_ep_mapping(95);
        v17 = ipa3_ctx;
        if ( ep_mapping == -1 || (*(_BYTE *)(ipa3_ctx + 51242) & 1) != 0 )
        {
          v18 = 0;
        }
        else
        {
          ipa_close_coal_frame(&v77);
          if ( !v77 )
          {
            printk(&unk_3AEDE8, "__ipa_get_flt_rt_stats");
            v66 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v67 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v67 )
              {
                ipc_log_string(v67, "ipa %s:%d failed to construct coal close IC\n", "__ipa_get_flt_rt_stats", 1666);
                v66 = ipa3_ctx;
              }
              v68 = *(_QWORD *)(v66 + 34160);
              if ( v68 )
                ipc_log_string(v68, "ipa %s:%d failed to construct coal close IC\n", "__ipa_get_flt_rt_stats", 1666);
            }
            v35 = -12;
            goto LABEL_51;
          }
          ipa3_init_imm_cmd_desc(v76, v77);
          v17 = ipa3_ctx;
          v18 = 1;
        }
        v30 = *(unsigned __int16 *)(v17 + 29522);
        *(_WORD *)((char *)&v74 + 1) = 1;
        LOBYTE(v74) = v6;
        HIDWORD(v74) = 0;
        v72 = v70;
        LODWORD(v73) = v71;
        HIDWORD(v73) = v11 + v30 + v75;
        v31 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(11, &v72, 0);
        *(&v77 + v18) = v31;
        if ( v31 )
        {
          ipa3_init_imm_cmd_desc(&v76[13 * v18], v31);
          v32 = v18 + 1;
          v33 = ((__int64 (__fastcall *)(_QWORD, _QWORD *))ipa3_send_cmd)(v18 + 1, v76);
          if ( v33 )
          {
            v35 = v33;
            printk(&unk_3B18DA, "__ipa_get_flt_rt_stats");
            v60 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v61 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v61 )
              {
                ipc_log_string(
                  v61,
                  "ipa %s:%d failed to send immediate command (error %d)\n",
                  "__ipa_get_flt_rt_stats",
                  1694,
                  v35);
                v60 = ipa3_ctx;
              }
              v62 = *(_QWORD *)(v60 + 34160);
              if ( v62 )
                ipc_log_string(
                  v62,
                  "ipa %s:%d failed to send immediate command (error %d)\n",
                  "__ipa_get_flt_rt_stats",
                  1694,
                  v35);
            }
          }
          else
          {
            v34 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, unsigned __int8 *))ipahal_parse_stats)(
                    2,
                    0,
                    v69,
                    a1);
            if ( v34 )
            {
              v35 = v34;
              printk(&unk_3E0FF4, "__ipa_get_flt_rt_stats");
              v63 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v64 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v64 )
                {
                  ipc_log_string(
                    v64,
                    "ipa %s:%d failed to parse stats (error %d)\n",
                    "__ipa_get_flt_rt_stats",
                    1701,
                    v35);
                  v63 = ipa3_ctx;
                }
                v65 = *(_QWORD *)(v63 + 34160);
                if ( v65 )
                  ipc_log_string(
                    v65,
                    "ipa %s:%d failed to parse stats (error %d)\n",
                    "__ipa_get_flt_rt_stats",
                    1701,
                    v35);
              }
            }
            else
            {
              v35 = 0;
            }
          }
        }
        else
        {
          printk(&unk_3A8EB0, "__ipa_get_flt_rt_stats");
          v57 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v58 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v58 )
            {
              ipc_log_string(
                v58,
                "ipa %s:%d failed to construct dma_shared_mem imm cmd\n",
                "__ipa_get_flt_rt_stats",
                1685);
              v57 = ipa3_ctx;
            }
            v59 = *(_QWORD *)(v57 + 34160);
            if ( v59 )
              ipc_log_string(
                v59,
                "ipa %s:%d failed to construct dma_shared_mem imm cmd\n",
                "__ipa_get_flt_rt_stats",
                1685);
          }
          v35 = -12;
          if ( !v18 )
            goto LABEL_51;
          v32 = 1;
        }
        kfree(v77);
        if ( v32 != 1 )
          kfree(v78);
LABEL_51:
        dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), (unsigned int)v71, v69, v70, 0);
LABEL_92:
        kfree(v7);
        result = v35;
        goto LABEL_93;
      }
      printk(&unk_3DB7B7, "__ipa_get_flt_rt_stats");
      v54 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v55 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v55 )
        {
          ipc_log_string(v55, "ipa %s:%d fail to alloc DMA memory\n", "__ipa_get_flt_rt_stats", 1657);
          v54 = ipa3_ctx;
        }
        v56 = *(_QWORD *)(v54 + 34160);
        if ( v56 )
        {
          ipc_log_string(v56, "ipa %s:%d fail to alloc DMA memory\n", "__ipa_get_flt_rt_stats", 1657);
          v35 = 0;
          goto LABEL_92;
        }
      }
    }
    v35 = 0;
    goto LABEL_92;
  }
  if ( !ipa3_ctx )
    goto LABEL_27;
  v19 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v19 )
  {
    ipc_log_string(v19, "ipa %s:%d no mem\n", "__ipa_get_flt_rt_stats", 1628);
    v8 = ipa3_ctx;
  }
  v20 = *(_QWORD *)(v8 + 34160);
  if ( v20 )
  {
    ipc_log_string(v20, "ipa %s:%d no mem\n", "__ipa_get_flt_rt_stats", 1628);
    result = 4294967284LL;
  }
  else
  {
LABEL_27:
    result = 4294967284LL;
  }
LABEL_93:
  _ReadStatusReg(SP_EL0);
  return result;
}
