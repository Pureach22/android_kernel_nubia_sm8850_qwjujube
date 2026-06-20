void __fastcall sub_CA38(
        int a1,
        int a2,
        const char *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 arg,
        __int64 *a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 *p_arg,
        __int64 a22,
        __int64 a23,
        char a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39,
        __int64 a40,
        __int64 a41,
        __int64 a42,
        __int64 a43,
        __int64 a44,
        __int64 a45,
        __int64 a46,
        __int64 a47,
        __int64 a48,
        __int64 a49,
        __int64 a50,
        __int64 a51,
        __int64 a52,
        __int64 a53,
        __int64 a54,
        __int64 a55,
        __int64 s,
        __int64 a57,
        __int64 a58,
        __int64 a59,
        __int64 a60,
        __int64 a61,
        __int64 a62,
        __int64 a63)
{
  __int64 a70; // [xsp+1F8h] [xbp+1F8h]
  __int64 v70; // x29
  __int64 v71; // x11
  int v72; // w0
  int v73; // w0

  v71 = a22;
  STACK[0x270] = 0x2020202020202020LL;
  STACK[0x268] = 0x2020202020202020LL;
  STACK[0x260] = 0x2020202020202020LL;
  STACK[0x258] = 0x2020202020202020LL;
  STACK[0x250] = 0x2020202020202020LL;
  STACK[0x248] = 0x2020202020202020LL;
  STACK[0x240] = 0x2020202020202020LL;
  STACK[0x238] = 0x2020202020202020LL;
  STACK[0x230] = 0x2020202020202020LL;
  STACK[0x228] = 0x2020202020202020LL;
  STACK[0x220] = 0x2020202020202020LL;
  STACK[0x218] = 0x2020202020202020LL;
  STACK[0x210] = 0x2020202020202020LL;
  STACK[0x208] = 0x2020202020202020LL;
  a70 = 0x2020202020202020LL;
  STACK[0x200] = 0x2020202020202020LL;
  memset(&s, 32, 128);
  a23 = 4294967256LL;
  a20 = v70 + 48;
  p_arg = &arg;
  arg = v70 + 48;
  a17 = &arg;
  a18 = v71;
  a19 = 4294967256LL;
  v72 = vsnprintf((char *)&s, 0x100u, a3, &arg);
  if ( (v72 & 0x80000000) == 0 )
  {
    if ( v72 == 256 )
      LOBYTE(STACK[0x277]) = 0;
    v73 = snprintf(&a24, 0x100u, "C|%d|%s|%d\n", a1, (const char *)&s, a2);
    if ( (v73 & 0x80000000) == 0 && v73 == 256 )
      HIBYTE(a55) = 0;
  }
  JUMPOUT(0xCA08);
}
