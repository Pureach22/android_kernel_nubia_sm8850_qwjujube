__int64 __fastcall ipa_is_vlan_mode(unsigned int a1, unsigned __int8 *a2)
{
  char v4; // w23
  int v5; // w5
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 result; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0

  if ( !a2 )
  {
    printk(&unk_3CA71E, "ipa_is_vlan_mode");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d NULL out param\n", "ipa_is_vlan_mode", 11674);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d NULL out param\n", "ipa_is_vlan_mode", 11674);
        return 4294967274LL;
      }
    }
    return 4294967274LL;
  }
  if ( a1 >= 5 )
  {
    printk(&unk_3F8E02, "ipa_is_vlan_mode");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d invalid iface %d\n", "ipa_is_vlan_mode", 11679, a1);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
      {
        ipc_log_string(v17, "ipa %s:%d invalid iface %d\n", "ipa_is_vlan_mode", 11679, a1);
        return 4294967274LL;
      }
    }
    return 4294967274LL;
  }
  if ( ipa3_ctx
    && (mutex_lock(ipa3_ctx + 29472), v4 = *(_BYTE *)(ipa3_ctx + 43637), mutex_unlock(ipa3_ctx + 29472), (v4 & 1) != 0) )
  {
    v5 = *(unsigned __int8 *)(ipa3_ctx + a1 + 44848);
    *a2 = v5;
    v6 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 0;
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d Driver %d vlan mode is %d\n", "ipa_is_vlan_mode", 11690, a1, v5);
      v6 = ipa3_ctx;
    }
    result = *(_QWORD *)(v6 + 34160);
    if ( result )
    {
      ipc_log_string(result, "ipa %s:%d Driver %d vlan mode is %d\n", "ipa_is_vlan_mode", 11690, a1, *a2);
      return 0;
    }
  }
  else
  {
    printk(&unk_3CD847, "ipa_is_vlan_mode");
    v9 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 4294967277LL;
    v10 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v10 )
    {
      ipc_log_string(v10, "ipa %s:%d IPA is not ready yet\n", "ipa_is_vlan_mode", 11684);
      v9 = ipa3_ctx;
    }
    v11 = *(_QWORD *)(v9 + 34160);
    if ( v11 )
    {
      ipc_log_string(v11, "ipa %s:%d IPA is not ready yet\n", "ipa_is_vlan_mode", 11684);
      return 4294967277LL;
    }
    else
    {
      return 4294967277LL;
    }
  }
  return result;
}
