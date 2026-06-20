unsigned __int64 regulator_debug_register()
{
  unsigned __int64 result; // x0

  result = regulator_debug_add();
  if ( result <= 0xFFFFFFFFFFFFF000LL )
    return 0;
  else
    return (unsigned int)result;
}
