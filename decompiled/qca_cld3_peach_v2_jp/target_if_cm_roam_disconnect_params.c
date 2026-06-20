__int64 __fastcall target_if_cm_roam_disconnect_params(__int64 a1, char a2, unsigned int *a3)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x4
  unsigned int v14; // w19

  if ( a2 != 4 )
  {
    if ( a2 == 2 )
    {
      *((_BYTE *)a3 + 4) = 0;
      goto LABEL_7;
    }
    if ( a2 != 1 )
      goto LABEL_7;
  }
  if ( (a3[1] & 1) == 0 )
    return 0;
LABEL_7:
  result = wmi_unified_send_disconnect_roam_params(a1, a3);
  if ( (_DWORD)result )
  {
    v13 = *a3;
    v14 = result;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: failed to send disconnect roam parameters for vdev_id %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "target_if_cm_roam_disconnect_params",
      v13);
    return v14;
  }
  return result;
}
