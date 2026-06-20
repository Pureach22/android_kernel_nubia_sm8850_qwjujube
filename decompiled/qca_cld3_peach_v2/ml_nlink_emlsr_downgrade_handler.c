__int64 __fastcall ml_nlink_emlsr_downgrade_handler(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  bool is_mld_sta; // w8
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x4
  __int64 v27; // x0
  __int64 v28; // x22
  __int64 link_info; // x0
  __int64 v30; // x1
  __int64 v31; // x2
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned __int64 v40; // x8
  unsigned int v41; // w19
  const char *v42; // x2
  const char *v43; // x3
  unsigned int v44; // w1
  unsigned int v45; // w23
  int v46; // w25
  int v47; // w26
  char v48; // w28
  int v49; // w27
  unsigned int v50; // w23
  unsigned int v51; // w0
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
  void *v68; // x0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  char *v77; // x8
  unsigned int v78; // w9
  unsigned int v79; // w0
  char v80; // [xsp+18h] [xbp-88h]
  _BYTE v81[4]; // [xsp+24h] [xbp-7Ch] BYREF
  __int64 v82; // [xsp+28h] [xbp-78h] BYREF
  __int64 v83; // [xsp+30h] [xbp-70h] BYREF
  int v84; // [xsp+38h] [xbp-68h] BYREF
  _BYTE v85[4]; // [xsp+40h] [xbp-60h] BYREF
  _BYTE v86[4]; // [xsp+44h] [xbp-5Ch] BYREF
  __int16 v87; // [xsp+48h] [xbp-58h] BYREF
  char v88; // [xsp+4Ah] [xbp-56h]
  __int16 v89; // [xsp+4Ch] [xbp-54h] BYREF
  char v90; // [xsp+4Eh] [xbp-52h]
  int v91; // [xsp+50h] [xbp-50h] BYREF
  char v92; // [xsp+54h] [xbp-4Ch]
  _QWORD v93[3]; // [xsp+58h] [xbp-48h] BYREF
  __int64 v94; // [xsp+70h] [xbp-30h] BYREF
  int v95; // [xsp+78h] [xbp-28h]
  _QWORD v96[2]; // [xsp+80h] [xbp-20h] BYREF
  int v97; // [xsp+90h] [xbp-10h]
  __int64 v98; // [xsp+98h] [xbp-8h]

  v98 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v84 = 0;
  v82 = 0;
  v83 = 0;
  v81[0] = 0;
  v90 = 0;
  v89 = 0;
  v95 = 0;
  v94 = 0;
  v88 = 0;
  v87 = 0;
  memset(v93, 0, sizeof(v93));
  is_mld_sta = mlo_is_mld_sta(a2, a5, a6, a7, a8, a9, a10, a11, a12);
  result = 0;
  if ( is_mld_sta )
    goto LABEL_15;
  if ( (wlan_mlme_is_aux_emlsr_support(a1) & 1) == 0 || (policy_mgr_is_mlo_in_mode_emlsr(a1, 0, nullptr) & 1) == 0 )
    goto LABEL_14;
  v26 = *(unsigned int *)(a2 + 16);
  if ( (unsigned int)v26 >= 4 && (_DWORD)v26 != 16 )
  {
    v42 = "%s: op_mode: %d";
    v43 = "ml_nlink_emlsr_downgrade_handler";
    v44 = 8;
LABEL_13:
    qdf_trace_msg(0x8Fu, v44, v42, v18, v19, v20, v21, v22, v23, v24, v25, v43, v26);
    goto LABEL_14;
  }
  v86[0] = 0;
  v85[0] = 0;
  v92 = 0;
  v91 = 0;
  v97 = 0;
  v96[0] = 0;
  v96[1] = 0;
  policy_mgr_get_ml_sta_info_psoc(a1, v86, v85, (__int64)&v91, (__int64)v96, nullptr, 0, 0);
  if ( (unsigned int)v86[0] - 6 < 0xFFFFFFFB )
  {
LABEL_14:
    result = 0;
    goto LABEL_15;
  }
  v27 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          a1,
          (unsigned __int8)v91,
          90);
  if ( !v27 )
  {
    v26 = (unsigned __int8)v91;
    v42 = "%s: invalid vdev for id %d";
    v43 = "ml_nlink_get_affect_ml_sta";
    v44 = 2;
    goto LABEL_13;
  }
  v28 = v27;
  link_info = ml_nlink_get_link_info(a1, v27, 1, 3, (int)v93, (int)&v94, (int)&v89, (int)&v87, (__int64)v81);
  v40 = v81[0];
  if ( v81[0] < 2u )
  {
LABEL_9:
    v41 = 0;
LABEL_10:
    wlan_objmgr_vdev_release_ref(v28, 0x5Au, (unsigned int *)v40, v32, v33, v34, v35, v36, v37, v38, v39);
    result = v41;
LABEL_15:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( a3 == 14 )
    v45 = *(_DWORD *)(a4 + 4);
  else
    v45 = 0;
  v80 = v87;
  if ( v81[0] == 2 )
  {
    if ( (unsigned __int8)v89 == 255 || (policy_mgr_vdev_is_force_inactive(a1, v89) & 1) != 0 )
      goto LABEL_22;
    v46 = 0;
    v47 = 0;
    if ( wlan_reg_is_24ghz_ch_freq(v94) || !v45 )
    {
LABEL_24:
      v48 = 1;
      v49 = 1 << SHIBYTE(v87);
      if ( HIBYTE(v89) != 255
        && (policy_mgr_vdev_is_force_inactive(a1, SHIBYTE(v89)) & 1) == 0
        && !wlan_reg_is_24ghz_ch_freq(HIDWORD(v94))
        && v45
        && (policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(v94), v45) & 1) != 0 )
      {
        if ( HIDWORD(v94) == v45 )
        {
          v47 = 1;
          if ( a3 != 14 )
          {
LABEL_45:
            switch ( a3 )
            {
              case 4u:
                v50 = 16;
                break;
              case 0xAu:
                v50 = 8;
                break;
              case 0x18u:
                v50 = 256;
                break;
              default:
                qdf_trace_msg(
                  0x8Fu,
                  8u,
                  "%s: not handled for evt %d",
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  v39,
                  "ml_nlink_emlsr_downgrade_handler",
                  a3);
                goto LABEL_9;
            }
LABEL_51:
            v51 = policy_mgr_wait_for_set_link_update(a1);
            if ( v51 && v51 != 35 )
            {
              v41 = v51;
              qdf_trace_msg(
                0x8Fu,
                8u,
                "%s: wait for set link completion status %d",
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                "ml_nlink_emlsr_downgrade_handler");
              goto LABEL_10;
            }
            ml_nlink_set_emlsr_mode_disable_req(v28, v50);
            qdf_mem_set(&v82, 0x14u, 0);
            ml_nlink_get_force_link_request(v28, &v82, 1);
            if ( !(HIWORD(v84) | WORD1(v83)) )
            {
              v68 = qdf_mem_set(&v82, 0x14u, 0);
              if ( v46 )
              {
                v77 = (char *)&v83 + 2;
                v78 = 2;
              }
              else
              {
                v78 = 4;
                LOBYTE(v84) = v48;
                v46 = v49 | (1 << v80);
                v77 = (char *)&v84 + 2;
              }
              *(_WORD *)v77 = v46;
              v82 = v78 | 0x100000000LL;
              ml_nlink_update_force_link_request(v69, v70, v71, v72, v73, v74, v75, v76, (__int64)v68, v28, &v82, 1u);
              v79 = ml_nlink_state_change(a1, 1, a3, a4);
              if ( v79 == 24 )
                v41 = 0;
              else
                v41 = v79;
              goto LABEL_10;
            }
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: eMLSR downgrade req is present",
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              "ml_nlink_emlsr_downgrade_handler");
            goto LABEL_9;
          }
        }
        else
        {
          v46 |= 1 << SHIBYTE(v87);
          if ( a3 != 14 )
            goto LABEL_45;
        }
LABEL_35:
        v40 = *(unsigned __int8 *)(a4 + 8);
        if ( (_DWORD)v40 != 1 )
        {
          v41 = 24;
          goto LABEL_10;
        }
        v50 = 4;
        if ( !v47 )
          v46 = 0;
        goto LABEL_51;
      }
LABEL_34:
      if ( a3 != 14 )
        goto LABEL_45;
      goto LABEL_35;
    }
    if ( (policy_mgr_2_freq_always_on_same_mac(a1, (unsigned int)v94, v45) & 1) == 0 )
    {
LABEL_22:
      v46 = 0;
    }
    else
    {
      v47 = 1;
      if ( (_DWORD)v94 == v45 )
      {
        v46 = 0;
        goto LABEL_24;
      }
      v46 = 1 << v87;
    }
    v47 = 0;
    goto LABEL_24;
  }
  if ( v81[0] == 3 )
  {
    v46 = 0;
    v47 = 0;
    v48 = 2;
    v49 = (1 << SHIBYTE(v87)) | (1 << v88);
    goto LABEL_34;
  }
  __break(0x5512u);
  return ml_nlink_ap_csa_start_handler(link_info, v30, v31);
}
