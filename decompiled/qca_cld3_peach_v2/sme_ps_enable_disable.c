__int64 __fastcall sme_ps_enable_disable(_QWORD *a1, unsigned int a2, unsigned int a3)
{
  unsigned int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w22
  int v16; // w21
  char user_ps; // w0
  const char *v18; // x2
  const char *v19; // x3

  v6 = sme_acquire_global_lock((__int64)(a1 + 1605));
  if ( !v6 )
  {
    if ( a2 > 5 )
    {
      v16 = 4;
      goto LABEL_12;
    }
    if ( (*(_BYTE *)(a1[1] + 5633LL) & 1) != 0 )
    {
      user_ps = mlme_get_user_ps(a1[2703], a2);
      if ( a3 || (user_ps & 1) != 0 )
      {
        if ( a3 == 1 || cm_is_vdevid_active(a1[2704], a2) )
        {
          v15 = sme_ps_process_command((__int64)a1, a2, a3, v7, v8, v9, v10, v11, v12, v13, v14);
LABEL_15:
          sme_release_global_lock((__int64)(a1 + 1605));
          return v15;
        }
        goto LABEL_11;
      }
      v18 = "%s: vdev:%d Cannot initiate PS. PS is disabled by usr(ioctl)";
      v19 = "sme_ps_enable_user_check";
    }
    else
    {
      v18 = "%s: vdev:%d power save mode is disabled via ini";
      v19 = "sme_enable_sta_ps_check";
    }
    qdf_trace_msg(0x34u, 8u, v18, v7, v8, v9, v10, v11, v12, v13, v14, v19, a2);
LABEL_11:
    v16 = 16;
LABEL_12:
    if ( cm_is_vdevid_active(a1[2704], a2) )
      v15 = v16;
    else
      v15 = 0;
    goto LABEL_15;
  }
  v15 = v6;
  qdf_trace_msg(
    0x34u,
    2u,
    "%s: can't acquire sme global lock",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "sme_ps_enable_disable");
  return v15;
}
