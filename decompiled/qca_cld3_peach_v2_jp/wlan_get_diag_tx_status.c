__int64 __fastcall wlan_get_diag_tx_status(int a1)
{
  unsigned int v1; // w8

  if ( a1 == 3 )
    v1 = 2;
  else
    v1 = 1;
  if ( a1 == 1 )
    return 3;
  else
    return v1;
}
