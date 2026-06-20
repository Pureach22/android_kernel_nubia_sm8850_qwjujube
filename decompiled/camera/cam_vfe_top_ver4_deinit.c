__int64 __fastcall cam_vfe_top_ver4_deinit(_QWORD **a1)
{
  _QWORD *v1; // x20
  _QWORD *v2; // x19
  _DWORD *v3; // x27
  unsigned __int64 v4; // x22
  _DWORD *v5; // x24
  unsigned int v6; // w21
  _QWORD *v7; // x0

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver4_deinit",
      3230,
      "Error, Invalid input");
    return (unsigned int)-22;
  }
  v1 = *a1;
  v2 = a1;
  if ( !*a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver4_deinit",
      3236,
      "Error, vfe_top NULL");
    return (unsigned int)-19;
  }
  v3 = (_DWORD *)*v1;
  if ( !*v1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver4_deinit",
      3242,
      "Error, vfe_top_priv NULL");
    v6 = -19;
LABEL_17:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v1, 0);
    else
      kvfree(v1);
    *v2 = 0;
    return v6;
  }
  if ( !v3[272] )
  {
    v6 = 0;
LABEL_14:
    v7 = (_QWORD *)*v1;
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v7, 0);
    else
      kvfree(v7);
    goto LABEL_17;
  }
  v4 = 0;
  v5 = v3 + 6;
  while ( v4 != 7 )
  {
    v5[2] = 0;
    a1 = (_QWORD **)cam_vfe_res_mux_deinit(v5);
    v6 = (unsigned int)a1;
    if ( (_DWORD)a1 )
      a1 = (_QWORD **)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        8,
                        1,
                        "cam_vfe_top_ver4_deinit",
                        3253,
                        "VFE:%u Mux[%d] deinit failed rc=%d",
                        *(_DWORD *)(*(_QWORD *)v3 + 4LL),
                        v4,
                        (_DWORD)a1);
    ++v4;
    v5 += 38;
    if ( v4 >= (unsigned int)v3[272] )
      goto LABEL_14;
  }
  __break(0x5512u);
  return cam_vfe_top_ver4_print_debug_regs(a1);
}
