__int64 __fastcall sde_encoder_handle_self_refresh(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x22
  __int64 v4; // x8
  __int64 v5; // x21
  __int64 v6; // x23
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 (__fastcall *v9)(_QWORD); // x8
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x4
  __int64 v13; // x5
  __int64 v14; // x6
  int v15; // w7
  __int64 result; // x0
  void *v17; // x0

  v1 = a1 - 1144;
  if ( a1 == 1144 )
    return printk(&unk_268E21, "sde_encoder_handle_self_refresh");
  v2 = a1 - 816;
  if ( !*(_QWORD *)(a1 - 816) )
    return printk(&unk_268E21, "sde_encoder_handle_self_refresh");
  if ( !*(_QWORD *)v1 )
  {
    v17 = &unk_26FCAB;
    goto LABEL_24;
  }
  v4 = *(_QWORD *)(*(_QWORD *)v1 + 56LL);
  if ( !v4 || (v5 = *(_QWORD *)(v4 + 8)) == 0 )
  {
    v17 = &unk_234896;
LABEL_24:
    printk(v17, "sde_encoder_get_kms");
    v5 = 0;
  }
  v6 = *(_QWORD *)(*(_QWORD *)v2 + 8LL);
  if ( !v6 )
    return printk(&unk_220C83, "sde_encoder_handle_self_refresh");
  if ( !v5 )
    return printk(&unk_26C6E1, "sde_encoder_handle_self_refresh");
  v7 = *(_QWORD *)(v5 + 6384);
  if ( !v7 )
    goto LABEL_14;
  mutex_lock(v7);
  v8 = *(_QWORD *)(v5 + 6384);
  if ( !v8 )
    goto LABEL_14;
  v9 = *(__int64 (__fastcall **)(_QWORD))(v8 + 88);
  if ( !v9 )
    goto LABEL_14;
  if ( *((_DWORD *)v9 - 1) != 1370937740 )
    __break(0x8228u);
  if ( (v9(v5) & 1) != 0 )
  {
LABEL_14:
    if ( *(_BYTE *)(a1 - 395) != 1 )
    {
      sde_connector_trigger_cmd_self_refresh(*(_QWORD *)(*(_QWORD *)v2 + 8LL));
      result = *(_QWORD *)(v5 + 6384);
      if ( !result )
        return result;
      return mutex_unlock(result);
    }
    mutex_lock(v6 + 4592);
    sde_encoder_handle_video_psr_self_refresh(v1, 1, v10, v11, v12, v13, v14, v15);
    mutex_unlock(v6 + 4592);
  }
  result = *(_QWORD *)(v5 + 6384);
  if ( !result )
    return result;
  return mutex_unlock(result);
}
