__int64 __fastcall sme_process_twt_add_dialog_event(_QWORD *a1, int *a2)
{
  unsigned int v4; // w21
  __int64 v5; // x0
  int v6; // w1
  unsigned int opmode_from_vdev_id; // w22
  __int64 result; // x0
  _DWORD *v9; // x8
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _DWORD *v19; // x8
  __int64 v20; // x0
  const char *v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a2[4];
  v5 = a1[2695];
  v6 = *a2;
  v30 = 0;
  opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(v5, v6);
  result = qdf_mutex_acquire((__int64)(a1 + 1597));
  if ( !(_DWORD)result )
  {
    if ( opmode_from_vdev_id )
    {
      if ( opmode_from_vdev_id == 1 )
      {
        v9 = (_DWORD *)a1[1804];
        if ( v9 )
        {
          v10 = a1[2694];
          if ( *(v9 - 1) != -214395026 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, int *, _QWORD))v9)(v10, a2, 0);
        }
      }
      else
      {
        v21 = qdf_opmode_str(opmode_from_vdev_id);
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: TWT Setup is not supported on %s",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "sme_process_twt_add_dialog_event",
          v21);
      }
    }
    else if ( (((__int64 (__fastcall *)(_QWORD, int *, _QWORD, __int64, unsigned int *))mlme_twt_is_command_in_progress)(
                 a1[2694],
                 a2 + 1,
                 (unsigned int)a2[3],
                 1,
                 &v30)
             & 1) != 0 )
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: setup_done:%d status:%d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "sme_process_twt_add_dialog_event",
        0,
        v4);
      v19 = (_DWORD *)a1[1804];
      if ( v19 )
      {
        v20 = a1[2694];
        if ( *(v19 - 1) != -214395026 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, int *, _QWORD))v19)(v20, a2, 0);
      }
      mlme_set_twt_command_in_progress(a1[2694], a2 + 1, (unsigned int)a2[3], 0);
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Drop TWT add dialog event for dialog_id:%d status:%d active_cmd:%d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "sme_process_twt_add_dialog_event",
        (unsigned int)a2[3],
        v4,
        v30);
    }
    result = qdf_mutex_release((__int64)(a1 + 1597));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
