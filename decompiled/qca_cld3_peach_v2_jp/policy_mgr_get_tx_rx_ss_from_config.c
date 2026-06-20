__int64 __fastcall policy_mgr_get_tx_rx_ss_from_config(__int64 result, _DWORD *a2, _DWORD *a3)
{
  int v3; // w8

  if ( (unsigned int)(result - 1) >= 4 )
    v3 = 0;
  else
    v3 = result;
  *a2 = v3;
  *a3 = v3;
  return result;
}
