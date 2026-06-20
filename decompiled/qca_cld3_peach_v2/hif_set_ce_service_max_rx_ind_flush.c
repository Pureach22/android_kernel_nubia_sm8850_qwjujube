__int64 __fastcall hif_set_ce_service_max_rx_ind_flush(__int64 result, unsigned __int8 a2)
{
  char v2; // w8

  if ( (unsigned int)a2 - 33 >= 0xFFFFFFE0 )
    v2 = a2;
  else
    v2 = 32;
  *(_BYTE *)(result + 2456) = v2;
  return result;
}
