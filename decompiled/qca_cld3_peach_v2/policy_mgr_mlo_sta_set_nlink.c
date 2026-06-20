__int64 __fastcall policy_mgr_mlo_sta_set_nlink(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned __int8 a5,
        unsigned __int16 a6,
        unsigned __int16 a7,
        unsigned int a8)
{
  __int64 context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x22
  __int64 v26; // x0
  __int64 v27; // x23
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x19
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  const char *v46; // x6
  __int64 result; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned int bss_peer_mld_mac; // w0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int v65; // w24
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned int *v74; // x8
  unsigned __int8 v75; // [xsp+1Ch] [xbp-14h]

  _ReadStatusReg(SP_EL0);
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v25 = context;
    v26 = _qdf_mem_malloc(0xA0u, "policy_mgr_mlo_sta_set_nlink", 7328);
    if ( v26 )
    {
      v27 = v26;
      v75 = a5;
      v28 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
      if ( v28 )
      {
        v37 = v28;
        v38 = policy_mgr_set_link_in_progress(v25, 1);
        if ( a4 - 1 > 6 )
          v46 = "Unknown";
        else
          v46 = off_AD9278[a4 - 1];
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: vdev %d: mode %d %s reason %d bitmap 0x%x 0x%x ctrl 0x%x",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "policy_mgr_mlo_sta_set_nlink",
          *(unsigned __int8 *)(v37 + 168),
          a4,
          v46,
          a3,
          a6,
          a7,
          a8);
        *(_QWORD *)v27 = v37;
        *(_DWORD *)(v27 + 32) = a4;
        *(_DWORD *)(v27 + 36) = a3;
        *(_BYTE *)(v27 + 107) = 1;
        *(_WORD *)(v27 + 114) = a6;
        *(_WORD *)(v27 + 116) = a7;
        *(_BYTE *)(v27 + 118) = v75;
        policy_mgr_update_disallowed_mode_bitmap(a1, v37, v27, a8);
        if ( (a8 & 1) != 0 )
        {
          *(_BYTE *)(v27 + 100) = 1;
          if ( (a8 & 2) == 0 )
          {
LABEL_12:
            if ( (a8 & 4) == 0 )
              goto LABEL_13;
            goto LABEL_22;
          }
        }
        else if ( (a8 & 2) == 0 )
        {
          goto LABEL_12;
        }
        *(_BYTE *)(v27 + 101) = 1;
        if ( (a8 & 4) == 0 )
        {
LABEL_13:
          if ( (a8 & 8) == 0 )
            goto LABEL_14;
          goto LABEL_23;
        }
LABEL_22:
        *(_BYTE *)(v27 + 102) = 1;
        if ( (a8 & 8) == 0 )
        {
LABEL_14:
          if ( (a8 & 0x40) == 0 )
            goto LABEL_15;
          goto LABEL_24;
        }
LABEL_23:
        *(_BYTE *)(v27 + 103) = 1;
        *(_BYTE *)(v27 + 104) = a8 >> 30;
        if ( (a8 & 0x40) == 0 )
        {
LABEL_15:
          if ( (a8 & 0x80) == 0 )
            goto LABEL_17;
          goto LABEL_16;
        }
LABEL_24:
        *(_BYTE *)(v27 + 105) = 1;
        if ( (a8 & 0x80) == 0 )
        {
LABEL_17:
          bss_peer_mld_mac = wlan_vdev_get_bss_peer_mld_mac(
                               v37,
                               (void *)(v27 + 108),
                               v48,
                               v49,
                               v50,
                               v51,
                               v52,
                               v53,
                               v54,
                               v55);
          if ( bss_peer_mld_mac )
          {
            v65 = bss_peer_mld_mac;
            qdf_trace_msg(
              0x4Fu,
              2u,
              "%s: fail to get ap mld addr for vdev %d",
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              "policy_mgr_mlo_sta_set_nlink",
              *(unsigned __int8 *)(v37 + 168));
LABEL_19:
            qdf_trace_msg(
              0x4Fu,
              2u,
              "%s: vdev %d: Failed to set link mode %d num_mlo_vdev %d reason %d",
              v66,
              v67,
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              "policy_mgr_mlo_sta_set_nlink",
              *(unsigned __int8 *)(v37 + 168),
              a4,
              v75,
              a3);
            _qdf_mem_free(v27);
            v66 = policy_mgr_set_link_in_progress(v25, 0);
LABEL_31:
            wlan_objmgr_vdev_release_ref(v37, 0x18u, v74, v66, v67, v68, v69, v70, v71, v72, v73);
            result = v65;
            goto LABEL_32;
          }
          if ( *(_DWORD *)(v27 + 108) | *(unsigned __int16 *)(v27 + 112) )
          {
            *(_QWORD *)(v27 + 24) = v27;
            *(_QWORD *)(v27 + 8) = policy_mgr_handle_link_enable_disable_resp;
            *(_QWORD *)(v27 + 16) = policy_mgr_validate_set_mlo_link_cb;
            v65 = mlo_ser_set_link_req(v27);
            if ( v65 )
              goto LABEL_19;
          }
          else
          {
            qdf_trace_msg(
              0x4Fu,
              2u,
              "%s: get ap zero mld addr for vdev %d",
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              "policy_mgr_mlo_sta_set_nlink",
              *(unsigned __int8 *)(v37 + 168));
          }
          v65 = 24;
          goto LABEL_31;
        }
LABEL_16:
        *(_BYTE *)(v27 + 106) = 1;
        goto LABEL_17;
      }
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: invalid vdev for id %d",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "policy_mgr_mlo_sta_set_nlink",
        (unsigned __int8)a2);
      _qdf_mem_free(v27);
      result = 4;
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "policy_mgr_mlo_sta_set_nlink");
    result = 4;
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
