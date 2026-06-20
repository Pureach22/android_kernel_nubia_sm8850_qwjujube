__int64 __fastcall init_transfer_ring(int a1, char a2)
{
  __int64 v3; // x10
  __int64 v4; // x23
  __int64 v5; // x0
  __int64 i; // x9
  __int64 v7; // x22
  __int64 *v8; // x8
  __int64 v9; // x9
  __int64 v10; // x11
  __int64 v11; // x12
  __int64 v12; // x11
  unsigned __int64 v13; // x14
  __int64 v14; // x9
  __int64 v15; // x12
  __int64 v16; // x19
  __int64 v17; // x20

  if ( (a2 & 1) != 0 )
  {
    v3 = tr_rings;
    v4 = a1;
  }
  else
  {
    v5 = _alloc_pages_noprof(3520, 0, 0, 0);
    if ( !v5 )
      return 4294967284LL;
    v3 = tr_rings;
    v4 = a1;
    *(_QWORD *)(tr_rings + 32LL * a1) = ((v5 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL;
  }
  for ( i = 28; i != 4124; i += 32 )
    *(_DWORD *)(*(_QWORD *)(v3 + 32 * v4) + i) |= 0x80000u;
  v7 = a1 << 12;
  writel(0, (unsigned int *)(qpace_tr_regs + v7 + 32));
  v8 = (__int64 *)(tr_rings + 32 * v4);
  v9 = *v8;
  v10 = *v8 << 8;
  v11 = v10 >> 8;
  v8[1] = *v8 + 4064;
  v8[2] = v9;
  v12 = (v10 + 0x100000) >> 8;
  v13 = (unsigned __int64)(v11 + 0x8000000000LL) >> 38;
  v14 = v11 + 0x8000000000LL + memstart_addr;
  v15 = v11 - kimage_voffset;
  if ( v13 )
    v16 = v15;
  else
    v16 = v14;
  if ( (unsigned __int64)(v12 + 0x8000000000LL) >> 38 )
    v17 = v12 - kimage_voffset;
  else
    v17 = v12 + 0x8000000000LL + memstart_addr;
  writel(HIDWORD(v16), (unsigned int *)(qpace_tr_regs + v7 + 4));
  writel(v16, (unsigned int *)(qpace_tr_regs + v7));
  writel(HIDWORD(v17), (unsigned int *)(qpace_tr_regs + v7 + 12));
  writel(v17, (unsigned int *)(qpace_tr_regs + v7 + 8));
  return 0;
}
