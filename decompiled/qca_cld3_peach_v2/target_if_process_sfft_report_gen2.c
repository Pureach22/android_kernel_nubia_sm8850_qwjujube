__int64 __fastcall target_if_process_sfft_report_gen2(
        unsigned __int8 *a1,
        int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int8 *v11; // x19
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x22
  unsigned int v23; // t1
  unsigned int v25; // w8
  unsigned int v26; // w9
  int v27; // w12
  int v28; // w11
  int v29; // w13
  __int64 v30; // [xsp+0h] [xbp-10h] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v11 = a1;
  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  if ( a2 > 7 )
  {
    qdf_mem_copy((char *)&v30 + 4, a1 + 4, 4u);
    result = (__int64)qdf_mem_copy(&v30, v11 + 8, 4u);
    if ( a3 )
    {
      v25 = v30;
      v26 = HIDWORD(v30);
      v27 = (unsigned __int8)v30;
      v28 = (HIDWORD(v30) >> 14) & 0x1FF;
      v29 = (HIDWORD(v30) >> 12) & 3;
      *(_DWORD *)a3 = (unsigned int)v30 >> 26;
      *(_DWORD *)(a3 + 4) = v27;
      *(_DWORD *)(a3 + 8) = v28;
      *(_DWORD *)(a3 + 12) = v26 >> 23;
      *(_DWORD *)(a3 + 16) = v29;
      *(_DWORD *)(a3 + 20) = (unsigned __int8)(v25 >> 18);
      *(_WORD *)(a3 + 28) = ((__int16)(16 * v26) >> 15) & 0xF000 | v26 & 0xFFF;
      *(_DWORD *)(a3 + 24) = (v25 >> 8) & 0x3FF;
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x56u,
               2u,
               "%s: Unexpected TLV length %d for Spectral Summary Report! Hexdump follows",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "target_if_process_sfft_report_gen2",
               (unsigned int)a2);
    if ( a2 >= -3 )
    {
      v22 = (unsigned int)(a2 + 4);
      do
      {
        v23 = *v11++;
        result = qdf_trace_msg(
                   0x56u,
                   8u,
                   "%s: %02X ",
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   "target_if_print_buf",
                   v23,
                   v30,
                   v31);
        --v22;
      }
      while ( v22 );
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
