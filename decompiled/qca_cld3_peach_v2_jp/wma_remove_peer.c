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
  __int64 v37; // x8
  __int64 (*v38)(void); // x8
  char v39; // w25
  __int64 v40; // x4
  __int64 v41; // x5
  const char *v42; // x2
  __int64 v43; // x6
  __int64 v44; // x7
  __int64 result; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x8
  _DWORD *v55; // x8
  unsigned int v56; // w0
  unsigned int v57; // w26
  unsigned int v58; // w28
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x8
  __int64 *v68; // x8
  __int64 v69; // x8
  void (__fastcall *v70)(__int64 **, __int64, int *, __int64 (__fastcall *)(unsigned int, unsigned int, const void *, double, double, double, double, double, double, double, double), __int64); // x8
  __int64 (__fastcall *v71)(unsigned int, unsigned int, const void *, double, double, double, double, double, double, double, double); // x3
  __int64 **v72; // x0
  __int64 v73; // x1
  __int64 v74; // x4
  __int64 v75; // x8
  const char *v76; // x3
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  int v93; // [xsp+8h] [xbp-48h]
  __int64 v94; // [xsp+18h] [xbp-38h]
  int v95; // [xsp+40h] [xbp-10h] BYREF
  __int16 v96; // [xsp+44h] [xbp-Ch]
  __int64 v97; // [xsp+48h] [xbp-8h]

  v97 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v96 = 0;
  v95 = 0;
  context = (__int64 **)_cds_get_context(71, (__int64)"wma_remove_peer", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( (unsigned __int8)a3 < 6u )
  {
    v25 = context;
    qdf_mem_copy(&v95, a2, 6u);
    v34 = a1[65] + 488LL * (unsigned __int8)a3;
    if ( *(_DWORD *)(v34 + 244) )
    {
      if ( !v25 )
        goto LABEL_16;
      peer_by_mac = wlan_objmgr_get_peer_by_mac(a1[3], &v95, 8u);
      if ( peer_by_mac )
      {
        v36 = (__int64)peer_by_mac;
        if ( *(unsigned __int8 *)(peer_by_mac[11] + 104LL) != (unsigned __int8)a3 )
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
            (unsigned __int8)v95,
            BYTE1(v95),
            BYTE2(v95),
            HIBYTE(v96),
            *(unsigned __int8 *)(peer_by_mac[11] + 104LL),
            (unsigned __int8)a3,
            *(_DWORD *)(v34 + 244),
            v94,
            0,
            0,
            0,
            0);
          wlan_objmgr_peer_release_ref(v36, 8u, v46, v47, v48, v49, v50, v51, v52, v53);
          goto LABEL_16;
        }
        if ( *v25 )
        {
          v37 = (*v25)[13];
          if ( v37 )
          {
            v38 = *(__int64 (**)(void))(v37 + 96);
            if ( v38 )
            {
              if ( *((_DWORD *)v38 - 1) != 799902358 )
                __break(0x8228u);
              v39 = v38();
LABEL_21:
              if ( *v25 )
              {
                v54 = **v25;
                if ( v54 )
                {
                  v55 = *(_DWORD **)(v54 + 96);
                  if ( v55 )
                  {
                    if ( *(v55 - 1) != -612755781 )
                      __break(0x8228u);
                    ((void (__fastcall *)(__int64 **, _QWORD, int *))v55)(v25, a3, &v95);
                  }
                }
              }
              else
              {
                qdf_trace_msg(
                  0x89u,
                  8u,
                  "%s: Invalid Instance:",
                  v26,
                  v27,
                  v28,
                  v29,
                  v30,
                  v31,
                  v32,
                  v33,
                  "cdp_peer_teardown");
              }
              if ( (a4 & 1) != 0 )
                goto LABEL_33;
              if ( (wmi_service_enabled(*a1, 0xC5u, v26, v27, v28, v29, v30, v31, v32, v33) & 1) == 0 )
                wmi_unified_peer_flush_tids_send(*a1);
              wlan_roam_debug_log(a3, 2u, 0xFFFFu, (__int64)&v95, 0, 0, 0);
              v56 = wmi_unified_peer_delete_send(*a1);
              if ( !v56 )
              {
LABEL_33:
                v58 = 0;
                v57 = 1;
              }
              else
              {
                v57 = 2;
                qdf_trace_msg(
                  0x36u,
                  2u,
                  "%s: Peer delete could not be sent to firmware %d",
                  v26,
                  v27,
                  v28,
                  v29,
                  v30,
                  v31,
                  v32,
                  v33,
                  "wma_remove_peer",
                  v56);
                v58 = 16;
              }
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: vdevid %d is detaching with peer_addr %02x:%02x:%02x:**:**:%02x peer_count %d",
                v26,
                v27,
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                "wma_remove_peer",
                (unsigned __int8)a3,
                (unsigned __int8)v95,
                BYTE1(v95),
                BYTE2(v95),
                HIBYTE(v96),
                *(_DWORD *)(v34 + 244));
              if ( (a4 & 1) != 0 )
              {
                if ( *v25 && (v67 = (*v25)[9]) != 0 )
                {
                  if ( *(_QWORD *)(v67 + 152) )
                  {
                    if ( (v39 & 1) != 0 )
                    {
                      cdp_peer_delete_sync(v25, a3, &v95, v57);
                    }
                    else
                    {
                      qdf_trace_msg(
                        0x36u,
                        8u,
                        "%s: LFR3: trigger force delete for peer %02x:%02x:%02x:**:**:%02x",
                        v59,
                        v60,
                        v61,
                        v62,
                        v63,
                        v64,
                        v65,
                        v66,
                        "wma_remove_peer",
                        (unsigned __int8)v95,
                        BYTE1(v95),
                        BYTE2(v95),
                        HIBYTE(v96));
                      cdp_peer_detach_force_delete(v25, a3, &v95);
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
                    v59,
                    v60,
                    v61,
                    v62,
                    v63,
                    v64,
                    v65,
                    v66,
                    "is_cdp_peer_detach_force_delete_supported");
                }
                qdf_trace_msg(
                  0x36u,
                  8u,
                  "%s: LFR3: Delete the peer %02x:%02x:%02x:**:**:%02x",
                  v59,
                  v60,
                  v61,
                  v62,
                  v63,
                  v64,
                  v65,
                  v66,
                  "wma_remove_peer",
                  (unsigned __int8)v95,
                  BYTE1(v95),
                  BYTE2(v95),
                  HIBYTE(v96));
              }
              v68 = *v25;
              if ( (v39 & 1) != 0 )
              {
                if ( v68 )
                {
                  v69 = *v68;
                  if ( !v69 )
                    goto LABEL_58;
                  v70 = *(void (__fastcall **)(__int64 **, __int64, int *, __int64 (__fastcall *)(unsigned int, unsigned int, const void *, double, double, double, double, double, double, double, double), __int64))(v69 + 176);
                  if ( !v70 )
                    goto LABEL_58;
                  v71 = wma_peer_unmap_conf_cb;
                  v72 = v25;
                  v73 = a3;
                  v74 = v57;
                  if ( *((_DWORD *)v70 - 1) != 2049932883 )
                    __break(0x8228u);
                  goto LABEL_48;
                }
                v76 = "cdp_peer_delete_sync";
              }
              else
              {
                if ( v68 )
                {
                  v75 = *v68;
                  if ( !v75 )
                    goto LABEL_58;
                  v70 = *(void (__fastcall **)(__int64 **, __int64, int *, __int64 (__fastcall *)(unsigned int, unsigned int, const void *, double, double, double, double, double, double, double, double), __int64))(v75 + 160);
                  if ( !v70 )
                    goto LABEL_58;
                  v72 = v25;
                  v73 = a3;
                  v71 = (__int64 (__fastcall *)(unsigned int, unsigned int, const void *, double, double, double, double, double, double, double, double))v57;
                  v74 = 1;
                  if ( *((_DWORD *)v70 - 1) != -175540032 )
                    __break(0x8228u);
LABEL_48:
                  v70(v72, v73, &v95, v71, v74);
LABEL_58:
                  wlan_objmgr_peer_release_ref(v36, 8u, v59, v60, v61, v62, v63, v64, v65, v66);
                  wlan_release_peer_key_wakelock(
                    *(_QWORD *)v34,
                    (unsigned __int8 *)&v95,
                    v77,
                    v78,
                    v79,
                    v80,
                    v81,
                    v82,
                    v83,
                    v84);
                  wma_remove_objmgr_peer(
                    (__int64)a1,
                    *(_QWORD *)v34,
                    (unsigned __int8 *)&v95,
                    v85,
                    v86,
                    v87,
                    v88,
                    v89,
                    v90,
                    v91,
                    v92);
                  result = v58;
                  --*(_DWORD *)(v34 + 244);
                  goto LABEL_17;
                }
                v76 = "cdp_peer_delete";
              }
              qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v59, v60, v61, v62, v63, v64, v65, v66, v76);
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
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "cdp_cfg_get_peer_unmap_conf_support");
        }
        v39 = 0;
        goto LABEL_21;
      }
      v40 = (unsigned __int8)v95;
      v42 = "%s: peer doesn't exist peer_addr %02x:%02x:%02x:**:**:%02x vdevid %d peer_count %d";
      v41 = BYTE1(v95);
      v43 = BYTE2(v95);
      v44 = HIBYTE(v96);
      v93 = *(_DWORD *)(v34 + 244);
    }
    else
    {
      v40 = (unsigned __int8)v95;
      v41 = BYTE1(v95);
      v42 = "%s: Can't remove peer with peer_addr %02x:%02x:%02x:**:**:%02x vdevid %d peer_count %d";
      v43 = BYTE2(v95);
      v44 = HIBYTE(v96);
      v93 = 0;
    }
    qdf_trace_msg(
      0x36u,
      2u,
      v42,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wma_remove_peer",
      v40,
      v41,
      v43,
      v44,
      (unsigned __int8)a3,
      v93);
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
