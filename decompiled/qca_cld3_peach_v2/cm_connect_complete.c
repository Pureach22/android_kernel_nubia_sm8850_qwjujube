__int64 __fastcall cm_connect_complete(__int64 *a1, __int64 a2)
{
  unsigned int *v4; // x20
  int state; // w0
  int v6; // w22
  int param; // w8
  __int64 req_by_cm_id_fl; // x0
  __int64 v9; // x23
  __int64 v10; // x8
  __int64 v11; // x24
  __int64 v12; // x8
  unsigned int *v13; // x9
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _QWORD *v22; // x23
  unsigned int v23; // w22
  __int64 v24; // x26
  _QWORD *v25; // x1
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x28
  int v35; // w8
  __int64 v38; // x6
  __int64 v39; // x7
  int v40; // w9
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x0
  int v50; // w8
  __int64 v51; // x22
  _QWORD *v52; // x3
  __int64 *v53; // x0
  __int64 v54; // x2
  int v55; // w0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v65; // [xsp+0h] [xbp-30h]
  __int64 v66; // [xsp+8h] [xbp-28h]
  _QWORD *v67; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v68[2]; // [xsp+20h] [xbp-10h] BYREF

  v68[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = (unsigned int *)(a2 + 4);
  if ( !cm_get_req_by_cm_id_fl(a1, *(unsigned int *)(a2 + 4), "cm_connect_complete", 3237) )
    goto LABEL_47;
  state = cm_get_state(a1);
  if ( *(_DWORD *)(a2 + 52) )
  {
    if ( (*(_BYTE *)(a2 + 152) & 1) == 0 )
    {
      v6 = state;
      param = wlan_crypto_get_param(*a1, 7u);
      state = v6;
      if ( (param & 0x3C0000) != 0 )
        *(_BYTE *)(a2 + 152) = 1;
    }
  }
  if ( !*(_DWORD *)(a2 + 52) && state == 2 )
  {
    if ( (cm_is_vdev_connected(*a1) & 1) != 0 )
    {
      req_by_cm_id_fl = cm_get_req_by_cm_id_fl(a1, *v4, "cm_update_scan_db_on_connect_success", 2949);
      if ( req_by_cm_id_fl )
      {
        v9 = req_by_cm_id_fl;
        v10 = 144;
        if ( (*(_BYTE *)(a2 + 1) & 4) == 0 )
          v10 = 1040;
        v11 = *(_QWORD *)(req_by_cm_id_fl + v10);
        if ( v11 )
        {
          v12 = *(_QWORD *)(v11 + 24);
          v13 = (unsigned int *)(*(_QWORD *)(a2 + 80) ? a2 + 72 : v12 + 1888);
          cm_inform_bcn_probe(
            a1,
            *((_QWORD *)v13 + 1),
            *v13,
            *(unsigned int *)(a2 + 48),
            (unsigned int)*(char *)(v12 + 60),
            *(unsigned int *)(a2 + 4));
          if ( (*(_BYTE *)(a2 + 1) & 4) == 0
            && (wlan_vdev_mlme_is_mlo_vdev(*a1, v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0 )
          {
            v22 = *(_QWORD **)(v9 + 1024);
            v23 = *v4;
            v24 = *(_QWORD *)(v11 + 24);
            v68[0] = 0;
            v67 = nullptr;
            qdf_list_peek_front(v22, v68);
            v25 = (_QWORD *)v68[0];
            if ( v68[0] )
            {
              do
              {
                qdf_list_peek_next(v22, v25, &v67);
                v34 = *(_QWORD *)(v68[0] + 24LL);
                v35 = v34 + 1;
                if ( (*(_DWORD *)(v34 + 1) != *(_DWORD *)(v24 + 1)
                   || *(unsigned __int16 *)(v34 + 5) != *(unsigned __int16 *)(v24 + 5))
                  && *(_DWORD *)(v34 + 1912) == *(_DWORD *)(v24 + 1912)
                  && *(unsigned __int16 *)(v34 + 1916) == *(unsigned __int16 *)(v24 + 1916) )
                {
                  if ( v34 == -1 )
                  {
                    v38 = 0;
                    v39 = 0;
                    v40 = 0;
                  }
                  else
                  {
                    v38 = *(unsigned __int8 *)(v34 + 1);
                    v39 = *(unsigned __int8 *)(v34 + 2);
                    v35 = *(unsigned __int8 *)(v34 + 3);
                    v40 = *(unsigned __int8 *)(v34 + 6);
                  }
                  LODWORD(v66) = v40;
                  LODWORD(v65) = v35;
                  qdf_trace_msg(
                    0x68u,
                    8u,
                    "%s: vdev %d cm_id 0x%x: Inform Partner bssid: %02x:%02x:%02x:**:**:%02x to kernel",
                    v26,
                    v27,
                    v28,
                    v29,
                    v30,
                    v31,
                    v32,
                    v33,
                    "cm_update_partner_link_scan_db",
                    *(unsigned __int8 *)(*a1 + 168),
                    v23,
                    v38,
                    v39,
                    v65,
                    v66);
                  v49 = *(_QWORD *)(*a1 + 216);
                  if ( v49 )
                    util_scan_entry_renew_timestamp(v49, v34);
                  else
                    qdf_trace_msg(
                      0x68u,
                      2u,
                      "%s: vdev %d cm_id 0x%x: Failed to find pdev",
                      v41,
                      v42,
                      v43,
                      v44,
                      v45,
                      v46,
                      v47,
                      v48,
                      "cm_inform_bcn_probe_handler",
                      *(unsigned __int8 *)(*a1 + 168),
                      v23);
                }
                v25 = v67;
                v67 = nullptr;
                v68[0] = v25;
              }
              while ( v25 );
            }
          }
        }
      }
    }
    v50 = *(unsigned __int8 *)(a2 + 152);
    WORD2(v68[0]) = -1;
    LODWORD(v68[0]) = -1;
    if ( v50 == 1 )
    {
      v51 = *(_QWORD *)(a2 + 136);
      if ( !v51 )
        goto LABEL_43;
      cm_store_fils_key(a1, 1, 0, *(unsigned __int8 *)(v51 + 122), v51 + 90, a2 + 8, *(unsigned int *)(a2 + 4));
      cm_store_fils_key(a1, 0, 2, *(unsigned __int8 *)(v51 + 378), v51 + 123, a2 + 8, *(unsigned int *)(a2 + 4));
      cm_set_key(a1, 1, 0, a2 + 8);
      v52 = (_QWORD *)(a2 + 8);
      v53 = a1;
      v54 = 2;
    }
    else
    {
      v55 = wlan_crypto_get_param(*a1, 1u);
      if ( v55 < 0 || (v55 & 0x18000) == 0 )
        goto LABEL_43;
      cm_set_key(a1, 1, 0, a2 + 8);
      v52 = v68;
      v53 = a1;
      v54 = 0;
    }
    cm_set_key(v53, 0, v54, v52);
  }
LABEL_43:
  if ( (*(_BYTE *)(a2 + 1) & 4) == 0 || !*(_DWORD *)(a2 + 52) )
    cm_notify_connect_complete(a1, a2, 1);
  cm_update_scan_mlme_info(a1, a2);
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: vdev %d cm_id 0x%x: ",
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    "cm_connect_complete",
    *(unsigned __int8 *)(*a1 + 168),
    *(unsigned int *)(a2 + 4));
  cm_remove_cmd(a1, v4);
  mlo_mgr_link_switch_connect_done_notify(*a1, a2);
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return 0;
}
