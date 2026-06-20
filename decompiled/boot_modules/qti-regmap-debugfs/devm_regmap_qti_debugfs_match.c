bool __fastcall devm_regmap_qti_debugfs_match(__int64 a1, _QWORD *a2, __int64 a3)
{
  if ( a2 && *a2 )
    return *a2 == a3;
  __break(0x800u);
  return 0;
}
