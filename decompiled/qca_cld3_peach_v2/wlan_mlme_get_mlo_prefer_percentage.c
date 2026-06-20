__int64 __fastcall wlan_mlme_get_mlo_prefer_percentage(__int64 a1, _BYTE *a2)
{
  __int64 psoc_ext_obj_fl; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return qdf_trace_msg(
             0x1Fu,
             2u,
             "%s: invalid mlo object",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "wlan_mlme_get_mlo_prefer_percentage");
  *a2 = *(_BYTE *)(psoc_ext_obj_fl + 3595);
  return qdf_trace_msg(
           0x1Fu,
           8u,
           "%s: mlo_prefer_percentage %d",
           v4,
           v5,
           v6,
           v7,
           v8,
           v9,
           v10,
           v11,
           "wlan_mlme_get_mlo_prefer_percentage");
}
