__int64 __fastcall dsi_phy_hw_v4_0_dyn_refresh_config(_QWORD *a1, __int64 a2, char a3)
{
  int v5; // w21
  _QWORD *v6; // x19
  unsigned int v7; // w0
  __int64 v8; // x8
  int v9; // w0
  __int64 v10; // t1
  unsigned int v11; // w20
  __int64 result; // x0

  v5 = *(_DWORD *)(a2 + 340) & 0xF | 0x10;
  if ( (a3 & 1) != 0 )
  {
    v6 = a1 + 2;
    writel_relaxed_10(
      (*(unsigned __int8 *)(a2 + 196) << 8) | (*(unsigned __int8 *)(a2 + 197) << 24) | 0x2E002D,
      (unsigned int *)(a1[2] + 96LL));
    writel_relaxed_10(
      (*(unsigned __int8 *)(a2 + 198) << 8) | (*(unsigned __int8 *)(a2 + 199) << 24) | 0x30002F,
      (unsigned int *)(*v6 + 100LL));
    writel_relaxed_10(
      (*(unsigned __int8 *)(a2 + 200) << 8) | (*(unsigned __int8 *)(a2 + 201) << 24) | 0x320031,
      (unsigned int *)(*v6 + 104LL));
    writel_relaxed_10(
      (*(unsigned __int8 *)(a2 + 202) << 8) | (*(unsigned __int8 *)(a2 + 203) << 24) | 0x340033,
      (unsigned int *)(*v6 + 108LL));
    writel_relaxed_10(
      (*(unsigned __int8 *)(a2 + 204) << 8) | (*(unsigned __int8 *)(a2 + 205) << 24) | 0x360035,
      (unsigned int *)(*v6 + 112LL));
    writel_relaxed_10(
      (*(unsigned __int8 *)(a2 + 206) << 8) | (*(unsigned __int8 *)(a2 + 207) << 24) | 0x380037,
      (unsigned int *)(*v6 + 116LL));
    writel_relaxed_10(
      (*(unsigned __int8 *)(a2 + 208) << 8) | (*(unsigned __int8 *)(a2 + 209) << 24) | 0x3A0039,
      (unsigned int *)(*v6 + 120LL));
    v7 = (v5 << 24) | 0x287F09;
    v8 = 124;
  }
  else
  {
    v9 = readl_relaxed_13((unsigned int *)(*a1 + 20LL));
    v10 = a1[2];
    v6 = a1 + 2;
    writel_relaxed_10((v9 << 8) & 0xFFF0DFFA | 0xF0005, (unsigned int *)(v10 + 20));
    writel_relaxed_10((*(unsigned __int8 *)(a2 + 196) << 24) | 0x2D0007, (unsigned int *)(*v6 + 24LL));
    writel_relaxed_10(
      (*(unsigned __int8 *)(a2 + 197) << 8) | (*(unsigned __int8 *)(a2 + 198) << 24) | 0x2F002E,
      (unsigned int *)(*v6 + 28LL));
    writel_relaxed_10(
      (*(unsigned __int8 *)(a2 + 199) << 8) | (*(unsigned __int8 *)(a2 + 200) << 24) | 0x310030,
      (unsigned int *)(*v6 + 32LL));
    writel_relaxed_10(
      (*(unsigned __int8 *)(a2 + 201) << 8) | (*(unsigned __int8 *)(a2 + 202) << 24) | 0x330032,
      (unsigned int *)(*v6 + 36LL));
    writel_relaxed_10(
      (*(unsigned __int8 *)(a2 + 203) << 8) | (*(unsigned __int8 *)(a2 + 204) << 24) | 0x350034,
      (unsigned int *)(*v6 + 40LL));
    writel_relaxed_10(
      (*(unsigned __int8 *)(a2 + 205) << 8) | (*(unsigned __int8 *)(a2 + 206) << 24) | 0x370036,
      (unsigned int *)(*v6 + 44LL));
    writel_relaxed_10(
      (*(unsigned __int8 *)(a2 + 207) << 8) | (*(unsigned __int8 *)(a2 + 208) << 24) | 0x390038,
      (unsigned int *)(*v6 + 48LL));
    writel_relaxed_10((*(unsigned __int8 *)(a2 + 209) << 8) | 0x7F09003A, (unsigned int *)(*v6 + 52LL));
    writel_relaxed_10(((v5 & 0x1F) << 8) | 0x400B0028, (unsigned int *)(*v6 + 56LL));
    v11 = (v5 << 8) | 0x7F090028;
    writel_relaxed_10(v11, (unsigned int *)(*v6 + 64LL));
    writel_relaxed_10(v11, (unsigned int *)(*v6 + 68LL));
    writel_relaxed_10(v11, (unsigned int *)(*v6 + 72LL));
    writel_relaxed_10(v11, (unsigned int *)(*v6 + 76LL));
    writel_relaxed_10(v11, (unsigned int *)(*v6 + 80LL));
    writel_relaxed_10(v11, (unsigned int *)(*v6 + 84LL));
    writel_relaxed_10(v11, (unsigned int *)(*v6 + 88LL));
    writel_relaxed_10(v11, (unsigned int *)(*v6 + 92LL));
    writel_relaxed_10(v11, (unsigned int *)(*v6 + 96LL));
    writel_relaxed_10(v11, (unsigned int *)(*v6 + 100LL));
    writel_relaxed_10(v11, (unsigned int *)(*v6 + 104LL));
    writel_relaxed_10(v11, (unsigned int *)(*v6 + 108LL));
    writel_relaxed_10(v11, (unsigned int *)(*v6 + 112LL));
    writel_relaxed_10(v11, (unsigned int *)(*v6 + 116LL));
    writel_relaxed_10(v11, (unsigned int *)(*v6 + 120LL));
    writel_relaxed_10(v11, (unsigned int *)(*v6 + 124LL));
    writel_relaxed_10(v11, (unsigned int *)(*v6 + 128LL));
    writel_relaxed_10(v11, (unsigned int *)(*v6 + 132LL));
    writel_relaxed_10(v11, (unsigned int *)(*v6 + 136LL));
    writel_relaxed_10(0, (unsigned int *)(*v6 + 148LL));
    v7 = 0;
    v8 = 152;
  }
  result = writel_relaxed_10(v7, (unsigned int *)(*v6 + v8));
  __dsb(0xEu);
  return result;
}
