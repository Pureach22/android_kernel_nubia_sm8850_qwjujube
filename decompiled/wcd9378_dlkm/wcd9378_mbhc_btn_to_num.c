__int64 __fastcall wcd9378_mbhc_btn_to_num(__int64 a1)
{
  return snd_soc_component_read(a1, 1075314713) & 7;
}
