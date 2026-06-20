bool __fastcall wlansap_is_all_2ghz_channel_scanned(__int64 a1)
{
  __int64 v1; // x8
  unsigned __int64 v2; // x19
  unsigned __int16 v4; // w20
  unsigned int *v5; // x21
  unsigned int v6; // t1

  v1 = *(_QWORD *)(a1 + 32);
  if ( !v1 )
    return 0;
  v2 = *(unsigned __int8 *)(v1 + 120);
  if ( v2 < 0xB )
    return 0;
  v4 = 0;
  v5 = (unsigned int *)(v1 + 124);
  do
  {
    v6 = *v5;
    v5 += 3;
    --v2;
    v4 += wlan_reg_is_24ghz_ch_freq(v6);
  }
  while ( v2 );
  return v4 > 0xAu;
}
