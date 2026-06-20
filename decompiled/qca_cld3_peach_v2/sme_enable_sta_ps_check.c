__int64 __fastcall sme_enable_sta_ps_check(
        _QWORD *a1,
        unsigned int a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  char user_ps; // w0
  const char *v18; // x2
  const char *v19; // x3
  __int64 v20; // [xsp+8h] [xbp-28h]

  if ( a2 > 5 )
    return 4;
  v20 = v12;
  if ( (*(_BYTE *)(a1[1] + 5633LL) & 1) == 0 )
  {
    v18 = "%s: vdev:%d power save mode is disabled via ini";
    v19 = "sme_enable_sta_ps_check";
    goto LABEL_8;
  }
  user_ps = mlme_get_user_ps(a1[2703], a2);
  if ( !a3 && (user_ps & 1) == 0 )
  {
    v18 = "%s: vdev:%d Cannot initiate PS. PS is disabled by usr(ioctl)";
    v19 = "sme_ps_enable_user_check";
LABEL_8:
    qdf_trace_msg(0x34u, 8u, v18, a4, a5, a6, a7, a8, a9, a10, a11, v19, a2, v11, v20);
    return 16;
  }
  if ( a3 == 1 )
    return 0;
  if ( cm_is_vdevid_active(a1[2704], a2) )
    return 0;
  return 16;
}
