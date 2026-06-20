__int64 __fastcall policy_mgr_update_mlo_links_based_on_linkid_nlink(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        unsigned __int8 *a4,
        _DWORD *a5)
{
  unsigned int v5; // w19
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w26
  unsigned int v26; // w22
  unsigned __int8 v27; // w21
  unsigned __int8 v28; // w24
  __int64 v29; // x25
  unsigned int v30; // w19
  bool v31; // cf
  int v32; // w8
  int v33; // w9
  unsigned __int8 *v34; // x23
  __int64 v35; // x27
  _DWORD *v36; // x20
  int v37; // t1
  int v38; // w4
  int v39; // w8
  unsigned int v40; // w20
  const char *v41; // x2
  const char *v42; // x3
  unsigned int v43; // w1
  unsigned int *v44; // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v54; // x19
  unsigned __int64 v55; // x8
  unsigned int v56; // w20
  unsigned __int64 v57; // x8
  unsigned __int64 v58; // x8
  __int64 v59; // x1
  __int64 v60; // x0
  __int64 v61; // x4
  __int64 v62; // x6
  __int64 v63; // x7
  __int64 v64; // [xsp+0h] [xbp-70h]
  __int64 v65; // [xsp+8h] [xbp-68h]
  unsigned int v66; // [xsp+14h] [xbp-5Ch]
  __int64 v67; // [xsp+18h] [xbp-58h]
  __int64 v68; // [xsp+20h] [xbp-50h]
  _BYTE v72[20]; // [xsp+54h] [xbp-1Ch] BYREF
  __int64 v73; // [xsp+68h] [xbp-8h]

  v5 = a2;
  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( v7 )
  {
    v16 = v7;
    if ( wlan_cm_is_vdev_connected(v7, v8, v9, v10, v11, v12, v13, v14, v15) )
    {
      if ( (wlan_vdev_mlme_is_mlo_vdev(v16, v17, v18, v19, v20, v21, v22, v23, v24) & 1) != 0 )
      {
        if ( (policy_mgr_is_emlsr_sta_concurrency_present(a1) & 1) != 0 && (wlan_mlme_is_aux_emlsr_support(a1) & 1) == 0 )
        {
          v41 = "%s: Concurrency exists, cannot enter EMLSR mode";
          v42 = "policy_mgr_update_mlo_links_based_on_linkid_nlink";
          v43 = 8;
          goto LABEL_25;
        }
        v66 = v5;
        v25 = 0;
        v26 = 0;
        v27 = 0;
        v28 = 0;
        v29 = *(_QWORD *)(*(_QWORD *)(v16 + 1360) + 3880LL);
        v30 = 0;
        v67 = a1;
        v68 = v16;
        do
        {
          if ( *(unsigned __int8 *)(v29 + 6) != 255 && *(_DWORD *)(v29 + 24) | *(unsigned __int16 *)(v29 + 28) )
          {
            if ( v29 )
            {
              v32 = *(unsigned __int8 *)(v29 + 2);
              v33 = *(unsigned __int8 *)(v29 + 5);
            }
            else
            {
              v32 = 0;
              v33 = 0;
            }
            LODWORD(v65) = v33;
            LODWORD(v64) = v32;
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: linkid %d freq %d link addr: %02x:%02x:%02x:**:**:%02x",
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              "policy_mgr_update_mlo_links_based_on_linkid_nlink",
              v64,
              v65);
            if ( a3 )
            {
              v35 = a3;
              v34 = a4;
              v36 = a5;
              do
              {
                v37 = *v34++;
                v38 = *(unsigned __int8 *)(v29 + 6);
                if ( v37 == v38 )
                {
                  v39 = 1 << v38;
                  if ( *v36 )
                  {
                    v26 |= v39;
                    qdf_trace_msg(
                      0x4Fu,
                      8u,
                      "%s: link id:%d matched to active",
                      v17,
                      v18,
                      v19,
                      v20,
                      v21,
                      v22,
                      v23,
                      v24,
                      "policy_mgr_update_mlo_links_based_on_linkid_nlink");
                    ++v28;
                  }
                  else
                  {
                    v25 |= v39;
                    qdf_trace_msg(
                      0x4Fu,
                      8u,
                      "%s: link id:%d matched to inactive",
                      v17,
                      v18,
                      v19,
                      v20,
                      v21,
                      v22,
                      v23,
                      v24,
                      "policy_mgr_update_mlo_links_based_on_linkid_nlink");
                    ++v27;
                  }
                }
                --v35;
                ++v36;
              }
              while ( v35 );
            }
          }
          v31 = v30++ >= 2;
          v29 += 48;
        }
        while ( !v31 );
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: active_bitmap: %d, num_active: %d, inactive_bitmap: %d, num_inactive: %d",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "policy_mgr_update_mlo_links_based_on_linkid_nlink",
          v26,
          v28,
          v25,
          v27);
        v16 = v68;
        if ( (policy_mgr_is_hw_dbs_capable(v67) & 1) != 0 || v28 < 2u )
          goto LABEL_44;
        v72[0] = 0;
        wlan_mlme_get_emlsr_mode_enabled(v67, v72);
        if ( (v72[0] & 1) != 0 )
        {
          v54 = *(_QWORD *)(*(_QWORD *)(v68 + 1360) + 3880LL);
          v55 = *(unsigned __int8 *)(v54 + 6);
          if ( v55 > 0xE
            || !(*(_DWORD *)(v54 + 24) | *(unsigned __int16 *)(v54 + 28))
            || (v56 = **(unsigned __int16 **)(v54 + 32), ((v26 >> v55) & 1) == 0)
            || (unsigned int)wlan_reg_freq_to_band(v56) )
          {
            v57 = *(unsigned __int8 *)(v54 + 54);
            if ( v57 <= 0xE
              && *(_DWORD *)(v54 + 72) | *(unsigned __int16 *)(v54 + 76)
              && (v56 = **(unsigned __int16 **)(v54 + 80), ((v26 >> v57) & 1) != 0)
              && !(unsigned int)wlan_reg_freq_to_band(v56) )
            {
              v54 += 48;
            }
            else
            {
              v58 = *(unsigned __int8 *)(v54 + 102);
              if ( v58 > 0xE
                || !(*(_DWORD *)(v54 + 120) | *(unsigned __int16 *)(v54 + 124))
                || (v56 = **(unsigned __int16 **)(v54 + 128), ((v26 >> v58) & 1) == 0)
                || (unsigned int)wlan_reg_freq_to_band(v56) )
              {
LABEL_44:
                qdf_trace_msg(
                  0x4Fu,
                  8u,
                  "%s: active link bitmap: %d, inactive link bitmap: %d",
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  v22,
                  v23,
                  v24,
                  "policy_mgr_update_mlo_links_based_on_linkid_nlink",
                  v26,
                  v25);
                if ( v26 && v25 )
                {
                  v59 = v66;
                  v60 = v67;
                  v61 = 6;
                  v62 = v26;
                  v63 = v25;
LABEL_49:
                  v40 = ml_nlink_vendor_command_set_link(v60, v59, 1, 1, v61, 0, v62, v63);
                  goto LABEL_27;
                }
                if ( v26 )
                {
                  v59 = v66;
                  v60 = v67;
                  v61 = 1;
                  v62 = v26;
                  v63 = 0;
                  goto LABEL_49;
                }
LABEL_26:
                v40 = 16;
LABEL_27:
                wlan_objmgr_vdev_release_ref(v16, 0x18u, v44, v45, v46, v47, v48, v49, v50, v51, v52);
                goto LABEL_28;
              }
              v54 += 96;
            }
          }
          qdf_trace_msg(
            0x4Fu,
            2u,
            "%s: vdev: %d Invalid link activation for link: %d at freq: %d",
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "policy_mgr_is_link_active_allowed",
            *(unsigned __int8 *)(v54 + 12),
            *(unsigned __int8 *)(v54 + 6),
            v56);
          goto LABEL_26;
        }
        v41 = "%s: eMLSR is disabled";
        v42 = "policy_mgr_is_link_active_allowed";
LABEL_24:
        v43 = 2;
LABEL_25:
        qdf_trace_msg(0x4Fu, v43, v41, v17, v18, v19, v20, v21, v22, v23, v24, v42);
        goto LABEL_26;
      }
      v41 = "%s: vdev is not mlo vdev";
    }
    else
    {
      v41 = "%s: vdev is not in connected state";
    }
    v42 = "policy_mgr_update_mlo_links_based_on_linkid_nlink";
    goto LABEL_24;
  }
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: vdev_id: %d vdev not found",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "policy_mgr_update_mlo_links_based_on_linkid_nlink",
    (unsigned __int8)v5);
  v40 = 16;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return v40;
}
