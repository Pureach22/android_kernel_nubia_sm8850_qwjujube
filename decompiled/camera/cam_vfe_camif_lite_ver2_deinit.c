__int64 __fastcall cam_vfe_camif_lite_ver2_deinit(_QWORD *a1)
{
  _QWORD *v2; // x0
  __int64 v3; // x10
  _QWORD *v4; // x9
  int v5; // w9

  v2 = (_QWORD *)a1[3];
  if ( v2 )
  {
    v3 = 256;
    v2[2827] = v2 + 2827;
    v2[2828] = v2 + 2827;
    v4 = v2 + 11;
    do
    {
      *v4 = v4;
      --v3;
      v4[1] = v4;
      v4 += 11;
    }
    while ( v3 );
    a1[3] = 0;
    v5 = (unsigned __int8)mem_trace_en;
    a1[11] = 0;
    a1[12] = 0;
    a1[13] = 0;
    a1[14] = 0;
    a1[15] = 0;
    if ( v5 == 1 )
      cam_mem_trace_free(v2, 0);
    else
      kvfree(v2);
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      2,
      "cam_vfe_camif_lite_ver2_deinit",
      577,
      "Error! camif_priv is NULL");
    return 4294967277LL;
  }
}
