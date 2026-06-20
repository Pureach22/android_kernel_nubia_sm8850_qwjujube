__int64 __fastcall wcd939x_init_reg(__int64 a1)
{
  __int64 v2; // x21
  int v3; // w8
  unsigned int v4; // w20

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  snd_soc_component_update_bits(a1, 12289, 128, 128);
  snd_soc_component_update_bits(a1, 12289, 64, 64);
  usleep_range_state(10000, 10010, 2);
  snd_soc_component_update_bits(a1, 12289, 64, 0);
  snd_soc_component_update_bits(a1, 12608, 63, 21);
  snd_soc_component_update_bits(a1, 12609, 63, 21);
  snd_soc_component_update_bits(a1, 13403, 2, 2);
  snd_soc_component_update_bits(a1, 12769, 240, 16);
  snd_soc_component_update_bits(a1, 12769, 15, 4);
  snd_soc_component_update_bits(a1, 12767, 31, 8);
  snd_soc_component_update_bits(a1, 12395, 224, 224);
  snd_soc_component_update_bits(a1, 12398, 224, 224);
  snd_soc_component_update_bits(a1, 12401, 224, 224);
  snd_soc_component_update_bits(a1, 12404, 224, 224);
  snd_soc_component_update_bits(a1, 12431, 1, 0);
  v3 = of_find_property(
         *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 32) + 72LL) + 744LL),
         "qcom,wcd-disable-legacy-surge",
         0) == 0;
  v4 = v3 << 6;
  snd_soc_component_update_bits(a1, 12514, 128, (unsigned int)(v3 << 7));
  snd_soc_component_update_bits(a1, 12514, 64, v4);
  snd_soc_component_update_bits(a1, 12494, 16, 16);
  snd_soc_component_update_bits(a1, 12494, 2, 2);
  if ( *(_DWORD *)(v2 + 3176) != 2 )
    snd_soc_component_write(a1, 13697, 5);
  return snd_soc_component_update_bits(a1, 12377, 128, 128);
}
