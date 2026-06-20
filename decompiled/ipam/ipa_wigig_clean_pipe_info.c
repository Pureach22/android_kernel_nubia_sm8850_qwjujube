__int64 __fastcall ipa_wigig_clean_pipe_info(unsigned int a1)
{
  __int64 ipc_logbuf; // x0
  long double v3; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x8
  __int64 v6; // x19
  long double v7; // q0
  _QWORD *v8; // x8
  _QWORD *v9; // x8
  __int64 v10; // x0
  __int64 result; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d cleaning pipe %d info\n", "ipa_wigig_clean_pipe_info", 732, a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v3 = ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d cleaning pipe %d info\n", "ipa_wigig_clean_pipe_info", 732, a1);
  }
  if ( a1 < 5 )
  {
    v5 = ipa_wigig_ctx + 128;
    if ( *(_BYTE *)(ipa_wigig_ctx + 908) == 1 )
    {
      v6 = 96LL * a1;
      sg_free_table(v5 + v6, v3);
      sg_free_table(ipa_wigig_ctx + v6 + 176, v7);
      v8 = (_QWORD *)(ipa_wigig_ctx + v6);
      v8[18] = 0;
      v8[19] = 0;
      v8[20] = 0;
      v8[21] = 0;
      v8[22] = 0;
      v8[23] = 0;
      v8[24] = 0;
      v8[25] = 0;
      v8[26] = 0;
      v8[27] = 0;
      v8[16] = 0;
      v8[17] = 0;
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_12:
        result = ipa3_get_ipc_logbuf_low();
        if ( result )
        {
          v12 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v12, "ipa_wigig %s:%d exit\n", "ipa_wigig_clean_pipe_info", 753);
          return 0;
        }
        return result;
      }
    }
    else
    {
      v9 = (_QWORD *)(v5 + ((unsigned __int64)a1 << 6));
      v9[6] = 0;
      v9[7] = 0;
      v9[4] = 0;
      v9[5] = 0;
      v9[2] = 0;
      v9[3] = 0;
      *v9 = 0;
      v9[1] = 0;
      if ( !ipa3_get_ipc_logbuf() )
        goto LABEL_12;
    }
    v10 = ipa3_get_ipc_logbuf();
    ipc_log_string(v10, "ipa_wigig %s:%d exit\n", "ipa_wigig_clean_pipe_info", 753);
    goto LABEL_12;
  }
  printk(&unk_3FA00D, "ipa_wigig_clean_pipe_info");
  if ( ipa3_get_ipc_logbuf() )
  {
    v13 = ipa3_get_ipc_logbuf();
    ipc_log_string(v13, "ipa_wigig %s:%d invalid index %d\n", "ipa_wigig_clean_pipe_info", 735, a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v14 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v14, "ipa_wigig %s:%d invalid index %d\n", "ipa_wigig_clean_pipe_info", 735, a1);
  }
  return 4294967274LL;
}
