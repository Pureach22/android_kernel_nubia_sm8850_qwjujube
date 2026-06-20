__int64 __fastcall hdd_enable_disable_apf(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x20
  __int64 v12; // x0
  char v13; // w19
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v10 = *(_QWORD *)(a1 + 24);
  v11 = a1 + 49152;
  if ( v10 )
    v12 = *(_QWORD *)(v10 + 16);
  else
    v12 = 0;
  v13 = a2 & 1;
  result = sme_set_apf_enable_disable(
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             v12,
             *(unsigned __int8 *)(*(_QWORD *)(v11 + 3672) + 8LL),
             a2 & 1);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Unable to post sme apf enable/disable message (status-%d)",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "hdd_enable_disable_apf",
      (unsigned int)result);
    return 4294967274LL;
  }
  else
  {
    *(_BYTE *)(v11 + 3112) = v13;
  }
  return result;
}
