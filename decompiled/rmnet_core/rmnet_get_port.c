__int64 __fastcall rmnet_get_port(__int64 a1)
{
  if ( *(__int64 (__fastcall **)())(a1 + 264) == rmnet_rx_handler )
    return *(_QWORD *)(a1 + 272);
  else
    return 0;
}
