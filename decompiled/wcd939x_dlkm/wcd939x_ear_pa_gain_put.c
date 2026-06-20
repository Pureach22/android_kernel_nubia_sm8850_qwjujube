__int64 __fastcall wcd939x_ear_pa_gain_put(__int64 a1, __int64 a2)
{
  snd_soc_component_update_bits(*(_QWORD *)(a1 + 128), 12299, 124, 4 * (*(_DWORD *)(a2 + 72) & 0x3Fu));
  return 0;
}
