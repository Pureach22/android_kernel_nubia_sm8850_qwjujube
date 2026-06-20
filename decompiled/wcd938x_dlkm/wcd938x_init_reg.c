__int64 __fastcall wcd938x_init_reg(__int64 a1)
{
  char v2; // w0

  snd_soc_component_update_bits(a1, 12547, 14, 14);
  snd_soc_component_update_bits(a1, 12547, 128, 128);
  usleep_range_state(1000, 1010, 2);
  snd_soc_component_update_bits(a1, 12547, 64, 64);
  usleep_range_state(1000, 1010, 2);
  snd_soc_component_update_bits(a1, 12586, 16, 0);
  snd_soc_component_update_bits(a1, 12329, 240, 128);
  snd_soc_component_update_bits(a1, 12289, 128, 128);
  snd_soc_component_update_bits(a1, 12289, 64, 64);
  usleep_range_state(10000, 10010, 2);
  snd_soc_component_update_bits(a1, 12289, 64, 0);
  snd_soc_component_update_bits(a1, 12594, 240, 0);
  snd_soc_component_update_bits(a1, 12608, 31, 21);
  snd_soc_component_update_bits(a1, 12609, 31, 21);
  snd_soc_component_update_bits(a1, 12509, 192, 128);
  snd_soc_component_update_bits(a1, 13403, 2, 2);
  snd_soc_component_update_bits(a1, 12769, 255, 20);
  snd_soc_component_update_bits(a1, 12767, 31, 8);
  snd_soc_component_update_bits(a1, 13520, 255, 85);
  snd_soc_component_update_bits(a1, 13521, 255, 68);
  snd_soc_component_update_bits(a1, 13522, 255, 17);
  snd_soc_component_update_bits(a1, 13523, 255, 0);
  snd_soc_component_update_bits(a1, 13524, 255, 0);
  snd_soc_component_update_bits(a1, 12395, 224, 224);
  snd_soc_component_update_bits(a1, 12398, 224, 224);
  snd_soc_component_update_bits(a1, 12401, 224, 224);
  snd_soc_component_update_bits(a1, 12404, 224, 224);
  snd_soc_component_update_bits(a1, 12431, 1, 0);
  v2 = snd_soc_component_read(a1, 13518);
  snd_soc_component_update_bits(a1, 12547, 14, 2 * (v2 & 7u));
  return snd_soc_component_update_bits(a1, 12514, 192, 192);
}
