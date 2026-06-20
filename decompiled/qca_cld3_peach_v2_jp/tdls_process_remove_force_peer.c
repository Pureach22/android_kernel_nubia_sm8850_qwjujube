__int64 __fastcall tdls_process_remove_force_peer(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  const void *v10; // x21
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  __int64 comp_private_obj; // x22
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x4
  unsigned int v41; // w8
  __int64 v42; // x23
  __int64 peer; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x24
  _DWORD *v53; // x8
  __int64 v54; // x0
  __int64 v55; // x2
  __int64 v56; // x1
  __int64 v57; // x0
  void (__fastcall *v58)(__int64, __int64, __int64 *); // x10
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int *v67; // x8
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  unsigned int updated; // w21
  const char *v77; // x2
  int *v79; // x0
  int *v80; // x22
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 v89; // [xsp+0h] [xbp-20h] BYREF
  __int16 v90; // [xsp+8h] [xbp-18h]
  _BYTE v91[6]; // [xsp+Ah] [xbp-16h] BYREF

  v10 = (const void *)(a1 + 8);
  qdf_trace_msg(
    0,
    8u,
    "%s: NL80211_TDLS_TEARDOWN for %02x:%02x:%02x:**:**:%02x",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "tdls_process_remove_force_peer",
    *(unsigned __int8 *)(a1 + 8),
    *(unsigned __int8 *)(a1 + 9),
    *(unsigned __int8 *)(a1 + 10),
    *(unsigned __int8 *)(a1 + 13),
    0,
    0,
    0,
    *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808));
  v19 = *(_QWORD *)a1;
  if ( *(_QWORD *)a1 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(*(_QWORD *)a1, 0xAu);
    if ( *(_QWORD *)a1 )
    {
      v29 = *(_QWORD *)(*(_QWORD *)a1 + 152LL);
      if ( v29 )
      {
        v30 = *(_QWORD *)(v29 + 80);
        if ( v30 )
        {
          v31 = wlan_objmgr_psoc_get_comp_private_obj(v30, 0xAu);
          v40 = v31;
          if ( v31 && comp_private_obj )
          {
            v41 = *(_DWORD *)(v31 + 156);
            if ( (v41 & 0x180) == 0 || (v41 & 0x40) == 0 )
            {
              qdf_trace_msg(
                0,
                2u,
                "%s: TDLS ext ctrl or Imp Trig not enabled, %x",
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                "tdls_process_remove_force_peer",
                v41);
              updated = 11;
              goto LABEL_28;
            }
            v42 = v31;
            peer = tdls_find_peer(comp_private_obj, v10);
            if ( !peer )
            {
              qdf_trace_msg(
                0,
                2u,
                "%s: peer matching %02x:%02x:%02x:**:**:%02x not found",
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                v50,
                v51,
                "tdls_process_remove_force_peer",
                *(unsigned __int8 *)(a1 + 8),
                *(unsigned __int8 *)(a1 + 9),
                *(unsigned __int8 *)(a1 + 10),
                *(unsigned __int8 *)(a1 + 13));
              updated = 29;
              goto LABEL_28;
            }
            v52 = peer;
            if ( *(_DWORD *)(peer + 36) == 4 )
              tdls_set_peer_link_status(peer, 5, 0xFFFFFFFFLL);
            v53 = *(_DWORD **)(v42 + 296);
            v54 = v42;
            if ( v53 )
            {
              v55 = *(unsigned int *)(v42 + 344);
              v56 = *(unsigned __int8 *)(v19 + 104);
              if ( *(v53 - 1) != 792568820 )
                __break(0x8228u);
              ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v53)(v42, v56, v55, 0);
              v54 = v42;
            }
            if ( *(_QWORD *)(v54 + 264) )
            {
              qdf_mem_copy(v91, v10, 6u);
              v58 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v42 + 264);
              v57 = *(_QWORD *)(v42 + 272);
              v89 = v19;
              v90 = 26;
              if ( *((_DWORD *)v58 - 1) != 1890320457 )
                __break(0x822Au);
              v58(v57, 6, &v89);
            }
            if ( !(unsigned int)tdls_set_force_peer(comp_private_obj, v10, 0) )
            {
              if ( *(_BYTE *)(v42 + 213) )
                --*(_BYTE *)(v42 + 213);
              tdls_set_callback(v52, 0);
              v79 = (int *)_qdf_mem_malloc(0x444u, "tdls_process_remove_force_peer", 2271);
              if ( v79 )
              {
                v80 = v79;
                *v79 = *(unsigned __int8 *)(v19 + 104);
                qdf_mem_copy(v79 + 1, v10, 6u);
                v80[3] = 4;
                updated = tdls_wma_update_peer_state(v42, v80, v81, v82, v83, v84, v85, v86, v87, v88);
                if ( updated )
                  _qdf_mem_free((__int64)v80);
                else
                  tdls_set_ct_mode(*(_QWORD *)v42, v19);
              }
              else
              {
                updated = 2;
              }
              goto LABEL_28;
            }
            qdf_trace_msg(
              0,
              2u,
              "%s: set force peer failed",
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              "tdls_process_remove_force_peer");
LABEL_27:
            updated = 4;
LABEL_28:
            wlan_objmgr_vdev_release_ref(v19, 0x11u, v67, v68, v69, v70, v71, v72, v73, v74, v75);
            goto LABEL_29;
          }
LABEL_26:
          qdf_trace_msg(
            0,
            2u,
            "%s: soc_obj: %pK, vdev_obj: %pK",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "tdls_process_remove_force_peer",
            v40,
            comp_private_obj);
          goto LABEL_27;
        }
      }
      v77 = "%s: can't get psoc";
    }
    else
    {
      v77 = "%s: NULL vdev";
    }
    qdf_trace_msg(0, 2u, v77, v21, v22, v23, v24, v25, v26, v27, v28, "wlan_vdev_get_tdls_soc_obj");
    v40 = 0;
    goto LABEL_26;
  }
  qdf_trace_msg(0, 2u, "%s: NULL vdev object", v11, v12, v13, v14, v15, v16, v17, v18, "tdls_process_remove_force_peer");
  updated = 29;
LABEL_29:
  _qdf_mem_free(a1);
  _ReadStatusReg(SP_EL0);
  return updated;
}
