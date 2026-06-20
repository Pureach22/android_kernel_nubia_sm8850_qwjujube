__int64 __fastcall hdd_get_max_tx_bitrate(__int64 a1)
{
  __int64 *v2; // x26
  int v3; // w21
  __int64 vdev_by_user; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x24
  __int64 cmpt_obj; // x0
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w23
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 result; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x9
  __int64 v43; // x4
  __int64 v44; // x5
  __int64 v45; // x6
  __int64 v46; // x7
  _QWORD v47[34]; // [xsp+0h] [xbp-110h] BYREF

  v47[33] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  memset(v47, 0, 0x108u);
  qdf_mem_set(v47, 0x108u, 0);
  v3 = *(_DWORD *)(a1 + 2584);
  BYTE5(v47[5]) = *(_BYTE *)(a1 + 2416);
  if ( (v3 & 1) == 0 )
  {
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 0x51u, (__int64)"hdd_get_max_tx_bitrate");
    if ( vdev_by_user )
    {
      v13 = vdev_by_user;
      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(vdev_by_user, v5, v6, v7, v8, v9, v10, v11, v12);
      if ( cmpt_obj )
        v24 = *(unsigned __int8 *)(cmpt_obj + 23);
      else
        v24 = 0;
      _hdd_objmgr_put_vdev_by_user(
        v13,
        0x51u,
        (__int64)"hdd_get_max_tx_bitrate",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23);
      if ( v24 < 2 )
        goto LABEL_13;
    }
    else
    {
      v24 = *(unsigned __int8 *)(a1 + 2536);
      if ( v24 < 2 )
        goto LABEL_13;
    }
    if ( (policy_mgr_is_current_hwmode_dbs(*v2) & 1) != 0 && !policy_mgr_is_hw_dbs_2x2_capable(*v2) )
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Hw mode is DBS, Reduce tx nss(%d) to 1",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "hdd_check_and_update_nss",
        v24);
  }
LABEL_13:
  result = hdd_report_max_rate(a1);
  if ( (result & 1) != 0 )
  {
    v42 = *(_QWORD *)((char *)&v47[7] + 6);
    v43 = LOWORD(v47[7]);
    v44 = BYTE4(v47[7]);
    v45 = BYTE5(v47[7]);
    v46 = BYTE6(v47[7]);
    *(_QWORD *)(a1 + 1616) = v47[7];
    *(_QWORD *)(a1 + 1622) = v42;
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: Reporting max tx rate flags %d mcs %d nss %d bw %d",
               v34,
               v35,
               v36,
               v37,
               v38,
               v39,
               v40,
               v41,
               "hdd_get_max_tx_bitrate",
               v43,
               v44,
               v45,
               v46);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
