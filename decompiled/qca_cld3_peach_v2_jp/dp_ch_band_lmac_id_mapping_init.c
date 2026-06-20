__int64 __fastcall dp_ch_band_lmac_id_mapping_init(__int64 a1)
{
  __int64 result; // x0
  int v3; // w8

  result = hal_get_target_type(*(__int64 **)(*(_QWORD *)(a1 + 8) + 1128LL));
  if ( (unsigned int)(result - 28) > 0xF )
    v3 = 1;
  else
    v3 = dword_A2BEE0[(unsigned int)(result - 28)];
  *(_DWORD *)(a1 + 272) = v3;
  *(_QWORD *)(a1 + 276) = 0;
  return result;
}
