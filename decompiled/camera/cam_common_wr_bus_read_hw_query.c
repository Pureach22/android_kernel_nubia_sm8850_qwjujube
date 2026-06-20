__int64 __fastcall cam_common_wr_bus_read_hw_query(__int64 a1, unsigned int *a2, unsigned int *a3)
{
  unsigned int v6; // w8
  _DWORD *v7; // x23
  unsigned int v8; // w22
  unsigned int v9; // w0
  int v10; // w22
  _DWORD *v11; // x23
  unsigned int v12; // w0
  unsigned int v13; // w8
  unsigned int v14; // w9
  unsigned int v15; // w22
  _DWORD *v16; // x21
  int v17; // w22

  if ( a1 && a2 && a3 )
  {
    cam_io_w(*a2, a1 + a2[3]);
    cam_io_w(0, a1 + a2[1]);
    *a3 = cam_io_r(a1 + a2[2]);
    a3[1] = cam_io_r(a1 + a2[2]);
    cam_io_w(3, a1 + a2[1]);
    a3[3] = cam_io_r(a1 + a2[2]);
    cam_io_w(38, a1 + a2[1]);
    v6 = a3[3];
    if ( v6 )
    {
      v7 = a3 + 38;
      v8 = 64 - 2 * __clz(v6);
      do
      {
        --v8;
        *v7++ = cam_io_r(a1 + a2[2]);
      }
      while ( v8 );
    }
    v9 = cam_io_r(a1 + a2[2]);
    v10 = 2 * v9;
    a3[70] = v9;
    if ( 2 * v9 )
    {
      v11 = a3 + 71;
      do
      {
        --v10;
        *v11++ = cam_io_r(a1 + a2[2]);
      }
      while ( v10 );
    }
    a3[87] = cam_io_r(a1 + a2[2]);
    cam_io_w(91, a1 + a2[1]);
    a3[91] = cam_io_r(a1 + a2[2]);
    v12 = cam_io_r(a1 + a2[2]);
    v13 = *a3;
    v14 = a3[1];
    a3[92] = v12;
    v15 = __clz(v14) + __clz(v13);
    cam_io_w(101, a1 + a2[1]);
    if ( v15 != 64 )
    {
      v16 = a3 + 101;
      v17 = 7 * (64 - v15);
      do
      {
        --v17;
        *v16++ = cam_io_r(a1 + a2[2]);
      }
      while ( v17 );
    }
    return 0;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_common_wr_bus_read_hw_query",
      947,
      "Invalid args, base:0x%lx lut:0x%lx query_ptr:0x%lx",
      a1,
      a2,
      a3);
    return 4294967274LL;
  }
}
