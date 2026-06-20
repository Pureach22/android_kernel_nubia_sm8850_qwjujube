__int64 __fastcall ipa_gsi_setup_event_ring(__int64 a1, unsigned int a2, unsigned int a3)
{
  int v5; // w20
  __int64 v6; // x0
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x9
  int v10; // w10
  int v11; // w21
  int v12; // w9
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x9
  __int64 v18; // x1
  __int64 result; // x0
  int v20; // w21
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x2
  unsigned int v25; // w20
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // [xsp+8h] [xbp-98h] BYREF
  __int64 v30; // [xsp+10h] [xbp-90h] BYREF
  __int64 v31; // [xsp+18h] [xbp-88h] BYREF
  __int64 v32; // [xsp+20h] [xbp-80h]
  __int64 v33; // [xsp+28h] [xbp-78h]
  __int64 v34; // [xsp+30h] [xbp-70h]
  __int64 v35; // [xsp+38h] [xbp-68h]
  __int64 v36; // [xsp+40h] [xbp-60h]
  __int64 v37; // [xsp+48h] [xbp-58h]
  __int64 v38; // [xsp+50h] [xbp-50h]
  __int64 v39; // [xsp+58h] [xbp-48h]
  __int64 v40; // [xsp+60h] [xbp-40h]
  __int64 v41; // [xsp+68h] [xbp-38h]
  __int64 v42; // [xsp+70h] [xbp-30h]
  __int64 (__fastcall *v43)(__int64); // [xsp+78h] [xbp-28h]
  __int64 v44; // [xsp+80h] [xbp-20h]
  __int64 v45; // [xsp+88h] [xbp-18h]
  __int64 v46; // [xsp+90h] [xbp-10h]
  __int64 v47; // [xsp+98h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v30 = 0;
  v32 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  v38 = 0;
  v39 = 0;
  v40 = 0;
  v41 = 0;
  v42 = 0;
  v43 = nullptr;
  v44 = 0;
  v45 = 0;
  v46 = 0;
  v31 = 2;
  if ( !*(_QWORD *)(ipa3_ctx + 51248) || (*(_DWORD *)(a1 + 4) | 0x10) != 0x79 )
    HIDWORD(v31) = 1;
  v5 = 16;
  LODWORD(v32) = 16;
  HIDWORD(v32) = a2;
  v6 = ipa3_ring_alloc(*(_QWORD *)(ipa3_ctx + 34216), a2, &v30, a3);
  v7 = v30;
  v8 = *(_QWORD *)(a1 + 472);
  *(_DWORD *)(a1 + 24) = a2;
  v33 = v7;
  v34 = v6;
  *(_QWORD *)(a1 + 32) = v7;
  *(_QWORD *)(a1 + 40) = v6;
  if ( !v8 )
  {
    LOWORD(v35) = 16;
    LOBYTE(v11) = 1;
    goto LABEL_14;
  }
  v9 = *(_QWORD *)(v8 + 384);
  v10 = *(unsigned __int8 *)(v8 + 1608);
  LOWORD(v35) = 16;
  if ( v9 )
    LOBYTE(v11) = 20;
  else
    LOBYTE(v11) = 1;
  BYTE2(v35) = v11;
  if ( v10 == 1 )
  {
    if ( (v12 = *(_DWORD *)(a1 + 4), (unsigned int)(v12 - 95) <= 0x1A) && ((1 << (v12 - 95)) & 0x6000601) != 0
      || (unsigned int)(v12 - 34) < 2 )
    {
      v11 = *(_DWORD *)(v8 + 1596);
      v5 = (unsigned __int16)*(_DWORD *)(v8 + 1592);
      LOWORD(v35) = *(_DWORD *)(v8 + 1592);
LABEL_14:
      BYTE2(v35) = v11;
    }
  }
  v13 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v14 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v14 )
    {
      ipc_log_string(
        v14,
        "ipa %s:%d client=%d moderation threshold cycles=%u cnt=%u\n",
        "ipa_gsi_setup_event_ring",
        6903,
        *(_DWORD *)(a1 + 4),
        v5,
        (unsigned __int8)v11);
      v13 = ipa3_ctx;
    }
    v15 = *(_QWORD *)(v13 + 34160);
    if ( v15 )
    {
      ipc_log_string(
        v15,
        "ipa %s:%d client=%d moderation threshold cycles=%u cnt=%u\n",
        "ipa_gsi_setup_event_ring",
        6903,
        *(_DWORD *)(a1 + 4),
        v5,
        (unsigned __int8)v11);
      v13 = ipa3_ctx;
    }
  }
  if ( *(_BYTE *)(v13 + 48857) == 1 )
  {
    v16 = dma_alloc_attrs(*(_QWORD *)(v13 + 34216), 8, &v29, 3264, 0);
    v41 = v16;
    if ( !v16 )
    {
      printk(&unk_3DB437, "ipa_gsi_setup_event_ring");
      v21 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v22 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v22 )
        {
          ipc_log_string(v22, "ipa %s:%d fail to dma alloc %u bytes\n", "ipa_gsi_setup_event_ring", 6911, 8);
          v21 = ipa3_ctx;
        }
        v23 = *(_QWORD *)(v21 + 34160);
        if ( v23 )
          ipc_log_string(v23, "ipa %s:%d fail to dma alloc %u bytes\n", "ipa_gsi_setup_event_ring", 6911, 8);
      }
      LODWORD(result) = -12;
      goto LABEL_34;
    }
    v17 = v29;
    v13 = ipa3_ctx;
    v40 = v29;
  }
  else
  {
    v16 = 0;
    v17 = 0;
    v40 = 0;
  }
  *(_QWORD *)(a1 + 72) = v17;
  *(_QWORD *)(a1 + 80) = v16;
  v18 = *(_QWORD *)(v13 + 43296);
  LOBYTE(v42) = 1;
  v43 = ipa_gsi_evt_ring_err_cb;
  v44 = 0;
  result = gsi_alloc_evt_ring(&v31, v18, a1 + 16);
  if ( !(_DWORD)result )
    goto LABEL_25;
  if ( v41 )
  {
    v20 = result;
    dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), 8, v41, v29, 0);
    LODWORD(result) = v20;
    *(_QWORD *)(a1 + 72) = 0;
    *(_QWORD *)(a1 + 80) = 0;
  }
LABEL_34:
  v24 = *(_QWORD *)(a1 + 40);
  v25 = result;
  if ( v24 )
    dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), *(unsigned int *)(a1 + 24), v24, *(_QWORD *)(a1 + 32), 0);
  printk(&unk_3DB4BA, "ipa_gsi_setup_event_ring");
  v26 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v27 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v27 )
    {
      ipc_log_string(v27, "ipa %s:%d Return with err: %d\n", "ipa_gsi_setup_event_ring", 6950, v25);
      v26 = ipa3_ctx;
    }
    v28 = *(_QWORD *)(v26 + 34160);
    if ( v28 )
      ipc_log_string(v28, "ipa %s:%d Return with err: %d\n", "ipa_gsi_setup_event_ring", 6950, v25);
  }
  result = v25;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
