__int64 __fastcall cm_roam_event_handler(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x4
  unsigned __int8 *v10; // x19
  unsigned __int8 *v11; // x19
  int v12; // w8
  int v13; // w10

  v9 = *((unsigned int *)a1 + 4);
  if ( (int)v9 <= 4 )
  {
    if ( (int)v9 > 1 )
    {
      if ( (_DWORD)v9 == 2 )
      {
        cm_handle_roam_reason_bmiss(*a1, *((unsigned int *)a1 + 5));
        return 0;
      }
      if ( (_DWORD)v9 == 4 )
      {
        cm_handle_roam_reason_suitable_ap(*a1, *((unsigned int *)a1 + 5));
        return 0;
      }
      goto LABEL_27;
    }
    if ( (_DWORD)v9 )
    {
      if ( (_DWORD)v9 == 1 )
      {
        cm_handle_roam_reason_better_ap(*a1, *((unsigned int *)a1 + 5));
        return 0;
      }
      goto LABEL_27;
    }
    goto LABEL_25;
  }
  if ( (int)v9 <= 6 )
  {
    if ( (_DWORD)v9 != 5 )
    {
      cm_handle_roam_reason_invoke_roam_fail(*a1, *((unsigned int *)a1 + 7), *((_QWORD *)a1 + 5));
      return 0;
    }
    if ( a1[56] != 1 )
    {
LABEL_24:
      v13 = *((_DWORD *)a1 + 7);
      cm_handle_roam_reason_ho_failed(
        *a1,
        ((unsigned __int64)(unsigned __int8)*((_DWORD *)a1 + 8) << 32)
      | ((unsigned __int64)(unsigned __int8)BYTE1(*((_DWORD *)a1 + 8)) << 40)
      | v13 & 0xFF000000
      | *(_QWORD *)&v13 & 0xFF0000LL
      | (unsigned __int16)v13 & 0xFF00
      | (unsigned __int8)v13,
        *((_QWORD *)a1 + 5));
      return 0;
    }
    v11 = a1;
    wlan_cm_rso_stop_continue_disconnect(*((_QWORD *)a1 + 1), *a1, 1);
    v12 = *((_DWORD *)v11 + 4);
    a1 = v11;
    if ( v12 )
    {
      if ( v12 != 5 )
        return 0;
      goto LABEL_24;
    }
LABEL_25:
    cm_invalid_roam_reason_handler(*a1, *((unsigned int *)a1 + 6), *((unsigned int *)a1 + 7));
    return 0;
  }
  if ( (_DWORD)v9 != 7 )
  {
    if ( (_DWORD)v9 == 9 )
    {
      cm_handle_roam_reason_deauth(*a1, *((unsigned int *)a1 + 7), *((_QWORD *)a1 + 6), *((unsigned int *)a1 + 8));
      return 0;
    }
    if ( (_DWORD)v9 == 8 )
    {
      cm_handle_roam_reason_btm(*a1);
      return 0;
    }
LABEL_27:
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Unhandled roam event with reason 0x%x for vdev_id %u",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "cm_roam_event_handler",
      v9,
      *a1);
    return 0;
  }
  if ( a1[56] == 1 && (*((_DWORD *)a1 + 6) & 0xFFFFFFFE) == 4 )
  {
    v10 = a1;
    wlan_cm_rso_stop_continue_disconnect(*((_QWORD *)a1 + 1), *a1, 0);
    a1 = v10;
  }
  cm_rso_cmd_status_event_handler(*a1, *((unsigned int *)a1 + 6));
  return 0;
}
