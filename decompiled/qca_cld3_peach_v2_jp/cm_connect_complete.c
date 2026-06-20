__int64 __fastcall cm_connect_complete(__int64 *a1, __int64 a2)
{
  unsigned int *v4; // x19
  int state; // w0
  int v6; // w22
  int param; // w8
  __int64 req_by_cm_id_fl; // x0
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x8
  unsigned int *v12; // x9
  int v13; // w8
  __int64 v14; // x22
  int *v15; // x3
  __int64 *v16; // x0
  __int64 v17; // x2
  int v18; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v28; // [xsp+0h] [xbp-10h] BYREF
  __int16 v29; // [xsp+4h] [xbp-Ch]
  __int64 v30; // [xsp+8h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = (unsigned int *)(a2 + 4);
  if ( !cm_get_req_by_cm_id_fl(a1, *(unsigned int *)(a2 + 4), "cm_connect_complete", 3237) )
    goto LABEL_28;
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
        v9 = 144;
        if ( (*(_BYTE *)(a2 + 1) & 4) == 0 )
          v9 = 864;
        v10 = *(_QWORD *)(req_by_cm_id_fl + v9);
        if ( v10 )
        {
          v11 = *(_QWORD *)(v10 + 24);
          if ( *(_QWORD *)(a2 + 80) )
            v12 = (unsigned int *)(a2 + 72);
          else
            v12 = (unsigned int *)(v11 + 1704);
          cm_inform_bcn_probe(
            a1,
            *((_QWORD *)v12 + 1),
            *v12,
            *(unsigned int *)(a2 + 48),
            (unsigned int)*(char *)(v11 + 60),
            *(unsigned int *)(a2 + 4));
        }
      }
    }
    v13 = *(unsigned __int8 *)(a2 + 152);
    v29 = -1;
    v28 = -1;
    if ( v13 == 1 )
    {
      v14 = *(_QWORD *)(a2 + 136);
      if ( !v14 )
        goto LABEL_24;
      cm_store_fils_key(a1, 1, 0, *(unsigned __int8 *)(v14 + 122), v14 + 90, a2 + 8, *(unsigned int *)(a2 + 4));
      cm_store_fils_key(a1, 0, 2, *(unsigned __int8 *)(v14 + 378), v14 + 123, a2 + 8, *(unsigned int *)(a2 + 4));
      cm_set_key(a1, 1, 0, a2 + 8);
      v15 = (int *)(a2 + 8);
      v16 = a1;
      v17 = 2;
    }
    else
    {
      v18 = wlan_crypto_get_param(*a1, 1u);
      if ( v18 < 0 || (v18 & 0x18000) == 0 )
        goto LABEL_24;
      cm_set_key(a1, 1, 0, a2 + 8);
      v15 = &v28;
      v16 = a1;
      v17 = 0;
    }
    cm_set_key(v16, 0, v17, v15);
  }
LABEL_24:
  if ( (*(_BYTE *)(a2 + 1) & 4) == 0 || !*(_DWORD *)(a2 + 52) )
    cm_notify_connect_complete(a1, a2, 1);
  cm_update_scan_mlme_info(a1, a2);
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: vdev %d cm_id 0x%x: ",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "cm_connect_complete",
    *(unsigned __int8 *)(*a1 + 104),
    *(unsigned int *)(a2 + 4));
  cm_remove_cmd(a1, v4);
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return 0;
}
