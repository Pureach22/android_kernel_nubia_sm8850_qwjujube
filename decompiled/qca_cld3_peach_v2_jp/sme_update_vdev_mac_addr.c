__int64 __fastcall sme_update_vdev_mac_addr(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        char a4,
        unsigned int a5,
        int a6,
        char a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  __int64 v17; // x8
  __int64 v18; // x0
  int v19; // w23
  __int64 v20; // x8
  unsigned int v21; // w22
  unsigned __int8 *v22; // x21
  _QWORD *peer_by_mac; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int *v32; // x1
  unsigned int v33; // w24
  __int64 v34; // x21
  unsigned int updated; // w22
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 result; // x0
  __int16 v53; // w9
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x4
  __int64 v71; // x5
  __int64 v72; // x6
  __int64 v73; // x7
  int v74; // [xsp+8h] [xbp-18h] BYREF
  __int16 v75; // [xsp+Ch] [xbp-14h]
  int v76; // [xsp+10h] [xbp-10h] BYREF
  __int16 v77; // [xsp+14h] [xbp-Ch]
  __int64 v78; // [xsp+18h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v76 = a2;
  v77 = WORD2(a2);
  v17 = *(_QWORD *)(a1 + 152);
  v74 = a3;
  v75 = WORD2(a3);
  if ( v17 )
  {
    v18 = *(_QWORD *)(v17 + 80);
    v19 = *(_DWORD *)(a1 + 16);
    if ( a6 )
      goto LABEL_19;
  }
  else
  {
    v18 = 0;
    v19 = *(_DWORD *)(a1 + 16);
    if ( a6 )
      goto LABEL_19;
  }
  if ( v19 || (a4 & 1) == 0 )
    goto LABEL_15;
  v20 = 74;
  if ( (a5 & 1) != 0 )
    v20 = 80;
  v21 = a5;
  v22 = (unsigned __int8 *)(a1 + v20);
  peer_by_mac = wlan_objmgr_get_peer_by_mac(v18, (_BYTE *)(a1 + v20), 2u);
  if ( !peer_by_mac )
  {
    if ( v22 )
    {
      v70 = *v22;
      v71 = v22[1];
      v72 = v22[2];
      v73 = v22[5];
    }
    else
    {
      v72 = 0;
      v70 = 0;
      v71 = 0;
      v73 = 0;
    }
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Self peer not found with MAC addr:%02x:%02x:%02x:**:**:%02x",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "sme_update_vdev_mac_addr",
      v70,
      v71,
      v72,
      v73);
    goto LABEL_29;
  }
  v32 = (v21 & 1) != 0 ? &v74 : &v76;
  v33 = v21;
  v34 = (__int64)peer_by_mac;
  updated = wlan_peer_update_macaddr((__int64)peer_by_mac, v32, v24, v25, v26, v27, v28, v29, v30, v31);
  wlan_objmgr_peer_release_ref(v34, 2u, v36, v37, v38, v39, v40, v41, v42, v43);
  LOBYTE(a5) = v33;
  if ( !updated )
  {
LABEL_15:
    if ( (a5 & 1) != 0 )
      qdf_mem_copy((void *)(a1 + 80), &v74, 6u);
    qdf_mem_copy((void *)(a1 + 74), &v76, 6u);
    v53 = v77;
    *(_DWORD *)(a1 + 86) = v76;
    *(_WORD *)(a1 + 90) = v53;
    if ( (a7 & 1) == 0 )
      ucfg_vdev_mgr_cdp_vdev_attach(a1);
LABEL_19:
    if ( v19 != 7 )
    {
      result = 0;
      goto LABEL_30;
    }
    if ( wlan_vdev_mlme_get_cmpt_obj(a1, a8, a9, a10, a11, a12, a13, a14, a15) )
    {
      result = wma_vdev_self_peer_create();
      if ( !(_DWORD)result )
        goto LABEL_30;
      qdf_trace_msg(
        0x34u,
        2u,
        "Failed to create self peer for P2P device mode. Status:%d",
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        (unsigned int)result);
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Invalid vdev MLME context",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "sme_update_vdev_mac_addr");
    }
LABEL_29:
    result = 4;
    goto LABEL_30;
  }
  qdf_trace_msg(
    0x34u,
    2u,
    "Failed to update self peer MAC address. Status:%d",
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    updated,
    v33);
  result = updated;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
