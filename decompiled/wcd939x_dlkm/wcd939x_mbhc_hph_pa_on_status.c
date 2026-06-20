bool __fastcall wcd939x_mbhc_hph_pa_on_status(__int64 a1)
{
  return (snd_soc_component_read(a1, 12297) & 0xC0) != 0;
}
