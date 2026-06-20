__int64 __fastcall ce_prepare_shadow_register_v3_cfg_srng(
        __int64 a1,
        _QWORD *a2,
        _DWORD *a3,
        long double a4,
        long double a5,
        long double a6,
        long double a7,
        long double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x0
  const char *v15; // x2
  long double v17; // q0
  long double v18; // q1
  long double v19; // q2
  long double v20; // q3
  long double v21; // q4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w9
  __int64 v26; // x8
  __int64 v27; // x22
  long double v28; // q0
  long double v29; // q1
  long double v30; // q2
  long double v31; // q3
  long double v32; // q4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  v12 = *(_QWORD *)(a1 + 2560);
  if ( !v12 )
  {
    v15 = "%s: hal not initialized: not initializing shadow config";
    return qdf_trace_msg(
             0x3Du,
             2u,
             v15,
             *(double *)&a4,
             *(double *)&a5,
             *(double *)&a6,
             *(double *)&a7,
             *(double *)&a8,
             a9,
             a10,
             a11,
             "ce_prepare_shadow_register_v3_cfg_srng");
  }
  hal_get_shadow_v3_config(v12, a2, a3);
  if ( *a3 )
  {
    v15 = "%s: hal shadow register configuration already constructed";
    return qdf_trace_msg(
             0x3Du,
             2u,
             v15,
             *(double *)&a4,
             *(double *)&a5,
             *(double *)&a6,
             *(double *)&a7,
             *(double *)&a8,
             a9,
             a10,
             a11,
             "ce_prepare_shadow_register_v3_cfg_srng");
  }
  hal_construct_srng_shadow_regs(*(_QWORD *)(a1 + 2560), a4, a5, a6, a7, a8, a9, a10, a11);
  if ( *(_DWORD *)(a1 + 656) )
  {
    v25 = 0;
    do
    {
      v26 = *(_QWORD *)(a1 + 27400);
      v27 = v25;
      if ( *(_DWORD *)(v26 + 32LL * v25 + 8) )
      {
        hal_set_one_shadow_config(*(_QWORD *)(a1 + 2560), 8u, v25, v17, v18, v19, v20, v21, v22, v23, v24);
        v26 = *(_QWORD *)(a1 + 27400);
      }
      if ( *(_DWORD *)(v26 + 32 * v27 + 16) )
      {
        hal_set_one_shadow_config(*(_QWORD *)(a1 + 2560), 9u, v27, v17, v18, v19, v20, v21, v22, v23, v24);
        hal_set_one_shadow_config(*(_QWORD *)(a1 + 2560), 0xAu, v27, v28, v29, v30, v31, v32, v33, v34, v35);
      }
      v25 = v27 + 1;
    }
    while ( (unsigned int)(v27 + 1) < *(_DWORD *)(a1 + 656) );
  }
  return hal_get_shadow_v3_config(*(_QWORD *)(a1 + 2560), a2, a3);
}
