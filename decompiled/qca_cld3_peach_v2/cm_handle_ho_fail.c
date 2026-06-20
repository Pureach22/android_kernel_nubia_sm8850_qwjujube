__int64 __fastcall cm_handle_ho_fail(__int64 a1)
{
  unsigned __int8 *v1; // x19
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x23
  __int64 v12; // x20
  __int64 v13; // x0
  __int64 psoc_ext_obj_fl; // x0
  __int64 v15; // x22
  __int64 cm_ctx_fl; // x0
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 *v26; // x21
  __int64 first_roam_command; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int *v36; // x24
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x8
  int v56; // w9
  int v57; // w8
  unsigned int v59; // w20
  const char *v60; // x2
  __int16 v63; // w10
  int v64; // w0
  int v65; // w22
  unsigned int v66; // [xsp+Ch] [xbp-A4h] BYREF
  _QWORD v67[11]; // [xsp+10h] [xbp-A0h] BYREF
  __int64 v68; // [xsp+68h] [xbp-48h]
  __int64 v69; // [xsp+70h] [xbp-40h]
  _QWORD v70[4]; // [xsp+78h] [xbp-38h] BYREF
  __int64 v71; // [xsp+98h] [xbp-18h]
  char v72; // [xsp+A0h] [xbp-10h]
  __int64 v73; // [xsp+A8h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v66 = -1;
  if ( a1 )
  {
    v1 = *(unsigned __int8 **)(a1 + 8);
    if ( v1 )
    {
      v68 = 0;
      v69 = 0;
      memset(v67, 0, sizeof(v67));
      v2 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
             *((_QWORD *)v1 + 1),
             *v1,
             77);
      if ( !v2 )
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev_id: %d : vdev not found",
          v3,
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          "cm_handle_ho_fail",
          *v1);
        v59 = 4;
LABEL_32:
        _qdf_mem_free((__int64)v1);
        goto LABEL_33;
      }
      v11 = *(_QWORD *)(v2 + 216);
      v12 = v2;
      if ( v11 )
      {
        v13 = *(_QWORD *)(v11 + 80);
        if ( v13 )
        {
          psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(v13);
          if ( psoc_ext_obj_fl )
          {
            v15 = psoc_ext_obj_fl;
            cm_ctx_fl = cm_get_cm_ctx_fl(v12, (__int64)"cm_handle_ho_fail", 0x726u, v3, v4, v5, v6, v7, v8, v9, v10);
            if ( cm_ctx_fl )
            {
              v26 = (__int64 *)cm_ctx_fl;
              first_roam_command = cm_get_first_roam_command(v12, v18, v19, v20, v21, v22, v23, v24, v25);
              if ( first_roam_command )
              {
                v36 = (unsigned int *)first_roam_command;
                qdf_trace_msg(
                  0x68u,
                  8u,
                  "%s: Roam req found, get cm id to remove it, before disconnect",
                  v28,
                  v29,
                  v30,
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  "cm_handle_ho_fail");
                v66 = *v36;
              }
              cm_sm_deliver_event(v12, 0x14u, 4u, (__int64)&v66, v28, v29, v30, v31, v32, v33, v34, v35);
              qdf_mem_set(v67, 0x68u, 0);
              WORD2(v70[0]) = 0;
              LODWORD(v70[0]) = 0;
              if ( (wlan_vdev_mlme_is_mlo_vdev(v12, v37, v38, v39, v40, v41, v42, v43, v44) & 1) != 0 )
              {
                v53 = *(_QWORD *)(*(_QWORD *)(v12 + 1360) + 3880LL);
                if ( *(_DWORD *)(v53 + 24) == *((_DWORD *)v1 + 4)
                  && *(unsigned __int16 *)(v53 + 28) == *((unsigned __int16 *)v1 + 10) )
                {
                  goto LABEL_40;
                }
                if ( *(_DWORD *)(v53 + 72) == *((_DWORD *)v1 + 4)
                  && *(unsigned __int16 *)(v53 + 76) == *((unsigned __int16 *)v1 + 10) )
                {
                  goto LABEL_40;
                }
                v56 = *(_DWORD *)(v53 + 120);
                v57 = *(unsigned __int16 *)(v53 + 124);
                if ( v56 == *((_DWORD *)v1 + 4) && v57 == *((unsigned __int16 *)v1 + 10) )
                  goto LABEL_40;
              }
              else
              {
                wlan_vdev_get_bss_peer_mac(v12, v70, v45, v46, v47, v48, v49, v50, v51, v52);
                if ( (wlan_crypto_get_param(v12, 7u) & 0x63DF3E3) == 0
                  && LODWORD(v70[0]) == *((_DWORD *)v1 + 4)
                  && WORD2(v70[0]) == *((unsigned __int16 *)v1 + 10) )
                {
                  goto LABEL_40;
                }
              }
              v63 = *((_WORD *)v1 + 10);
              LODWORD(v67[0]) = *((_DWORD *)v1 + 4);
              v68 = 0x300000002LL;
              WORD2(v67[0]) = v63;
              LODWORD(v69) = 1;
              ((void (__fastcall *)(__int64, _QWORD, _QWORD *))dlm_update_mlo_reject_ap_info)(v11, *v1, v67);
              dlm_add_bssid_to_reject_list(v11, (__int64)v67);
LABEL_40:
              v72 = 0;
              v71 = 0;
              memset(v70, 0, sizeof(v70));
              qdf_mem_set(v70, 0x29u, 0);
              LOBYTE(v70[0]) = 1;
              HIBYTE(v71) = 8;
              host_diag_event_report_payload(2739, 41, v70);
              wlan_roam_debug_log(*v1, 0xAu, 0xFFFFu, 0, 0, 0, 0);
              v64 = mlo_disconnect(v12, 8, 65520, 0);
              v17 = (unsigned int *)*(unsigned __int8 *)(v15 + 1057);
              v65 = v64;
              if ( (_DWORD)v17 == 1 )
                cds_flush_logs(1u, 2u, 13, 0, 0, v18, v19, v20, v21, v22, v23, v24, v25);
              if ( v65 )
                cm_remove_cmd(v26, &v66, v18, v19, v20, v21, v22, v23, v24, v25);
            }
LABEL_31:
            wlan_objmgr_vdev_release_ref(v12, 0x4Du, v17, v18, v19, v20, v21, v22, v23, v24, v25);
            v59 = 0;
            goto LABEL_32;
          }
          v60 = "%s: Failed to mlme psoc obj";
        }
        else
        {
          v60 = "%s: psoc object is NULL";
        }
      }
      else
      {
        v60 = "%s: pdev object is NULL";
      }
      qdf_trace_msg(0x68u, 2u, v60, v3, v4, v5, v6, v7, v8, v9, v10, "cm_handle_ho_fail");
      goto LABEL_31;
    }
  }
  v59 = 16;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return v59;
}
