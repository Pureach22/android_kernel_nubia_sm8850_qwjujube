__int64 __fastcall sme_update_sta_roam_policy(
        __int64 a1,
        int a2,
        char a3,
        unsigned int a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 psoc_ext_obj_fl; // x0
  __int64 result; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w21

  if ( !a1 )
  {
    qdf_trace_msg(0x34u, 2u, "%s: mac_ctx is null", a6, a7, a8, a9, a10, a11, a12, a13, "sme_update_sta_roam_policy");
    return 16;
  }
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(*(_QWORD *)(a1 + 21624));
  if ( !psoc_ext_obj_fl )
    return 16;
  *(_DWORD *)(psoc_ext_obj_fl + 2716) = a2;
  *(_BYTE *)(psoc_ext_obj_fl + 2720) = a3 & 1;
  *(_BYTE *)(psoc_ext_obj_fl + 2721) = a5;
  result = csr_update_channel_list(a1);
  if ( (_DWORD)result )
  {
    v28 = result;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: failed to update the supported channel list",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "sme_update_sta_roam_policy");
    result = v28;
  }
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1912LL) == 1 )
  {
    result = qdf_mutex_acquire(a1 + 12848);
    if ( !(_DWORD)result )
    {
      wlan_roam_update_cfg(*(_QWORD *)(a1 + 21624), a4, 0x23u);
      qdf_mutex_release(a1 + 12848);
      return 0;
    }
  }
  return result;
}
