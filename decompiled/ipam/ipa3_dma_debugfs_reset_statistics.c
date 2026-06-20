__int64 __fastcall ipa3_dma_debugfs_reset_statistics(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v7; // x0
  __int64 ipc_logbuf; // x0
  __int64 v9; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  _BYTE v17[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17[0] = 0;
  v4 = kstrtos8_from_user(a2, a3, 0, v17);
  if ( (_DWORD)v4 )
  {
    v3 = (int)v4;
  }
  else if ( v17[0] )
  {
    v7 = printk(&unk_3E945D, "ipa3_dma_debugfs_reset_statistics");
    ipc_logbuf = ipa3_get_ipc_logbuf(v7);
    if ( ipc_logbuf )
    {
      v9 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(
                     v9,
                     "ipa_dma %s:%d invalid argument: To reset statistics echo 0\n",
                     "ipa3_dma_debugfs_reset_statistics",
                     1212);
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( ipc_logbuf_low )
    {
      v11 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_log_string(
        v11,
        "ipa_dma %s:%d invalid argument: To reset statistics echo 0\n",
        "ipa3_dma_debugfs_reset_statistics",
        1212);
    }
  }
  else
  {
    if ( (ipa3_dma_work_pending(v4) & 1) != 0 )
    {
      v12 = printk(&unk_3FDC1E, "ipa3_dma_debugfs_reset_statistics");
      v13 = ipa3_get_ipc_logbuf(v12);
      if ( v13 )
      {
        v14 = ipa3_get_ipc_logbuf(v13);
        v13 = ipc_log_string(
                v14,
                "ipa_dma %s:%d Note, there are pending memcpy\n",
                "ipa3_dma_debugfs_reset_statistics",
                1206);
      }
      v15 = ipa3_get_ipc_logbuf_low(v13);
      if ( v15 )
      {
        v16 = ipa3_get_ipc_logbuf_low(v15);
        ipc_log_string(v16, "ipa_dma %s:%d Note, there are pending memcpy\n", "ipa3_dma_debugfs_reset_statistics", 1206);
      }
    }
    v5 = ipa3_dma_ctx;
    *(_DWORD *)(ipa3_dma_ctx + 192) = 0;
    *(_DWORD *)(v5 + 188) = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
