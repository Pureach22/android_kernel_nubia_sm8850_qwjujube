__int64 __fastcall wlan_mlme_restore_user_set_link_num(__int64 a1)
{
  __int64 result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
  {
    if ( *(_BYTE *)(result + 3591) )
    {
      *(_BYTE *)(result + 3592) = *(_BYTE *)(result + 3591);
      return qdf_trace_msg(
               0x1Fu,
               8u,
               "%s: restore mlo_support_link_num %d",
               v2,
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               "wlan_mlme_restore_user_set_link_num");
    }
  }
  return result;
}
