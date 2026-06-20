__int64 __fastcall wlan_mlme_set_ht_mpdu_density(__int64 a1, unsigned __int8 a2)
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
    return 16;
  if ( a2 >= 8u )
  {
    qdf_trace_msg(0x1Fu, 2u, "%s: Invalid value %d", v4, v5, v6, v7, v8, v9, v10, v11, "wlan_mlme_set_ht_mpdu_density");
    return 4;
  }
  else
  {
    *(_BYTE *)(psoc_ext_obj_fl + 1270) = *(_BYTE *)(psoc_ext_obj_fl + 1270) & 0xE3 | (4 * a2);
    return 0;
  }
}
