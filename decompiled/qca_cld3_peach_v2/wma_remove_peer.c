__int64 __fastcall wma_remove_peer(
        __int64 *a1,
        const void *a2,
        unsigned int a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 **context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 **v25; // x22
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x27
  _QWORD *peer_by_mac; // x0
  __int64 v36; // x20
  __int64 v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x8
  __int64 (__fastcall *v47)(_QWORD); // x8
  char v48; // w25
  __int64 v49; // x4
  __int64 v50; // x5
  const char *v51; // x2
  __int64 v52; // x6
  __int64 v53; // x7
  __int64 result; // x0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x8
  _DWORD *v64; // x8
  unsigned int v65; // w0
  unsigned int v66; // w26
  unsigned int v67; // w28
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x8
  __int64 *v77; // x8
  __int64 v78; // x8
  void (__fastcall *v79)(__int64 **, __int64, int *, __int64 (__fastcall *)(unsigned int, unsigned int, const void *, double, double, double, double, double, double, double, double), __int64); // x8
  __int64 (__fastcall *v80)(unsigned int, unsigned int, const void *, double, double, double, double, double, double, double, double); // x3
  __int64 **v81; // x0
  __int64 v82; // x1
  __int64 v83; // x4
  __int64 v84; // x8
  const char *v85; // x3
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  int v102; // [xsp+8h] [xbp-48h]
  __int64 v103; // [xsp+18h] [xbp-38h]
  int v104; // [xsp+40h] [xbp-10h] BYREF
  __int16 v105; // [xsp+44h] [xbp-Ch]
  __int64 v106; // [xsp+48h] [xbp-8h]

  v106 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v105 = 0;
  v104 = 0;
  context = (__int64 **)_cds_get_context(71, (__int64)"wma_remove_peer", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( (unsigned __int8)a3 < 6u )
  {
    v25 = context;
    qdf_mem_copy(&v104, a2, 6u);
    v34 = a1[65] + 488LL * (unsigned __int8)a3;
    if ( *(_DWORD *)(v34 + 244) )
    {
      if ( !v25 )
        goto LABEL_16;
      peer_by_mac = wlan_objmgr_get_peer_by_mac(a1[3], &v104, 8u);
      if ( peer_by_mac )
      {
        v36 = (__int64)peer_by_mac;
        if ( *(unsigned __int8 *)(peer_by_mac[12] + 168LL) != (unsigned __int8)a3 )
        {
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: peer %02x:%02x:%02x:**:**:%02x is on vdev id %d but delete req on vdevid %d peer_count %d",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "wma_remove_peer",
            (unsigned __int8)v104,
            BYTE1(v104),
            BYTE2(v104),
            HIBYTE(v105),
            *(unsigned __int8 *)(peer_by_mac[12] + 168LL),
            (unsigned __int8)a3,
            *(_DWORD *)(v34 + 244),
            v103,
            0,
            0,
            0,
            0);
          wlan_objmgr_peer_release_ref(v36, 8u, v55, v56, v57, v58, v59, v60, v61, v62);
          goto LABEL_16;
        }
        v37 = wma_peer_tbl_trans_add_entry((__int64)peer_by_mac, 0, 0);
        if ( *v25 )
        {
          v46 = (*v25)[13];
          if ( v46 )
          {
            v47 = *(__int64 (__fastcall **)(_QWORD))(v46 + 96);
            if ( v47 )
            {
              if ( *((_DWORD *)v47 - 1) != 799902358 )
                __break(0x8228u);
              v48 = v47(v37);
LABEL_21:
              if ( *v25 )
              {
                v63 = **v25;
                if ( v63 )
                {
                  v64 = *(_DWORD **)(v63 + 96);
                  if ( v64 )
                  {
                    if ( *(v64 - 1) != -612755781 )
                      __break(0x8228u);
                    ((void (__fastcall *)(__int64 **, _QWORD, int *))v64)(v25, a3, &v104);
                  }
                }
              }
              else
              {
                qdf_trace_msg(
                  0x89u,
                  8u,
                  "%s: Invalid Instance:",
                  v38,
                  v39,
                  v40,
                  v41,
                  v42,
                  v43,
                  v44,
                  v45,
                  "cdp_peer_teardown");
              }
              if ( (a4 & 1) != 0 )
                goto LABEL_33;
              if ( (wmi_service_enabled(*a1, 0xC5u, v38, v39, v40, v41, v42, v43, v44, v45) & 1) == 0 )
                wmi_unified_peer_flush_tids_send(*a1);
              wlan_roam_debug_log(a3, 2u, 0xFFFFu, (__int64)&v104, 0, 0, 0);
              v65 = wmi_unified_peer_delete_send(*a1);
              if ( !v65 )
              {
LABEL_33:
                v67 = 0;
                v66 = 1;
              }
              else
              {
                v66 = 2;
                qdf_trace_msg(
                  0x36u,
                  2u,
                  "%s: Peer delete could not be sent to firmware %d",
                  v38,
                  v39,
                  v40,
                  v41,
                  v42,
                  v43,
                  v44,
                  v45,
                  "wma_remove_peer",
                  v65);
                v67 = 16;
              }
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: vdevid %d is detaching with peer_addr %02x:%02x:%02x:**:**:%02x peer_count %d",
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                "wma_remove_peer",
                (unsigned __int8)a3,
                (unsigned __int8)v104,
                BYTE1(v104),
                BYTE2(v104),
                HIBYTE(v105),
                *(_DWORD *)(v34 + 244));
              if ( (a4 & 1) != 0 )
              {
                if ( *v25 && (v76 = (*v25)[9]) != 0 )
                {
                  if ( *(_QWORD *)(v76 + 152) )
                  {
                    if ( (v48 & 1) != 0 )
                    {
                      cdp_peer_delete_sync(v25, a3, &v104, v66);
                    }
                    else
                    {
                      qdf_trace_msg(
                        0x36u,
                        8u,
                        "%s: LFR3: trigger force delete for peer %02x:%02x:%02x:**:**:%02x",
                        v68,
                        v69,
                        v70,
                        v71,
                        v72,
                        v73,
                        v74,
                        v75,
                        "wma_remove_peer",
                        (unsigned __int8)v104,
                        BYTE1(v104),
                        BYTE2(v104),
                        HIBYTE(v105));
                      cdp_peer_detach_force_delete(v25, a3, &v104);
                    }
                    goto LABEL_58;
                  }
                }
                else
                {
                  qdf_trace_msg(
                    0x45u,
                    1u,
                    "%s invalid instance",
                    v68,
                    v69,
                    v70,
                    v71,
                    v72,
                    v73,
                    v74,
                    v75,
                    "is_cdp_peer_detach_force_delete_supported");
                }
                qdf_trace_msg(
                  0x36u,
                  8u,
                  "%s: LFR3: Delete the peer %02x:%02x:%02x:**:**:%02x",
                  v68,
                  v69,
                  v70,
                  v71,
                  v72,
                  v73,
                  v74,
                  v75,
                  "wma_remove_peer",
                  (unsigned __int8)v104,
                  BYTE1(v104),
                  BYTE2(v104),
                  HIBYTE(v105));
              }
              v77 = *v25;
              if ( (v48 & 1) != 0 )
              {
                if ( v77 )
                {
                  v78 = *v77;
                  if ( !v78 )
                    goto LABEL_58;
                  v79 = *(void (__fastcall **)(__int64 **, __int64, int *, __int64 (__fastcall *)(unsigned int, unsigned int, const void *, double, double, double, double, double, double, double, double), __int64))(v78 + 176);
                  if ( !v79 )
                    goto LABEL_58;
                  v80 = wma_peer_unmap_conf_cb;
                  v81 = v25;
                  v82 = a3;
                  v83 = v66;
                  if ( *((_DWORD *)v79 - 1) != 2049932883 )
                    __break(0x8228u);
                  goto LABEL_48;
                }
                v85 = "cdp_peer_delete_sync";
              }
              else
              {
                if ( v77 )
                {
                  v84 = *v77;
                  if ( !v84 )
                    goto LABEL_58;
                  v79 = *(void (__fastcall **)(__int64 **, __int64, int *, __int64 (__fastcall *)(unsigned int, unsigned int, const void *, double, double, double, double, double, double, double, double), __int64))(v84 + 160);
                  if ( !v79 )
                    goto LABEL_58;
                  v81 = v25;
                  v82 = a3;
                  v80 = (__int64 (__fastcall *)(unsigned int, unsigned int, const void *, double, double, double, double, double, double, double, double))v66;
                  v83 = 1;
                  if ( *((_DWORD *)v79 - 1) != -175540032 )
                    __break(0x8228u);
LABEL_48:
                  v79(v81, v82, &v104, v80, v83);
LABEL_58:
                  wlan_objmgr_peer_release_ref(v36, 8u, v68, v69, v70, v71, v72, v73, v74, v75);
                  wlan_release_peer_key_wakelock(
                    *(_QWORD *)v34,
                    (unsigned __int8 *)&v104,
                    v86,
                    v87,
                    v88,
                    v89,
                    v90,
                    v91,
                    v92,
                    v93);
                  wma_remove_objmgr_peer(
                    (__int64)a1,
                    *(_QWORD *)v34,
                    (unsigned __int8 *)&v104,
                    v94,
                    v95,
                    v96,
                    v97,
                    v98,
                    v99,
                    v100,
                    v101);
                  result = v67;
                  --*(_DWORD *)(v34 + 244);
                  goto LABEL_17;
                }
                v85 = "cdp_peer_delete";
              }
              qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v68, v69, v70, v71, v72, v73, v74, v75, v85);
              goto LABEL_58;
            }
          }
        }
        else
        {
          qdf_trace_msg(
            0x89u,
            8u,
            "%s: invalid instance",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "cdp_cfg_get_peer_unmap_conf_support");
        }
        v48 = 0;
        goto LABEL_21;
      }
      v49 = (unsigned __int8)v104;
      v51 = "%s: peer doesn't exist peer_addr %02x:%02x:%02x:**:**:%02x vdevid %d peer_count %d";
      v50 = BYTE1(v104);
      v52 = BYTE2(v104);
      v53 = HIBYTE(v105);
      v102 = *(_DWORD *)(v34 + 244);
    }
    else
    {
      v49 = (unsigned __int8)v104;
      v50 = BYTE1(v104);
      v51 = "%s: Can't remove peer with peer_addr %02x:%02x:%02x:**:**:%02x vdevid %d peer_count %d";
      v52 = BYTE2(v104);
      v53 = HIBYTE(v105);
      v102 = 0;
    }
    qdf_trace_msg(
      0x36u,
      2u,
      v51,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wma_remove_peer",
      v49,
      v50,
      v52,
      v53,
      (unsigned __int8)a3,
      v102);
    goto LABEL_16;
  }
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: Invalid vdev_id %d",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "wma_remove_peer",
    (unsigned __int8)a3);
LABEL_16:
  result = 4;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
