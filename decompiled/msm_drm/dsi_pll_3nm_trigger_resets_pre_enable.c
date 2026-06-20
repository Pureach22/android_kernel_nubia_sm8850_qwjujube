__int64 __fastcall dsi_pll_3nm_trigger_resets_pre_enable(_QWORD *a1)
{
  __int64 v2; // x20
  __int64 v3; // x20
  __int64 v4; // x20
  __int64 result; // x0
  __int64 v6; // x20
  __int64 v7; // x20
  __int64 v8; // x19

  writel_relaxed_15(1, a1[1] + 296LL);
  __dsb(0xEu);
  writel_relaxed_15(0, a1[1] + 296LL);
  __dsb(0xEu);
  v2 = a1[15];
  if ( v2 )
  {
    writel_relaxed_15(1, *(_QWORD *)(v2 + 8) + 296LL);
    __dsb(0xEu);
    writel_relaxed_15(0, *(_QWORD *)(v2 + 8) + 296LL);
    __dsb(0xEu);
  }
  v3 = a1[16];
  if ( v3 )
  {
    writel_relaxed_15(1, *(_QWORD *)(v3 + 8) + 296LL);
    __dsb(0xEu);
    writel_relaxed_15(0, *(_QWORD *)(v3 + 8) + 296LL);
    __dsb(0xEu);
  }
  v4 = a1[17];
  if ( v4 )
  {
    writel_relaxed_15(1, *(_QWORD *)(v4 + 8) + 296LL);
    __dsb(0xEu);
    writel_relaxed_15(0, *(_QWORD *)(v4 + 8) + 296LL);
    __dsb(0xEu);
  }
  writel_relaxed_15(128, a1[1] + 40LL);
  __dsb(0xEu);
  result = writel_relaxed_15(0, a1[1] + 40LL);
  __dsb(0xEu);
  v6 = a1[15];
  if ( v6 )
  {
    writel_relaxed_15(128, *(_QWORD *)(v6 + 8) + 40LL);
    __dsb(0xEu);
    result = writel_relaxed_15(0, *(_QWORD *)(v6 + 8) + 40LL);
    __dsb(0xEu);
  }
  v7 = a1[16];
  if ( v7 )
  {
    writel_relaxed_15(128, *(_QWORD *)(v7 + 8) + 40LL);
    __dsb(0xEu);
    result = writel_relaxed_15(0, *(_QWORD *)(v7 + 8) + 40LL);
    __dsb(0xEu);
  }
  v8 = a1[17];
  if ( v8 )
  {
    writel_relaxed_15(128, *(_QWORD *)(v8 + 8) + 40LL);
    __dsb(0xEu);
    result = writel_relaxed_15(0, *(_QWORD *)(v8 + 8) + 40LL);
    __dsb(0xEu);
  }
  return result;
}
