__int64 __fastcall gsi_alloc(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x20
  _UNKNOWN ***v4; // x9

  v1 = *(_QWORD *)(a1 + 176);
  v3 = *(unsigned int *)(v1 + 224);
  if ( v1 )
    ipc_log_string(*(_QWORD *)(v1 + 1344), "%s: prot id %d", "gsi_bind_config", v3);
  if ( (unsigned int)v3 >= 5 )
  {
    if ( v1 )
    {
      ipc_log_string(*(_QWORD *)(v1 + 1344), "%s: invalid prot id %d", "gsi_bind_config", v3);
      printk(&unk_11106, "gsi_bind_config");
    }
    return -22;
  }
  else
  {
    v4 = off_12788[v3];
    *(_QWORD *)v1 = off_12760[v3];
    *(_QWORD *)(v1 + 8) = v4;
    *(_QWORD *)(v1 + 72) = gsi_bind;
    *(_QWORD *)(v1 + 80) = gsi_unbind;
    *(_QWORD *)(v1 + 104) = gsi_set_alt;
    *(_QWORD *)(v1 + 112) = gsi_get_alt;
    *(_QWORD *)(v1 + 120) = gsi_disable;
    *(_QWORD *)(v1 + 128) = gsi_setup;
    *(_QWORD *)(v1 + 88) = gsi_free_func;
    *(_QWORD *)(v1 + 160) = gsi_get_status;
    *(_QWORD *)(v1 + 168) = gsi_func_suspend;
    *(_QWORD *)(v1 + 144) = gsi_suspend;
    *(_QWORD *)(v1 + 152) = gsi_resume;
    return *(_QWORD *)(a1 + 176);
  }
}
