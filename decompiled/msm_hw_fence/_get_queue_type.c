const char *__fastcall get_queue_type(int a1)
{
  if ( a1 == 1 )
    return "RXQ";
  else
    return "TXQ";
}
