__int64 __fastcall sme_send_he_om_ctrl_update(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w19
  __int64 v15; // x24
  _QWORD *context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _QWORD *v25; // x23
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w10
  char v35; // w8
  const char *v36; // x2
  unsigned int v37; // w1
  __int64 result; // x0
  unsigned int v39; // w10
  char v40; // w11
  unsigned int v41; // w10
  unsigned int v42; // w11
  int v43; // w7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // [xsp+0h] [xbp-30h]
  __int64 v69; // [xsp+10h] [xbp-20h] BYREF
  int v70; // [xsp+18h] [xbp-18h] BYREF
  __int64 v71; // [xsp+1Ch] [xbp-14h] BYREF
  __int16 v72; // [xsp+24h] [xbp-Ch]
  __int64 v73; // [xsp+28h] [xbp-8h]

  v11 = a2;
  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 > 5u )
    v15 = 0;
  else
    v15 = *(_QWORD *)(a1 + 17296) + 96LL * a2;
  v71 = 0;
  v70 = 0;
  v69 = 0;
  v72 = 0;
  context = _cds_get_context(54, (__int64)"sme_send_he_om_ctrl_update", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context )
    goto LABEL_23;
  if ( !v15 )
  {
    v36 = "%s: Session does not exist, Session_id: %d";
    v37 = 2;
LABEL_12:
    qdf_trace_msg(0x34u, v37, v36, v17, v18, v19, v20, v21, v22, v23, v24, "sme_validate_session_for_cap_update", v11);
    result = 4294967274LL;
    goto LABEL_24;
  }
  v25 = context;
  if ( !cm_is_vdevid_connected(*(_QWORD *)(a1 + 21632), a2) )
  {
    v36 = "%s: STA is not connected, Session_id: %d";
    v37 = 8;
    goto LABEL_12;
  }
  wlan_get_op_chan_freq_info_vdev_id(*(_QWORD *)(a1 + 21632), a2, &v70, (_DWORD *)&v69 + 1, &v69);
  if ( !a3 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: OMI data is NULL",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "sme_send_he_om_ctrl_update");
LABEL_23:
    result = 4294967291LL;
    goto LABEL_24;
  }
  v34 = *a3 & 0xFFFFFFC3 | 4;
  *a3 = v34;
  if ( *(_BYTE *)(a1 + 21776) == 1 )
    v35 = *(_BYTE *)(a1 + 21777);
  else
    v35 = *(_BYTE *)(v15 + 61) + 7;
  v39 = v34 & 0xFFFFFE07 | ((v35 & 7) << 6);
  *a3 = v39;
  if ( *(_BYTE *)(a1 + 21779) == 1 )
    v40 = *(_BYTE *)(a1 + 21780);
  else
    v40 = *(_BYTE *)(v15 + 61) + 7;
  v41 = v39 & 0xFFFF8FC7 | ((v40 & 7) << 12);
  *a3 = v41;
  if ( *(_BYTE *)(a1 + 21774) == 1 )
    v42 = (*(_BYTE *)(a1 + 21775) & 3) << 9;
  else
    v42 = (v69 & 3) << 9;
  *a3 = v42 | v41 & 0xFFFFF9C7;
  v43 = *(unsigned __int8 *)(a1 + 21778);
  *a3 = v42 & 0xFFFFF7C7 | v41 & 0xFFFFF1C7 | (v43 << 11);
  *a3 = v42 & 0xFFFDF7C7 | v41 & 0xFFFDF1C7 | (v43 << 11) & 0xFFFDFFFF | (*(unsigned __int8 *)(a1 + 21781) << 17) | 3;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: OMI: BW %d TxNSTS %d RxNSS %d ULMU %d, OMI_VHT %d, OMI_HE %d",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "sme_send_he_om_ctrl_update",
    v42 >> 9,
    (v41 >> 12) & 7,
    v35 & 7,
    1,
    1);
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: EHT OMI: BW %d rx nss %d tx nss %d",
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    "sme_send_he_om_ctrl_update",
    (*a3 >> 19) & 1,
    (*a3 >> 18) & 1,
    (*a3 >> 20) & 1);
  qdf_mem_copy(&v71, a3, 4u);
  wlan_mlme_get_bssid_vdev_id(*(_QWORD *)(a1 + 21632), a2, (char *)&v71 + 4);
  LODWORD(v68) = HIBYTE(v72);
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: param val %08X, bssid:%02x:%02x:%02x:**:**:%02x",
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    "sme_send_he_om_ctrl_update",
    (unsigned int)v71,
    BYTE4(v71),
    BYTE5(v71),
    BYTE6(v71),
    v68);
  result = wma_set_peer_param(v25, (char *)&v71 + 4, 28, (unsigned int)v71, v11);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: set_peer_param_cmd returned %d",
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      "sme_send_he_om_ctrl_update",
      (unsigned int)result);
    goto LABEL_23;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
