__int64 __fastcall rmnet_get_rmnet_port(__int64 result)
{
  __int64 v1; // x8

  if ( result )
  {
    v1 = *(_QWORD *)(result + 2696);
    if ( *(__int64 (__fastcall **)())(v1 + 264) == rmnet_rx_handler )
      return *(_QWORD *)(v1 + 272);
    else
      return 0;
  }
  return result;
}
