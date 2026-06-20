__int64 __fastcall extract_unit_test_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        _DWORD *a11,
        unsigned int a12)
{
  unsigned int *v12; // x8
  const void *v13; // x20
  unsigned int v14; // w21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  v12 = *(unsigned int **)a10;
  v13 = *(const void **)(a10 + 16);
  v14 = *(_DWORD *)(a10 + 24);
  *a11 = *(_DWORD *)(*(_QWORD *)a10 + 4LL);
  a11[1] = v12[2];
  a11[2] = v12[3];
  a11[3] = v12[4];
  a11[4] = v12[5];
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev_id:%d mod_id:%d diag_token:%d flag:%d",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "extract_unit_test_tlv",
    v12[1],
    v12[2],
    v12[3],
    v12[4]);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Unit-test data given below %d",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "extract_unit_test_tlv",
    v14);
  ((void (__fastcall *)(__int64, __int64, const void *, _QWORD))qdf_trace_hex_dump)(49, 8, v13, v14);
  if ( v14 >= a12 )
    v14 = a12;
  qdf_mem_copy(a11 + 6, v13, v14);
  a11[5] = v14;
  return 0;
}
