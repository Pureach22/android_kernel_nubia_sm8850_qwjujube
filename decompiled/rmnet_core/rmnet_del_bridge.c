__int64 __fastcall rmnet_del_bridge(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  __int64 v4; // x9
  __int64 v5; // x1

  v2 = *(_QWORD *)(a1 + 2696);
  if ( *(__int64 (__fastcall **)())(v2 + 264) == rmnet_rx_handler )
    v4 = *(_QWORD *)(v2 + 272);
  else
    v4 = 0;
  *(_QWORD *)(v4 + 2056) = 0;
  v5 = 0;
  *(_BYTE *)(v4 + 13) = 1;
  if ( *(__int64 (__fastcall **)())(a2 + 264) == rmnet_rx_handler )
    v5 = *(_QWORD *)(a2 + 272);
  rmnet_unregister_real_device(a2, v5);
  return 0;
}
