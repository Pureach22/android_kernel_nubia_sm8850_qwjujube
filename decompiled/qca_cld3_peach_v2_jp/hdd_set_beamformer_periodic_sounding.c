__int64 __fastcall hdd_set_beamformer_periodic_sounding(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x2

  v2 = *(unsigned __int8 *)(a1 + 8);
  if ( *(_BYTE *)(a2 + 4) )
    v3 = 100;
  else
    v3 = 0;
  return wma_cli_set_command(v2, 97, v3, 2);
}
