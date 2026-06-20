__int64 __fastcall hdd_ndp_get_peer_bw(__int64 a1, const void *a2, _BYTE *a3)
{
  __int64 v3; // x22
  __int64 v6; // x21
  __int64 v7; // x24
  __int64 result; // x0

  v3 = *(_QWORD *)(a1 + 52824);
  if ( !v3 )
    return 0;
  v6 = 0;
  v7 = -192;
  while ( (unsigned int)qdf_mem_cmp((const void *)(v3 + 540 + v7), a2, 6u) )
  {
    v7 += 6;
    ++v6;
    if ( !v7 )
      return 0;
  }
  result = hdd_convert_ch_width_to_cdp_peer_bw(*(_DWORD *)(v3 + 4 * v6 + 540));
  *a3 = v6 - 1;
  if ( (unsigned int)result >= 5 )
    return 0;
  return result;
}
