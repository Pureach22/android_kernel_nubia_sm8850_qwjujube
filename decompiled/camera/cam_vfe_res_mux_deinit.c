__int64 __fastcall cam_vfe_res_mux_deinit(_QWORD *a1)
{
  _QWORD *v2; // x0
  __int64 v3; // x9
  _QWORD *v4; // x8

  if ( a1 )
  {
    v2 = (_QWORD *)a1[3];
    a1[3] = 0;
    a1[9] = 0;
    a1[10] = 0;
    a1[11] = 0;
    a1[12] = 0;
    a1[13] = 0;
    a1[14] = 0;
    a1[15] = 0;
    if ( v2 )
    {
      v3 = 256;
      v2[2831] = v2 + 2831;
      v2[2832] = v2 + 2831;
      v4 = v2 + 15;
      do
      {
        *v4 = v4;
        --v3;
        v4[1] = v4;
        v4 += 11;
      }
      while ( v3 );
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v2, 0);
      else
        kvfree(v2);
      return 0;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_res_mux_deinit",
        2996,
        "VFE:%u vfe_priv is NULL %pK",
        *(_DWORD *)(a1[2] + 4LL),
        nullptr);
      return 4294967277LL;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_res_mux_deinit",
      2980,
      "Error, VFE Node Resource is NULL %pK",
      nullptr);
    return 4294967277LL;
  }
}
