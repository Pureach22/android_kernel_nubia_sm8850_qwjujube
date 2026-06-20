__int64 ipa3_setup_wlan_ctrl_ready_req()
{
  signed int ep_mapping; // w19
  signed int v1; // w20
  __int64 v2; // x8
  __int64 v3; // x9
  _DWORD *v4; // x10
  int v5; // w0
  __int64 result; // x0
  __int64 v7; // x8
  _DWORD *v8; // x9
  int v9; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-18h] BYREF
  __int64 v11; // [xsp+10h] [xbp-10h]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  ep_mapping = ipa_get_ep_mapping(12);
  v1 = ipa_get_ep_mapping(13);
  v10 = 0;
  v11 = 0;
  raw_spin_lock(ipa3_ctx + 32048);
  if ( (unsigned int)ep_mapping >= 0x24 )
    goto LABEL_16;
  v2 = ipa3_ctx;
  v3 = ipa3_ctx + 168;
  v4 = (_DWORD *)(ipa3_ctx + 168 + 480LL * ep_mapping);
  if ( *v4 )
  {
    if ( (unsigned int)v1 > 0x23 )
      goto LABEL_16;
    if ( *(_DWORD *)(v3 + 480LL * v1) && !v4[114] && !*(_DWORD *)(v3 + 480LL * v1 + 456) )
    {
      HIDWORD(v10) = ep_mapping;
      LODWORD(v11) = v1;
      LOBYTE(v10) = 1;
      v5 = ipa_get_ep_mapping(33);
      v2 = ipa3_ctx;
      HIDWORD(v11) = v5;
    }
  }
  result = raw_spin_unlock(v2 + 32048);
  v7 = ipa3_ctx + 168;
  v8 = (_DWORD *)(ipa3_ctx + 168 + 480LL * ep_mapping);
  if ( !*v8 )
    goto LABEL_15;
  if ( (unsigned int)v1 > 0x23 )
LABEL_16:
    __break(0x5512u);
  if ( *(_DWORD *)(v7 + 480LL * v1) && !v8[114] && !*(_DWORD *)(v7 + 480LL * v1 + 456) && (_BYTE)v10 )
  {
    ipa3_handle_ipa_wlan_opt_dp_set_wlan_ctrl_ready_req((__int64)&v10, &v9);
    result = ipa3_install_dl_opt_wdi_dpath_flt_rules(ep_mapping, v9);
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
