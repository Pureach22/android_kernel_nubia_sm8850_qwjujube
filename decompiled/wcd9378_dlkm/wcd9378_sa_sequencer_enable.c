__int64 __fastcall wcd9378_sa_sequencer_enable(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x19
  __int64 result; // x0
  __int64 v7; // x19
  unsigned int v8; // w19

  v3 = *(_QWORD *)(a1 + 40);
  v4 = v3 - 208;
  v5 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
  if ( a3 == 8 )
  {
    if ( (*(_QWORD *)(v5 + 16) & 0x400) == 0
      && (*(_QWORD *)(v5 + 16) & 0x800) == 0
      && (*(_QWORD *)(v5 + 16) & 0x1000) == 0 )
    {
      regmap_write(*(_QWORD *)(v5 + 48), 1082131336, 1);
      v4 = v3 - 208;
    }
    v7 = v4;
    snd_soc_component_update_bits(v4, 1082131464, 255, 3);
    usleep_range_state(15400, 15410, 2);
    result = wcd9378_pde_act_ps_check(v7, 1082655744, 3);
    if ( (_DWORD)result )
    {
      v8 = result;
      dev_err(*(_QWORD *)(v3 - 184), "%s: SA sequencer tear down failed\n", "wcd9378_sa_sequencer_enable");
      return v8;
    }
  }
  else
  {
    if ( a3 == 1 )
    {
      snd_soc_component_update_bits(v4, 1082131464, 255, 0);
      usleep_range_state(8600, 8610, 2);
      regmap_write(*(_QWORD *)(v5 + 48), 1082131336, 0);
      result = 0;
      if ( *(_DWORD *)(v5 + 8) != 10 )
        return result;
      regmap_write(*(_QWORD *)(v5 + 48), 1086325513, 0);
      regmap_write(*(_QWORD *)(v5 + 48), 1086325514, 0);
    }
    return 0;
  }
  return result;
}
