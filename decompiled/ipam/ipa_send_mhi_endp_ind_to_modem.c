__int64 ipa_send_mhi_endp_ind_to_modem()
{
  unsigned int v0; // w12
  unsigned int v1; // w13
  int v2; // w19
  unsigned int v3; // w10
  unsigned int v4; // w9
  int v5; // w21
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 result; // x0
  _BYTE s[508]; // [xsp+8h] [xbp-208h] BYREF
  int v11; // [xsp+204h] [xbp-Ch]
  __int64 v12; // [xsp+208h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(unsigned __int8 *)(ipa3_ctx + 32244) >= 0x18uLL )
    __break(0x5512u);
  if ( ipa3_ep_mapping[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244) + 5720] != 1
    || (v0 = *(_DWORD *)&ipa3_ep_mapping[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244) + 5740], (v0 & 0x80000000) != 0) )
  {
    v2 = -1;
  }
  else
  {
    if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x14u )
      v1 = 31;
    else
      v1 = 36;
    if ( v0 >= v1 )
      v2 = -1;
    else
      v2 = *(_DWORD *)&ipa3_ep_mapping[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244) + 5740];
  }
  if ( ipa3_ep_mapping[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244) + 5772] != 1
    || (v3 = *(_DWORD *)&ipa3_ep_mapping[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244) + 5792], (v3 & 0x80000000) != 0) )
  {
    v5 = -1;
  }
  else
  {
    if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x14u )
      v4 = 31;
    else
      v4 = 36;
    if ( v3 >= v4 )
      v5 = -1;
    else
      v5 = *(_DWORD *)&ipa3_ep_mapping[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244) + 5792];
  }
  mutex_lock(ipa3_ctx + 29472);
  if ( *(_BYTE *)(ipa3_ctx + 51096) == 1 && *(_BYTE *)(ipa3_ctx + 51296) == 6 )
  {
    mutex_unlock(ipa3_ctx + 29472);
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(
          v7,
          "ipa %s:%d Sending MHI end point indication to modem\n",
          "ipa_send_mhi_endp_ind_to_modem",
          14466);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
        ipc_log_string(
          v8,
          "ipa %s:%d Sending MHI end point indication to modem\n",
          "ipa_send_mhi_endp_ind_to_modem",
          14466);
    }
    memset(s, 0, sizeof(s));
    s[0] = 1;
    s[504] = 1;
    *(_DWORD *)&s[4] = 2;
    *(_QWORD *)&s[8] = 0xB00000001LL;
    v11 = 2;
    *(_DWORD *)&s[16] = v5;
    *(_DWORD *)&s[20] = 2;
    *(_QWORD *)&s[24] = 0xA00000001LL;
    *(_DWORD *)&s[32] = v2;
    *(_DWORD *)&s[36] = 2;
    result = ipa3_qmi_send_endp_desc_indication((__int64)s);
  }
  else
  {
    mutex_unlock(ipa3_ctx + 29472);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
