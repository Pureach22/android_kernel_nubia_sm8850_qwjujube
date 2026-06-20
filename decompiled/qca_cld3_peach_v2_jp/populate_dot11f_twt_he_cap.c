__int64 __fastcall populate_dot11f_twt_he_cap(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  char v7; // w8
  __int64 v8; // x0
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  int v18; // w8
  __int64 v19; // x0
  __int64 v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x1
  __int64 v30; // x0
  __int64 v31; // x8
  _BYTE v32[4]; // [xsp+0h] [xbp-20h] BYREF
  _BYTE v33[4]; // [xsp+4h] [xbp-1Ch] BYREF
  _BYTE v34[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v35[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v36[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v37[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v38; // [xsp+18h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 21552);
  v35[0] = 0;
  v34[0] = 0;
  v33[0] = 0;
  v32[0] = 0;
  wlan_twt_get_bcast_requestor_cfg(v6, v34);
  v7 = 0;
  if ( v34[0] == 1 )
    v7 = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3544LL) ^ 1;
  v8 = *(_QWORD *)(a1 + 21552);
  v34[0] = v7 & 1;
  result = wlan_twt_get_bcast_responder_cfg(v8, v33);
  *(_QWORD *)(a3 + 1) &= 0xFFFFFFFFFFEFFFF9LL;
  v18 = *(_DWORD *)(a2 + 7036);
  if ( v18 > 1 )
  {
    if ( v18 == 3 )
    {
      result = wlan_vdev_p2p_is_wfd_r2_mode(
                 *(_QWORD *)(a1 + 21552),
                 *(unsigned __int8 *)(a2 + 10),
                 v10,
                 v11,
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17);
      if ( (result & 1) == 0 )
        goto LABEL_23;
      goto LABEL_15;
    }
    if ( v18 != 2 )
      goto LABEL_23;
    result = wlan_vdev_p2p_is_wfd_r2_mode(
               *(_QWORD *)(a1 + 21552),
               *(unsigned __int8 *)(a2 + 10),
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17);
    if ( (result & 1) == 0 )
      goto LABEL_23;
  }
  else if ( v18 )
  {
    if ( v18 != 1 )
      goto LABEL_23;
LABEL_15:
    wlan_twt_get_responder_cfg(*(_QWORD *)(a1 + 21552), v32);
    if ( (wlan_twt_check_responder_bit(
            *(_QWORD *)(a1 + 21552),
            *(unsigned __int8 *)(a2 + 10),
            *(unsigned int *)(a2 + 7036),
            v32[0])
        & 1) != 0 )
    {
      v29 = *(unsigned __int8 *)(a2 + 10);
      v30 = *(_QWORD *)(a1 + 21552);
      v37[0] = 0;
      wlan_twt_cfg_get_res_flag(v30, v29, v37);
      v31 = 4;
      if ( !v37[0] )
        v31 = 0;
    }
    else
    {
      v31 = 0;
    }
    *(_QWORD *)(a3 + 1) = *(_QWORD *)(a3 + 1) & 0xFFFFFFFFFFEFFFFBLL | ((unsigned __int64)v33[0] << 20) | v31;
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: vdev:%d bcast_responder:%d twt_responder:%d",
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               "populate_dot11f_twt_he_cap",
               *(unsigned __int8 *)(a2 + 10));
    goto LABEL_23;
  }
  result = wlan_twt_get_requestor_cfg(*(_QWORD *)(a1 + 21552), v35);
  if ( v35[0] == 1 )
  {
    v19 = *(_QWORD *)(a1 + 21552);
    v36[0] = 0;
    result = wlan_twt_cfg_get_req_flag(v19, v36);
    v20 = 2;
    if ( !v36[0] )
      v20 = 0;
  }
  else
  {
    v20 = 0;
  }
  *(_QWORD *)(a3 + 1) = *(_QWORD *)(a3 + 1) & 0xFFFFFFFFFFEFFFFDLL | v20 | ((unsigned __int64)v34[0] << 20);
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
