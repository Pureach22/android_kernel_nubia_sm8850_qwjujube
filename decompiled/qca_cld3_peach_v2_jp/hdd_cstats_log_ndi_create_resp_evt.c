__int64 __fastcall hdd_cstats_log_ndi_create_resp_evt(__int64 a1, _DWORD *a2)
{
  __int64 vdev_by_user; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  __int64 comp_private_obj; // x0
  int v14; // w9
  char v15; // w10
  __int64 v16; // x20
  int v17; // w8
  unsigned __int64 v18; // x8
  __int64 v19; // x8
  unsigned int *v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 result; // x0
  const char *v30; // x2
  int v31; // [xsp+Ch] [xbp-24h] BYREF
  char v32; // [xsp+10h] [xbp-20h]
  char v33; // [xsp+11h] [xbp-1Fh]
  unsigned __int64 time_of_the_day_us; // [xsp+12h] [xbp-1Eh]
  unsigned __int64 StatusReg; // [xsp+1Ah] [xbp-16h]
  __int16 v36; // [xsp+22h] [xbp-Eh]
  char v37; // [xsp+24h] [xbp-Ch]
  char v38; // [xsp+25h] [xbp-Bh]
  __int64 v39; // [xsp+28h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 0x52u, (__int64)"hdd_cstats_log_ndi_create_resp_evt");
  if ( !vdev_by_user )
  {
    v30 = "%s: vdev is NULL";
LABEL_12:
    result = qdf_trace_msg(0x33u, 2u, v30, v4, v5, v6, v7, v8, v9, v10, v11, "hdd_cstats_log_ndi_create_resp_evt");
    goto LABEL_13;
  }
  v12 = vdev_by_user;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(vdev_by_user, 0xFu);
  if ( !comp_private_obj )
  {
    v30 = "%s: priv_obj is null";
    goto LABEL_12;
  }
  v14 = *(_DWORD *)(v12 + 16);
  v15 = *(_BYTE *)(v12 + 104);
  v16 = comp_private_obj;
  v31 = 1441826;
  v32 = v14;
  v33 = v15;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v17 = a2[1];
  v37 = *a2;
  v38 = v17;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v18 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v18 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v18 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v16);
    v19 = *(_QWORD *)(v16 + 8);
  }
  else
  {
    raw_spin_lock_bh(v16);
    v19 = *(_QWORD *)(v16 + 8) | 1LL;
    *(_QWORD *)(v16 + 8) = v19;
  }
  v36 = *(_WORD *)(v16 + 24);
  if ( (v19 & 1) != 0 )
  {
    *(_QWORD *)(v16 + 8) = v19 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v16);
  }
  else
  {
    raw_spin_unlock(v16);
  }
  _hdd_objmgr_put_vdev_by_user(
    v12,
    0x52u,
    (__int64)"hdd_cstats_log_ndi_create_resp_evt",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28);
  result = wlan_cp_stats_cstats_write_to_buff(0, &v31, 26);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
