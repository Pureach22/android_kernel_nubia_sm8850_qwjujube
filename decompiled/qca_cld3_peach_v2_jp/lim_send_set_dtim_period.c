_BYTE *__fastcall lim_send_set_dtim_period(
        __int64 a1,
        char a2,
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
  _BYTE *result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x19
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // [xsp+8h] [xbp-38h] BYREF
  _BYTE *v33; // [xsp+10h] [xbp-30h]
  __int64 v34; // [xsp+18h] [xbp-28h]
  __int64 v35; // [xsp+20h] [xbp-20h]
  __int64 v36; // [xsp+28h] [xbp-18h]
  __int64 v37; // [xsp+30h] [xbp-10h]
  __int64 v38; // [xsp+38h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = nullptr;
  if ( a3 )
  {
    result = (_BYTE *)_qdf_mem_malloc(2u, "lim_send_set_dtim_period", 6935);
    if ( result )
    {
      result[1] = a2;
      v23 = (__int64)result;
      *result = *(_BYTE *)(a3 + 10);
      v33 = result;
      LOWORD(v32) = 4491;
      HIDWORD(v32) = 0;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Post WMA_SET_DTIM_PERIOD to WMA",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "lim_send_set_dtim_period");
      result = (_BYTE *)wma_post_ctrl_msg(a1, &v32);
      if ( (_DWORD)result )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: wma_post_ctrl_msg() failed",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "lim_send_set_dtim_period");
        result = (_BYTE *)_qdf_mem_free(v23);
      }
    }
  }
  else
  {
    result = (_BYTE *)qdf_trace_msg(
                        0x35u,
                        2u,
                        "%s: Inavalid parameters",
                        a4,
                        a5,
                        a6,
                        a7,
                        a8,
                        a9,
                        a10,
                        a11,
                        "lim_send_set_dtim_period");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
