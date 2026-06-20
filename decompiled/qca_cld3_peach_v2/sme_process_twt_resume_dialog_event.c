__int64 __fastcall sme_process_twt_resume_dialog_event(_QWORD *a1, _DWORD *a2)
{
  unsigned int opmode_from_vdev_id; // w21
  __int64 result; // x0
  _DWORD *v6; // x8
  __int64 v7; // x0
  _DWORD *v8; // x8
  __int64 v9; // x0
  const char *v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(a1[2704], *a2);
  result = qdf_mutex_acquire((__int64)(a1 + 1606));
  if ( !(_DWORD)result )
  {
    if ( opmode_from_vdev_id )
    {
      if ( opmode_from_vdev_id == 1 )
      {
        v6 = (_DWORD *)a1[1817];
        if ( v6 )
        {
          v7 = a1[2703];
          if ( *(v6 - 1) != 375403533 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _DWORD *))v6)(v7, a2);
        }
      }
      else
      {
        v10 = qdf_opmode_str(opmode_from_vdev_id);
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: TWT Resume is not supported on %s",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "sme_process_twt_resume_dialog_event",
          v10);
      }
    }
    else
    {
      v8 = (_DWORD *)a1[1817];
      if ( v8 )
      {
        v9 = a1[2703];
        if ( *(v8 - 1) != 375403533 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _DWORD *))v8)(v9, a2);
      }
      mlme_set_twt_command_in_progress(a1[2703], a2 + 1, (unsigned int)a2[3], 0);
    }
    return qdf_mutex_release((__int64)(a1 + 1606));
  }
  return result;
}
