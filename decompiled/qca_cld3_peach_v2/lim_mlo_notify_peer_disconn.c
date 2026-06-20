__int64 __fastcall lim_mlo_notify_peer_disconn(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  _QWORD *peer_by_mac; // x0
  _QWORD *v14; // x22
  char is_mlo_vdev; // w8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int16 v24; // w24
  _QWORD *context; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x20
  unsigned __int8 *v35; // x25
  const char *v36; // x2
  __int64 result; // x0
  const char *v38; // x2
  __int64 partner_session_by_link_id; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x21
  __int64 v49; // x0
  unsigned int *v50; // x8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x21
  __int64 v69; // x0
  unsigned int *v70; // x8
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x0
  __int64 v80; // x19
  __int64 v81; // x0
  unsigned int *v82; // x8
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  _QWORD *v91; // x19
  _WORD v92[2]; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v93; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v94[2]; // [xsp+10h] [xbp-10h] BYREF

  v94[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    if ( a2 )
    {
      v10 = *(_QWORD *)(a1 + 8608);
      if ( v10 )
      {
        peer_by_mac = wlan_objmgr_get_peer_by_mac(*(_QWORD *)(v10 + 21624), (_BYTE *)(a2 + 350), 7u);
        if ( peer_by_mac )
        {
          if ( (peer_by_mac[8] & 1) == 0 )
          {
LABEL_44:
            result = wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 7u, a3, a4, a5, a6, a7, a8, a9, a10);
            goto LABEL_16;
          }
          if ( *(_DWORD *)(*(_QWORD *)(a1 + 16) + 16LL) != 1
            || (v14 = peer_by_mac,
                is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a1 + 16), a3, a4, a5, a6, a7, a8, a9, a10),
                peer_by_mac = v14,
                (is_mlo_vdev & 1) == 0) )
          {
LABEL_43:
            v91 = peer_by_mac;
            wlan_mlo_partner_peer_disconnect_notify();
            peer_by_mac = v91;
            goto LABEL_44;
          }
          v24 = *(_WORD *)(a2 + 34);
          v93 = 0;
          v94[0] = 0;
          v92[0] = 0;
          context = _cds_get_context(
                      53,
                      (__int64)"lim_mlo_update_cleanup_trigger",
                      v16,
                      v17,
                      v18,
                      v19,
                      v20,
                      v21,
                      v22,
                      v23);
          if ( !context )
          {
            v38 = "%s: mac ctx is null";
LABEL_41:
            qdf_trace_msg(0x35u, 2u, v38, v26, v27, v28, v29, v30, v31, v32, v33, "lim_mlo_update_cleanup_trigger");
LABEL_42:
            peer_by_mac = v14;
            goto LABEL_43;
          }
          v34 = (__int64)context;
          v35 = (unsigned __int8 *)a2;
          if ( *(_BYTE *)(a2 + 1086) == 1 )
          {
            v94[0] = a2;
          }
          else
          {
            lim_mlo_get_assoc_link_session_sta_ds(a1, *(unsigned __int16 *)(a2 + 348), &v93, v94);
            v35 = (unsigned __int8 *)v94[0];
            if ( !v94[0] )
            {
LABEL_40:
              v38 = "%s: assoc link sta ds is null";
              goto LABEL_41;
            }
            *(_WORD *)(v94[0] + 34LL) = v24;
          }
          if ( !v35[1088] )
            goto LABEL_42;
          partner_session_by_link_id = pe_find_partner_session_by_link_id(
                                         a1,
                                         v35[1102],
                                         v26,
                                         v27,
                                         v28,
                                         v29,
                                         v30,
                                         v31,
                                         v32,
                                         v33);
          if ( partner_session_by_link_id )
          {
            v48 = partner_session_by_link_id;
            v49 = dph_lookup_hash_entry(
                    v40,
                    v41,
                    v42,
                    v43,
                    v44,
                    v45,
                    v46,
                    v47,
                    v34,
                    v35 + 1096,
                    v92,
                    partner_session_by_link_id + 360);
            if ( v49 && v49 != a2 )
              *(_WORD *)(v49 + 34) = v24;
            wlan_objmgr_vdev_release_ref(*(_QWORD *)(v48 + 16), 0x5Au, v50, v51, v52, v53, v54, v55, v56, v57, v58);
          }
          if ( v35[1088] < 2u )
            goto LABEL_42;
          v59 = pe_find_partner_session_by_link_id(a1, v35[1150], v40, v41, v42, v43, v44, v45, v46, v47);
          if ( v59 )
          {
            v68 = v59;
            v69 = dph_lookup_hash_entry(v60, v61, v62, v63, v64, v65, v66, v67, v34, v35 + 1144, v92, v59 + 360);
            if ( v69 && v69 != a2 )
              *(_WORD *)(v69 + 34) = v24;
            wlan_objmgr_vdev_release_ref(*(_QWORD *)(v68 + 16), 0x5Au, v70, v71, v72, v73, v74, v75, v76, v77, v78);
          }
          if ( v35[1088] < 3u )
            goto LABEL_42;
          v79 = pe_find_partner_session_by_link_id(a1, v35[1198], v60, v61, v62, v63, v64, v65, v66, v67);
          if ( v79 )
          {
            v80 = v79;
            v81 = dph_lookup_hash_entry(v26, v27, v28, v29, v30, v31, v32, v33, v34, v35 + 1192, v92, v79 + 360);
            if ( v81 && v81 != a2 )
              *(_WORD *)(v81 + 34) = v24;
            wlan_objmgr_vdev_release_ref(*(_QWORD *)(v80 + 16), 0x5Au, v82, v83, v84, v85, v86, v87, v88, v89, v90);
          }
          if ( v35[1088] <= 3u )
            goto LABEL_42;
          __break(0x5512u);
          goto LABEL_40;
        }
        v36 = "%s: peer is null";
      }
      else
      {
        v36 = "%s: mac context is null";
      }
    }
    else
    {
      v36 = "%s: sta ds is null";
    }
  }
  else
  {
    v36 = "%s: pe session is null";
  }
  result = qdf_trace_msg(0x35u, 2u, v36, a3, a4, a5, a6, a7, a8, a9, a10, "lim_mlo_notify_peer_disconn");
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
