bool __fastcall wlan_dcs_get_max_no_intf_bw(
        unsigned int *a1,
        int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x4
  unsigned int v11; // w9
  int v13; // w8
  _DWORD *v14; // x21
  unsigned int v16; // w20
  int v17; // w4

  v10 = *a1;
  if ( (unsigned int)v10 >= 5 )
  {
    qdf_trace_msg(0x74u, 2u, "%s: Invalid ch width %d", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_dcs_get_max_seg_idx");
    return 0;
  }
  v11 = a1[4];
  if ( (v11 & 1) != 0 )
  {
    v14 = a1;
    v16 = 1;
LABEL_12:
    qdf_trace_msg(
      0x74u,
      8u,
      "%s: Intf found for seg idx %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_dcs_get_max_no_intf_bw",
      v16);
    v13 = v16;
    goto LABEL_13;
  }
  v13 = dword_B2BA90[v10];
  if ( !(_DWORD)v10 )
  {
LABEL_6:
    v14 = a1;
    goto LABEL_13;
  }
  if ( (v11 & 2) != 0 )
  {
    v14 = a1;
    v16 = 2;
    goto LABEL_12;
  }
  if ( (_DWORD)v10 == 1 )
    goto LABEL_6;
  if ( (v11 & 0xC) != 0 )
  {
    v14 = a1;
    v16 = 3;
    goto LABEL_12;
  }
  if ( (_DWORD)v10 == 2 )
    goto LABEL_6;
  if ( (v11 & 0xF0) != 0 )
  {
    v14 = a1;
    v16 = 4;
    goto LABEL_12;
  }
  v14 = a1;
LABEL_13:
  if ( v13 <= 2 )
  {
    if ( v13 == 1 )
    {
      qdf_trace_msg(
        0x74u,
        8u,
        "%s: Primary 20MHz Channel interference detected",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlan_dcs_get_max_no_intf_bw");
      return 0;
    }
    if ( v13 != 2 )
    {
LABEL_26:
      qdf_trace_msg(
        0x74u,
        2u,
        "%s: Invalid seg idx %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlan_dcs_get_chan_width_for_seg",
        (unsigned int)(v13 - 1));
      v17 = 8;
      goto LABEL_27;
    }
    v17 = 0;
  }
  else
  {
    switch ( v13 )
    {
      case 3:
        v17 = 1;
        break;
      case 4:
        v17 = 2;
        break;
      case 5:
        *a2 = 3;
        if ( *v14 == 4 )
          v17 = 4;
        else
          v17 = 3;
        break;
      default:
        goto LABEL_26;
    }
  }
LABEL_27:
  *a2 = v17;
  qdf_trace_msg(
    0x74u,
    8u,
    "%s: Found the max no intf width %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_dcs_get_max_no_intf_bw");
  return *a2 != 8;
}
