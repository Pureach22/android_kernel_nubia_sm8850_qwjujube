__int64 __fastcall hfi_connector_prepare_commit(_DWORD *a1, _QWORD *a2)
{
  __int64 v4; // x8
  __int64 v5; // x8
  unsigned int v6; // w21
  __int64 cmd_buf; // x0
  __int64 result; // x0
  void *v9; // x0
  unsigned int v10; // w19

  if ( !a1 )
  {
    printk(&unk_211DA1, "hfi_connector_prepare_commit");
    return 4294967274LL;
  }
  if ( *(_QWORD *)a1 && (v4 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) != 0 )
  {
    v5 = *(_QWORD *)(v4 + 8);
    if ( v5 )
      goto LABEL_5;
    v9 = &unk_234896;
  }
  else
  {
    v9 = &unk_242658;
  }
  printk(v9, "sde_connector_get_kms");
  v5 = 0;
LABEL_5:
  v6 = a1[685];
  cmd_buf = hfi_kms_get_cmd_buf(*(_QWORD *)(v5 + 6440), v6, 1);
  if ( !cmd_buf )
  {
    printk(&unk_220609, "hfi_connector_prepare_commit");
    return 4294967274LL;
  }
  if ( !a2 )
  {
    printk(&unk_211DA1, "hfi_conn_add_hfi_cmds");
    v10 = -22;
LABEL_16:
    printk(&unk_26538A, "hfi_connector_prepare_commit");
    return v10;
  }
  result = hfi_connector_populate_props(cmd_buf, v6, (__int64)a1, a2);
  if ( (_DWORD)result )
  {
    v10 = result;
    goto LABEL_16;
  }
  return result;
}
