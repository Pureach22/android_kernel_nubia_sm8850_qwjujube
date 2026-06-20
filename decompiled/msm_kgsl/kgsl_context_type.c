const char *__fastcall kgsl_context_type(int a1)
{
  if ( (unsigned int)(a1 - 1) > 4 )
    return "ANY";
  else
    return off_171728[a1 - 1];
}
