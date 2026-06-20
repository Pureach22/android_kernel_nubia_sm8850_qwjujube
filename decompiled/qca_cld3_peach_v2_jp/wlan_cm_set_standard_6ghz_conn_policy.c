__int64 __fastcall wlan_cm_set_standard_6ghz_conn_policy(__int64 a1, char a2)
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
  __int64 v12; // x19
  __int64 v13; // x4
  char v14; // w20

  result = wlan_psoc_mlme_get_cmpt_obj(a1);
  if ( result )
  {
    v12 = result;
    v13 = a2 & 1;
    if ( (a2 & 1) != 0 )
      v14 = 16;
    else
      v14 = 0;
    result = qdf_trace_msg(
               0x68u,
               8u,
               "%s: 6ghz standard connection policy val %x",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "wlan_cm_set_standard_6ghz_conn_policy",
               v13);
    *(_BYTE *)(v12 + 2000) = *(_BYTE *)(v12 + 2000) & 0xEF | v14;
  }
  return result;
}
