const char *__fastcall GetSourceSubsystemString(unsigned int a1)
{
  if ( a1 > 2 )
    return "Unknown Subsystem";
  else
    return off_10C00[a1];
}
