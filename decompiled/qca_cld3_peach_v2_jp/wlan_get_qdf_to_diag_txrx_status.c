__int64 __fastcall wlan_get_qdf_to_diag_txrx_status(unsigned int a1)
{
  if ( a1 > 7 )
    return 0;
  else
    return dword_A302B0[a1];
}
