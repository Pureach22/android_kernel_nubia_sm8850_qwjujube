__int64 __fastcall sme_ps_update(_QWORD *a1, unsigned int a2)
{
  unsigned int v4; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w21
  char user_ps; // w21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v4 = sme_acquire_global_lock((__int64)(a1 + 1605));
  if ( v4 )
  {
    v13 = v4;
    qdf_trace_msg(0x34u, 2u, "%s: can't acquire sme global lock", v5, v6, v7, v8, v9, v10, v11, v12, "sme_ps_update");
  }
  else
  {
    user_ps = mlme_get_user_ps(a1[2703], a2);
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Allow power save %d vdev %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "sme_ps_update",
      user_ps & 1,
      a2);
    v13 = sme_ps_enable_disable(a1, a2, (user_ps & 1) == 0);
    sme_release_global_lock((__int64)(a1 + 1605));
  }
  return v13;
}
