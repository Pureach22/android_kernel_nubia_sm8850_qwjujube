__int64 __fastcall ipa_uc_offload_cleanup(unsigned int a1)
{
  _DWORD *v2; // x20
  __int64 v3; // x21
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0

  if ( a1 - 4 <= 0xFFFFFFFC )
  {
    printk(&unk_3EDA3A, "ipa_uc_offload_cleanup");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_uc_offload %s:%d Invalid client handle %d\n", "ipa_uc_offload_cleanup", 633, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa_uc_offload %s:%d Invalid client handle %d\n",
        "ipa_uc_offload_cleanup",
        633,
        a1);
    }
    return 4294967274LL;
  }
  v2 = (_DWORD *)ipa_uc_offload_ctx[a1];
  if ( !v2 )
  {
    printk(&unk_3EDA3A, "ipa_uc_offload_cleanup");
    if ( ipa3_get_ipc_logbuf() )
    {
      v7 = ipa3_get_ipc_logbuf();
      ipc_log_string(v7, "ipa_uc_offload %s:%d Invalid client handle %d\n", "ipa_uc_offload_cleanup", 639, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v8 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v8, "ipa_uc_offload %s:%d Invalid client handle %d\n", "ipa_uc_offload_cleanup", 639, a1);
    }
    return 4294967274LL;
  }
  if ( v2[1] != 1 )
  {
    printk(&unk_3C5A55, "ipa_uc_offload_cleanup");
    if ( ipa3_get_ipc_logbuf() )
    {
      v9 = ipa3_get_ipc_logbuf();
      ipc_log_string(v9, "ipa_uc_offload %s:%d Invalid State %d\n", "ipa_uc_offload_cleanup", 644, v2[1]);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v10 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v10, "ipa_uc_offload %s:%d Invalid State %d\n", "ipa_uc_offload_cleanup", 644, (unsigned int)v2[1]);
    }
    return 4294967274LL;
  }
  if ( *v2 == 3 )
  {
    ((void (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)((unsigned int)v2[26]);
    ((void (__fastcall *)(_QWORD))ipa_pm_deregister)((unsigned int)v2[26]);
    goto LABEL_11;
  }
  if ( *v2 != 2 )
  {
    printk(&unk_3B9A09, "ipa_uc_offload_cleanup");
    if ( ipa3_get_ipc_logbuf() )
    {
      v11 = ipa3_get_ipc_logbuf();
      ipc_log_string(v11, "ipa_uc_offload %s:%d Invalid Proto :%d\n", "ipa_uc_offload_cleanup", 659, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v12 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v12, "ipa_uc_offload %s:%d Invalid Proto :%d\n", "ipa_uc_offload_cleanup", 659, a1);
    }
    return 4294967274LL;
  }
  ((void (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)((unsigned int)v2[26]);
  ((void (__fastcall *)(_QWORD))ipa_pm_deregister)((unsigned int)v2[26]);
  v3 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 20);
  if ( !v3 )
    return 4294967284LL;
  *(_WORD *)v3 = 513;
  *(_DWORD *)(v3 + 4) = v2[5];
  *(_DWORD *)(v3 + 12) = v2[6];
  if ( (unsigned int)ipa_del_hdr((_BYTE *)v3) )
  {
    printk(&unk_3BCACA, "ipa_uc_ntn_cleanup");
    if ( ipa3_get_ipc_logbuf() )
    {
      v13 = ipa3_get_ipc_logbuf();
      ipc_log_string(v13, "ipa_uc_offload %s:%d fail to delete partial header\n", "ipa_uc_ntn_cleanup", 610);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v14 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v14, "ipa_uc_offload %s:%d fail to delete partial header\n", "ipa_uc_ntn_cleanup", 610);
    }
  }
  else
  {
    if ( !(unsigned int)((__int64 (__fastcall *)(_DWORD *))ipa_deregister_intf)(v2 + 7) )
    {
      kfree(v3);
LABEL_11:
      kfree(v2);
      ipa_uc_offload_ctx[a1] = 0;
      return 0;
    }
    printk(&unk_3C2780, "ipa_uc_ntn_cleanup");
    if ( ipa3_get_ipc_logbuf() )
    {
      v15 = ipa3_get_ipc_logbuf();
      ipc_log_string(v15, "ipa_uc_offload %s:%d fail to delete interface prop\n", "ipa_uc_ntn_cleanup", 616);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v16 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v16, "ipa_uc_offload %s:%d fail to delete interface prop\n", "ipa_uc_ntn_cleanup", 616);
    }
  }
  kfree(v3);
  return 4294967282LL;
}
