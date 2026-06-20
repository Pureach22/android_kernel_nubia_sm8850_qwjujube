__int64 __fastcall wsa_pa_gain_put(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x9
  __int64 v4; // x8
  char v5; // w10

  v2 = *(_QWORD *)(a1 + 128);
  v3 = *(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL);
  v4 = *(_QWORD *)(a2 + 72);
  v5 = *(_BYTE *)(v3 + 32);
  *(_BYTE *)(v3 + 200) = v4;
  if ( (v5 & 1) == 0 )
    snd_soc_component_update_bits(v2, 13421, 62, 2 * (unsigned int)(unsigned __int8)v4);
  return 0;
}
