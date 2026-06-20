__int64 ipa_init_hdr_v3_0()
{
  __int64 v0; // x9
  __int64 v1; // x1
  __int64 v2; // x0
  __int64 v3; // x19
  int ep_mapping; // w0
  __int64 v5; // x8
  unsigned int v6; // w22
  char v7; // w19
  unsigned int v8; // w19
  unsigned int v9; // w8
  int ep_reg_offset; // w0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 result; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  __int128 v36; // [xsp+0h] [xbp-1B0h] BYREF
  int v37; // [xsp+10h] [xbp-1A0h]
  __int64 v38; // [xsp+18h] [xbp-198h] BYREF
  __int64 v39; // [xsp+20h] [xbp-190h] BYREF
  unsigned __int64 v40; // [xsp+28h] [xbp-188h]
  __int64 v41; // [xsp+30h] [xbp-180h]
  __int64 v42; // [xsp+38h] [xbp-178h] BYREF
  __int64 v43; // [xsp+40h] [xbp-170h]
  __int64 v44; // [xsp+48h] [xbp-168h]
  __int64 v45; // [xsp+50h] [xbp-160h] BYREF
  __int64 v46; // [xsp+58h] [xbp-158h]
  _QWORD v47[13]; // [xsp+60h] [xbp-150h] BYREF
  __int64 v48; // [xsp+C8h] [xbp-E8h]
  __int64 v49; // [xsp+D0h] [xbp-E0h]
  _QWORD v50[27]; // [xsp+D8h] [xbp-D8h] BYREF

  v50[26] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v47, 0, sizeof(v47));
  memset(v50, 0, 208);
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v38 = 0;
  v37 = 0;
  v36 = 0u;
  v0 = *(_QWORD *)(ipa3_ctx + 34176);
  v48 = 0;
  v49 = 0;
  v1 = (unsigned int)(*(_DWORD *)(*(_QWORD *)v0 + 152LL) + *(_DWORD *)(*(_QWORD *)v0 + 144LL));
  v46 = v1;
  v44 = dma_alloc_attrs(*(_QWORD *)(ipa3_ctx + 34216), v1, &v45, 3264, 0);
  if ( !v44 )
  {
    printk(&unk_3B73AF, "_ipa_init_hdr_v3_0");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d fail to alloc DMA buff of size %d\n", "_ipa_init_hdr_v3_0", 5786, v46);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
      {
        ipc_log_string(
          v17,
          "ipa %s:%d fail to alloc DMA buff of size %d\n",
          "_ipa_init_hdr_v3_0",
          5786,
          (unsigned int)v46);
LABEL_42:
        result = 4294967284LL;
        goto LABEL_18;
      }
    }
LABEL_62:
    result = 4294967284LL;
    goto LABEL_18;
  }
  v42 = v45;
  LODWORD(v43) = v46;
  HIDWORD(v43) = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 140LL) + *(unsigned __int16 *)(ipa3_ctx + 29522);
  v2 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(5, &v42, 0);
  if ( !v2 )
  {
    printk(&unk_3CB922, "_ipa_init_hdr_v3_0");
    v18 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_36;
    v19 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v19 )
    {
      ipc_log_string(v19, "ipa %s:%d fail to construct hdr_init_local imm cmd\n", "_ipa_init_hdr_v3_0", 5797);
      v18 = ipa3_ctx;
    }
    v20 = *(_QWORD *)(v18 + 34160);
    if ( !v20 )
      goto LABEL_36;
    ipc_log_string(v20, "ipa %s:%d fail to construct hdr_init_local imm cmd\n", "_ipa_init_hdr_v3_0", 5797);
LABEL_35:
    v18 = ipa3_ctx;
LABEL_36:
    dma_free_attrs(*(_QWORD *)(v18 + 34216), (unsigned int)v46, v44, v45, 0);
    result = 4294967282LL;
    goto LABEL_18;
  }
  v3 = v2;
  ipa3_init_imm_cmd_desc(v47, v2);
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD *))ipa3_send_cmd)(1, v47) )
  {
    printk(&unk_3CB958, "_ipa_init_hdr_v3_0");
    v21 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v22 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v22 )
      {
        ipc_log_string(v22, "ipa %s:%d fail to send immediate command\n", "_ipa_init_hdr_v3_0", 5807);
        v21 = ipa3_ctx;
      }
      v23 = *(_QWORD *)(v21 + 34160);
      if ( v23 )
        ipc_log_string(v23, "ipa %s:%d fail to send immediate command\n", "_ipa_init_hdr_v3_0", 5807);
    }
    kfree(v3);
    goto LABEL_35;
  }
  kfree(v3);
  dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), (unsigned int)v46, v44, v45, 0);
  ep_mapping = ipa_get_ep_mapping(95);
  v5 = ipa3_ctx;
  if ( ep_mapping == -1 || (*(_BYTE *)(ipa3_ctx + 51242) & 1) != 0 )
  {
    v6 = 0;
    v7 = 1;
  }
  else
  {
    v8 = ipa_get_ep_mapping(95);
    BYTE12(v36) = 0;
    v9 = *(_DWORD *)(ipa3_ctx + 32240);
    v37 = 0;
    if ( v9 > 0x14 )
      ep_reg_offset = ipahal_get_ep_reg_offset(133, v8);
    else
      ep_reg_offset = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(44, 0, 0);
    LODWORD(v36) = ep_reg_offset;
    ipahal_get_aggr_force_close_valmask(v8, &v38);
    *(_QWORD *)((char *)&v36 + 4) = v38;
    v11 = ((__int64 (__fastcall *)(__int64, __int128 *, _QWORD))ipahal_construct_imm_cmd)(7, &v36, 0);
    v48 = v11;
    if ( !v11 )
    {
      printk(&unk_3AEDE8, "_ipa_init_hdr_v3_0");
      v33 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v34 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v34 )
        {
          ipc_log_string(v34, "ipa %s:%d failed to construct coal close IC\n", "_ipa_init_hdr_v3_0", 5840);
          v33 = ipa3_ctx;
        }
        v35 = *(_QWORD *)(v33 + 34160);
        if ( v35 )
          ipc_log_string(v35, "ipa %s:%d failed to construct coal close IC\n", "_ipa_init_hdr_v3_0", 5840);
      }
      goto LABEL_62;
    }
    ipa3_init_imm_cmd_desc(v50, v11);
    v5 = ipa3_ctx;
    v7 = 0;
    v6 = 1;
  }
  v12 = v5 + 0x8000;
  LODWORD(v46) = *(_DWORD *)(**(_QWORD **)(v12 + 1408) + 172LL) + *(_DWORD *)(**(_QWORD **)(v12 + 1408) + 164LL);
  v44 = dma_alloc_attrs(*(_QWORD *)(v12 + 1448), (unsigned int)v46, &v45, 3264, 0);
  if ( !v44 )
  {
    printk(&unk_3B73AF, "_ipa_init_hdr_v3_0");
    v24 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v25 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v25 )
      {
        ipc_log_string(v25, "ipa %s:%d fail to alloc DMA buff of size %d\n", "_ipa_init_hdr_v3_0", 5853, v46);
        v24 = ipa3_ctx;
      }
      v26 = *(_QWORD *)(v24 + 34160);
      if ( v26 )
      {
        ipc_log_string(
          v26,
          "ipa %s:%d fail to alloc DMA buff of size %d\n",
          "_ipa_init_hdr_v3_0",
          5853,
          (unsigned int)v46);
        goto LABEL_42;
      }
    }
    goto LABEL_62;
  }
  *(_WORD *)((char *)&v41 + 1) = 0;
  HIDWORD(v41) = 0;
  v39 = v45;
  v40 = __PAIR64__(
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 160LL) + (unsigned int)*(unsigned __int16 *)(ipa3_ctx + 29522),
          v46);
  v13 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(11, &v39, 0);
  *(&v48 + v6) = v13;
  if ( v13 )
  {
    ipa3_init_imm_cmd_desc(&v50[13 * v6], v13);
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD *))ipa3_send_cmd)(v6 + 1, v50) )
    {
      printk(&unk_3CB958, "_ipa_init_hdr_v3_0");
      v30 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v31 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v31 )
        {
          ipc_log_string(v31, "ipa %s:%d fail to send immediate command\n", "_ipa_init_hdr_v3_0", 5878);
          v30 = ipa3_ctx;
        }
        v32 = *(_QWORD *)(v30 + 34160);
        if ( v32 )
          ipc_log_string(v32, "ipa %s:%d fail to send immediate command\n", "_ipa_init_hdr_v3_0", 5878);
      }
      kfree(v48);
      if ( (v7 & 1) == 0 )
        kfree(v49);
      dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), (unsigned int)v46, v44, v45, 0);
      result = 4294967280LL;
    }
    else
    {
      kfree(v48);
      if ( (v7 & 1) == 0 )
        kfree(v49);
      ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))ipahal_write_reg_mn)(72, 0, 0, HIDWORD(v40));
      dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), (unsigned int)v46, v44, v45, 0);
      result = 0;
    }
  }
  else
  {
    printk(&unk_3C0035, "_ipa_init_hdr_v3_0");
    v27 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v28 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v28 )
      {
        ipc_log_string(v28, "ipa %s:%d fail to construct dma_shared_mem imm\n", "_ipa_init_hdr_v3_0", 5867);
        v27 = ipa3_ctx;
      }
      v29 = *(_QWORD *)(v27 + 34160);
      if ( v29 )
      {
        ipc_log_string(v29, "ipa %s:%d fail to construct dma_shared_mem imm\n", "_ipa_init_hdr_v3_0", 5867);
        v27 = ipa3_ctx;
      }
    }
    dma_free_attrs(*(_QWORD *)(v27 + 34216), (unsigned int)v46, v44, v45, 0);
    result = 4294967284LL;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
