const char *__fastcall eud_type(__int64 a1)
{
  if ( *(_DWORD *)(a1 + 296) == 300 )
    return "EUD UART";
  else
    return nullptr;
}
