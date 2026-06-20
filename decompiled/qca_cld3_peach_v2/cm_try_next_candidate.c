__int64 __fastcall cm_try_next_candidate(__int64 *a1, unsigned __int8 *a2)
{
  __int64 v4; // x1
  __int64 req_by_cm_id_fl; // x0
  __int64 v6; // x21
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int8 *v24; // x8
  __int64 v25; // x5
  __int64 v26; // x6
  __int64 v27; // x7
  int v28; // w8
  int v29; // w8
  __int64 v30; // x9
  _BYTE v31[4]; // [xsp+14h] [xbp-3Ch] BYREF
  _DWORD v32[2]; // [xsp+18h] [xbp-38h] BYREF
  __int64 v33; // [xsp+20h] [xbp-30h]
  __int64 v34; // [xsp+28h] [xbp-28h]
  __int64 v35; // [xsp+30h] [xbp-20h]
  __int64 v36; // [xsp+38h] [xbp-18h]
  __int64 v37; // [xsp+40h] [xbp-10h]
  __int64 v38; // [xsp+48h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *((unsigned int *)a2 + 1);
  v31[0] = 0;
  req_by_cm_id_fl = cm_get_req_by_cm_id_fl(a1, v4, "cm_try_next_candidate", 2409);
  if ( !req_by_cm_id_fl )
  {
    result = 16;
    goto LABEL_5;
  }
  v6 = req_by_cm_id_fl;
  if ( (unsigned int)cm_get_valid_candidate(a1, req_by_cm_id_fl, a2, v31) )
    goto LABEL_3;
  if ( (v31[0] & 1) == 0 )
  {
    cm_store_first_candidate_rsp(a1, *((unsigned int *)a2 + 1), a2);
    mlme_cm_osif_failed_candidate_ind(*a1, a2);
    v24 = *(unsigned __int8 **)(*(_QWORD *)(v6 + 1040) + 24LL);
    if ( v24 == (unsigned __int8 *)-1LL )
    {
      v27 = 0;
      v25 = 0;
      v26 = 0;
      v28 = 0;
    }
    else
    {
      v25 = v24[1];
      v26 = v24[2];
      v27 = v24[3];
      v28 = v24[6];
    }
    qdf_trace_msg(
      0x68u,
      8u,
      "vdev %d cm_id 0x%x: Try with next candidate %02x:%02x:%02x:**:**:%02x",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      *a2,
      *((unsigned int *)a2 + 1),
      v25,
      v26,
      v27,
      v28);
  }
  v29 = *((_DWORD *)a2 + 1);
  v33 = 0;
  v34 = 0;
  v32[0] = 23;
  v32[1] = v29;
  v30 = *a1;
  v35 = *((unsigned int *)a1 + 49);
  v36 = v30;
  v37 = 0;
  wlan_serialization_update_timer((__int64)v32, v7, v8, v9, v10, v11, v12, v13, v14);
  result = cm_send_bss_select_ind(a1, v6 + 24);
  if ( (_DWORD)result )
  {
    if ( (_DWORD)result == 11 && !(unsigned int)cm_update_vdev_mlme_macaddr(a1, v6 + 24) )
    {
      cm_create_bss_peer(a1, v6 + 24);
      result = 0;
      goto LABEL_5;
    }
LABEL_3:
    result = wlan_sm_dispatch(a1[9], 0xCu, 0x150u, (__int64)a2, v7, v8, v9, v10, v11, v12, v13, v14);
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
