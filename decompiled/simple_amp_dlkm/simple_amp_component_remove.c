__int64 __fastcall simple_amp_component_remove(__int64 result)
{
  _QWORD *v1; // x8
  __int64 v2; // x19

  v1 = *(_QWORD **)(*(_QWORD *)(result + 24) + 152LL);
  if ( v1 )
  {
    v2 = result;
    devm_regmap_qti_debugfs_unregister(*v1);
    return snd_soc_component_exit_regmap(v2);
  }
  return result;
}
