__int64 __fastcall adsp_add_coredump_segments(_QWORD *a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 result; // x0
  _QWORD *i; // x8

  v2 = a1[2];
  rproc_coredump_cleanup(v2);
  result = qcom_register_dump_segments(v2, a2);
  if ( (result & 0x80000000) != 0 )
    return rproc_coredump_cleanup(a1[2]);
  for ( i = *(_QWORD **)(v2 + 1256); i != (_QWORD *)(v2 + 1256); i = (_QWORD *)*i )
    i[2] = i[2] + a1[79] - a1[81];
  return result;
}
