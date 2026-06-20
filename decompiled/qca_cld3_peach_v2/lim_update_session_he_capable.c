bool __fastcall lim_update_session_he_capable(_QWORD *a1, __int64 a2)
{
  int v3; // w0
  __int64 v4; // x21
  _BOOL8 result; // x0

  v3 = *(_DWORD *)(a2 + 284);
  v4 = a2 + 7170;
  *(_BYTE *)(a2 + 8676) = 1;
  if ( wlan_reg_is_6ghz_chan_freq(v3) )
  {
    *(_BYTE *)(a2 + 155) = 0;
    *(_BYTE *)v4 = 0;
    *(_BYTE *)(v4 + 1594) = 1;
  }
  if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a2 + 284)) )
  {
    *(_QWORD *)(v4 + 1519) = *(_QWORD *)(v4 + 1519) & 0xFFFFFFFFFFFFFE7FLL
                           | (((*(_QWORD *)((char *)a1 + 21797) >> 7) & 3LL) << 7);
    if ( (*(_BYTE *)(a1[1] + 2875LL) & 1) == 0 )
      *(_BYTE *)v4 = 0;
  }
  result = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a2 + 284));
  if ( !result )
  {
    *(_QWORD *)(v4 + 1519) = *(_QWORD *)(v4 + 1519) & 0xFFFFFFFFFFFFFE7FLL
                           | (((*(_QWORD *)((char *)a1 + 21857) >> 7) & 3LL) << 7);
    *(_QWORD *)(v4 + 1511) = *(_QWORD *)(v4 + 1511) & 0xE1FFFFFFFFFFFFFFLL
                           | (((*(_QWORD *)((char *)a1 + 21849) >> 57) & 0xFLL) << 57);
  }
  return result;
}
