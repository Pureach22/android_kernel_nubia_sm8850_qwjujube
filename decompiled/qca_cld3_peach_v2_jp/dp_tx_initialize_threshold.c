__int64 __fastcall dp_tx_initialize_threshold(
        _WORD *a1,
        int a2,
        int a3,
        unsigned __int16 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v12; // w8
  unsigned int v13; // w9
  int v14; // w10
  int v15; // w11
  int v16; // w12
  int v17; // w13
  int v18; // w14
  int v19; // w15

  v12 = a4 * a2;
  v13 = a4 * a3;
  v14 = (unsigned __int16)(v12 / 0x64);
  v15 = (unsigned __int16)(v13 / 0x64);
  v16 = 4 * v14;
  v17 = v14 << 6;
  a1[40] = v12 / 0x64;
  v18 = 4 * v15;
  v19 = v15 << 6;
  a1[36] = v13 / 0x64;
  v14 *= 5;
  v15 *= 5;
  a1[38] = (42949673 * (unsigned __int64)(unsigned int)(v19 - v18)) >> 32;
  a1[42] = (42949673 * (unsigned __int64)(unsigned int)(v17 - v16)) >> 32;
  a1[41] = (42949673 * (unsigned __int64)(unsigned int)(16 * v14)) >> 32;
  a1[37] = (42949673 * (unsigned __int64)(unsigned int)(16 * v15)) >> 32;
  a1[43] = (42949673 * (unsigned __int64)(unsigned int)(8 * v14)) >> 32;
  a1[39] = (42949673 * (unsigned __int64)(unsigned int)(8 * v15)) >> 32;
  return qdf_trace_msg(
           0x45u,
           8u,
           "%s: tx flow control threshold is set, pool size is %d",
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           "dp_tx_initialize_threshold");
}
