__int64 __fastcall sme_update_is_ese_feature_enabled(
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
  __int64 v13; // x5
  __int64 v17; // x0
  __int64 result; // x0

  v11 = a1[1];
  v12 = a3 & 1;
  v13 = *(unsigned __int8 *)(v11 + 1766);
  if ( (_DWORD)v13 == (a3 & 1) )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: ESE Mode is already enabled or disabled, nothing to do (returning) old(%d) new(%d)",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "sme_update_is_ese_feature_enabled",
      *(unsigned __int8 *)(v11 + 1766));
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: vdev %d EseEnabled is changed from %d to %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "sme_update_is_ese_feature_enabled",
      (unsigned __int8)a2,
      v13,
      a3 & 1);
    *(_BYTE *)(a1[1] + 1766LL) = v12;
    mlme_set_supplicant_disabled_roaming(a1[2703], a2, (a3 & 1) == 0);
    v17 = a1[2704];
    if ( (a3 & 1) != 0 )
    {
      wlan_cm_roam_state_change(v17, a2, 2u, 1u);
      *(_BYTE *)(a1[1] + 1769LL) = 1;
    }
    else
    {
      wlan_cm_roam_state_change(v17, a2, 3u, 0x27u);
    }
    if ( *(_BYTE *)(a1[1] + 1912LL) == 1 )
    {
      result = qdf_mutex_acquire((__int64)(a1 + 1606));
      if ( (_DWORD)result )
        return result;
      wlan_roam_update_cfg(a1[2703], a2, 6u);
      qdf_mutex_release((__int64)(a1 + 1606));
    }
  }
  return 0;
}
