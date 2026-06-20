bool __fastcall mlo_is_sta_csa_param_handled(
        __int64 a1,
        const void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  int v11; // w19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int8 *v21; // x8
  int v22; // w9
  unsigned int v23; // w10
  const char *v24; // x2
  _BOOL4 v25; // w19
  unsigned __int8 *v26; // x0
  const char *v27; // x2
  unsigned int v28; // w1

  if ( a1 )
  {
    v10 = *(_QWORD *)(a1 + 1360);
    if ( v10 )
    {
      v11 = *(unsigned __int8 *)(a1 + 93);
      qdf_mutex_acquire(v10 + 1656);
      v21 = *(unsigned __int8 **)(v10 + 2224);
      if ( v21 )
      {
        if ( v11 == v21[236] )
        {
          v22 = v21[239];
          if ( (v22 & 1) != 0 || (v21[237] & 1) != 0 )
          {
            v23 = 0;
LABEL_15:
            v26 = &v21[40 * v23 + 200];
            if ( (v26[38] & 1) == 0 )
            {
              v26[38] = 1;
              if ( v22 )
              {
                v25 = qdf_mem_cmp(v26, a2, 0x24u) == 0;
LABEL_22:
                qdf_mutex_release(v10 + 1656);
                return v25;
              }
            }
LABEL_21:
            v25 = 0;
            goto LABEL_22;
          }
        }
        if ( v11 == v21[276] )
        {
          v22 = v21[279];
          if ( (v22 & 1) != 0 || (v21[277] & 1) != 0 )
          {
            v23 = 1;
            goto LABEL_15;
          }
        }
        v27 = "%s: mlo csa synced does not happen before csa FW event";
        v28 = 8;
      }
      else
      {
        v27 = "%s: invalid sta_ctx";
        v28 = 2;
      }
      qdf_trace_msg(0x8Fu, v28, v27, v13, v14, v15, v16, v17, v18, v19, v20, "mlo_is_sta_csa_param_handled");
      goto LABEL_21;
    }
    v24 = "%s: invalid mlo_dev_ctx";
  }
  else
  {
    v24 = "%s: invalid vdev";
  }
  qdf_trace_msg(0x8Fu, 2u, v24, a3, a4, a5, a6, a7, a8, a9, a10, "mlo_is_sta_csa_param_handled");
  return 0;
}
