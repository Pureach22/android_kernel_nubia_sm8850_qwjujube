__int64 __fastcall sme_process_twt_del_dialog_event(_QWORD *a1, unsigned int *a2)
{
  unsigned int opmode_from_vdev_id; // w21
  __int64 result; // x0
  void (__fastcall *v6)(__int64, unsigned int *); // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x2
  __int64 v11; // x0
  __int64 v12; // x2
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  void (__fastcall *v21)(__int64, unsigned int *); // x8
  __int64 v22; // x0
  const char *v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x0
  __int64 v33; // x2
  int v35; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(a1[2695], *a2);
  result = qdf_mutex_acquire((__int64)(a1 + 1597));
  if ( !(_DWORD)result )
  {
    if ( opmode_from_vdev_id )
    {
      if ( opmode_from_vdev_id == 1 )
      {
        v6 = (void (__fastcall *)(__int64, unsigned int *))a1[1805];
        if ( v6 )
        {
          v7 = a1[2694];
          if ( *((_DWORD *)v6 - 1) != -441533057 )
            __break(0x8228u);
          v6(v7, a2);
        }
        if ( a2[4] != 7 )
        {
          v8 = a1[2694];
          v9 = a2[3];
          if ( a2[1] == -1 && *((__int16 *)a2 + 4) == -1 )
            mlme_sap_set_twt_all_peers_cmd_in_progress(v8, *a2, v9, 0);
          else
            mlme_set_twt_command_in_progress(v8, a2 + 1, v9, 0);
          v32 = a1[2694];
          v33 = a2[3];
          if ( a2[1] == -1 && *((__int16 *)a2 + 4) == -1 )
            mlme_init_all_peers_twt_context(v32, *a2, v33);
          else
            ((void (__fastcall *)(__int64, unsigned int *, __int64))mlme_init_twt_context)(v32, a2 + 1, v33);
        }
      }
      else
      {
        v23 = qdf_opmode_str(opmode_from_vdev_id);
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: TWT Teardown is not supported on %s",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "sme_process_twt_del_dialog_event",
          v23);
      }
    }
    else
    {
      v11 = a1[2694];
      v12 = a2[3];
      v35 = 0;
      if ( (((__int64 (__fastcall *)(__int64, unsigned int *, __int64, __int64, int *))mlme_twt_is_command_in_progress)(
              v11,
              a2 + 1,
              v12,
              2,
              &v35)
          & 1) != 0
        || a2[3] == 255
        || a2[4] - 7 < 3 )
      {
        if ( (mlme_get_user_ps(a1[2694], *a2) & 1) == 0 && !a2[4] )
          a2[4] = 12;
        v21 = (void (__fastcall *)(__int64, unsigned int *))a1[1805];
        if ( v21 )
        {
          v22 = a1[2694];
          if ( *((_DWORD *)v21 - 1) != -441533057 )
            __break(0x8228u);
          v21(v22, a2);
        }
        if ( (a2[4] & 0xFFFFFFFE) == 8 )
          mlme_twt_set_wait_for_notify(a1[2694], *a2, 1);
        mlme_set_twt_command_in_progress(a1[2694], a2 + 1, a2[3], 0);
        if ( a2[4] - 1 >= 6 )
          ((void (__fastcall *)(_QWORD, unsigned int *, _QWORD))mlme_init_twt_context)(a1[2694], a2 + 1, a2[3]);
      }
      else
      {
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Drop TWT Del dialog event for dialog_id:%d status:%d active_cmd:%d",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "sme_process_sta_twt_del_dialog_event");
      }
    }
    result = qdf_mutex_release((__int64)(a1 + 1597));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
