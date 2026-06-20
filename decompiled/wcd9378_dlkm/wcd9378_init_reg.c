__int64 __fastcall wcd9378_init_reg(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x3

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( (unsigned int)snd_soc_component_read(a1, 1075315904) )
    v3 = 1;
  else
    v3 = 3;
  snd_soc_component_update_bits(a1, 1075314776, 3, v3);
  snd_soc_component_update_bits(a1, 1075314947, 14, 14);
  snd_soc_component_update_bits(a1, 1075314947, 128, 128);
  usleep_range_state(1000, 1010, 2);
  snd_soc_component_update_bits(a1, 1075314947, 64, 64);
  usleep_range_state(1000, 1010, 2);
  snd_soc_component_update_bits(a1, 1075314729, 240, 176);
  snd_soc_component_update_bits(a1, 1075314689, 128, 128);
  snd_soc_component_update_bits(a1, 1075314689, 64, 64);
  usleep_range_state(10000, 10010, 2);
  snd_soc_component_update_bits(a1, 1075314689, 64, 0);
  snd_soc_component_update_bits(a1, 1075315735, 1, 1);
  snd_soc_component_update_bits(a1, 1075314811, 128, 128);
  snd_soc_component_update_bits(a1, 1075315813, 24, 16);
  snd_soc_component_update_bits(a1, 1075315814, 24, 16);
  snd_soc_component_update_bits(a1, 1075314796, 7, 1);
  snd_soc_component_update_bits(a1, 1075314799, 7, 1);
  snd_soc_component_update_bits(a1, 1075314802, 7, 1);
  snd_soc_component_update_bits(a1, 1075314995, 15, 4);
  snd_soc_component_update_bits(a1, 1075314998, 15, 4);
  snd_soc_component_update_bits(a1, 1075314994, 240, 80);
  snd_soc_component_update_bits(a1, 1075315984, 7, 5);
  snd_soc_component_update_bits(a1, 1075315993, 7, 5);
  snd_soc_component_update_bits(a1, 1075315995, 7, 6);
  snd_soc_component_update_bits(a1, 1075315045, 8, 8);
  snd_soc_component_update_bits(a1, 1075316144, 3, 1);
  snd_soc_component_update_bits(a1, 1075316145, 3, 2);
  snd_soc_component_update_bits(a1, 1075316146, 3, 3);
  snd_soc_component_update_bits(a1, 1075315969, 15, 0);
  *(_DWORD *)(v2 + 8) = 0;
  snd_soc_component_update_bits(a1, 1082654728, 1, 1);
  usleep_range_state(20000, 20010, 2);
  snd_soc_component_update_bits(a1, 1082654720, 255, 255);
  snd_soc_component_update_bits(a1, 1086849032, 1, 1);
  usleep_range_state(30000, 30010, 2);
  snd_soc_component_update_bits(a1, 1086324744, 255, 2);
  snd_soc_component_update_bits(a1, 1086849024, 255, 255);
  snd_soc_component_update_bits(a1, 1091043336, 1, 1);
  usleep_range_state(5000, 5010, 2);
  snd_soc_component_update_bits(a1, 1091043328, 255, 255);
  snd_soc_component_update_bits(a1, 1095237640, 1, 1);
  usleep_range_state(5000, 5010, 2);
  snd_soc_component_update_bits(a1, 1095237632, 255, 255);
  snd_soc_component_update_bits(a1, 1099431944, 1, 1);
  usleep_range_state(5000, 5010, 2);
  return snd_soc_component_update_bits(a1, 1099431936, 255, 255);
}
