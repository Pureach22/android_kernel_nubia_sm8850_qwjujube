__int64 __fastcall lim_delete_sta_context(
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
  __int64 v10; // x19
  __int64 session_by_vdev_id; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w4
  __int64 v23; // x22
  __int64 result; // x0
  const char *v25; // x2
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x23
  int v44; // w8
  unsigned int v45; // w8
  __int64 v46; // x4
  const char *v47; // x2
  int v48; // w8
  unsigned int v49; // w9
  __int64 v50; // x2
  __int64 v51; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int v60; // w8
  __int16 v61; // w9
  __int64 v62; // [xsp+0h] [xbp-80h] BYREF
  __int64 v63; // [xsp+8h] [xbp-78h]
  __int64 v64; // [xsp+10h] [xbp-70h] BYREF
  __int64 v65; // [xsp+18h] [xbp-68h]
  __int64 v66; // [xsp+20h] [xbp-60h]
  __int64 v67; // [xsp+28h] [xbp-58h]
  __int64 v68; // [xsp+30h] [xbp-50h]
  __int64 v69; // [xsp+38h] [xbp-48h]
  __int64 v70; // [xsp+40h] [xbp-40h]
  __int64 v71; // [xsp+48h] [xbp-38h]
  __int64 v72; // [xsp+50h] [xbp-30h]
  __int64 v73; // [xsp+58h] [xbp-28h]
  __int64 v74; // [xsp+60h] [xbp-20h]
  __int64 v75; // [xsp+68h] [xbp-18h]
  __int64 v76; // [xsp+70h] [xbp-10h]
  __int64 v77; // [xsp+78h] [xbp-8h]

  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a2 + 8);
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  v64 = 0;
  if ( v10 )
  {
    session_by_vdev_id = pe_find_session_by_vdev_id(a1, *(unsigned __int8 *)(v10 + 1));
    if ( session_by_vdev_id )
    {
      v22 = *(unsigned __int16 *)(v10 + 16);
      v23 = session_by_vdev_id;
      if ( v22 > 5 )
      {
        if ( v22 - 6 > 1 )
          goto LABEL_25;
      }
      else if ( v22 != 1 )
      {
        if ( v22 == 4 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Deleting Unknown station:  %02x:%02x:%02x:**:**:%02x",
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            "lim_delete_sta_context",
            *(unsigned __int8 *)(v10 + 10),
            *(unsigned __int8 *)(v10 + 11),
            *(unsigned __int8 *)(v10 + 12),
            *(unsigned __int8 *)(v10 + 15));
          lim_send_deauth_mgmt_frame(a1, 7, v10 + 10, v23, 0);
LABEL_50:
          result = _qdf_mem_free(v10);
          *(_QWORD *)(a2 + 8) = 0;
          goto LABEL_51;
        }
        if ( v22 == 5 )
        {
          if ( (lim_is_sb_disconnect_allowed_fl(session_by_vdev_id, (__int64)"lim_delete_sta_context", 0x118u) & 1) != 0 )
          {
            lim_send_deauth_mgmt_frame(a1, 12, v23 + 24, v23, 0);
            ((void (__fastcall *)(__int64, _QWORD, __int64, __int64))lim_tear_down_link_with_ap)(
              a1,
              *(unsigned __int8 *)(v23 + 8),
              12,
              6);
          }
          goto LABEL_50;
        }
LABEL_25:
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Unknown reason code",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "lim_delete_sta_context");
        goto LABEL_50;
      }
      if ( *(_DWORD *)(session_by_vdev_id + 88) != 2 || (*(_BYTE *)v10 & 1) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Deleting station: reasonCode: %d",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "lim_delete_sta_util");
        v34 = dph_lookup_hash_entry(
                v26,
                v27,
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                a1,
                (unsigned __int8 *)(v10 + 10),
                (_WORD *)(v10 + 2),
                v23 + 360);
        if ( v34 )
        {
          v43 = v34;
          *(_BYTE *)(v34 + 660) = *(_BYTE *)(v10 + 18);
          v44 = *(_DWORD *)(v23 + 88);
          if ( v44 == 2 )
          {
            if ( *(_BYTE *)(v34 + 356) == 4 )
            {
              wlan_tdls_update_peer_kickout_count(*(_QWORD *)(v23 + 16), v34 + 350);
              lim_send_sme_tdls_del_sta_ind(a1, v43, v23, 25);
              goto LABEL_50;
            }
          }
          else if ( v44 == 1 )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Delete Station assocId: %d",
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              "lim_delete_sta_util",
              *(unsigned __int16 *)(v10 + 2));
            v45 = *(_DWORD *)(v43 + 8);
            if ( v45 <= 0xF && ((1 << v45) & 0xD000) != 0 )
            {
              if ( (*(_WORD *)v43 & 0x800) != 0 && *(_DWORD *)(v43 + 860) != *(_DWORD *)(v23 + 284) )
              {
                lim_send_deauth_mgmt_frame(a1, 2, v43 + 350, v23, 1);
                *(_BYTE *)(v43 + 658) = 1;
              }
              else
              {
                lim_send_disassoc_mgmt_frame(a1, 4, v43 + 350, v23, 0);
                lim_trigger_sta_deletion(a1, v43, v23);
              }
              goto LABEL_50;
            }
            v46 = *(unsigned __int16 *)(v10 + 2);
            v47 = "%s: Inv Del STA assocId: %d";
            goto LABEL_27;
          }
          LODWORD(v63) = 0;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Delete Station (assocId: %d)",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "lim_delete_sta_util",
            *(unsigned __int16 *)(v10 + 2),
            0,
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            v77);
          v60 = *(_DWORD *)(v43 + 8);
          if ( v60 <= 0xF && ((1 << v60) & 0xD000) != 0 )
          {
            *(_DWORD *)(v43 + 24) = 4;
            *(_WORD *)(v43 + 34) = 6;
            qdf_mem_copy(&v62, (const void *)(v43 + 350), 6u);
            v61 = *(_WORD *)(v43 + 34);
            HIWORD(v62) = *(unsigned __int8 *)(v43 + 24);
            LOWORD(v63) = v61;
            lim_delete_tdls_peers(a1, v23, 0);
            if ( *(_DWORD *)(v23 + 88) == 2 )
              lim_process_mlm_rsp_messages(a1, 1019, &v62);
            lim_send_sme_deauth_ind(a1, v43, v23);
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Received SIR_LIM_DELETE_STA_CONTEXT_IND for STA that either has no context or in some transit state, A"
              "ddr = %02x:%02x:%02x:**:**:%02x",
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              "lim_delete_sta_util",
              *(unsigned __int8 *)(v10 + 4),
              *(unsigned __int8 *)(v10 + 5),
              *(unsigned __int8 *)(v10 + 6),
              *(unsigned __int8 *)(v10 + 9));
          }
          goto LABEL_50;
        }
        v46 = *(unsigned int *)(v23 + 88);
        v47 = "%s: Invalid STA limSystemRole: %d";
LABEL_27:
        qdf_trace_msg(0x35u, 2u, v47, v35, v36, v37, v38, v39, v40, v41, v42, "lim_delete_sta_util", v46);
        goto LABEL_50;
      }
      if ( (lim_is_sb_disconnect_allowed_fl(session_by_vdev_id, (__int64)"lim_delete_sta_context", 0xDEu) & 1) == 0 )
        goto LABEL_12;
      if ( dph_get_hash_entry(a1, 1u, v23 + 360) )
      {
        if ( (qdf_is_macaddr_zero(v10 + 10) & 1) != 0 )
          qdf_mem_copy((void *)(v10 + 10), (const void *)(v23 + 24), 6u);
        lim_send_deauth_mgmt_frame(a1, 4, v10 + 10, v23, 0);
        v48 = *(unsigned __int16 *)(v10 + 16);
        if ( v48 == 7 )
          v49 = 65529;
        else
          v49 = 65530;
        if ( v48 == 6 )
          v50 = 65531;
        else
          v50 = v49;
        ((void (__fastcall *)(__int64, _QWORD, __int64, __int64))lim_tear_down_link_with_ap)(
          a1,
          *(unsigned __int8 *)(v23 + 8),
          v50,
          6);
        qdf_mem_set(&v64, 0x68u, 0);
        qdf_mem_copy(&v64, (const void *)(v10 + 10), 6u);
        v51 = *(_QWORD *)(a1 + 21632);
        v75 = 0x200000002LL;
        LODWORD(v76) = 1;
        ((void (__fastcall *)(__int64, _QWORD, __int64 *))dlm_update_mlo_reject_ap_info)(
          v51,
          *(unsigned __int8 *)(v10 + 1),
          &v64);
        dlm_add_bssid_to_reject_list(*(_QWORD *)(a1 + 21632), &v64);
        goto LABEL_50;
      }
      v25 = "%s: Dph entry not found";
    }
    else
    {
      v25 = "%s: session not found for given sme session";
    }
    qdf_trace_msg(0x35u, 2u, v25, v14, v15, v16, v17, v18, v19, v20, v21, "lim_delete_sta_context");
LABEL_12:
    result = _qdf_mem_free(v10);
    goto LABEL_51;
  }
  result = qdf_trace_msg(
             0x35u,
             2u,
             "%s: Invalid body pointer in message",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "lim_delete_sta_context");
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
