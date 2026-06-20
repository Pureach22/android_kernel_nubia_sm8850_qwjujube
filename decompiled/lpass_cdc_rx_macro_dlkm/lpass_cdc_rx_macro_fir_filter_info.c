__int64 __fastcall lpass_cdc_rx_macro_fir_filter_info(__int64 a1, __int64 a2)
{
  __int64 v2; // x9

  v2 = *(_QWORD *)(a1 + 120);
  *(_DWORD *)(a2 + 64) = 4;
  *(_DWORD *)(a2 + 72) = *(_DWORD *)(v2 + 8);
  return 0;
}
