__int64 __fastcall wcd9378_pde_act_ps_check(__int64 a1, __int64 a2, int a3)
{
  unsigned int v4; // w20

  v4 = a2;
  if ( (unsigned int)snd_soc_component_read(a1, a2) == a3 )
    return 0;
  usleep_range_state(500, 510, 2);
  if ( (unsigned int)snd_soc_component_read(a1, v4) == a3 )
    return 0;
  usleep_range_state(500, 510, 2);
  if ( (unsigned int)snd_soc_component_read(a1, v4) == a3 )
    return 0;
  usleep_range_state(500, 510, 2);
  if ( (unsigned int)snd_soc_component_read(a1, v4) == a3 )
    return 0;
  usleep_range_state(500, 510, 2);
  if ( (unsigned int)snd_soc_component_read(a1, v4) == a3 )
    return 0;
  usleep_range_state(500, 510, 2);
  return 4294967274LL;
}
