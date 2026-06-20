__int64 __fastcall cam_vfe_camif_lite_ver3_deinit(__int64 a1)
{
  __int64 v1; // x8
  _QWORD *v2; // x0
  __int64 v3; // x10
  _QWORD *v4; // x9
  int v5; // w9
  _QWORD *v7; // x19
  __int64 v8; // x20

  v1 = a1;
  v2 = *(_QWORD **)(a1 + 24);
  if ( v2 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v7 = v2;
      v8 = v1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_lite_ver3_deinit",
        1315,
        "VFE:%d CAMIF LITE:%d %s Deinit",
        *(_DWORD *)(*(_QWORD *)(v1 + 16) + 4LL),
        *(_DWORD *)(v1 + 4),
        (const char *)(v1 + 128));
      v1 = v8;
      v2 = v7;
    }
    v3 = 256;
    v2[17] = v2 + 17;
    v2[18] = v2 + 17;
    v4 = v2 + 20;
    do
    {
      *v4 = v4;
      --v3;
      v4[1] = v4;
      v4 += 11;
    }
    while ( v3 );
    *(_QWORD *)(v1 + 24) = 0;
    v5 = (unsigned __int8)mem_trace_en;
    *(_QWORD *)(v1 + 88) = 0;
    *(_QWORD *)(v1 + 96) = 0;
    *(_QWORD *)(v1 + 104) = 0;
    *(_QWORD *)(v1 + 112) = 0;
    *(_QWORD *)(v1 + 120) = 0;
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
      1,
      "cam_vfe_camif_lite_ver3_deinit",
      1309,
      "Error! camif_priv is NULL");
    return 4294967277LL;
  }
}
