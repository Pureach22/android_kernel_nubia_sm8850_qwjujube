__int64 __fastcall simple_amp_component_probe(__int64 a1)
{
  _QWORD *v1; // x19

  v1 = *(_QWORD **)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( !v1 )
    return 4294967274LL;
  v1[3] = a1;
  snd_soc_component_init_regmap();
  devm_regmap_qti_debugfs_register(v1[1], *v1);
  return simple_amp_func_configuration(v1);
}
