__int64 __fastcall dsi_phy_hw_v3_0_dyn_refresh_config(_QWORD *a1, unsigned __int8 *a2, char a3)
{
  _QWORD *v5; // x19
  int v6; // w8
  int v7; // w9
  unsigned int v8; // w20
  __int64 v9; // x21
  unsigned int v10; // w0
  __int64 v11; // x8
  int v12; // w0
  __int64 v13; // t1
  __int64 result; // x0

  if ( (a3 & 1) != 0 )
  {
    v5 = a1 + 2;
    writel_relaxed_9(0x59081006u, (unsigned int *)(a1[2] + 56LL));
    writel_relaxed_9((a2[184] << 8) | (a2[185] << 24) | 0x2C002B, (unsigned int *)(*v5 + 60LL));
    writel_relaxed_9((a2[186] << 8) | (a2[187] << 24) | 0x2E002D, (unsigned int *)(*v5 + 64LL));
    writel_relaxed_9((a2[188] << 8) | (a2[189] << 24) | 0x30002F, (unsigned int *)(*v5 + 68LL));
    writel_relaxed_9((a2[190] << 8) | (a2[191] << 24) | 0x320031, (unsigned int *)(*v5 + 72LL));
    writel_relaxed_9((a2[192] << 8) | (a2[193] << 24) | 0x340033, (unsigned int *)(*v5 + 76LL));
    v6 = a2[194];
    v7 = a2[195];
    v8 = 522616585;
    v9 = 84;
    v10 = (v6 << 8) | (v7 << 24) | 0x360035;
    v11 = 80;
  }
  else
  {
    v12 = readl_relaxed_12((unsigned int *)(*a1 + 16LL));
    v13 = a1[2];
    v5 = a1 + 2;
    writel_relaxed_9((v12 << 8) & 0xFFF1DFFB | 0xE0004, (unsigned int *)(v13 + 20));
    writel_relaxed_9(0x10060007u, (unsigned int *)(*v5 + 24LL));
    writel_relaxed_9((a2[184] << 24) | 0x2B5908, (unsigned int *)(*v5 + 28LL));
    writel_relaxed_9((a2[185] << 8) | (a2[186] << 24) | 0x2D002C, (unsigned int *)(*v5 + 32LL));
    writel_relaxed_9((a2[187] << 8) | (a2[188] << 24) | 0x2F002E, (unsigned int *)(*v5 + 36LL));
    writel_relaxed_9((a2[189] << 8) | (a2[190] << 24) | 0x310030, (unsigned int *)(*v5 + 40LL));
    writel_relaxed_9((a2[191] << 8) | (a2[192] << 24) | 0x330032, (unsigned int *)(*v5 + 44LL));
    writel_relaxed_9((a2[193] << 8) | (a2[194] << 24) | 0x350034, (unsigned int *)(*v5 + 48LL));
    writel_relaxed_9((a2[195] << 8) | 0x7F090036, (unsigned int *)(*v5 + 52LL));
    writel_relaxed_9(0x400B1F26u, (unsigned int *)(*v5 + 56LL));
    writel_relaxed_9(0x7F091F26u, (unsigned int *)(*v5 + 64LL));
    writel_relaxed_9(0x7F091F26u, (unsigned int *)(*v5 + 68LL));
    writel_relaxed_9(0x7F091F26u, (unsigned int *)(*v5 + 72LL));
    writel_relaxed_9(0x7F091F26u, (unsigned int *)(*v5 + 76LL));
    writel_relaxed_9(0x7F091F26u, (unsigned int *)(*v5 + 80LL));
    writel_relaxed_9(0x7F091F26u, (unsigned int *)(*v5 + 84LL));
    writel_relaxed_9(0x7F091F26u, (unsigned int *)(*v5 + 88LL));
    writel_relaxed_9(0x7F091F26u, (unsigned int *)(*v5 + 92LL));
    writel_relaxed_9(0x7F091F26u, (unsigned int *)(*v5 + 96LL));
    writel_relaxed_9(0x7F091F26u, (unsigned int *)(*v5 + 100LL));
    writel_relaxed_9(0x7F091F26u, (unsigned int *)(*v5 + 104LL));
    writel_relaxed_9(0x7F091F26u, (unsigned int *)(*v5 + 108LL));
    writel_relaxed_9(0x7F091F26u, (unsigned int *)(*v5 + 112LL));
    writel_relaxed_9(0x7F091F26u, (unsigned int *)(*v5 + 116LL));
    writel_relaxed_9(0x7F091F26u, (unsigned int *)(*v5 + 120LL));
    writel_relaxed_9(0x7F091F26u, (unsigned int *)(*v5 + 124LL));
    writel_relaxed_9(0x7F091F26u, (unsigned int *)(*v5 + 128LL));
    writel_relaxed_9(0x7F091F26u, (unsigned int *)(*v5 + 132LL));
    writel_relaxed_9(0x7F091F26u, (unsigned int *)(*v5 + 136LL));
    v10 = 0;
    v8 = 0;
    v9 = 152;
    v11 = 148;
  }
  writel_relaxed_9(v10, (unsigned int *)(*v5 + v11));
  result = writel_relaxed_9(v8, (unsigned int *)(*v5 + v9));
  __dsb(0xEu);
  return result;
}
