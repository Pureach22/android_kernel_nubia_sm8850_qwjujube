__int64 __fastcall extract_obss_color_collision_info_tlv(
        unsigned int **a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int *v10; // x8
  __int64 v11; // x4
  int v12; // w8
  const char *v13; // x2

  if ( !a2 )
  {
    v13 = "%s: Invalid obss color buffer";
LABEL_9:
    qdf_trace_msg(0x31u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "extract_obss_color_collision_info_tlv");
    return 4;
  }
  if ( !a1 )
  {
    v13 = "%s: Invalid evt_buf";
    goto LABEL_9;
  }
  v10 = *a1;
  *a2 = (*a1)[1];
  a2[2] = v10[3];
  a2[3] = v10[4];
  v11 = v10[2];
  if ( (int)v11 > 1 )
  {
    if ( (_DWORD)v11 == 2 )
    {
      v12 = 2;
      goto LABEL_16;
    }
    if ( (_DWORD)v11 == 3 )
    {
      v12 = 3;
      goto LABEL_16;
    }
LABEL_13:
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid event type: %d, vdev_id: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "extract_obss_color_collision_info_tlv",
      v11,
      v10[1]);
    return 16;
  }
  if ( !(_DWORD)v11 )
  {
    a2[1] = 0;
    return 0;
  }
  if ( (_DWORD)v11 != 1 )
    goto LABEL_13;
  v12 = 1;
LABEL_16:
  a2[1] = v12;
  return 0;
}
