__int64 __fastcall sme_process_twt_nudge_dialog_event(_QWORD *a1, int *a2)
{
  __int64 v4; // x0
  int v5; // w1
  unsigned int opmode_from_vdev_id; // w21
  __int64 result; // x0
  void (__fastcall *v8)(__int64, int *); // x8
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  void (__fastcall *v18)(__int64, int *); // x8
  __int64 v19; // x0
  const char *v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+8h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a1[2695];
  v5 = *a2;
  v29 = 0;
  opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(v4, v5);
  result = qdf_mutex_acquire((__int64)(a1 + 1597));
  if ( !(_DWORD)result )
  {
    if ( opmode_from_vdev_id )
    {
      if ( opmode_from_vdev_id == 1 )
      {
        v8 = (void (__fastcall *)(__int64, int *))a1[1807];
        if ( v8 )
        {
          v9 = a1[2694];
          if ( *((_DWORD *)v8 - 1) != -1929870948 )
            __break(0x8228u);
          v8(v9, a2);
        }
      }
      else
      {
        v20 = qdf_opmode_str(opmode_from_vdev_id);
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: TWT Nudge is not supported on %s",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "sme_process_twt_nudge_dialog_event",
          v20);
      }
    }
    else if ( (((__int64 (__fastcall *)(_QWORD, int *, _QWORD, __int64, unsigned int *))mlme_twt_is_command_in_progress)(
                 a1[2694],
                 a2 + 1,
                 (unsigned int)a2[3],
                 16,
                 &v29)
             & 1) != 0
           || a2[3] == 255 )
    {
      v18 = (void (__fastcall *)(__int64, int *))a1[1807];
      if ( v18 )
      {
        v19 = a1[2694];
        if ( *((_DWORD *)v18 - 1) != -1929870948 )
          __break(0x8228u);
        v18(v19, a2);
      }
      mlme_set_twt_command_in_progress(a1[2694], a2 + 1, (unsigned int)a2[3], 0);
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Nudge event dropped active_cmd:%d",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "sme_process_twt_nudge_dialog_event",
        v29);
    }
    result = qdf_mutex_release((__int64)(a1 + 1597));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
