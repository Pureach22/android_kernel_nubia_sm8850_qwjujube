__int64 __fastcall qmp_v3_configure_dp_tx(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w21
  unsigned int v4; // w20

  result = ((__int64 (*)(void))qmp_combo_configure_dp_swing)();
  if ( (result & 0x80000000) == 0 )
  {
    if ( *(_DWORD *)(a1 + 304) == 1 )
      v3 = 19;
    else
      v3 = 16;
    if ( *(_DWORD *)(a1 + 304) == 1 )
      v4 = 62;
    else
      v4 = 63;
    writel(v3, *(_QWORD *)(a1 + 104) + 96LL);
    writel(v4, *(_QWORD *)(a1 + 104) + 92LL);
    writel(v3, *(_QWORD *)(a1 + 112) + 96LL);
    return writel(v4, *(_QWORD *)(a1 + 112) + 92LL);
  }
  return result;
}
