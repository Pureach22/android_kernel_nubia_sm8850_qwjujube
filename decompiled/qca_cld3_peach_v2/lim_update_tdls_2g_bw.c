__int64 __fastcall lim_update_tdls_2g_bw(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x8

  result = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a1 + 284));
  if ( (result & 1) != 0 )
  {
    v3 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 216LL);
    if ( v3 )
    {
      result = *(_QWORD *)(v3 + 80);
      if ( result )
        return wlan_tdls_teardown_links(result);
    }
  }
  return result;
}
