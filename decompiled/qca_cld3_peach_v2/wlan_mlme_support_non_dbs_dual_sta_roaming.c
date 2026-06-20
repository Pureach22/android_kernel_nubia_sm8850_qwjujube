__int64 __fastcall wlan_mlme_support_non_dbs_dual_sta_roaming(__int64 a1)
{
  __int64 psoc_ext_obj_fl; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  char v11; // w8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: mlme_obj is not ready",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_mlme_support_non_dbs_dual_sta_roaming");
    goto LABEL_5;
  }
  if ( *(_BYTE *)(psoc_ext_obj_fl + 1716) != 1 )
  {
LABEL_5:
    v11 = 0;
    return v11 & 1;
  }
  v11 = policy_mgr_is_hw_dbs_capable(a1) ^ 1;
  return v11 & 1;
}
