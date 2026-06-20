__int64 __fastcall ml_nlink_ap_csa_start_handler(
        __int64 a1,
        __int64 a2,
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
  __int64 v14; // x4
  unsigned int v15; // w22
  __int64 v16; // x6
  char is_mlo_in_mode_emlsr; // w8
  __int64 result; // x0
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x19
  __int64 link_info; // x0
  __int64 v30; // x2
  unsigned __int64 v31; // x8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  int v40; // w24
  unsigned int v41; // w25
  char v42; // w26
  unsigned int v43; // w27
  _DWORD *v44; // x9
  bool v45; // w11
  __int64 v46; // x1
  unsigned int v47; // w20
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned int updated; // w0
  _BYTE v57[4]; // [xsp+1Ch] [xbp-74h] BYREF
  _BYTE v58[4]; // [xsp+20h] [xbp-70h] BYREF
  _BYTE v59[4]; // [xsp+24h] [xbp-6Ch] BYREF
  __int16 v60; // [xsp+28h] [xbp-68h] BYREF
  char v61; // [xsp+2Ah] [xbp-66h]
  __int16 v62; // [xsp+2Ch] [xbp-64h] BYREF
  unsigned __int8 v63; // [xsp+2Eh] [xbp-62h]
  int v64; // [xsp+30h] [xbp-60h] BYREF
  char v65; // [xsp+34h] [xbp-5Ch]
  __int64 v66; // [xsp+38h] [xbp-58h] BYREF
  int v67; // [xsp+40h] [xbp-50h]
  _QWORD v68[3]; // [xsp+48h] [xbp-48h] BYREF
  __int64 v69; // [xsp+60h] [xbp-30h] BYREF
  unsigned int v70; // [xsp+68h] [xbp-28h]
  _QWORD v71[2]; // [xsp+70h] [xbp-20h] BYREF
  int v72; // [xsp+80h] [xbp-10h]
  __int64 v73; // [xsp+88h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *a3;
  v15 = a3[1];
  v16 = *((unsigned __int8 *)a3 + 8);
  v57[0] = 0;
  v63 = 0;
  v62 = 0;
  v70 = 0;
  v69 = 0;
  v61 = 0;
  v60 = 0;
  memset(v68, 0, sizeof(v68));
  v67 = 0;
  v66 = 0;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: csa from %d to %d wait_set_link %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "ml_nlink_ap_csa_start_handler",
    v14,
    v15,
    v16);
  is_mlo_in_mode_emlsr = policy_mgr_is_mlo_in_mode_emlsr(a1, 0, nullptr);
  result = 0;
  if ( (is_mlo_in_mode_emlsr & 1) == 0 )
    goto LABEL_30;
  if ( (wlan_mlme_is_aux_emlsr_support(a1) & 1) == 0 )
    goto LABEL_29;
  v59[0] = 0;
  v58[0] = 0;
  v65 = 0;
  v64 = 0;
  v72 = 0;
  v71[0] = 0;
  v71[1] = 0;
  policy_mgr_get_ml_sta_info_psoc(a1, v59, v58, (__int64)&v64, (__int64)v71, nullptr, 0, 0);
  if ( (unsigned int)v59[0] - 6 < 0xFFFFFFFB )
    goto LABEL_29;
  v19 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          a1,
          (unsigned __int8)v64,
          90);
  if ( !v19 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: invalid vdev for id %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "ml_nlink_get_affect_ml_sta",
      (unsigned __int8)v64);
LABEL_29:
    result = 0;
    goto LABEL_30;
  }
  v28 = v19;
  link_info = ml_nlink_get_link_info(a1, v19, 1, 3, (int)v68, (int)&v69, (int)&v62, (int)&v60, (__int64)v57);
  v40 = v57[0];
  if ( v57[0] < 2u )
    goto LABEL_26;
  if ( (unsigned __int8)v62 == 255
    || (link_info = policy_mgr_vdev_is_force_inactive(a1, v62), (link_info & 1) != 0)
    || (link_info = wlan_reg_is_24ghz_ch_freq(v69), (link_info & 1) != 0) )
  {
    v41 = 0;
    v42 = 0;
    v43 = 0;
  }
  else
  {
    link_info = policy_mgr_2_freq_always_on_same_mac(a1, (unsigned int)v69, v15);
    v31 = (unsigned int)v69;
    v41 = link_info & 1;
    v43 = 1;
    LODWORD(v66) = v69;
    v42 = link_info & ((_DWORD)v69 == v15);
  }
  if ( HIBYTE(v62) != 255 )
  {
    link_info = policy_mgr_vdev_is_force_inactive(a1, SHIBYTE(v62));
    if ( (link_info & 1) == 0 )
    {
      link_info = wlan_reg_is_24ghz_ch_freq(HIDWORD(v69));
      if ( (link_info & 1) == 0 )
      {
        link_info = policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(v69), v15);
        v31 = HIDWORD(v69);
        v44 = (_DWORD *)((unsigned __int64)&v66 | (4LL * v43++));
        v45 = HIDWORD(v69) == v15;
        *v44 = HIDWORD(v69);
        if ( (link_info & 1) != 0 )
          ++v41;
        v42 |= link_info & v45;
      }
    }
  }
  if ( v40 == 2 )
  {
LABEL_25:
    if ( v43 >= 2 )
    {
      if ( v41 >= 2 )
      {
        if ( (v42 & 1) != 0 )
        {
          v47 = ml_nlink_emlsr_downgrade_handler(a1, a2, 0xEu, (__int64)a3, v32, v33, v34, v35, v36, v37, v38, v39);
        }
        else
        {
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: Reject AP CSA to MCC chan of ML STA in same subband",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "ml_nlink_ap_csa_start_handler");
          v47 = 4;
        }
        goto LABEL_27;
      }
      if ( !(unsigned int)ml_nlink_get_emlsr_mode_disable_req(link_info, v28) )
      {
        if ( (ml_nlink_is_support_emlsr_with_freq(a1, &v66, v15) & 1) != 0 )
        {
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: emlsr is allowed after CSA to %d, no need to disable",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "ml_nlink_ap_csa_start_handler",
            v15);
          v47 = 0;
          goto LABEL_27;
        }
        v31 = *((unsigned __int8 *)a3 + 8);
        if ( (_DWORD)v31 != 1 )
        {
          v47 = 24;
          goto LABEL_27;
        }
        if ( !(unsigned int)ml_nlink_set_emlsr_mode_disable_req(v28, 2) )
        {
          updated = ml_nlink_update_non_force_disallow_bitmap(a1, v28, 14, 1, 16);
          if ( updated == 24 )
            v47 = 0;
          else
            v47 = updated;
          goto LABEL_27;
        }
      }
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: emlsr is disabled already",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "ml_nlink_ap_csa_start_handler");
      v47 = 0;
LABEL_27:
      wlan_objmgr_vdev_release_ref(v28, 0x5Au, (unsigned int *)v31, v32, v33, v34, v35, v36, v37, v38, v39);
      result = v47;
LABEL_30:
      _ReadStatusReg(SP_EL0);
      return result;
    }
LABEL_26:
    v47 = 0;
    goto LABEL_27;
  }
  v46 = v63;
  if ( v63 != 255 )
  {
    link_info = policy_mgr_vdev_is_force_inactive(a1, v63);
    if ( (link_info & 1) == 0 )
    {
      link_info = wlan_reg_is_24ghz_ch_freq(v70);
      if ( (link_info & 1) == 0 )
      {
        link_info = policy_mgr_2_freq_always_on_same_mac(a1, v70, v15);
        if ( (link_info & 1) != 0 )
          ++v41;
        if ( v43 > 2 )
          goto LABEL_46;
        v31 = (unsigned __int8)link_info & (v70 == v15);
        v42 |= link_info & (v70 == v15);
        *((_DWORD *)&v66 + v43++) = v70;
      }
    }
  }
  if ( v40 == 3 )
    goto LABEL_25;
LABEL_46:
  __break(0x5512u);
  return ml_nlink_ap_csa_end_handler(link_info, v46, v30);
}
