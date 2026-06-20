bool __fastcall qpace_trigger_tr(int a1)
{
  _QWORD *v1; // x8
  __int64 v2; // x20
  __int64 v3; // x9
  __int64 v4; // x9
  __int64 v5; // x11
  __int64 v6; // x8
  unsigned __int64 v7; // x9
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x12
  unsigned __int64 v10; // x9
  __int64 v11; // x22
  unsigned __int64 v12; // x19

  v1 = (_QWORD *)(tr_rings + 32LL * a1);
  v2 = v1[3];
  if ( v2 )
  {
    v3 = v1[2];
    if ( v3 == *v1 )
      v4 = *v1 + 4064LL;
    else
      v4 = v3 - 32;
    v5 = kimage_voffset;
    *(_DWORD *)(v4 + 28) &= ~0x80000u;
    v6 = (__int64)(v1[2] << 8) >> 8;
    v7 = v6 + 0x8000000000LL;
    v8 = v6 - v5;
    v9 = v7 >> 38;
    v10 = v7 + memstart_addr;
    v11 = a1 << 12;
    if ( v9 )
      v12 = v8;
    else
      v12 = v10;
    writel(HIDWORD(v12), qpace_tr_regs + (a1 << 12) + 20);
    writel((unsigned int)v12, qpace_tr_regs + v11 + 16);
  }
  return v2 != 0;
}
