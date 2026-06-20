__int64 __fastcall cm_update_dlm_mlo_score(__int64 a1, _QWORD *a2, _QWORD *a3, _BYTE *a4)
{
  __int64 result; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  _QWORD *v16; // x1
  _QWORD *v17; // x23
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x8
  int v27; // w9
  __int64 v28; // x8
  __int64 v29; // x3
  __int64 v30; // x4
  __int64 v31; // x5
  __int64 v32; // x6
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x24
  __int64 v42; // x0
  __int64 v43; // x0
  unsigned __int8 *v44; // x8
  __int64 v45; // x4
  __int64 v46; // x5
  __int64 v47; // x6
  __int64 v48; // x7
  __int64 v49; // [xsp+0h] [xbp-30h]
  __int64 v50; // [xsp+8h] [xbp-28h]
  _QWORD *v51; // [xsp+18h] [xbp-18h] BYREF
  _QWORD *v52[2]; // [xsp+20h] [xbp-10h] BYREF

  v52[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v52[0] = nullptr;
  v51 = nullptr;
  result = qdf_list_peek_next(a2, a3, v52);
  if ( (_DWORD)result )
  {
    result = qdf_trace_msg(
               0x68u,
               2u,
               "%s: failed to peer front of scan list",
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               "cm_update_dlm_mlo_score");
    goto LABEL_3;
  }
  v16 = v52[0];
  if ( !v52[0] )
    goto LABEL_3;
  while ( 1 )
  {
    qdf_list_peek_next(a2, v16, &v51);
    v17 = v52[0];
    result = wlan_denylist_action_on_bssid(a1, v52[0][3]);
    v26 = v17[3];
    if ( !*(_QWORD *)(v26 + 1824) )
      break;
    v27 = 2 * *(unsigned __int8 *)(v26 + 1918) + 2;
    if ( (_DWORD)result == 3 )
      goto LABEL_11;
LABEL_15:
    if ( (unsigned int)(result - 1) <= 1 )
    {
      if ( (unsigned int)qdf_list_remove_node((__int64)a2, v52[0]) )
        goto LABEL_25;
      *a4 = 1;
      v41 = v17[3];
      if ( v41 )
      {
        v42 = *(_QWORD *)(v41 + 1320);
        if ( v42 )
          _qdf_mem_free(v42);
        v43 = *(_QWORD *)(v41 + 1896);
        if ( v43 )
          _qdf_mem_free(v43);
        _qdf_mem_free(v41);
      }
      result = _qdf_mem_free((__int64)v17);
    }
LABEL_8:
    v16 = v51;
    v51 = nullptr;
    v52[0] = v16;
    if ( !v16 )
      goto LABEL_3;
  }
  v27 = 1;
  if ( (_DWORD)result != 3 )
    goto LABEL_15;
LABEL_11:
  if ( *(_DWORD *)(v26 + 1260) == v27 )
    goto LABEL_8;
  *(_DWORD *)(v26 + 1260) = v27;
  v28 = v17[3];
  if ( v28 == -1 )
  {
    v31 = 0;
    v29 = 0;
    v30 = 0;
    v32 = 0;
  }
  else
  {
    v29 = *(unsigned __int8 *)(v28 + 1);
    v30 = *(unsigned __int8 *)(v28 + 2);
    v31 = *(unsigned __int8 *)(v28 + 3);
    v32 = *(unsigned __int8 *)(v28 + 6);
  }
  LODWORD(v49) = *(char *)(v28 + 60);
  LODWORD(v50) = *(_DWORD *)(v28 + 1260);
  qdf_trace_msg(
    0x68u,
    8u,
    "Candidate(%02x:%02x:%02x:**:**:%02x freq %d): rssi %d, is in Avoidlist, give min score %d",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v29,
    v30,
    v31,
    v32,
    *(unsigned int *)(v28 + 1192),
    v49,
    v50);
  if ( !(unsigned int)qdf_list_remove_node((__int64)a2, v52[0]) )
  {
    result = qdf_list_insert_back(a2, v17);
    *a4 = 1;
    goto LABEL_8;
  }
LABEL_25:
  v44 = (unsigned __int8 *)v17[3];
  if ( v44 == (unsigned __int8 *)-1LL )
  {
    v47 = 0;
    v45 = 0;
    v46 = 0;
    v48 = 0;
  }
  else
  {
    v45 = v44[1];
    v46 = v44[2];
    v47 = v44[3];
    v48 = v44[6];
  }
  result = qdf_trace_msg(
             0x68u,
             2u,
             "%s: failed to remove node for BSS %02x:%02x:%02x:**:**:%02x from scan list",
             v33,
             v34,
             v35,
             v36,
             v37,
             v38,
             v39,
             v40,
             "cm_update_dlm_mlo_score",
             v45,
             v46,
             v47,
             v48);
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
