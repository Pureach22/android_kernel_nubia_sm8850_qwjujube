__int64 __fastcall devm_regmap_qti_debugfs_register(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  _QWORD *v5; // x21
  unsigned __int64 v6; // x20

  v4 = _devres_alloc_node(devm_regmap_qti_debugfs_release, 8, 3264, 0xFFFFFFFFLL, "devm_regmap_qti_debugfs_release");
  if ( v4 )
  {
    v5 = (_QWORD *)v4;
    v6 = regmap_qti_debugfs_add(a1, a2);
    if ( v6 < 0xFFFFFFFFFFFFF001LL )
    {
      *v5 = v6;
      devres_add(a1, v5);
      LODWORD(v6) = 0;
    }
    else
    {
      devres_free(v5);
    }
  }
  else
  {
    LODWORD(v6) = -12;
  }
  return (unsigned int)v6;
}
