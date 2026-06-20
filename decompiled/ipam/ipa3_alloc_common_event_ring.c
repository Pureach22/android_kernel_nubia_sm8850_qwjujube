__int64 ipa3_alloc_common_event_ring()
{
  __int64 v0; // x0
  __int64 v1; // x8
  __int64 v2; // x1
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  unsigned int v7; // w19
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // [xsp+8h] [xbp-98h] BYREF
  __int64 v15; // [xsp+10h] [xbp-90h] BYREF
  __int64 v16; // [xsp+18h] [xbp-88h] BYREF
  __int64 v17; // [xsp+20h] [xbp-80h]
  __int64 v18; // [xsp+28h] [xbp-78h]
  __int64 v19; // [xsp+30h] [xbp-70h]
  __int64 v20; // [xsp+38h] [xbp-68h]
  __int64 v21; // [xsp+40h] [xbp-60h]
  __int64 v22; // [xsp+48h] [xbp-58h]
  __int64 v23; // [xsp+50h] [xbp-50h]
  __int64 v24; // [xsp+58h] [xbp-48h]
  __int64 v25; // [xsp+60h] [xbp-40h]
  __int64 v26; // [xsp+68h] [xbp-38h]
  __int64 v27; // [xsp+70h] [xbp-30h]
  __int64 (__fastcall *v28)(); // [xsp+78h] [xbp-28h]
  __int64 v29; // [xsp+80h] [xbp-20h]
  __int64 v30; // [xsp+88h] [xbp-18h]
  __int64 v31; // [xsp+90h] [xbp-10h]
  __int64 v32; // [xsp+98h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  v15 = 0;
  v20 = 0;
  v21 = 0;
  v0 = *(_QWORD *)(ipa3_ctx + 34216);
  v22 = 0;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v28 = nullptr;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v16 = 0x100000002LL;
  v17 = 0x7C0000000010LL;
  v19 = dma_alloc_attrs(v0, 31744, &v15, 3264, 0);
  if ( v19 )
  {
    v1 = ipa3_ctx;
    LOWORD(v20) = 0;
    v18 = v15;
    BYTE2(v20) = 1;
    if ( *(_BYTE *)(ipa3_ctx + 48857) == 1 )
    {
      v26 = dma_alloc_attrs(*(_QWORD *)(ipa3_ctx + 34216), 8, &v14, 3264, 0);
      if ( !v26 )
      {
        printk(&unk_3DB437, "ipa3_alloc_common_event_ring");
        v11 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v12 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v12 )
          {
            ipc_log_string(v12, "ipa %s:%d fail to dma alloc %u bytes\n", "ipa3_alloc_common_event_ring", 6690, 8);
            v11 = ipa3_ctx;
          }
          v13 = *(_QWORD *)(v11 + 34160);
          if ( v13 )
            ipc_log_string(v13, "ipa %s:%d fail to dma alloc %u bytes\n", "ipa3_alloc_common_event_ring", 6690, 8);
        }
        v7 = -12;
        goto LABEL_28;
      }
      v1 = ipa3_ctx;
      v25 = v14;
    }
    else
    {
      v25 = 0;
    }
    v2 = *(_QWORD *)(v1 + 43296);
    v28 = ipa_gsi_evt_ring_err_cb;
    v29 = 0;
    LOBYTE(v27) = 0;
    result = gsi_alloc_evt_ring(&v16, v2, v1 + 32024);
    if ( !(_DWORD)result )
    {
      *(_DWORD *)(ipa3_ctx + 32032) = 31744;
      goto LABEL_8;
    }
    v7 = result;
    printk(&unk_3FB299, "ipa3_alloc_common_event_ring");
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d gsi_alloc_evt_ring failed %d\n", "ipa3_alloc_common_event_ring", 6706, v7);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
        ipc_log_string(v10, "ipa %s:%d gsi_alloc_evt_ring failed %d\n", "ipa3_alloc_common_event_ring", 6706, v7);
    }
    if ( v26 )
      dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), 8, v26, v14, 0);
LABEL_28:
    dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), HIDWORD(v17), v19, v15, 0);
    result = v7;
    goto LABEL_8;
  }
  printk(&unk_3DB437, "ipa3_alloc_common_event_ring");
  v4 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_21;
  v5 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v5 )
  {
    ipc_log_string(v5, "ipa %s:%d fail to dma alloc %u bytes\n", "ipa3_alloc_common_event_ring", 6676, 31744);
    v4 = ipa3_ctx;
  }
  v6 = *(_QWORD *)(v4 + 34160);
  if ( v6 )
  {
    ipc_log_string(v6, "ipa %s:%d fail to dma alloc %u bytes\n", "ipa3_alloc_common_event_ring", 6676, 31744);
    result = 4294967284LL;
  }
  else
  {
LABEL_21:
    result = 4294967284LL;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
