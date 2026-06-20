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
  *(_BYTE *)(a1 + 17482) = 50;
  if ( (unsigned int)qdf_mc_timer_init(a1 + 17728, 0, (__int64)rrm_neighbor_rsp_timeout_handler, a1) )
    goto LABEL_2;
  v1[1113] = 0;
  v1[1336] = 0;
  if ( (unsigned int)csr_ll_open(a1 + 17632, v3, v4, v5, v6, v7, v8, v9, v10) )
  {
LABEL_4:
    v11 = "%s: Fail to open neighbor cache result";
    goto LABEL_5;
  }
  if ( !(unsigned int)qdf_mc_timer_init(a1 + 18272, 0, (__int64)rrm_neighbor_rsp_timeout_handler, a1) )
  {
    v1[1880] = 0;
    v1[1657] = 1;
    if ( (unsigned int)csr_ll_open(a1 + 18176, v3, v4, v5, v6, v7, v8, v9, v10) )
      goto LABEL_4;
    if ( !(unsigned int)qdf_mc_timer_init(a1 + 18816, 0, (__int64)rrm_neighbor_rsp_timeout_handler, a1) )
    {
      v1[2424] = 0;
      v1[2201] = 2;
      if ( (unsigned int)csr_ll_open(a1 + 18720, v3, v4, v5, v6, v7, v8, v9, v10) )
        goto LABEL_4;
      if ( !(unsigned int)qdf_mc_timer_init(a1 + 19360, 0, (__int64)rrm_neighbor_rsp_timeout_handler, a1) )
      {
        v1[2968] = 0;
        v1[2745] = 3;
        if ( (unsigned int)csr_ll_open(a1 + 19264, v3, v4, v5, v6, v7, v8, v9, v10) )
          goto LABEL_4;
        if ( !(unsigned int)qdf_mc_timer_init(a1 + 19904, 0, (__int64)rrm_neighbor_rsp_timeout_handler, a1) )
        {
          v1[3512] = 0;
          v1[3289] = 4;
          if ( !(unsigned int)csr_ll_open(a1 + 19808, v3, v4, v5, v6, v7, v8, v9, v10) )
          {
            v13 = *(_BYTE **)(a1 + 8);
            v1[1096] = v13[5940];
            v1[1097] = v13[5941];
            v1[1098] = v13[5942];
            qdf_mem_copy((void *)(a1 + 17483), v13 + 5943, 5u);
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
