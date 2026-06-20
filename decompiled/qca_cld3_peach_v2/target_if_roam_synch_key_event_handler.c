__int64 __fastcall target_if_roam_synch_key_event_handler(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 psoc_from_scn_hdl; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  __int64 v15; // x19
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  const char *v25; // x2
  __int64 result; // x0
  unsigned int v27; // w19
  const char *v28; // x2
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  _BYTE *v45; // x8
  unsigned __int64 v46; // x20
  _BYTE *v47; // x9
  __int64 v48; // x9
  char *v49; // x11
  int v50; // w12
  char *v51; // x8
  unsigned __int8 *ap_link_by_link_id; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned __int8 *v61; // x10
  __int64 v62; // x7
  int v63; // w8
  int v64; // w9
  int v65; // w11
  __int64 i; // x25
  __int64 v67; // x9
  int *v68; // x28
  unsigned __int8 *v69; // x23
  __int64 v70; // x5
  unsigned __int8 *v71; // x9
  __int64 v72; // x6
  __int64 v73; // x7
  int v74; // w8
  int v75; // w9
  int v76; // w11
  char *v77; // x8
  char *v78; // x9
  __int64 v79; // x10
  int v80; // w12
  __int64 v81; // x10
  int v82; // w12
  __int64 v83; // x10
  int v84; // w12
  __int64 v85; // x9
  int v86; // w11
  unsigned __int8 *v87; // x25
  char *v88; // x9
  __int64 v89; // x10
  int v90; // w12
  __int64 v91; // x10
  int v92; // w12
  __int64 v93; // x10
  int v94; // w12
  __int64 v95; // x9
  int v96; // w11
  __int64 ext_hdl; // x0
  _DWORD *v98; // x8
  _BYTE *v99; // x1
  __int64 v100; // x2
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 v109; // [xsp+0h] [xbp-70h]
  __int64 v110; // [xsp+8h] [xbp-68h]
  __int64 v111; // [xsp+10h] [xbp-60h]
  __int64 v112; // [xsp+18h] [xbp-58h]
  __int64 v113; // [xsp+20h] [xbp-50h]
  __int64 v114; // [xsp+28h] [xbp-48h]
  __int64 v115; // [xsp+30h] [xbp-40h]
  _BYTE v116[4]; // [xsp+3Ch] [xbp-34h] BYREF
  _QWORD *v117; // [xsp+40h] [xbp-30h] BYREF
  _BYTE *v118; // [xsp+48h] [xbp-28h] BYREF
  int v119; // [xsp+50h] [xbp-20h] BYREF
  __int16 v120; // [xsp+54h] [xbp-1Ch]
  __int64 v121; // [xsp+68h] [xbp-8h]

  v121 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v117 = nullptr;
  v118 = nullptr;
  v120 = 0;
  v119 = 0;
  v116[0] = 0;
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v28 = "%s: psoc is null";
    goto LABEL_12;
  }
  v14 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  v15 = psoc_from_scn_hdl;
  if ( !v14 || (v16 = *(_QWORD *)(v14 + 16)) == 0 )
  {
    v28 = "%s: wmi_handle is null";
LABEL_12:
    qdf_trace_msg(0x49u, 2u, v28, v6, v7, v8, v9, v10, v11, v12, v13, "target_if_roam_synch_key_event_handler");
    result = 4294967274LL;
    goto LABEL_13;
  }
  if ( (unsigned int)wmi_extract_roam_synch_key_event(v16, a2, a3, &v118, v116, &v119) )
  {
    v25 = "%s: parsing of roam sync key event failed";
  }
  else
  {
    wlan_mlo_get_mlpeer_by_peer_mladdr(&v119, &v117);
    if ( !v117 )
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: ML context is not found mld addr: %02x:%02x:%02x:**:**:%02x",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "target_if_roam_synch_key_event_handler",
        (unsigned __int8)v119,
        BYTE1(v119),
        BYTE2(v119),
        HIBYTE(v120));
      goto LABEL_7;
    }
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: num_keys:%d ML context is found mld addr: %02x:%02x:%02x:**:**:%02x",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "target_if_roam_synch_key_event_handler",
      v116[0],
      (unsigned __int8)v119,
      BYTE1(v119),
      BYTE2(v119),
      HIBYTE(v120));
    if ( v116[0] )
    {
      v45 = v118;
      v46 = 0;
      do
      {
        v45[168 * v46 + 10] = -1;
        v45 = v118;
        v48 = v117[3];
        v49 = &v118[168 * v46];
        if ( v48 && v49[9] == *(_BYTE *)(v48 + 93) || (v48 = v117[4]) != 0 && v49[9] == *(_BYTE *)(v48 + 93) )
        {
          v118[168 * v46 + 10] = *(_BYTE *)(v48 + 168);
          v50 = *(_DWORD *)(v48 + 86);
          v51 = &v118[168 * v46];
          *((_WORD *)v51 + 2) = *(_WORD *)(v48 + 90);
          *(_DWORD *)v51 = v50;
          ap_link_by_link_id = (unsigned __int8 *)mlo_mgr_get_ap_link_by_link_id(
                                                    *(_QWORD *)(v48 + 1360),
                                                    (unsigned __int8)v118[168 * v46 + 9]);
          if ( ap_link_by_link_id )
          {
            v61 = &v118[168 * v46];
            if ( v61 )
            {
              v62 = *v61;
              v63 = v61[1];
              v64 = v61[2];
              v65 = v61[5];
            }
            else
            {
              v64 = 0;
              v62 = 0;
              v63 = 0;
              v65 = 0;
            }
            v87 = ap_link_by_link_id + 24;
            LODWORD(v115) = ap_link_by_link_id[29];
            LODWORD(v114) = ap_link_by_link_id[26];
            LODWORD(v113) = ap_link_by_link_id[25];
            LODWORD(v112) = ap_link_by_link_id[24];
            LODWORD(v111) = v65;
            LODWORD(v110) = v64;
            LODWORD(v109) = v63;
            qdf_trace_msg(
              0x49u,
              8u,
              "%s: i:%d link_id:%d vdev_id:%d self link_addr: %02x:%02x:%02x:**:**:%02x AP link addr: %02x:%02x:%02x:**:**:%02x",
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              "target_if_roam_synch_key_event_handler",
              (unsigned int)v46,
              v61[9],
              v61[10],
              v62,
              v109,
              v110,
              v111,
              v112,
              v113,
              v114,
              v115);
            v45 = v118;
            v88 = &v118[168 * v46];
            if ( (unsigned __int8)v88[9] != 255 )
            {
              v89 = *((_QWORD *)v88 + 2);
              if ( v89 && !*(_DWORD *)(v89 + 12) )
              {
                v90 = *(_DWORD *)v87;
                *(_WORD *)(v89 + 20) = *((_WORD *)v87 + 2);
                *(_DWORD *)(v89 + 16) = v90;
              }
              v91 = *((_QWORD *)v88 + 3);
              if ( v91 && !*(_DWORD *)(v91 + 12) )
              {
                v92 = *(_DWORD *)v87;
                *(_WORD *)(v91 + 20) = *((_WORD *)v87 + 2);
                *(_DWORD *)(v91 + 16) = v92;
              }
              v93 = *((_QWORD *)v88 + 4);
              if ( v93 && !*(_DWORD *)(v93 + 12) )
              {
                v94 = *(_DWORD *)v87;
                *(_WORD *)(v93 + 20) = *((_WORD *)v87 + 2);
                *(_DWORD *)(v93 + 16) = v94;
              }
              v95 = *((_QWORD *)v88 + 5);
              if ( v95 && !*(_DWORD *)(v95 + 12) )
              {
                v96 = *(_DWORD *)v87;
                *(_WORD *)(v95 + 20) = *((_WORD *)v87 + 2);
                *(_DWORD *)(v95 + 16) = v96;
              }
            }
          }
          else
          {
            qdf_trace_msg(
              0x49u,
              2u,
              "%s: Link info not found for link_id:%d",
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              "target_if_roam_synch_key_event_handler",
              (unsigned __int8)v118[168 * v46 + 9]);
            v45 = v118;
          }
        }
        v47 = &v45[168 * v46];
        if ( (unsigned __int8)v47[10] == 255 && (unsigned __int8)v47[9] != 255 && v117[485] )
        {
          for ( i = 0; i != 144; i += 48 )
          {
            v67 = v117[485];
            v68 = (int *)(v67 + i);
            v69 = (unsigned __int8 *)(v67 + i + 24);
            if ( *(_DWORD *)v69 | *(unsigned __int16 *)(v67 + i + 28) )
            {
              if ( *v68 | *((unsigned __int16 *)v68 + 2) )
              {
                v70 = (unsigned __int8)v45[168 * v46 + 9];
                if ( *(unsigned __int8 *)(v67 + i + 6) == (_DWORD)v70 )
                {
                  if ( v67 + i == -24 )
                  {
                    v74 = 0;
                    v72 = 0;
                    v73 = 0;
                    v75 = 0;
                  }
                  else
                  {
                    v71 = (unsigned __int8 *)(v67 + i);
                    v72 = *v69;
                    v73 = v71[25];
                    v74 = v71[26];
                    v75 = v71[29];
                  }
                  LODWORD(v110) = v75;
                  LODWORD(v109) = v74;
                  qdf_trace_msg(
                    0x49u,
                    8u,
                    "%s: i:%d Standby vdev: link_id:%d ap_link_addr: %02x:%02x:%02x:**:**:%02x",
                    v37,
                    v38,
                    v39,
                    v40,
                    v41,
                    v42,
                    v43,
                    v44,
                    "target_if_roam_synch_key_event_handler",
                    (unsigned int)v46,
                    v70,
                    v72,
                    v73,
                    v109,
                    v110);
                  v76 = *v68;
                  v77 = &v118[168 * v46];
                  *((_WORD *)v77 + 2) = *((_WORD *)v68 + 2);
                  *(_DWORD *)v77 = v76;
                  v45 = v118;
                  v78 = &v118[168 * v46];
                  if ( (unsigned __int8)v78[9] != 255 )
                  {
                    v79 = *((_QWORD *)v78 + 2);
                    if ( v79 && !*(_DWORD *)(v79 + 12) )
                    {
                      v80 = *(_DWORD *)v69;
                      *(_WORD *)(v79 + 20) = *((_WORD *)v69 + 2);
                      *(_DWORD *)(v79 + 16) = v80;
                    }
                    v81 = *((_QWORD *)v78 + 3);
                    if ( v81 && !*(_DWORD *)(v81 + 12) )
                    {
                      v82 = *(_DWORD *)v69;
                      *(_WORD *)(v81 + 20) = *((_WORD *)v69 + 2);
                      *(_DWORD *)(v81 + 16) = v82;
                    }
                    v83 = *((_QWORD *)v78 + 4);
                    if ( v83 && !*(_DWORD *)(v83 + 12) )
                    {
                      v84 = *(_DWORD *)v69;
                      *(_WORD *)(v83 + 20) = *((_WORD *)v69 + 2);
                      *(_DWORD *)(v83 + 16) = v84;
                    }
                    v85 = *((_QWORD *)v78 + 5);
                    if ( v85 && !*(_DWORD *)(v85 + 12) )
                    {
                      v86 = *(_DWORD *)v69;
                      *(_WORD *)(v85 + 20) = *((_WORD *)v69 + 2);
                      *(_DWORD *)(v85 + 16) = v86;
                    }
                  }
                }
              }
            }
          }
        }
        ++v46;
      }
      while ( v46 < v116[0] );
    }
    ext_hdl = wlan_psoc_mlme_get_ext_hdl(v15);
    if ( ext_hdl )
    {
      v98 = *(_DWORD **)(ext_hdl + 7544);
      if ( v98 )
      {
        v99 = v118;
        v100 = v116[0];
        if ( *(v98 - 1) != -794165925 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _BYTE *, __int64))v98)(v15, v99, v100);
        if ( (_DWORD)result )
        {
          qdf_trace_msg(
            0x49u,
            2u,
            "%s: Add keys failed",
            v101,
            v102,
            v103,
            v104,
            v105,
            v106,
            v107,
            v108,
            "target_if_roam_synch_key_event_handler");
          result = 0;
        }
        goto LABEL_8;
      }
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: psoc legacy private object is NULL",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "target_if_cm_get_roam_rx_ops");
    }
    v25 = "%s: No valid roam rx ops";
  }
  qdf_trace_msg(0x49u, 2u, v25, v17, v18, v19, v20, v21, v22, v23, v24, "target_if_roam_synch_key_event_handler");
LABEL_7:
  result = 4294967274LL;
LABEL_8:
  if ( v118 )
  {
    v27 = result;
    qdf_mem_set(v118, 0x1F8u, 0);
    _qdf_mem_free((__int64)v118);
    result = v27;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
