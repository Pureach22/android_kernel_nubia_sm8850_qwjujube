__int64 __fastcall ll_lt_sap_bs_decreament_ref_count(
        unsigned int *a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x7
  __int64 v11; // x8
  int v13; // t1
  unsigned int v17; // w8
  unsigned int v18; // w8
  unsigned int v25; // w7
  unsigned int v27; // w7

  v10 = *((unsigned int *)a2 + 3);
  if ( (_DWORD)v10 != 2 )
  {
    if ( (unsigned int)v10 > 6 || *a2 >= 6u )
    {
      __break(0x5512u);
      goto LABEL_12;
    }
    v11 = (__int64)&a1[6 * *a2 + v10];
    v13 = *(_DWORD *)(v11 + 96);
    _X8 = (unsigned int *)(v11 + 96);
    if ( v13 )
    {
      __asm { PRFM            #0x11, [X8] }
      do
        v27 = __ldxr(_X8);
      while ( __stlxr(v27 - 1, _X8) );
      goto LABEL_16;
    }
    qdf_trace_msg(
      0xA1u,
      8u,
      "%s: BS_SM_%d req_id 0x%x: vdev %d src %d count is zero",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "ll_lt_sap_bs_decreament_ref_count",
      *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL),
      *((unsigned int *)a2 + 1));
    return 4;
  }
  if ( !a1[60] )
  {
    qdf_trace_msg(
      0xA1u,
      8u,
      "%s: BS_SM_%d req_id 0x%x: ref_count is zero for FW",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "ll_lt_sap_bs_decreament_ref_count",
      *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL),
      *((unsigned int *)a2 + 1));
    return 4;
  }
  _X8 = a1 + 60;
  __asm { PRFM            #0x11, [X8] }
  do
    v25 = __ldxr(_X8);
  while ( __stlxr(v25 - 1, _X8) );
LABEL_16:
  __dmb(0xBu);
LABEL_12:
  _X9 = a1 + 61;
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v17 = __ldxr(_X9);
    v18 = v17 - 1;
  }
  while ( __stlxr(v18, _X9) );
  __dmb(0xBu);
  qdf_trace_msg(
    0xA1u,
    8u,
    "BS_SM_%d req_id 0x%x: vdev %d src %d count %d Total req count %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL),
    *((unsigned int *)a2 + 1),
    *a2,
    *((unsigned int *)a2 + 3),
    v18);
  return 0;
}
