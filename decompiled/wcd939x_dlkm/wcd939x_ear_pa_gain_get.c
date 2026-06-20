__int64 __fastcall wcd939x_ear_pa_gain_get(__int64 a1, __int64 a2)
{
  __int64 v3; // x8

  v3 = ((unsigned int)snd_soc_component_read(*(_QWORD *)(a1 + 128), 12299) >> 2) & 0x1F;
  *(_QWORD *)(a2 + 72) = v3;
  return 0;
}
