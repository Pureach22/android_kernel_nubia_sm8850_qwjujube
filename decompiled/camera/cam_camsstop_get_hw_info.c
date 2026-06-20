__int64 __fastcall cam_camsstop_get_hw_info(
        __int64 a1,
        _DWORD *a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6,
        float a7,
        double a8,
        __n128 a9)
{
  short float v9; // h15
  short float v10; // h16
  unsigned int v11; // w8
  unsigned int v13; // w8
  __int64 result; // x0
  int v15; // w9

  v11 = *(_DWORD *)(*(_QWORD *)(a1 + 3680) + 2820LL);
  if ( v11 == -1 )
    return 4294967274LL;
  *a2 = 1;
  if ( v11 > 7 )
  {
    __break(0x5512u);
    *(short float *)&a7 = -(short float)(v10 - (short float)(v9 * *(short float *)a9.n128_u16));
    return cam_camsstop_setup_regbase_indices(a3, a4, a5, a6, a7);
  }
  else
  {
    v13 = cam_io_r_mb(*(_QWORD *)(a1 + 24LL * v11 + 384));
    result = 0;
    v15 = HIWORD(v13) & 0xFFF;
    a2[3] = (unsigned __int16)v13;
    a2[1] = v13 >> 28;
    a2[2] = v15;
    if ( (debug_mdl & 0x400) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x400,
        4,
        "cam_camsstop_get_hw_info",
        34,
        "Family %d, version %d.%d.%d",
        *a2,
        v13 >> 28,
        v15,
        (unsigned __int16)v13);
      return 0;
    }
  }
  return result;
}
