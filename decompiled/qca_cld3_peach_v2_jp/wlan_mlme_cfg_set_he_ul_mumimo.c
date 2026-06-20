__int64 __fastcall wlan_mlme_cfg_set_he_ul_mumimo(__int64 a1, unsigned int a2)
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
  __int64 v12; // x8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    if ( a2 < 4 )
    {
      v12 = psoc_ext_obj_fl;
      *(_QWORD *)(v12 + 1297) = *(_QWORD *)(v12 + 1297) & 0xFFFFFFFFFFFFFE7FLL | (a2 << 7);
      return 0;
    }
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: Failed to set CFG_HE_UL_MUMIMO with %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_mlme_cfg_set_he_ul_mumimo",
      a2);
  }
  return 16;
}
