__int64 __fastcall tgt_vdev_mgr_set_max_channel_switch_time(__int64 a1, __int64 a2, int a3)
{
  __int64 result; // x0
  __int64 v7; // x22
  int v8; // w8
  unsigned int *v9; // x8
  __int64 v10; // x25
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x27
  __int64 cmpt_obj; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x28
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x5
  unsigned int v40; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v41; // [xsp+8h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = qdf_mc_timer_get_system_time();
  v40 = 0;
  if ( a3 )
  {
    v7 = result;
    v8 = 0;
    do
    {
      v10 = v8;
      v11 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              a1,
              *(unsigned int *)(a2 + 4LL * v8),
              49);
      if ( v11 )
      {
        v20 = v11;
        cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v11);
        if ( cmpt_obj )
        {
          v30 = cmpt_obj;
          if ( (unsigned int)wlan_util_vdev_mgr_compute_max_channel_switch_time(v20, &v40) )
          {
            qdf_trace_msg(
              0x68u,
              2u,
              "%s: Failed to get the max channel switch time value",
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              "tgt_vdev_mgr_set_max_channel_switch_time");
          }
          else
          {
            v9 = (unsigned int *)v40;
            *(_QWORD *)(v30 + 264) = v7;
            *(_DWORD *)(v30 + 256) = (_DWORD)v9;
          }
        }
        else
        {
          if ( a1 )
            v39 = *(unsigned __int8 *)(a1 + 48);
          else
            v39 = 255;
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: VDEV_%d: PSOC_%d VDEV_MLME is NULL",
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            "tgt_vdev_mgr_set_max_channel_switch_time",
            *(unsigned int *)(a2 + 4 * v10),
            v39);
        }
        result = wlan_objmgr_vdev_release_ref(v20, 0x31u, v9, v31, v32, v33, v34, v35, v36, v37, v38);
      }
      else
      {
        result = qdf_trace_msg(
                   0x68u,
                   2u,
                   "%s: VDEV is NULL",
                   v12,
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   "tgt_vdev_mgr_set_max_channel_switch_time");
      }
      v8 = v10 + 1;
    }
    while ( a3 != (_DWORD)v10 + 1 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
