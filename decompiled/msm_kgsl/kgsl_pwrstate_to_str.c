const char *__fastcall kgsl_pwrstate_to_str(int a1)
{
  if ( a1 > 15 )
  {
    if ( a1 == 16 )
      return "SUSPEND";
    if ( a1 != 32 )
    {
      if ( a1 == 128 )
        return "SLUMBER";
      return "UNKNOWN";
    }
    return "AWARE";
  }
  else
  {
    if ( !a1 )
      return "NONE";
    if ( a1 != 1 )
    {
      if ( a1 == 2 )
        return "ACTIVE";
      return "UNKNOWN";
    }
    return "INIT";
  }
}
