__int64 __fastcall dp_wbm_get_rx_desc_from_hal_desc_be(__int64 a1, unsigned int *a2, unsigned __int64 *a3)
{
  unsigned __int64 v3; // x8

  if ( (a2[2] & 0x10000) != 0 )
    v3 = *a2 | ((unsigned __int64)a2[1] << 32);
  else
    v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 22608) + 24LL * (a2[1] >> 21))
                   + (((unsigned __int64)a2[1] >> 9) & 0xFF8));
  *a3 = v3;
  return 0;
}
