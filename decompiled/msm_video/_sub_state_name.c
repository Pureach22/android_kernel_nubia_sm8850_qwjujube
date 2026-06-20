const char *__fastcall sub_state_name(int a1)
{
  if ( a1 <= 7 )
  {
    if ( a1 == 1 )
      return "DRAIN ";
    if ( a1 != 2 )
    {
      if ( a1 == 4 )
        return "DRAIN_LAST_BUFFER ";
      return "SUB_STATE_NONE";
    }
    return "DRC ";
  }
  else if ( a1 > 31 )
  {
    if ( a1 != 32 )
    {
      if ( a1 == 64 )
        return "FIRST_IPSC ";
      return "SUB_STATE_NONE";
    }
    return "OUTPUT_PAUSE ";
  }
  else
  {
    if ( a1 != 8 )
    {
      if ( a1 == 16 )
        return "INPUT_PAUSE ";
      return "SUB_STATE_NONE";
    }
    return "DRC_LAST_BUFFER ";
  }
}
