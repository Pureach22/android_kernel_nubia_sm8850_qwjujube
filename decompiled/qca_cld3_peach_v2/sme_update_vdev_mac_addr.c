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
  __int64 v16; // x8
  __int64 v17; // x0
  int v18; // w22
  __int64 v20; // x8
  char v21; // w24
  unsigned __int8 *v22; // x20
  unsigned int v23; // w21
  _QWORD *peer_by_mac; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int *v33; // x1
  unsigned int v34; // w25
  __int64 v35; // x20
  unsigned int updated; // w21
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 result; // x0
  __int16 v54; // w9
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x4
  __int64 v72; // x5
  __int64 v73; // x6
  __int64 v74; // x7
  int v75; // [xsp+8h] [xbp-18h] BYREF
  __int16 v76; // [xsp+Ch] [xbp-14h]
  int v77; // [xsp+10h] [xbp-10h] BYREF
  __int16 v78; // [xsp+14h] [xbp-Ch]
  __int64 v79; // [xsp+18h] [xbp-8h]

  v79 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v77 = a2;
  v78 = WORD2(a2);
  v16 = *(_QWORD *)(a1 + 216);
  v75 = a3;
  v76 = WORD2(a3);
  if ( v16 )
  {
    v17 = *(_QWORD *)(v16 + 80);
    v18 = *(_DWORD *)(a1 + 16);
    if ( a6 )
      goto LABEL_22;
  }
  else
  {
    v17 = 0;
    v18 = *(_DWORD *)(a1 + 16);
    if ( a6 )
      goto LABEL_22;
  }
  if ( !v18 && (a4 & 1) != 0 )
  {
    v20 = 74;
    if ( (a5 & 1) != 0 )
      v20 = 80;
    v21 = a4;
    v22 = (unsigned __int8 *)(a1 + v20);
    v23 = a5;
    peer_by_mac = wlan_objmgr_get_peer_by_mac(v17, (_BYTE *)(a1 + v20), 2u);
    if ( !peer_by_mac )
    {
      if ( v22 )
      {
        v71 = *v22;
        v72 = v22[1];
        v73 = v22[2];
        v74 = v22[5];
      }
      else
      {
        v73 = 0;
        v71 = 0;
        v72 = 0;
        v74 = 0;
      }
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Self peer not found with MAC addr:%02x:%02x:%02x:**:**:%02x",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "sme_update_vdev_mac_addr",
        v71,
        v72,
        v73,
        v74);
      goto LABEL_32;
    }
    if ( (v23 & 1) != 0 )
      v33 = &v75;
    else
      v33 = &v77;
    v34 = v23;
    v35 = (__int64)peer_by_mac;
    updated = wlan_peer_update_macaddr((__int64)peer_by_mac, v33, v25, v26, v27, v28, v29, v30, v31, v32);
    wlan_objmgr_peer_release_ref(v35, 2u, v37, v38, v39, v40, v41, v42, v43, v44);
    LOBYTE(a5) = v34;
    a4 = v21;
    if ( updated )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "Failed to update self peer MAC address. Status:%d",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        updated,
        v34);
      result = updated;
      goto LABEL_33;
    }
  }
  if ( (a5 & 1) == 0 )
  {
LABEL_20:
    qdf_mem_copy((void *)(a1 + 74), &v77, 6u);
    v54 = v78;
    *(_DWORD *)(a1 + 86) = v77;
    *(_WORD *)(a1 + 90) = v54;
    if ( (a7 & 1) == 0 )
      ucfg_vdev_mgr_cdp_vdev_attach(a1);
LABEL_22:
    if ( v18 != 7 )
    {
      result = 0;
      goto LABEL_33;
    }
    if ( wlan_vdev_mlme_get_cmpt_obj(a1, a8, a9, a10, a11, a12, a13, a14, a15) )
    {
      result = wma_vdev_self_peer_create();
      if ( !(_DWORD)result )
        goto LABEL_33;
      qdf_trace_msg(
        0x34u,
        2u,
        "Failed to create self peer for P2P device mode. Status:%d",
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        (unsigned int)result);
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Invalid vdev MLME context",
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        "sme_update_vdev_mac_addr");
    }
LABEL_32:
    result = 4;
    goto LABEL_33;
  }
  if ( (a4 & 1) == 0 && v18 != 1 || (result = wlan_mlo_mgr_update_mld_addr(a1 + 80, &v75), !(_DWORD)result) )
  {
    qdf_mem_copy((void *)(a1 + 80), &v75, 6u);
    goto LABEL_20;
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
