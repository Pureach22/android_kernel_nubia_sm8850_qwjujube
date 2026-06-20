__int64 __fastcall lim_init_mlm(_DWORD *a1)
{
  int v1; // w3
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  v1 = a1[1005];
  a1[996] = 0;
  qdf_trace(53, 0, 255, v1);
  a1[2851] = 0;
  lim_init_pre_auth_list((__int64)a1);
  if ( (unsigned int)lim_create_timers((__int64)a1, v3, v4, v5, v6, v7, v8, v9, v10) )
    qdf_trace_msg(0x35u, 2u, "%s: lim_create_timers Failed", v11, v12, v13, v14, v15, v16, v17, v18, "lim_init_mlm");
  else
    a1[996] = 1;
  return 0;
}
