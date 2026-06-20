__int64 __fastcall ipa_pm_associate_ipa_cons_to_client(unsigned int a1, unsigned int a2)
{
  __int64 ep_mapping; // x0
  unsigned int v5; // w20
  __int64 v6; // x0
  __int64 v7; // x0
  _QWORD *v8; // x0
  __int64 v9; // x13
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 result; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 ipc_logbuf; // x0
  __int64 v23; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0

  if ( !ipa_pm_ctx )
  {
    v21 = printk(&unk_3F575E, "ipa_pm_associate_ipa_cons_to_client");
    ipc_logbuf = ipa3_get_ipc_logbuf(v21);
    if ( ipc_logbuf )
    {
      v23 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(v23, "ipa_pm %s:%d PM_ctx is null\n", "ipa_pm_associate_ipa_cons_to_client", 892);
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( ipc_logbuf_low )
    {
      v25 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_log_string(v25, "ipa_pm %s:%d PM_ctx is null\n", "ipa_pm_associate_ipa_cons_to_client", 892);
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  if ( a1 > 0x23 || a2 >= 0x86 )
  {
    v26 = printk(&unk_3D306F, "ipa_pm_associate_ipa_cons_to_client");
    v27 = ipa3_get_ipc_logbuf(v26);
    if ( v27 )
    {
      v28 = ipa3_get_ipc_logbuf(v27);
      v27 = ipc_log_string(v28, "ipa_pm %s:%d invalid params\n", "ipa_pm_associate_ipa_cons_to_client", 898);
    }
    v29 = ipa3_get_ipc_logbuf_low(v27);
    if ( v29 )
    {
      v30 = ipa3_get_ipc_logbuf_low(v29);
      ipc_log_string(v30, "ipa_pm %s:%d invalid params\n", "ipa_pm_associate_ipa_cons_to_client", 898);
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  mutex_lock(ipa_pm_ctx + 1152);
  if ( !*(_QWORD *)(ipa_pm_ctx + 8LL * a1) )
  {
    mutex_unlock(ipa_pm_ctx + 1152);
    v31 = printk(&unk_3DBA7D, "ipa_pm_associate_ipa_cons_to_client");
    v32 = ipa3_get_ipc_logbuf(v31);
    if ( v32 )
    {
      v33 = ipa3_get_ipc_logbuf(v32);
      v32 = ipc_log_string(v33, "ipa_pm %s:%d Client is NULL\n", "ipa_pm_associate_ipa_cons_to_client", 905);
    }
    v34 = ipa3_get_ipc_logbuf_low(v32);
    if ( v34 )
    {
      v35 = ipa3_get_ipc_logbuf_low(v34);
      ipc_log_string(v35, "ipa_pm %s:%d Client is NULL\n", "ipa_pm_associate_ipa_cons_to_client", 905);
      return 0xFFFFFFFFLL;
    }
    return 0xFFFFFFFFLL;
  }
  ep_mapping = ipa_get_ep_mapping(a2);
  if ( (ep_mapping & 0x80000000) == 0 )
  {
    v5 = ep_mapping;
    v6 = ipa3_get_ipc_logbuf(ep_mapping);
    if ( v6 )
    {
      v7 = ipa3_get_ipc_logbuf(v6);
      v6 = ipc_log_string(
             v7,
             "ipa_pm %s:%d Mapping pipe %d to client %d\n",
             "ipa_pm_associate_ipa_cons_to_client",
             917,
             v5,
             a1);
    }
    v8 = (_QWORD *)ipa3_get_ipc_logbuf_low(v6);
    if ( v8 )
    {
      v10 = ipa3_get_ipc_logbuf_low(v8);
      v8 = (_QWORD *)ipc_log_string(
                       v10,
                       "ipa_pm %s:%d Mapping pipe %d to client %d\n",
                       "ipa_pm_associate_ipa_cons_to_client",
                       917,
                       v5,
                       a1);
    }
    if ( v5 > 0x23 )
    {
      __break(0x5512u);
      *v8 = v9;
      return ipa_pm_activate((char *)v8 + 217);
    }
    v11 = ipa_pm_ctx;
    if ( !*(_QWORD *)(ipa_pm_ctx + 288 + 8LL * v5) )
    {
      *(_QWORD *)(ipa_pm_ctx + 288 + 8LL * v5) = *(_QWORD *)(ipa_pm_ctx + 8LL * a1);
      v12 = mutex_unlock(v11 + 1152);
      v13 = ipa3_get_ipc_logbuf(v12);
      if ( v13 )
      {
        v14 = ipa3_get_ipc_logbuf(v13);
        v13 = ipc_log_string(
                v14,
                "ipa_pm %s:%d Pipe %d is mapped to client %d\n",
                "ipa_pm_associate_ipa_cons_to_client",
                927,
                v5,
                a1);
      }
      result = ipa3_get_ipc_logbuf_low(v13);
      if ( result )
      {
        v16 = ipa3_get_ipc_logbuf_low(result);
        ipc_log_string(
          v16,
          "ipa_pm %s:%d Pipe %d is mapped to client %d\n",
          "ipa_pm_associate_ipa_cons_to_client",
          927,
          v5,
          a1);
        return 0;
      }
      return result;
    }
    mutex_unlock(ipa_pm_ctx + 1152);
    v36 = printk(&unk_3AD279, "ipa_pm_associate_ipa_cons_to_client");
    v37 = ipa3_get_ipc_logbuf(v36);
    if ( v37 )
    {
      v38 = ipa3_get_ipc_logbuf(v37);
      v37 = ipc_log_string(v38, "ipa_pm %s:%d Pipe is already mapped\n", "ipa_pm_associate_ipa_cons_to_client", 921);
    }
    v39 = ipa3_get_ipc_logbuf_low(v37);
    if ( v39 )
    {
      v40 = ipa3_get_ipc_logbuf_low(v39);
      ipc_log_string(v40, "ipa_pm %s:%d Pipe is already mapped\n", "ipa_pm_associate_ipa_cons_to_client", 921);
      return 0xFFFFFFFFLL;
    }
    return 0xFFFFFFFFLL;
  }
  v17 = mutex_unlock(ipa_pm_ctx + 1152);
  v18 = ipa3_get_ipc_logbuf(v17);
  if ( v18 )
  {
    v19 = ipa3_get_ipc_logbuf(v18);
    v18 = ipc_log_string(v19, "ipa_pm %s:%d Pipe is not used\n", "ipa_pm_associate_ipa_cons_to_client", 913);
  }
  result = ipa3_get_ipc_logbuf_low(v18);
  if ( result )
  {
    v20 = ipa3_get_ipc_logbuf_low(result);
    ipc_log_string(v20, "ipa_pm %s:%d Pipe is not used\n", "ipa_pm_associate_ipa_cons_to_client", 913);
    return 0;
  }
  return result;
}
