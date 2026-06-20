__int64 __fastcall osif_pre_cac_complete_cb(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int v4; // w19
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  int started; // w23
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  _DWORD *v35; // x8
  __int64 *v36[2]; // [xsp+0h] [xbp-10h] BYREF

  v4 = a2;
  v36[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v36[0] = nullptr;
  v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 96);
  if ( v6 )
  {
    v15 = v6;
    started = _osif_vdev_sync_trans_start_wait(
                *(_QWORD *)(**(_QWORD **)(v6 + 608) + 32LL),
                v36,
                (__int64)"osif_pre_cac_complete_cb");
    wlan_objmgr_vdev_release_ref(v15, 0x60u, v17, v18, v19, v20, v21, v22, v23, v24, v25);
    if ( started )
    {
      result = qdf_trace_msg(
                 0x48u,
                 2u,
                 "%s: Failed to complete pre_cac_cb",
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 v32,
                 v33,
                 "osif_pre_cac_complete_cb");
    }
    else
    {
      if ( osif_pre_cac_legacy_ops )
      {
        v35 = *(_DWORD **)(osif_pre_cac_legacy_ops + 8);
        if ( v35 )
        {
          if ( *(v35 - 1) != -345040066 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, _QWORD))v35)(a1, v4, a3);
        }
      }
      result = osif_vdev_sync_trans_stop((__int64)v36[0]);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x48u,
               2u,
               "%s: Invalid vdev for %d",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "osif_pre_cac_complete_cb",
               (unsigned __int8)v4);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
