const char *__fastcall get_dump_event_str(int a1)
{
  if ( a1 == 48879 )
    return "init trace dumps. [max trace events][trace mem ptr]";
  else
    return nullptr;
}
