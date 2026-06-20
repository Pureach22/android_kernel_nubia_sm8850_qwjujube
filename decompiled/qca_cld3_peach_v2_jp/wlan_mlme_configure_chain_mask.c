__int64 __fastcall wlan_mlme_configure_chain_mask(__int64 a1)
{
  unsigned __int8 *psoc_ext_obj_fl; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned __int8 *v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v28; // w23
  int v29; // w24
  int v30; // w20
  int v31; // w22
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  int v48; // w25
  unsigned int v49; // w21
  __int64 result; // x0
  int v51; // w8
  unsigned int v52; // w25
  unsigned int v53; // w27
  int v54; // w8
  _DWORD *v55; // x8
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int v64; // w19
  int v65; // w8
  _DWORD *v66; // x9
  int v67; // w8
  _DWORD *v68; // x9
  int v69; // w8
  _DWORD *v70; // x9
  int v71; // w8
  _DWORD *v72; // x9
  _QWORD v73[7]; // [xsp+8h] [xbp-38h] BYREF

  v73[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  psoc_ext_obj_fl = (unsigned __int8 *)mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    goto LABEL_5;
  v11 = psoc_ext_obj_fl;
  memset(v73, 0, 48);
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: txchainmask1x1: %d rxchainmask1x1: %d",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "wlan_mlme_configure_chain_mask",
    *psoc_ext_obj_fl,
    psoc_ext_obj_fl[1]);
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: tx_chain_mask_2g: %d, rx_chain_mask_2g: %d",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "wlan_mlme_configure_chain_mask",
    v11[8],
    v11[9]);
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: tx_chain_mask_5g: %d, rx_chain_mask_5g: %d",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "wlan_mlme_configure_chain_mask",
    v11[10],
    v11[11]);
  v28 = v11[3288];
  v29 = v11[3290];
  v30 = v11[3289];
  v31 = v11[3291];
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: MRC values TX:- 2g %d 5g %d RX:- 2g %d 5g %d",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "wlan_mlme_configure_chain_mask",
    v11[3290],
    v11[3291],
    v11[3288],
    v11[3289]);
  if ( (wlan_mlme_configure_chain_mask_supported(a1) & 1) == 0 )
    goto LABEL_5;
  v48 = *v11;
  if ( *v11 )
  {
    v49 = 1;
    if ( (unsigned int)wma_validate_txrx_chain_mask(1, *v11) )
    {
LABEL_5:
      result = 16;
      goto LABEL_6;
    }
    v51 = 0;
    LODWORD(v73[0]) = 1;
    HIDWORD(v73[0]) = v48;
    v52 = v11[1];
    if ( !v11[1] )
    {
LABEL_12:
      if ( *v11 )
        goto LABEL_14;
      goto LABEL_13;
    }
  }
  else
  {
    v49 = 0;
    v51 = 16;
    v52 = v11[1];
    if ( !v11[1] )
      goto LABEL_12;
  }
  v53 = v51;
  v54 = wma_validate_txrx_chain_mask(2, v52);
  result = v53;
  if ( v54 )
    goto LABEL_6;
  v55 = &v73[v49++];
  *v55 = 2;
  v55[1] = v52;
  if ( *v11 )
    goto LABEL_14;
LABEL_13:
  if ( !v11[1] )
  {
    v65 = v11[8];
    if ( v11[8] && v29 )
    {
      v66 = &v73[v49++];
      *v66 = 72;
      v66[1] = v65;
    }
    v67 = v11[9];
    if ( v11[9] && v28 )
    {
      v68 = &v73[v49++];
      *v68 = 73;
      v68[1] = v67;
    }
    v69 = v11[10];
    if ( v11[10] && v31 )
    {
      v70 = &v73[v49++];
      *v70 = 74;
      v70[1] = v69;
    }
    v71 = v11[11];
    if ( v11[11] && v30 )
    {
      v72 = &v73[v49++];
      *v72 = 75;
      v72[1] = v71;
    }
    goto LABEL_15;
  }
LABEL_14:
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: band agnostic tx/rx chain mask set. skip per band chain mask",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    "wlan_mlme_configure_chain_mask");
LABEL_15:
  result = wma_send_multi_pdev_vdev_set_params(0, 0, v73, v49);
  if ( (_DWORD)result )
  {
    v64 = result;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: failed to send chainmask params",
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      "wlan_mlme_configure_chain_mask");
    result = v64;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
