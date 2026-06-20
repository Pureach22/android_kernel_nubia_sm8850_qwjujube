__int64 __fastcall cam_vfe_camif_ver3_deinit(_QWORD *a1)
{
  _QWORD *v1; // x8
  _QWORD *v2; // x8
  __int64 v3; // x9
  _QWORD *v4; // x8
  const char *v5; // x5
  __int64 v6; // x4

  if ( !a1 )
  {
    v5 = "Error, camif_node is NULL %pK";
    v6 = 1582;
LABEL_9:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_ver3_deinit",
      v6,
      v5,
      0);
    return 4294967277LL;
  }
  v1 = (_QWORD *)a1[3];
  v1[2833] = v1 + 2833;
  v1[2834] = v1 + 2833;
  v2 = v1 + 17;
  v3 = 256;
  do
  {
    *v2 = v2;
    --v3;
    v2[1] = v2;
    v2 += 11;
  }
  while ( v3 );
  v4 = (_QWORD *)a1[3];
  a1[3] = 0;
  a1[11] = 0;
  a1[12] = 0;
  a1[13] = 0;
  a1[14] = 0;
  a1[15] = 0;
  if ( !v4 )
  {
    v5 = "Error, camif_priv is NULL %pK";
    v6 = 1602;
    goto LABEL_9;
  }
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v4, 0);
  else
    kvfree(v4);
  return 0;
}
