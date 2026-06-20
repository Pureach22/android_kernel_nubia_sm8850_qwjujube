__int64 __fastcall rndis_ipa_register_properties(char a1)
{
  int v2; // w10
  unsigned int v3; // w19
  _QWORD v5[2]; // [xsp+0h] [xbp-300h] BYREF
  _QWORD v6[2]; // [xsp+10h] [xbp-2F0h] BYREF
  _QWORD v7[40]; // [xsp+20h] [xbp-2E0h] BYREF
  int v8; // [xsp+160h] [xbp-1A0h]
  int v9; // [xsp+164h] [xbp-19Ch]
  _DWORD v10[100]; // [xsp+168h] [xbp-198h] BYREF
  __int64 v11; // [xsp+2F8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  memset(&v10[1], 0, 0x188u);
  memset(&v7[1], 0, 0x138u);
  v5[0] = 0;
  if ( ipa_rndis_logbuf )
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d begin\n", "rndis_ipa_register_properties", 1899);
  *(_QWORD *)&v10[41] = *(_QWORD *)"rndis_eth_ipv4";
  if ( (a1 & 1) != 0 )
    v2 = 3;
  else
    v2 = 1;
  strcpy((char *)&v10[42] + 3, "th_ipv4");
  v10[39] = 19;
  v10[89] = 19;
  strcpy((char *)&v10[91], "rndis_eth_ipv6");
  v6[1] = v10;
  v10[0] = 0;
  v10[49] = v2;
  v10[50] = 1;
  v10[99] = v2;
  LODWORD(v6[0]) = 2;
  v5[1] = v7;
  v7[0] = 0;
  HIDWORD(v7[19]) = 18;
  LODWORD(v7[20]) = v2;
  *(_QWORD *)((char *)&v7[20] + 4) = 1;
  v8 = 18;
  v9 = v2;
  LODWORD(v5[0]) = 2;
  v3 = ipa_register_intf((__int64)"rndis0", (__int64)v6, (__int64)v5);
  if ( v3 )
  {
    _ReadStatusReg(SP_EL0);
    printk(&unk_4001FA, "rndis_ipa_register_properties");
    if ( !ipa_rndis_logbuf )
      goto LABEL_11;
    ipc_log_string(
      ipa_rndis_logbuf,
      "RNDIS_IPA %s:%d fail on Tx/Rx properties registration\n",
      "rndis_ipa_register_properties",
      1936);
  }
  else
  {
    if ( !ipa_rndis_logbuf )
      goto LABEL_11;
    ipc_log_string(
      ipa_rndis_logbuf,
      "RNDIS_IPA %s:%d Tx/Rx properties registration done\n",
      "rndis_ipa_register_properties",
      1938);
  }
  if ( ipa_rndis_logbuf )
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d end\n", "rndis_ipa_register_properties", 1940);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v3;
}
