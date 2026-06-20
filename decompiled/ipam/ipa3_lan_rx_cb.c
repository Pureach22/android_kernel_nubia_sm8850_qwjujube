__int64 __fastcall ipa3_lan_rx_cb(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x0
  unsigned int ep_mapping; // w21
  int v6; // w20
  char v7; // w24
  __int64 v8; // x23
  __int64 size; // x1
  int v10; // w21
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  _DWORD *v14; // x21
  __int64 v15; // x20
  __int64 result; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // [xsp+8h] [xbp-18h] BYREF
  int v21; // [xsp+10h] [xbp-10h]
  __int64 v22; // [xsp+18h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a3 + 224);
  v21 = 0;
  v20 = 0;
  ipahal_pkt_status_parse_thin(v4, &v20);
  ep_mapping = (unsigned __int8)v21;
  v6 = HIDWORD(v20);
  v7 = BYTE1(v21);
  if ( *(_BYTE *)(ipa3_ctx + 32267) == 1
    && (((__int64 (__fastcall *)(_QWORD))ipa_wdi_opt_dpath_ctrl_enabled)(0) & 1) != 0
    && !*(_DWORD *)(ipa3_ctx + 45216)
    && (unsigned int)ipa_get_ep_mapping(52) == ep_mapping )
  {
    ep_mapping = ipa_get_ep_mapping(12);
  }
  if ( ep_mapping >= 0x25 )
    __break(0x5512u);
  if ( ep_mapping >= *(_DWORD *)(ipa3_ctx + 34308)
    || (v8 = ipa3_ctx + 480LL * ep_mapping + 168, *(_DWORD *)(ipa3_ctx + 480LL * ep_mapping + 624)) )
  {
    printk(&unk_3EEEAB, "ipa3_lan_rx_cb");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v18 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v18 )
      {
        ipc_log_string(v18, "ipa %s:%d drop pipe=%d\n", "ipa3_lan_rx_cb", 4528, ep_mapping);
        v17 = ipa3_ctx;
      }
      v19 = *(_QWORD *)(v17 + 34160);
      if ( v19 )
        ipc_log_string(v19, "ipa %s:%d drop pipe=%d\n", "ipa3_lan_rx_cb", 4528, ep_mapping);
    }
    goto LABEL_33;
  }
  if ( (_DWORD)v20 )
  {
    size = (unsigned int)ipahal_pkt_status_get_size();
  }
  else
  {
    if ( (((__int64 (*)(void))lan_coal_enabled)() & 1) != 0 )
      v10 = 0;
    else
      v10 = 2;
    size = (unsigned int)ipahal_pkt_status_get_size() + v10;
  }
  skb_pull(a3, size);
  *(_BYTE *)(a3 + 44) = v7;
  v11 = ipa3_ctx;
  *(_WORD *)(a3 + 40) = HIWORD(v6);
  if ( v11 )
  {
    v12 = *(_QWORD *)(v11 + 34160);
    if ( !v12
      || (ipc_log_string(v12, "ipa %s:%d meta_data: 0x%x cb: 0x%x\n", "ipa3_lan_rx_cb", 4548, v6, *(_DWORD *)(a3 + 40)),
          (v11 = ipa3_ctx) != 0) )
    {
      v13 = *(_QWORD *)(v11 + 34160);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d ucp: %d\n", "ipa3_lan_rx_cb", 4549, *(unsigned __int8 *)(a3 + 44));
        v11 = ipa3_ctx;
      }
    }
  }
  raw_spin_lock(v11 + 32048);
  if ( *(_DWORD *)(v8 + 456) || !*(_DWORD *)v8 || (v14 = *(_DWORD **)(v8 + 376)) == nullptr )
  {
    raw_spin_unlock(ipa3_ctx + 32048);
LABEL_33:
    result = dev_kfree_skb_any_reason(a3, 2);
    goto LABEL_26;
  }
  v15 = *(_QWORD *)(v8 + 368);
  raw_spin_unlock(ipa3_ctx + 32048);
  if ( *(v14 - 1) != 420538815 )
    __break(0x8235u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v14)(v15, 0, a3);
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
