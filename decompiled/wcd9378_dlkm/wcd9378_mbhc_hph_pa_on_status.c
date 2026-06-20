bool __fastcall wcd9378_mbhc_hph_pa_on_status(__int64 a1)
{
  return (unsigned int)snd_soc_component_read(a1, 1086850176) == 0;
}
