__int64 __fastcall wcd938x_ear_pa_gain_put(__int64 a1, __int64 a2)
{
  __int64 v2; // x0

  v2 = *(_QWORD *)(a1 + 128);
  if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL) + 288LL) & 1) == 0 )
    snd_soc_component_update_bits(v2, 12299, 124, 4 * (*(_DWORD *)(a2 + 72) & 0x3Fu));
  return 0;
}
