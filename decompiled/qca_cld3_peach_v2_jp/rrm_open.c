__int64 __fastcall rrm_open(__int64 a1)
{
  _BYTE *v1; // x20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  const char *v11; // x2
  _BYTE *v13; // x8

  v1 = (_BYTE *)(a1 + 0x4000);
  *(_BYTE *)(a1 + 17410) = 50;
  if ( (unsigned int)qdf_mc_timer_init(a1 + 17656, 0, (__int64)rrm_neighbor_rsp_timeout_handler, a1) )
    goto LABEL_2;
  v1[1041] = 0;
  v1[1264] = 0;
  if ( (unsigned int)csr_ll_open(a1 + 17560, v3, v4, v5, v6, v7, v8, v9, v10) )
  {
LABEL_4:
    v11 = "%s: Fail to open neighbor cache result";
    goto LABEL_5;
  }
  if ( !(unsigned int)qdf_mc_timer_init(a1 + 18200, 0, (__int64)rrm_neighbor_rsp_timeout_handler, a1) )
  {
    v1[1808] = 0;
    v1[1585] = 1;
    if ( (unsigned int)csr_ll_open(a1 + 18104, v3, v4, v5, v6, v7, v8, v9, v10) )
      goto LABEL_4;
    if ( !(unsigned int)qdf_mc_timer_init(a1 + 18744, 0, (__int64)rrm_neighbor_rsp_timeout_handler, a1) )
    {
      v1[2352] = 0;
      v1[2129] = 2;
      if ( (unsigned int)csr_ll_open(a1 + 18648, v3, v4, v5, v6, v7, v8, v9, v10) )
        goto LABEL_4;
      if ( !(unsigned int)qdf_mc_timer_init(a1 + 19288, 0, (__int64)rrm_neighbor_rsp_timeout_handler, a1) )
      {
        v1[2896] = 0;
        v1[2673] = 3;
        if ( (unsigned int)csr_ll_open(a1 + 19192, v3, v4, v5, v6, v7, v8, v9, v10) )
          goto LABEL_4;
        if ( !(unsigned int)qdf_mc_timer_init(a1 + 19832, 0, (__int64)rrm_neighbor_rsp_timeout_handler, a1) )
        {
          v1[3440] = 0;
          v1[3217] = 4;
          if ( !(unsigned int)csr_ll_open(a1 + 19736, v3, v4, v5, v6, v7, v8, v9, v10) )
          {
            v13 = *(_BYTE **)(a1 + 8);
            v1[1024] = v13[5724];
            v1[1025] = v13[5725];
            v1[1026] = v13[5726];
            qdf_mem_copy((void *)(a1 + 17411), v13 + 5727, 5u);
            return 0;
          }
          goto LABEL_4;
        }
      }
    }
  }
LABEL_2:
  v11 = "%s: Fail to init neighbor rsp wait timer";
LABEL_5:
  qdf_trace_msg(0x34u, 2u, v11, v3, v4, v5, v6, v7, v8, v9, v10, "rrm_open");
  return 16;
}
