__int64 __fastcall rndis_ipa_hdrs_destroy(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  int v4; // w9
  int v5; // w10
  unsigned int v6; // w20

  v2 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 20);
  v3 = v2;
  if ( v2 )
  {
    v4 = *(_DWORD *)(a1 + 40);
    v5 = *(_DWORD *)(a1 + 44);
    *(_WORD *)v2 = 513;
    *(_DWORD *)(v2 + 4) = v4;
    *(_DWORD *)(v2 + 12) = v5;
    v6 = ipa_del_hdr((_BYTE *)v2);
    if ( v6 || *(_DWORD *)(v3 + 8) || *(_DWORD *)(v3 + 16) )
    {
      _ReadStatusReg(SP_EL0);
      printk(&unk_3D1CD9, "rndis_ipa_hdrs_destroy");
      if ( ipa_rndis_logbuf )
        ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d ipa_del_hdr failed\n", "rndis_ipa_hdrs_destroy", 1850);
    }
    else if ( ipa_rndis_logbuf )
    {
      ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d hdrs deletion done\n", "rndis_ipa_hdrs_destroy", 1852);
    }
    kfree(v3);
  }
  else
  {
    return (unsigned int)-12;
  }
  return v6;
}
