__int64 __fastcall lim_check_vht_op_mode_change(
        _QWORD *a1,
        __int64 a2,
        unsigned __int8 a3,
        const void *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v14; // w21
  __int64 v15; // x8
  unsigned __int16 v16; // w8
  __int64 result; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  const void *v20; // x22
  unsigned int peer_phymode; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  const char *v30; // x2
  const char *v31; // x3
  unsigned int ch_width_from_phymode; // w0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x0
  unsigned int v42; // w1
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  _BYTE *v51; // x0
  _BYTE *v52; // x21
  int v53; // w9
  __int16 v54; // w8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // [xsp+8h] [xbp-38h]
  __int64 v64; // [xsp+10h] [xbp-30h] BYREF
  __int64 v65; // [xsp+18h] [xbp-28h]
  __int64 v66; // [xsp+20h] [xbp-20h]
  unsigned int v67; // [xsp+2Ch] [xbp-14h] BYREF
  _QWORD v68[2]; // [xsp+30h] [xbp-10h] BYREF

  v14 = a3;
  v68[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = *(_QWORD *)(a2 + 16);
  v65 = 0;
  v66 = 0;
  v64 = 0;
  if ( (*(_DWORD *)(v15 + 16) & 0xFFFFFFFD) != 0 )
    goto LABEL_2;
  v67 = 0;
  if ( !a2 )
  {
    v30 = "%s: invalid input";
    goto LABEL_11;
  }
  v18 = *(_QWORD *)(v15 + 216);
  if ( !v18 || (v19 = *(_QWORD *)(v18 + 80)) == 0 )
  {
    v30 = "%s: psoc object invalid";
LABEL_11:
    v31 = "lim_get_update_bw_allow";
LABEL_12:
    qdf_trace_msg(0x35u, 2u, v30, a5, a6, a7, a8, a9, a10, a11, a12, v31);
    goto LABEL_13;
  }
  v20 = a4;
  peer_phymode = mlme_get_peer_phymode(v19, (_BYTE *)(a2 + 24), &v67);
  if ( peer_phymode )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: failed to get phy_mode %d mac: %02x:%02x:%02x:**:**:%02x",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "lim_get_update_bw_allow",
      peer_phymode,
      *(unsigned __int8 *)(a2 + 24),
      *(unsigned __int8 *)(a2 + 25),
      *(unsigned __int8 *)(a2 + 26),
      *(unsigned __int8 *)(a2 + 29),
      v63,
      v64,
      v65,
      v66);
LABEL_13:
    result = 0;
    goto LABEL_14;
  }
  ch_width_from_phymode = wlan_mlme_get_ch_width_from_phymode(v67, v22, v23, v24, v25, v26, v27, v28, v29);
  a4 = v20;
  if ( ch_width_from_phymode < v14 )
  {
    if ( !wlan_cm_is_vdev_connected(*(_QWORD *)(a2 + 16), v33, v34, v35, v36, v37, v38, v39, v40) )
      goto LABEL_13;
    qdf_mem_set(&v64, 0x18u, 0);
    v41 = a1[2704];
    v42 = *(_DWORD *)(a2 + 284);
    LODWORD(v64) = v14;
    wlan_reg_set_channel_params_for_pwrmode(v41, v42, 0, (__int64)&v64, 0, v43, v44, v45, v46, v47, v48, v49, v50);
    v51 = (_BYTE *)_qdf_mem_malloc(0x24u, "lim_check_vht_op_mode_change", 5164);
    if ( v51 )
    {
      v52 = v51;
      *v51 = wlan_reg_freq_to_chan(a1[2704], *(_DWORD *)(a2 + 284), a5, a6, a7, a8, a9, a10, a11, a12);
      v53 = v64;
      *((_DWORD *)v52 + 1) = *(_DWORD *)(a2 + 284);
      v54 = *(_WORD *)((char *)&v64 + 5);
      *((_DWORD *)v52 + 3) = v53;
      *(_WORD *)(v52 + 19) = v54;
      LOWORD(v53) = *(_WORD *)(a2 + 28);
      *((_DWORD *)v52 + 7) = *(_DWORD *)(a2 + 24);
      *((_WORD *)v52 + 16) = v53;
      lim_handle_sta_csa_param(a1, v52, 0, v55, v56, v57, v58, v59, v60, v61, v62);
      goto LABEL_3;
    }
    v30 = "%s: csa_param allocation fails";
    v31 = "lim_check_vht_op_mode_change";
    goto LABEL_12;
  }
LABEL_2:
  v16 = *(unsigned __int8 *)(a2 + 10);
  v67 = v14;
  v68[0] = v16;
  qdf_mem_copy((char *)v68 + 2, a4, 6u);
  lim_send_mode_update((__int64)a1, &v67, a2);
  lim_update_tdls_2g_bw(a2);
LABEL_3:
  result = 1;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
