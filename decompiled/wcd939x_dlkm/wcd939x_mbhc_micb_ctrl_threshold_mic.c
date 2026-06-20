__int64 __fastcall wcd939x_mbhc_micb_ctrl_threshold_mic(__int64 a1, int a2, char a3)
{
  int v4; // w1

  if ( a2 != 2 )
    return 4294967274LL;
  if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 144LL) + 36LL) > 0xA8Bu )
    return 0;
  if ( (a3 & 1) != 0 )
    v4 = 2700;
  else
    v4 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 144LL) + 36LL);
  return wcd939x_mbhc_micb_adjust_voltage(a1, v4, 2);
}
