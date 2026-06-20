__int64 __fastcall wcd938x_mbhc_btn_to_num(__int64 a1)
{
  return snd_soc_component_read(a1, 12313) & 7;
}
