void *__fastcall lim_add_additional_ie(
        __int64 a1,
        unsigned int a2,
        char *a3,
        unsigned int a4,
        unsigned __int64 a5,
        char *a6,
        unsigned int a7,
        const void *a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        unsigned int a17)
{
  void *result; // x0
  void *v18; // x0
  char *v19; // x1
  size_t v20; // x2
  unsigned int v27; // w20
  const char *v28; // x2
  char *v35; // x23
  __int64 v36; // x21

  if ( !a3 || !a4 )
    return (void *)qdf_trace_msg(
                     0x35u,
                     8u,
                     "%s: no valid additional ie",
                     a9,
                     a10,
                     a11,
                     a12,
                     a13,
                     a14,
                     a15,
                     a16,
                     "lim_add_additional_ie");
  if ( !a17 )
  {
    v18 = (void *)(a1 + a2);
    v19 = a3;
    v20 = a4;
    return qdf_mem_copy(v18, v19, v20);
  }
  if ( a7 >= 0x26 )
    return (void *)qdf_trace_msg(
                     0x35u,
                     2u,
                     "%s: Not able to insert NoA, len=%d",
                     a9,
                     a10,
                     a11,
                     a12,
                     a13,
                     a14,
                     a15,
                     a16,
                     "lim_add_additional_ie",
                     a7);
  if ( a7 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: new p2p ie for noa attr",
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      a16,
      "lim_add_additional_ie");
    qdf_mem_copy((void *)(a1 + a2), a3, a4);
    v19 = a6;
    v20 = a7;
    v18 = (void *)(a1 + a4 + a2);
    return qdf_mem_copy(v18, v19, v20);
  }
  if ( a5 < (unsigned __int64)a3 || (unsigned __int64)&a3[a4] < a5 )
  {
    v28 = "%s: invalid p2p ie";
    return (void *)qdf_trace_msg(0x35u, 2u, v28, a9, a10, a11, a12, a13, a14, a15, a16, "lim_add_additional_ie");
  }
  v27 = (unsigned __int16)(a5 - (_WORD)a3 + *(unsigned __int8 *)(a5 + 1) + 2);
  if ( a4 < v27 )
  {
    v28 = "%s: Invalid p2p ie";
    return (void *)qdf_trace_msg(0x35u, 2u, v28, a9, a10, a11, a12, a13, a14, a15, a16, "lim_add_additional_ie");
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: insert noa attr to existed p2p ie",
    a9,
    a10,
    a11,
    a12,
    a13,
    a14,
    a15,
    a16,
    "lim_add_additional_ie");
  *(_BYTE *)(a5 + 1) += a17;
  v35 = a3;
  qdf_mem_copy((void *)(a1 + a2), a3, v27);
  v36 = v27 + a2;
  result = qdf_mem_copy((void *)(a1 + v36), a8, a17);
  v20 = a4 - v27;
  if ( a4 > v27 )
  {
    v19 = &v35[v27];
    v18 = (void *)(a1 + (unsigned int)v36 + a17);
    return qdf_mem_copy(v18, v19, v20);
  }
  return result;
}
