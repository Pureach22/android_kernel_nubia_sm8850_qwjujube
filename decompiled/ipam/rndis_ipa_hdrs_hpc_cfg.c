__int64 __fastcall rndis_ipa_hdrs_hpc_cfg(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  unsigned int v4; // w0
  int v5; // w9
  unsigned int v6; // w21
  _QWORD v8[4]; // [xsp+0h] [xbp-30h] BYREF
  int v9; // [xsp+20h] [xbp-10h]
  __int64 v10; // [xsp+28h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  memset(v8, 0, sizeof(v8));
  if ( ipa_rndis_logbuf )
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d begin\n", "rndis_ipa_hdrs_hpc_cfg", 1708);
  v2 = _kmalloc_cache_noprof(scnprintf, 3520, 312);
  v3 = v2;
  if ( v2 )
  {
    strcpy((char *)(v2 + 4), "rndis");
    *(_QWORD *)(v2 + 36) = 0x2C00000001LL;
    *(_QWORD *)(v2 + 44) = 36;
    *(_BYTE *)(v2 + 291) = 44;
    *(_QWORD *)(v2 + 300) = -1;
    *(_QWORD *)(v2 + 52) = 0;
    *(_QWORD *)(v2 + 60) = 0;
    *(_QWORD *)(v2 + 68) = 0;
    *(_DWORD *)(v2 + 76) = 0;
    *(_BYTE *)(v2 + 296) = 0;
    *(_WORD *)v2 = 257;
    v4 = ipa3_add_hdr_hpc(v2);
    if ( v4 )
    {
      v6 = v4;
      _ReadStatusReg(SP_EL0);
      printk(&unk_3AECCD, "rndis_ipa_hdrs_hpc_cfg");
      if ( ipa_rndis_logbuf )
        ipc_log_string(
          ipa_rndis_logbuf,
          "RNDIS_IPA %s:%d Fail on Header-Insertion(%d)\n",
          "rndis_ipa_hdrs_hpc_cfg",
          1727,
          v6);
    }
    else if ( *(_DWORD *)(v3 + 304) )
    {
      _ReadStatusReg(SP_EL0);
      printk(&unk_3BD284, "rndis_ipa_hdrs_hpc_cfg");
      if ( ipa_rndis_logbuf )
        ipc_log_string(
          ipa_rndis_logbuf,
          "RNDIS_IPA %s:%d Fail on Header-Insertion rndis(%d)\n",
          "rndis_ipa_hdrs_hpc_cfg",
          1732,
          *(_DWORD *)(v3 + 304));
      v6 = *(_DWORD *)(v3 + 304);
    }
    else
    {
      v5 = *(_DWORD *)(v3 + 300);
      v9 = 19;
      LODWORD(v8[0]) = 1768189554;
      *(_DWORD *)(a1 + 228) = v5;
      WORD2(v8[0]) = 115;
      if ( !(unsigned int)ipa_set_pkt_init_ex_hdr_ofst((__int64)v8, 1) && ipa_rndis_logbuf )
        ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d end\n", "rndis_ipa_hdrs_hpc_cfg", 1743);
      v6 = 0;
    }
    kfree(v3);
  }
  else
  {
    v6 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v6;
}
