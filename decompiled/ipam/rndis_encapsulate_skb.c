_DWORD *__fastcall rndis_encapsulate_skb(_DWORD *a1, __int64 a2)
{
  int v2; // w21
  _DWORD *v3; // x19
  int v4; // w4
  __int64 v5; // x0
  __int64 v7; // x22
  _DWORD *v9; // x0

  v2 = a1[28];
  if ( (unsigned int)(a1[56] - a1[54]) > 0x2B )
  {
    v3 = a1;
LABEL_3:
    if ( *(_BYTE *)(a2 + 208) == 1 )
    {
      v4 = *((unsigned __int16 *)v3 + 90);
      if ( v4 != 129 )
      {
        if ( ipa_rndis_logbuf )
          ipc_log_string(
            ipa_rndis_logbuf,
            "RNDIS_IPA %s:%d ether_type != ETH_P_8021Q && vlan, prot = 0x%X\n",
            "rndis_encapsulate_skb",
            2052,
            v4);
      }
    }
    v5 = skb_push(v3, 44);
    *(_QWORD *)(v5 + 16) = 0;
    *(_QWORD *)(v5 + 24) = 0;
    *(_QWORD *)(v5 + 32) = 0;
    *(_QWORD *)v5 = 0x2C00000001LL;
    *(_QWORD *)(v5 + 8) = 36;
    *(_DWORD *)(v5 + 40) = 0;
    *(_DWORD *)(v5 + 4) = v2 + 44;
    *(_DWORD *)(v5 + 12) = v2;
    return v3;
  }
  v7 = a2;
  v9 = (_DWORD *)skb_copy_expand(a1, 44, 0, 2080);
  if ( v9 )
  {
    v3 = v9;
    if ( ipa_rndis_logbuf )
      ipc_log_string(
        ipa_rndis_logbuf,
        "RNDIS_IPA %s:%d skb expanded. old %pK new %pK\n",
        "rndis_encapsulate_skb",
        2043,
        a1,
        v9);
    dev_kfree_skb_any_reason(a1, 2);
    a2 = v7;
    goto LABEL_3;
  }
  if ( (unsigned int)__ratelimit(&rndis_encapsulate_skb__rs, "rndis_encapsulate_skb") )
  {
    _ReadStatusReg(SP_EL0);
    printk(&unk_3D4D18, "rndis_encapsulate_skb");
  }
  if ( ipa_rndis_logbuf )
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d no memory for skb expand\n", "rndis_encapsulate_skb", 2039);
  return a1;
}
