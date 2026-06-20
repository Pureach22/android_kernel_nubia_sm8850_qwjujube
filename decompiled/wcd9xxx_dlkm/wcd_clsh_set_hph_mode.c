__int64 __fastcall wcd_clsh_set_hph_mode(__int64 a1, unsigned int a2)
{
  if ( a2 >= 9 )
    return dev_err(*(_QWORD *)(a1 + 24), "%s:Invalid mode %d\n", "wcd_clsh_set_hph_mode", a2);
  else
    return snd_soc_component_update_bits(a1, 12297, 12, dword_8890[a2]);
}
