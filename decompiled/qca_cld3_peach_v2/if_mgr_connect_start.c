__int64 __fastcall if_mgr_connect_start(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v4; // x0
  unsigned __int8 mode_specific_conn_info; // w0
  int v6; // w24
  unsigned __int8 v7; // w21
  unsigned __int8 sap_mode_info; // w0
  int v9; // w23
  unsigned __int8 v10; // w22
  int v11; // w8
  __int64 v12; // x22
  __int64 v13; // x24
  int v14; // w21
  bool v15; // zf
  int v16; // w25
  int is_mlo_sta_nan_ndi_allowed; // w0
  __int64 result; // x0
  int v19; // [xsp+0h] [xbp-10h] BYREF
  char v20; // [xsp+4h] [xbp-Ch]
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 216);
  if ( !v1 || (v2 = *(_QWORD *)(v1 + 80)) == 0 )
  {
    result = 16;
    goto LABEL_39;
  }
  v4 = *(_QWORD *)(v1 + 80);
  v20 = 0;
  v19 = 0;
  mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(v4, 0, &v19, 0);
  v6 = mode_specific_conn_info;
  if ( mode_specific_conn_info >= 6u )
LABEL_40:
    __break(0x5512u);
  v7 = mode_specific_conn_info;
  sap_mode_info = policy_mgr_get_sap_mode_info(v2, 0, (char *)&v19 + mode_specific_conn_info);
  v9 = *(_DWORD *)(a1 + 16);
  v10 = sap_mode_info;
  if ( (v9 | 2) == 2 && (wlan_mlme_is_aux_emlsr_support(v2) & 1) == 0 )
    wlan_handle_emlsr_sta_concurrency(v2, 1, 0);
  if ( v9 != 2 && !(v10 | v7) )
    goto LABEL_36;
  v11 = v10;
  v12 = (unsigned int)v10 + v6;
  if ( !(v11 + v6) )
  {
    if ( v9 != 2 )
      goto LABEL_35;
    v14 = 1;
    goto LABEL_31;
  }
  v13 = 0;
  LOBYTE(v14) = 1;
  if ( v9 )
    v15 = 0;
  else
    v15 = v11 == 1;
  v16 = !v15;
  do
  {
    if ( v13 == 5 )
      goto LABEL_40;
    v14 = (*((unsigned __int8 *)&v19 + v13) != *(unsigned __int8 *)(a1 + 168)) & (unsigned __int8)v14;
    if ( (*(_BYTE *)(a1 + 60) & 2) != 0 )
    {
      is_mlo_sta_nan_ndi_allowed = wlan_is_mlo_sta_nan_ndi_allowed(v2);
      if ( ((is_mlo_sta_nan_ndi_allowed | v16) & 1) != 0 )
      {
        v14 &= ~is_mlo_sta_nan_ndi_allowed;
        goto LABEL_17;
      }
    }
    else if ( (v16 & 1) != 0 )
    {
      goto LABEL_17;
    }
    if ( (ucfg_nan_is_sta_sap_ndp_supported(v2) & 1) != 0 )
      v14 &= *(unsigned __int8 *)(a1 + 60) >> 1;
LABEL_17:
    ++v13;
  }
  while ( v12 != v13 );
  if ( v9 == 2 )
  {
LABEL_31:
    if ( (ucfg_nan_is_sta_p2p_ndp_supported(v2) & 1) == 0 && v14 )
      ucfg_nan_disable_concurrency(v2);
    wlan_tdls_handle_p2p_client_connect(v2, a1);
    goto LABEL_36;
  }
  if ( v14 )
LABEL_35:
    ucfg_nan_disable_concurrency(v2);
LABEL_36:
  if ( (ucfg_nan_is_sta_nan_ndi_4_port_allowed(v2) & 1) == 0 )
    ucfg_nan_check_and_disable_unsupported_ndi(v2, 0);
  result = 0;
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
