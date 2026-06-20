__int64 __fastcall wlan_mlme_disable_he_dynamic_smps(__int64 a1)
{
  __int64 psoc_ext_obj_fl; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  v10 = psoc_ext_obj_fl;
  qdf_trace_msg(0x1Fu, 8u, "%s: Disable HE D-SMPS", v2, v3, v4, v5, v6, v7, v8, v9, "wlan_mlme_disable_he_dynamic_smps");
  *(_QWORD *)(v10 + 1309) &= ~0x400000000000uLL;
  return 0;
}
