bool __fastcall wcd938x_mbhc_micb_en_status(__int64 a1, int a2)
{
  return a2 == 2 && (snd_soc_component_read(*(_QWORD *)(a1 + 216), 12323) & 0xC0) == 0x40;
}
