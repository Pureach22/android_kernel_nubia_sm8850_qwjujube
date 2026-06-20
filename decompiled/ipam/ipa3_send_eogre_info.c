__int64 __fastcall ipa3_send_eogre_info(char a1, _QWORD *a2)
{
  __int64 v4; // x19
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x10
  __int64 v8; // x8
  unsigned int v9; // w20
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v20 = 3145728;
    v4 = _kmalloc_cache_noprof(ipc_log_string, 3520, 48);
    if ( v4 )
    {
      v5 = a2[2];
      v6 = a2[3];
      LOBYTE(v20) = a1;
      *(_QWORD *)(v4 + 16) = v5;
      *(_QWORD *)(v4 + 24) = v6;
      v7 = a2[5];
      *(_QWORD *)(v4 + 32) = a2[4];
      *(_QWORD *)(v4 + 40) = v7;
      v8 = a2[1];
      *(_QWORD *)v4 = *a2;
      *(_QWORD *)(v4 + 8) = v8;
      v9 = ipa_send_msg((unsigned __int8 *)&v20, (_WORD *)v4, ipa3_eogre_info_free_cb);
      if ( v9 )
      {
        if ( (unsigned int)__ratelimit(&ipa3_send_eogre_info__rs, "ipa3_send_eogre_info") )
          printk(&unk_3A28DF, "ipa3_send_eogre_info");
        v10 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v11 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v11 )
          {
            ipc_log_string(v11, "ipa %s:%d ipa_send_msg failed: %d\n", "ipa3_send_eogre_info", 14438, v9);
            v10 = ipa3_ctx;
          }
          v12 = *(_QWORD *)(v10 + 34160);
          if ( v12 )
            ipc_log_string(v12, "ipa %s:%d ipa_send_msg failed: %d\n", "ipa3_send_eogre_info", 14438, v9);
        }
        kfree(v4);
      }
    }
    else
    {
      printk(&unk_3E1BA9, "ipa3_send_eogre_info");
      v17 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v18 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v18 )
        {
          ipc_log_string(v18, "ipa %s:%d eogre_info memory allocation failed !\n", "ipa3_send_eogre_info", 14420);
          v17 = ipa3_ctx;
        }
        v19 = *(_QWORD *)(v17 + 34160);
        if ( v19 )
          ipc_log_string(v19, "ipa %s:%d eogre_info memory allocation failed !\n", "ipa3_send_eogre_info", 14420);
      }
      v9 = -12;
    }
  }
  else
  {
    printk(&unk_3EE270, "ipa3_send_eogre_info");
    v14 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_18;
    v15 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v15 )
    {
      ipc_log_string(v15, "ipa %s:%d Bad arg: info is NULL\n", "ipa3_send_eogre_info", 14406);
      v14 = ipa3_ctx;
    }
    v16 = *(_QWORD *)(v14 + 34160);
    if ( v16 )
    {
      ipc_log_string(v16, "ipa %s:%d Bad arg: info is NULL\n", "ipa3_send_eogre_info", 14406);
      v9 = -5;
    }
    else
    {
LABEL_18:
      v9 = -5;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v9;
}
