__int64 __fastcall sme_update_is_fast_roam_ini_feature_enabled(
        _QWORD *a1,
        unsigned int a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  char v12; // w22
  __int64 v13; // x4
  int v17; // w2
  unsigned int v18; // w3

  v11 = a1[1];
  v12 = a3 & 1;
  v13 = *(unsigned __int8 *)(v11 + 1563);
  if ( (_DWORD)v13 == (a3 & 1) )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: FastRoam is already enabled or disabled, nothing to do (returning) old(%d) new(%d)",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "sme_update_is_fast_roam_ini_feature_enabled",
      v13,
      *(unsigned __int8 *)(v11 + 1563));
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: FastRoamEnabled is changed from %d to %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "sme_update_is_fast_roam_ini_feature_enabled",
      v13,
      a3 & 1);
    *(_BYTE *)(a1[1] + 1563LL) = v12;
    mlme_set_supplicant_disabled_roaming(a1[2694], a2, (a3 & 1) == 0);
    if ( (a3 & 1) != 0 )
    {
      v17 = 2;
      v18 = 1;
    }
    else
    {
      v17 = 3;
      v18 = 39;
    }
    wlan_cm_roam_state_change(a1[2695], a2, v17, v18);
  }
  return 0;
}
