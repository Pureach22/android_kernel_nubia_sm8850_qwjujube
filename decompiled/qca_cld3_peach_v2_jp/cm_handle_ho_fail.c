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
  bool v45; // zf
  __int16 v46; // w10
  int v47; // w0
  int v48; // w22
  unsigned int v49; // w20
  const char *v50; // x2
  unsigned int v52; // [xsp+4h] [xbp-6Ch] BYREF
  _QWORD v53[4]; // [xsp+8h] [xbp-68h] BYREF
  __int64 v54; // [xsp+28h] [xbp-48h]
  __int64 v55; // [xsp+30h] [xbp-40h]
  _QWORD v56[4]; // [xsp+38h] [xbp-38h] BYREF
  __int64 v57; // [xsp+58h] [xbp-18h]
  char v58; // [xsp+60h] [xbp-10h]
  __int64 v59; // [xsp+68h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v52 = -1;
  if ( a1 )
  {
    v1 = *(unsigned __int8 **)(a1 + 8);
    if ( v1 )
    {
      v54 = 0;
      v55 = 0;
      memset(v53, 0, sizeof(v53));
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
        v49 = 4;
LABEL_27:
        _qdf_mem_free((__int64)v1);
        goto LABEL_28;
      }
      v11 = *(_QWORD *)(v2 + 152);
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
                v52 = *v36;
              }
              cm_sm_deliver_event(v12, 0x14u, 4u, (__int64)&v52, v28, v29, v30, v31, v32, v33, v34, v35);
              qdf_mem_set(v53, 0x30u, 0);
              WORD2(v56[0]) = 0;
              LODWORD(v56[0]) = 0;
              if ( (wlan_crypto_get_param(v12, 7u) & 0x63DF3E3) != 0
                || ((wlan_vdev_get_bss_peer_mac(v12, v56, v37, v38, v39, v40, v41, v42, v43, v44),
                     LODWORD(v56[0]) == *((_DWORD *)v1 + 4))
                  ? (v45 = WORD2(v56[0]) == *((unsigned __int16 *)v1 + 10))
                  : (v45 = 0),
                    !v45) )
              {
                v46 = *((_WORD *)v1 + 10);
                LODWORD(v53[0]) = *((_DWORD *)v1 + 4);
                v54 = 0x300000002LL;
                WORD2(v53[0]) = v46;
                LODWORD(v55) = 1;
                dlm_add_bssid_to_reject_list(v11, (__int64)v53);
              }
              v58 = 0;
              v57 = 0;
              memset(v56, 0, sizeof(v56));
              qdf_mem_set(v56, 0x29u, 0);
              LOBYTE(v56[0]) = 1;
              HIBYTE(v57) = 8;
              host_diag_event_report_payload(2739, 41, v56);
              wlan_roam_debug_log(*v1, 0xAu, 0xFFFFu, 0, 0, 0, 0);
              v47 = wlan_cm_disconnect(v12, 8, 65520, nullptr);
              v17 = (unsigned int *)*(unsigned __int8 *)(v15 + 1057);
              v48 = v47;
              if ( (_DWORD)v17 == 1 )
                cds_flush_logs(1u, 2u, 13, 0, 0, v18, v19, v20, v21, v22, v23, v24, v25);
              if ( v48 )
                cm_remove_cmd(v26, &v52, v18, v19, v20, v21, v22, v23, v24, v25);
            }
            goto LABEL_26;
          }
          v50 = "%s: Failed to mlme psoc obj";
        }
        else
        {
          v50 = "%s: psoc object is NULL";
        }
      }
      else
      {
        v50 = "%s: pdev object is NULL";
      }
      qdf_trace_msg(0x68u, 2u, v50, v3, v4, v5, v6, v7, v8, v9, v10, "cm_handle_ho_fail");
LABEL_26:
      wlan_objmgr_vdev_release_ref(v12, 0x4Du, v17, v18, v19, v20, v21, v22, v23, v24, v25);
      v49 = 0;
      goto LABEL_27;
    }
  }
  v49 = 16;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return v49;
}
