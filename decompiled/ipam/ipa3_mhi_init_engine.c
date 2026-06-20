__int64 __fastcall ipa3_mhi_init_engine(__int64 a1)
{
  __int64 ipc_logbuf; // x0
  __int64 v3; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x0
  unsigned int v6; // w8
  __int64 v7; // x0
  int v8; // w9
  int v9; // w8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 result; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  unsigned int v27; // w19
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  _DWORD v33[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v34; // [xsp+8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v33, 0, 6);
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v3 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(v3, "ipa_mhi %s:%d ENTRY\n", "ipa3_mhi_init_engine", 477);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v5 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v5, "ipa_mhi %s:%d ENTRY\n", "ipa3_mhi_init_engine", 477);
  }
  if ( a1 )
  {
    if ( *(_BYTE *)(ipa3_ctx + 32264) )
      v6 = 7;
    else
      v6 = 5;
    if ( v6 > *(_DWORD *)(ipa3_ctx + 43748) - *(_DWORD *)(ipa3_ctx + 43744) + 1 )
    {
      v21 = printk(&unk_3E9A66, "ipa3_mhi_init_engine");
      v22 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v23 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v23 )
        {
          ipc_log_string(v23, "ipa %s:%d Not enough event rings for MHI\n", "ipa3_mhi_init_engine", 496);
          v22 = ipa3_ctx;
        }
        v21 = *(_QWORD *)(v22 + 34160);
        if ( v21 )
          v21 = ipc_log_string(v21, "ipa %s:%d Not enough event rings for MHI\n", "ipa3_mhi_init_engine", 496);
      }
      ((void (__fastcall *)(__int64))ipa_assert)(v21);
      result = 4294967274LL;
    }
    else
    {
      v7 = ((__int64 (__fastcall *)(__int64))ipa_get_gsi_ep_info)(42);
      if ( !v7 )
      {
        v24 = printk(&unk_3F5548, "ipa3_mhi_init_engine");
        v25 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v26 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v26 )
          {
            ipc_log_string(v26, "ipa %s:%d MHI PROD has no ep allocated\n", "ipa3_mhi_init_engine", 504);
            v25 = ipa3_ctx;
          }
          v24 = *(_QWORD *)(v25 + 34160);
          if ( v24 )
            v24 = ipc_log_string(v24, "ipa %s:%d MHI PROD has no ep allocated\n", "ipa3_mhi_init_engine", 504);
        }
        ((void (__fastcall *)(__int64))ipa_assert)(v24);
        v7 = 0;
      }
      *(_DWORD *)((char *)v33 + 2) = 0;
      v8 = *(_DWORD *)(a1 + 40);
      v9 = *(_DWORD *)(v7 + 4);
      v10 = *(_QWORD *)(ipa3_ctx + 43296);
      LOBYTE(v33[0]) = 1;
      *(_DWORD *)((char *)v33 + 1) = (unsigned __int8)(v8 + v9);
      v11 = gsi_write_device_scratch(v10, v33);
      if ( (_DWORD)v11 )
      {
        v27 = v11;
        v28 = printk(&unk_3A3A44, "ipa3_mhi_init_engine");
        v29 = ipa3_get_ipc_logbuf(v28);
        if ( v29 )
        {
          v30 = ipa3_get_ipc_logbuf(v29);
          v29 = ipc_log_string(
                  v30,
                  "ipa_mhi %s:%d failed to write device scratch %d\n",
                  "ipa3_mhi_init_engine",
                  514,
                  v27);
        }
        v31 = ipa3_get_ipc_logbuf_low(v29);
        if ( v31 )
        {
          v32 = ipa3_get_ipc_logbuf_low(v31);
          ipc_log_string(v32, "ipa_mhi %s:%d failed to write device scratch %d\n", "ipa3_mhi_init_engine", 514, v27);
        }
        result = v27;
      }
      else
      {
        v12 = ipa3_get_ipc_logbuf(v11);
        if ( v12 )
        {
          v13 = ipa3_get_ipc_logbuf(v12);
          v12 = ipc_log_string(v13, "ipa_mhi %s:%d EXIT\n", "ipa3_mhi_init_engine", 518);
        }
        result = ipa3_get_ipc_logbuf_low(v12);
        if ( result )
        {
          v15 = ipa3_get_ipc_logbuf_low(result);
          ipc_log_string(v15, "ipa_mhi %s:%d EXIT\n", "ipa3_mhi_init_engine", 518);
          result = 0;
        }
      }
    }
  }
  else
  {
    v16 = printk(&unk_3C1065, "ipa3_mhi_init_engine");
    v17 = ipa3_get_ipc_logbuf(v16);
    if ( v17 )
    {
      v18 = ipa3_get_ipc_logbuf(v17);
      v17 = ipc_log_string(v18, "ipa_mhi %s:%d null args\n", "ipa3_mhi_init_engine", 480);
    }
    v19 = ipa3_get_ipc_logbuf_low(v17);
    if ( v19 )
    {
      v20 = ipa3_get_ipc_logbuf_low(v19);
      ipc_log_string(v20, "ipa_mhi %s:%d null args\n", "ipa3_mhi_init_engine", 480);
    }
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
