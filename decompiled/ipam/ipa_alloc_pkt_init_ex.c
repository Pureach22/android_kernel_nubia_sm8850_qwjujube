__int64 ipa_alloc_pkt_init_ex()
{
  __int64 v0; // x20
  unsigned __int16 *v1; // x0
  __int64 v2; // x22
  unsigned __int16 *v3; // x19
  __int64 v4; // x10
  _QWORD *v5; // x20
  __int64 v6; // x1
  __int64 v7; // x0
  size_t v8; // x3
  unsigned int v9; // w8
  unsigned int v10; // w0
  unsigned int v11; // w0
  unsigned int v12; // w8
  unsigned int v13; // w9
  unsigned int v14; // w9
  unsigned int v15; // w20
  __int64 result; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // [xsp+8h] [xbp-58h] BYREF
  __int64 v30; // [xsp+10h] [xbp-50h]
  __int64 v31; // [xsp+18h] [xbp-48h]
  __int64 v32; // [xsp+20h] [xbp-40h]
  __int16 v33; // [xsp+28h] [xbp-38h]
  __int64 v34; // [xsp+30h] [xbp-30h] BYREF
  __int64 v35; // [xsp+38h] [xbp-28h]
  __int64 v36; // [xsp+40h] [xbp-20h]
  __int64 v37; // [xsp+48h] [xbp-18h]
  __int16 v38; // [xsp+50h] [xbp-10h]
  __int64 v39; // [xsp+58h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = ipa3_ctx;
  v38 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v33 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v1 = (unsigned __int16 *)((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(16, &v34, 0);
  if ( v1 )
  {
    v2 = v0 + 49152;
    v3 = v1;
    v4 = ipa3_ctx + 34216;
    *(_DWORD *)(ipa3_ctx + 50156) = v1[1];
    v5 = (_QWORD *)(v0 + 50192);
    v6 = *v1 + (unsigned int)*v1 * *(_DWORD *)(v4 + 92);
    *(_DWORD *)(v2 + 1048) = v6;
    v7 = dma_alloc_attrs(*(_QWORD *)v4, v6, v5, 3264, 0);
    v8 = *(unsigned int *)(v2 + 1048);
    *(_QWORD *)(v2 + 1032) = v7;
    if ( v7 )
    {
      memset(*(void **)(v2 + 1032), 0, v8);
      LOBYTE(v34) = 1;
      v9 = *(_DWORD *)(ipa3_ctx + 34308);
      LOBYTE(v29) = 1;
      *(_WORD *)((char *)&v34 + 1) = 257;
      *(_WORD *)((char *)&v29 + 1) = 257;
      BYTE3(v34) = 1;
      BYTE3(v29) = 1;
      WORD2(v34) = 0;
      WORD2(v29) = 257;
      HIWORD(v35) = 1;
      HIWORD(v30) = 257;
      HIBYTE(v36) = 1;
      HIBYTE(v31) = 1;
      if ( v9 )
      {
        while ( 1 )
        {
          v10 = ((__int64 (__fastcall *)(__int64, unsigned __int16 *, __int64 *, __int64 *))ipahal_modify_imm_cmd)(
                  16,
                  v3 + 2,
                  &v34,
                  &v29);
          if ( v10 )
            break;
          memcpy((void *)(*(_QWORD *)(v2 + 1032) + *v3 * (unsigned __int64)HIBYTE(v35)), v3 + 2, *v3);
          if ( HIBYTE(v35) >= 0x25uLL )
            goto LABEL_39;
          *(_QWORD *)(ipa3_ctx + 24LL * HIBYTE(v35) + 50216) = *v5 + *v3 * (unsigned __int64)HIBYTE(v35);
          if ( HIBYTE(v35) > 0x24uLL )
            goto LABEL_39;
          *(_QWORD *)(ipa3_ctx + 24LL * HIBYTE(v35) + 50208) = *(_QWORD *)(v2 + 1032)
                                                             + *v3 * (unsigned __int64)HIBYTE(v35);
          if ( HIBYTE(v35) > 0x24uLL )
            goto LABEL_39;
          *(_DWORD *)(ipa3_ctx + 24LL * HIBYTE(v35) + 50224) = *v3;
          v9 = *(_DWORD *)(ipa3_ctx + 34308);
          ++HIBYTE(v35);
          if ( v9 <= HIBYTE(v35) )
            goto LABEL_9;
        }
        v15 = v10;
        printk(&unk_3E5C1D, "ipa_alloc_pkt_init_ex");
        v23 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v24 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v24 )
          {
            ipc_log_string(v24, "ipa %s:%d failed to modify IMM cmd\n", "ipa_alloc_pkt_init_ex", 8939);
            v23 = ipa3_ctx;
          }
          v25 = *(_QWORD *)(v23 + 34160);
          if ( v25 )
            ipc_log_string(v25, "ipa %s:%d failed to modify IMM cmd\n", "ipa_alloc_pkt_init_ex", 8939);
        }
      }
      else
      {
LABEL_9:
        WORD2(v34) = 257;
        BYTE6(v35) = 0;
        HIBYTE(v36) = 0;
        BYTE2(v35) = 1;
        BYTE2(v30) = 1;
        BYTE2(v36) = 1;
        BYTE2(v31) = 1;
        HIBYTE(v35) = v9;
        v11 = ((__int64 (__fastcall *)(__int64, unsigned __int16 *, __int64 *, __int64 *))ipahal_modify_imm_cmd)(
                16,
                v3 + 2,
                &v34,
                &v29);
        if ( !v11 )
        {
          memcpy((void *)(*(_QWORD *)(v2 + 1032) + *(_DWORD *)(ipa3_ctx + 34308) * (unsigned int)*v3), v3 + 2, *v3);
          v12 = *(_DWORD *)(ipa3_ctx + 34308);
          if ( v12 > 0x24
            || (*(_QWORD *)(ipa3_ctx + 24LL * v12 + 50216) = *v5 + v12 * *v3,
                v13 = *(_DWORD *)(ipa3_ctx + 34308),
                v13 > 0x24)
            || (*(_QWORD *)(ipa3_ctx + 24LL * v13 + 50208) = *(_QWORD *)(v2 + 1032) + v13 * *v3,
                v14 = *(_DWORD *)(ipa3_ctx + 34308),
                v14 > 0x24) )
          {
LABEL_39:
            __break(0x5512u);
          }
          v15 = 0;
          *(_DWORD *)(ipa3_ctx + 24LL * v14 + 50224) = *v3;
          goto LABEL_14;
        }
        v15 = v11;
        printk(&unk_3E5C1D, "ipa_alloc_pkt_init_ex");
        v26 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v27 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v27 )
          {
            ipc_log_string(v27, "ipa %s:%d failed to modify IMM cmd\n", "ipa_alloc_pkt_init_ex", 8965);
            v26 = ipa3_ctx;
          }
          v28 = *(_QWORD *)(v26 + 34160);
          if ( v28 )
            ipc_log_string(v28, "ipa %s:%d failed to modify IMM cmd\n", "ipa_alloc_pkt_init_ex", 8965);
        }
      }
      dma_free_attrs(
        *(_QWORD *)(ipa3_ctx + 34216),
        *(unsigned int *)(v2 + 1048),
        *(_QWORD *)(v2 + 1032),
        *(_QWORD *)(v2 + 1040),
        0);
    }
    else
    {
      printk(&unk_3DDABF, "ipa_alloc_pkt_init_ex");
      v20 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_27;
      v21 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v21 )
      {
        ipc_log_string(
          v21,
          "ipa %s:%d failed to alloc DMA buff of size %d\n",
          "ipa_alloc_pkt_init_ex",
          8910,
          *(_DWORD *)(v2 + 1048));
        v20 = ipa3_ctx;
      }
      v22 = *(_QWORD *)(v20 + 34160);
      if ( v22 )
      {
        ipc_log_string(
          v22,
          "ipa %s:%d failed to alloc DMA buff of size %d\n",
          "ipa_alloc_pkt_init_ex",
          8910,
          *(_DWORD *)(v2 + 1048));
        v15 = -12;
      }
      else
      {
LABEL_27:
        v15 = -12;
      }
    }
LABEL_14:
    kfree(v3);
    result = v15;
    goto LABEL_15;
  }
  printk(&unk_3FA63B, "ipa_alloc_pkt_init_ex");
  v17 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_26;
  v18 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v18 )
  {
    ipc_log_string(v18, "ipa %s:%d failed to construct IMM cmd\n", "ipa_alloc_pkt_init_ex", 8900);
    v17 = ipa3_ctx;
  }
  v19 = *(_QWORD *)(v17 + 34160);
  if ( v19 )
  {
    ipc_log_string(v19, "ipa %s:%d failed to construct IMM cmd\n", "ipa_alloc_pkt_init_ex", 8900);
    result = 4294967284LL;
  }
  else
  {
LABEL_26:
    result = 4294967284LL;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
