__int64 __fastcall wlan_cm_enable_rso(
        __int64 a1,
        unsigned int a2,
        signed int a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  const char *v16; // x5
  unsigned int v17; // w3

  if ( a3 && a4 == 43 )
    mlme_set_rso_disabled_bitmap(*(_QWORD *)(a1 + 80), a2, a3, 1);
  v16 = "No requestor";
  if ( a3 <= 7 )
  {
    switch ( a3 )
    {
      case 1:
        v16 = "SAP start";
        break;
      case 2:
        v16 = "CSA";
        break;
      case 4:
        v16 = "STA connection";
        break;
    }
  }
  else if ( a3 > 31 )
  {
    if ( a3 == 32 )
    {
      v16 = "Set PCL";
    }
    else if ( a3 == 64 )
    {
      v16 = "Set Link";
    }
  }
  else if ( a3 == 8 )
  {
    v16 = "SAP Ch switch";
  }
  else if ( a3 == 16 )
  {
    v16 = "NDP connection";
  }
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: ROAM_CONFIG: vdev[%d] Enable roaming - requestor:%s",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "wlan_cm_enable_rso",
    (unsigned __int8)a2,
    v16);
  if ( a4 == 56 )
    v17 = 56;
  else
    v17 = 43;
  return cm_roam_state_change(a1, a2, 2, v17, 0, 0);
}
