__int64 __fastcall wlan_mlme_set_usr_disable_sta_eht(__int64 a1, char a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w19
  __int64 v13; // x20

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
  {
    v12 = a2 & 1;
    v13 = result;
    result = qdf_trace_msg(
               0x68u,
               8u,
               "%s: set usr_disable_eht from %d to %d",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "wlan_mlme_set_usr_disable_sta_eht",
               *(unsigned __int8 *)(result + 3599),
               v12);
    *(_BYTE *)(v13 + 3599) = v12;
  }
  return result;
}
