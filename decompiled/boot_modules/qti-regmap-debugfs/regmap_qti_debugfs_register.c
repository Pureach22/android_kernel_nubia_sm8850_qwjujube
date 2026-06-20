unsigned __int64 regmap_qti_debugfs_register()
{
  unsigned __int64 result; // x0

  result = regmap_qti_debugfs_add();
  if ( result <= 0xFFFFFFFFFFFFF000LL )
    return 0;
  else
    return (unsigned int)result;
}
