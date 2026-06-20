__int64 __fastcall ipa3_uc_send_remote_ipa_info(int a1, int a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x0
  _DWORD *v6; // x20
  unsigned int v7; // w19
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  _DWORD *v12; // [xsp+0h] [xbp-20h]
  __int64 v13; // [xsp+8h] [xbp-18h] BYREF
  __int64 v14; // [xsp+10h] [xbp-10h]
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  v14 = 0;
  v4 = *(_QWORD *)(ipa3_ctx + 34224);
  LODWORD(v14) = 8;
  v5 = (_DWORD *)dma_alloc_attrs(v4, 8, &v13, 3264, 0);
  v12 = v5;
  if ( v5 )
  {
    *v5 = a1;
    v5[1] = a2;
    v6 = v5;
    v7 = ipa3_uc_send_cmd_64b_param(v13, 0, 11, 0, 0, 2500);
    if ( v7 )
    {
      printk(&unk_3FBC8D, "ipa3_uc_send_remote_ipa_info");
      v9 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v10 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v10 )
        {
          ipc_log_string(
            v10,
            "ipa %s:%d fail to map 0x%x to mbox %d\n",
            "ipa3_uc_send_remote_ipa_info",
            1569,
            *v6,
            v6[1]);
          v9 = ipa3_ctx;
        }
        v11 = *(_QWORD *)(v9 + 34160);
        if ( v11 )
          ipc_log_string(
            v11,
            "ipa %s:%d fail to map 0x%x to mbox %d\n",
            "ipa3_uc_send_remote_ipa_info",
            1569,
            *v6,
            v6[1]);
      }
    }
    dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34224), (unsigned int)v14, v12, v13, 0);
  }
  else
  {
    v7 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
