__int64 __fastcall sub_8600(
        long double _Q0,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6)
{
  __asm { SDOT            V6.8H, V31.16B, V0.4B[2] }
  return mem_buf_alloc_resp_hdlr(_Q0, a2, a3, a4, a5, a6, _Q6);
}
