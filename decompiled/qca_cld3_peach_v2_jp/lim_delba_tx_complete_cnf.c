__int64 __fastcall lim_delba_tx_complete_cnf(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 **context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x22
  __int64 **v26; // x24
  unsigned int v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned __int8 *v36; // x22
  unsigned int v37; // t1
  __int64 v38; // x8
  _DWORD *v39; // x8
  __int64 v40; // x2
  __int64 v41; // x3
  const char *v42; // x2
  const char *v43; // x3
  unsigned int v44; // w0
  unsigned int v45; // w1
  __int64 v47; // [xsp+20h] [xbp-10h] BYREF
  __int64 v48; // [xsp+28h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  WORD2(v47) = 0;
  LODWORD(v47) = 0;
  context = (__int64 **)_cds_get_context(71, (__int64)"lim_delba_tx_complete_cnf", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !a2 || !a1 || !a4 || !context )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: delba tx cnf invalid parameters",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "lim_delba_tx_complete_cnf");
    if ( !a2 )
      goto LABEL_20;
    goto LABEL_19;
  }
  v25 = *(_QWORD *)(a2 + 224);
  if ( !v25 )
  {
    v42 = "%s: Delba frame is NULL";
    v43 = "lim_delba_tx_complete_cnf";
    v44 = 53;
    v45 = 2;
LABEL_18:
    qdf_trace_msg(v44, v45, v42, v17, v18, v19, v20, v21, v22, v23, v24, v43);
    goto LABEL_19;
  }
  v26 = context;
  qdf_mem_set(&v47, 6u, 0);
  v27 = dot11f_unpack_delba_req(a1, v25 + 24, 6, &v47, 0);
  if ( (v27 & 0x10000000) == 0 )
  {
    v37 = *(unsigned __int8 *)(v25 + 4);
    v36 = (unsigned __int8 *)(v25 + 4);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: delba ota done vdev %d %02x:%02x:%02x:**:**:%02x tid %d desc_id %d status %d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "lim_delba_tx_complete_cnf",
      *(unsigned __int8 *)(a4 + 10),
      v37,
      v36[1],
      v36[2],
      v36[5],
      WORD1(v47) >> 12,
      *(unsigned __int16 *)(a4 + 14),
      a3,
      v47,
      v48);
    if ( *v26 )
    {
      v38 = **v26;
      if ( v38 )
      {
        v39 = *(_DWORD **)(v38 + 472);
        if ( v39 )
        {
          v40 = *(unsigned __int8 *)(a4 + 10);
          v41 = WORD1(v47) >> 12;
          if ( *(v39 - 1) != 75369535 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64 **, unsigned __int8 *, __int64, __int64, _QWORD))v39)(v26, v36, v40, v41, a3);
        }
      }
      goto LABEL_19;
    }
    v42 = "%s: Invalid Instance:";
    v43 = "cdp_delba_tx_completion";
    v44 = 137;
    v45 = 8;
    goto LABEL_18;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Failed to unpack and parse delba (0x%08x, %d bytes)",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "lim_delba_tx_complete_cnf",
    v27,
    6);
LABEL_19:
  _qdf_nbuf_free(a2);
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return 0;
}
