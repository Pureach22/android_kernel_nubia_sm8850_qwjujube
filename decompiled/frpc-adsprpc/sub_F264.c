__int64 __fastcall sub_F264(
        long double a1,
        long double a2,
        float a3,
        double a4,
        double a5,
        double a6,
        double a7,
        __n128 a8)
{
  short float v8; // h23
  short float v9; // h24

  *(short float *)&a3 = -(short float)(v8 - (short float)(v9 * *(short float *)a8.n128_u16));
  return _dma_buf_unmap_attachment_wrap(a1, a2, a3);
}
