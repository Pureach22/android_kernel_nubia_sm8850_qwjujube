__int64 __fastcall wlan_convert_host_to_diag_tx_fail_reason(int a1)
{
  if ( (unsigned int)(a1 - 1) > 8 )
    return 0;
  else
    return dword_A2B944[a1 - 1];
}
