__int64 __fastcall rrm_reject_req(
        __int64 *a1,
        __int64 a2,
        unsigned __int8 *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v7; // x8
  unsigned __int8 v8; // w20
  __int64 *v10; // x21
  __int64 v11; // x23
  unsigned int v12; // w22
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0

  v7 = *a1;
  v8 = a4;
  if ( !*a1 )
  {
    v10 = a1;
    v11 = a2;
    v12 = a5;
    v13 = _qdf_mem_malloc(
            264 * (*(unsigned __int16 *)(a2 + 6) - (unsigned __int64)(unsigned __int8)a4),
            "rrm_reject_req",
            2440);
    *v10 = v13;
    if ( !v13 )
      return 2;
    a1 = (__int64 *)qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: rrm beacon refused of %d report, index: %d in beacon table",
                      v14,
                      v15,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20,
                      v21,
                      "rrm_reject_req",
                      *a3,
                      v8);
    v7 = *v10;
    a2 = v11;
    a5 = v12;
  }
  *(_BYTE *)(v7 + 264LL * *a3 + 1) = 1;
  *(_BYTE *)(v7 + 264LL * *a3 + 3) = a5;
  if ( v8 >= 5u )
  {
    __break(0x5512u);
    return rrm_process_radio_measurement_request(a1, a2, a3, a4, a5, a6, a7);
  }
  else
  {
    result = 0;
    *(_BYTE *)(v7 + 264LL * (*a3)++) = *(_BYTE *)(a2 + 682LL * v8 + 9);
  }
  return result;
}
