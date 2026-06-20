__int64 __fastcall cm_update_vdev_mlme_macaddr(__int64 *a1, unsigned int *a2)
{
  __int64 v2; // x20
  __int64 v3; // x8
  unsigned int v4; // w19
  _DWORD *v6; // x22
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x1
  __int64 v17; // x8
  __int64 v18; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x6
  __int64 v38; // x7
  int v39; // w8
  int v40; // w9
  unsigned __int64 v41; // x8
  __int64 v42; // x8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x5
  __int64 v52; // x6
  __int64 v53; // x7
  int v54; // w8
  int v55; // w9
  __int64 v56; // x6
  __int64 v57; // x7
  int v58; // w8
  int v59; // w9
  __int64 result; // x0
  _BYTE v61[20]; // [xsp+14h] [xbp-1Ch] BYREF
  __int64 v62; // [xsp+28h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  if ( *(_DWORD *)(*a1 + 16) )
    goto LABEL_41;
  v3 = *(_QWORD *)(v2 + 216);
  v4 = *(unsigned __int8 *)(v2 + 168);
  v6 = (_DWORD *)(v2 + 80);
  if ( v3 )
    v7 = *(_QWORD *)(v3 + 80);
  else
    v7 = 0;
  v61[0] = 0;
  wlan_psoc_mlme_get_11be_capab(v7, v61);
  if ( v61[0] == 1 )
  {
    if ( *v6 | *(unsigned __int16 *)(v2 + 84) )
    {
      v16 = *(_QWORD *)(*((_QWORD *)a2 + 127) + 24LL);
      if ( (unsigned int)(*(_DWORD *)(v16 + 52) - 31) <= 9 && *(_QWORD *)(v16 + 1808) && *(_QWORD *)(v16 + 1824) )
      {
        v17 = *(_QWORD *)(v2 + 216);
        v18 = v17 ? *(_QWORD *)(v17 + 80) : 0LL;
        if ( (wlan_cm_is_eht_allowed_for_current_security(v18, v16, 1) & 1) != 0 )
        {
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v2 + 1344);
          }
          else
          {
            raw_spin_lock_bh(v2 + 1344);
            *(_QWORD *)(v2 + 1352) |= 1uLL;
          }
          qdf_mem_copy((void *)(v2 + 74), (const void *)(v2 + 86), 6u);
          v20 = *(_QWORD *)(v2 + 1352);
          if ( (v20 & 1) != 0 )
          {
            *(_QWORD *)(v2 + 1352) = v20 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v2 + 1344);
          }
          else
          {
            raw_spin_unlock(v2 + 1344);
          }
          wlan_vdev_mlme_set_mlo_vdev(v2, v21, v22, v23, v24, v25, v26, v27, v28);
          if ( v2 == -80 )
          {
            v39 = 0;
            v37 = 0;
            v38 = 0;
            v40 = 0;
          }
          else
          {
            v37 = *(unsigned __int8 *)(v2 + 80);
            v38 = *(unsigned __int8 *)(v2 + 81);
            v39 = *(unsigned __int8 *)(v2 + 82);
            v40 = *(unsigned __int8 *)(v2 + 85);
          }
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: vdev %d cm_id 0x%x: setting ML link address %02x:%02x:%02x:**:**:%02x",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "cm_update_vdev_mlme_macaddr",
            v4,
            *a2,
            v37,
            v38,
            v39,
            v40);
          goto LABEL_41;
        }
      }
    }
  }
  if ( (*(_BYTE *)(v2 + 60) & 2) == 0 )
  {
    if ( !(*v6 | *(unsigned __int16 *)(v2 + 84)) )
    {
LABEL_40:
      wlan_vdev_mlme_clear_mlo_vdev(v2, v8, v9, v10, v11, v12, v13, v14, v15);
LABEL_41:
      result = 0;
      goto LABEL_42;
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v41 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v41 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v41 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v2 + 1344);
    }
    else
    {
      raw_spin_lock_bh(v2 + 1344);
      *(_QWORD *)(v2 + 1352) |= 1uLL;
    }
    qdf_mem_copy((void *)(v2 + 74), (const void *)(v2 + 80), 6u);
    v42 = *(_QWORD *)(v2 + 1352);
    if ( (v42 & 1) != 0 )
    {
      *(_QWORD *)(v2 + 1352) = v42 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v2 + 1344);
      v51 = *a2;
      if ( v2 != -80 )
        goto LABEL_30;
    }
    else
    {
      raw_spin_unlock(v2 + 1344);
      v51 = *a2;
      if ( v2 != -80 )
      {
LABEL_30:
        v52 = *(unsigned __int8 *)(v2 + 80);
        v53 = *(unsigned __int8 *)(v2 + 81);
        v54 = *(unsigned __int8 *)(v2 + 82);
        v55 = *(unsigned __int8 *)(v2 + 85);
LABEL_39:
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: vdev %d cm_id 0x%x: setting non-ML address %02x:%02x:%02x:**:**:%02x",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "cm_update_vdev_mlme_macaddr",
          v4,
          v51,
          v52,
          v53,
          v54,
          v55);
        goto LABEL_40;
      }
    }
    v54 = 0;
    v52 = 0;
    v53 = 0;
    v55 = 0;
    goto LABEL_39;
  }
  if ( v2 == -80 )
  {
    v58 = 0;
    v56 = 0;
    v57 = 0;
    v59 = 0;
  }
  else
  {
    v56 = *(unsigned __int8 *)(v2 + 80);
    v57 = *(unsigned __int8 *)(v2 + 81);
    v58 = *(unsigned __int8 *)(v2 + 82);
    v59 = *(unsigned __int8 *)(v2 + 85);
  }
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: vdev %d cm_id 0x%x: MLIE is not present for partner%02x:%02x:%02x:**:**:%02x",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "cm_update_vdev_mlme_macaddr",
    v4,
    *a2,
    v56,
    v57,
    v58,
    v59);
  result = 4;
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
