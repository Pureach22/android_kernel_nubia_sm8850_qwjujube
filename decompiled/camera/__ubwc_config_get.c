__int64 __fastcall _ubwc_config_get(const void *a1, const char *a2, __int64 a3, _BYTE *a4)
{
  unsigned int v8; // w0
  unsigned int v9; // w23
  __int64 result; // x0
  unsigned int u32_index; // w0
  unsigned int v12; // w21
  int v13; // w22
  __int64 v14; // x3

  v8 = of_property_count_elems_of_size(a1, a2, 4);
  if ( (v8 & 0x80000000) != 0 )
  {
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "__ubwc_config_get",
        22,
        "prop: %s is not listed",
        a2);
    *a4 = 0;
    return 0;
  }
  else
  {
    v9 = v8;
    *a4 = 1;
    if ( v8 > 2 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "__ubwc_config_get",
        30,
        "Invalid number of UBWC configs[=%d] MAX UBWC=%d",
        v8,
        2);
      return 4294967274LL;
    }
    if ( !v8 )
      return 0;
    u32_index = of_property_read_u32_index(a1, a2, 0, a3);
    if ( u32_index )
    {
      v12 = u32_index;
      v13 = 0;
LABEL_11:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "__ubwc_config_get",
        39,
        "Node %pOF has no valid %s prop at index=%d",
        a1,
        a2,
        v13);
      return v12;
    }
    if ( v9 != 1 )
    {
      v14 = a3 + 4;
      v13 = 1;
      result = of_property_read_u32_index(a1, a2, 1, v14);
      if ( (_DWORD)result )
      {
        v12 = result;
        goto LABEL_11;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}
