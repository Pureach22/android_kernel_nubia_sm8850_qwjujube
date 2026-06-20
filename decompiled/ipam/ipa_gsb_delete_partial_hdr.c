__int64 __fastcall ipa_gsb_delete_partial_hdr(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  int v4; // w9
  int v5; // w10
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  result = _kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 20);
  v3 = result;
  if ( result )
  {
    v4 = *(_DWORD *)(a1 + 88);
    v5 = *(_DWORD *)(a1 + 92);
    *(_WORD *)result = 513;
    *(_DWORD *)(result + 4) = v4;
    *(_DWORD *)(result + 12) = v5;
    if ( (unsigned int)ipa_del_hdr((_BYTE *)result) )
    {
      printk(&unk_3B0DAD, "ipa_gsb_delete_partial_hdr");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(ipc_logbuf, "ipa_gsb %s:%d failed to delete partial hdr\n", "ipa_gsb_delete_partial_hdr", 369);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipa_gsb %s:%d failed to delete partial hdr\n",
          "ipa_gsb_delete_partial_hdr",
          369);
      }
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v6 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v6,
        "ipa_gsb %s:%d deleted partial hdr hdl for ipv4: %d\n",
        "ipa_gsb_delete_partial_hdr",
        372,
        *(_DWORD *)(a1 + 88));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v7 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v7,
        "ipa_gsb %s:%d deleted partial hdr hdl for ipv4: %d\n",
        "ipa_gsb_delete_partial_hdr",
        372,
        *(_DWORD *)(a1 + 88));
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v8 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v8,
        "ipa_gsb %s:%d deleted partial hdr hdl for ipv6: %d\n",
        "ipa_gsb_delete_partial_hdr",
        374,
        *(_DWORD *)(a1 + 92));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v9 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v9,
        "ipa_gsb %s:%d deleted partial hdr hdl for ipv6: %d\n",
        "ipa_gsb_delete_partial_hdr",
        374,
        *(_DWORD *)(a1 + 92));
    }
    return kfree(v3);
  }
  return result;
}
