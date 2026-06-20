__int64 __fastcall init_event_ring(int a1, char a2)
{
  __int64 v4; // x24
  _DWORD *v5; // x0
  __int64 v6; // x0
  __int64 v7; // x23
  __int64 v8; // x24
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x12
  __int64 v12; // x11
  unsigned __int64 v13; // x14
  __int64 v14; // x9
  __int64 v15; // x12
  __int64 v16; // x19
  __int64 v17; // x20
  __int64 result; // x0
  unsigned __int64 *v19; // x8
  unsigned __int64 v20; // x9

  v4 = a1;
  v5 = (_DWORD *)(ev_rings + ((__int64)a1 << 6));
  *v5 = 0;
  _init_swait_queue_head(v5 + 2, "&x->wait", &init_completion___key);
  if ( (a2 & 1) == 0 )
  {
    v6 = _alloc_pages_noprof(3520, 0, 0, 0);
    if ( !v6 )
      return 4294967284LL;
    *(_QWORD *)(ev_rings + (v4 << 6) + 32) = ((v6 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL
                                           | 0xFF00000000000000LL;
  }
  v7 = a1 << 12;
  writel(1u, (unsigned int *)(qpace_er_regs + v7 + 32));
  v8 = v4 << 6;
  v9 = ev_rings + v8;
  v10 = *(_QWORD *)(ev_rings + v8 + 32);
  v11 = v10 << 8 >> 8;
  *(_QWORD *)(v9 + 40) = v10 + 4064;
  *(_QWORD *)(v9 + 48) = v10;
  v12 = ((v10 << 8) + 0x100000) >> 8;
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
  writel(HIDWORD(v16), (unsigned int *)(qpace_er_regs + v7 + 4));
  writel(v16, (unsigned int *)(qpace_er_regs + v7));
  writel(v17, (unsigned int *)(qpace_er_regs + v7 + 8));
  writel(HIDWORD(v17), (unsigned int *)(qpace_er_regs + v7 + 12));
  writel(HIDWORD(v17), (unsigned int *)(qpace_er_regs + v7 + 28));
  writel(v17 - 32, (unsigned int *)(qpace_er_regs + v7 + 24));
  result = 0;
  v19 = (unsigned __int64 *)(ev_rings + v8 + 32);
  v20 = *v19;
  *(_BYTE *)(ev_rings + v8 + 56) = 0;
  if ( v20 < v20 + 4096 )
  {
    do
    {
      *(_QWORD *)(v20 + 16) |= 0x40000000uLL;
      v20 += 32LL;
    }
    while ( v20 < *v19 + 4096 );
    return 0;
  }
  return result;
}
