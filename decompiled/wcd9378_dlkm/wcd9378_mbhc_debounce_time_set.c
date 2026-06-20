__int64 __fastcall wcd9378_mbhc_debounce_time_set(__int64 a1)
{
  return snd_soc_component_update_bits(a1, 1075314976, 15, 13);
}
