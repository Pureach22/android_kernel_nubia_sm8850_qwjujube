__int64 __fastcall rmnet_add_bridge(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v6; // x9

  v2 = *(_QWORD *)(a1 + 2696);
  if ( *(__int64 (__fastcall **)())(v2 + 264) == rmnet_rx_handler )
    v3 = *(_QWORD *)(v2 + 272);
  else
    v3 = 0;
  if ( *(unsigned __int8 *)(v3 + 12) > 1u )
    return 4294967274LL;
  if ( *(__int64 (__fastcall **)())(a2 + 264) == rmnet_rx_handler || (unsigned int)rmnet_register_real_device(a2) )
    return 4294967280LL;
  if ( *(__int64 (__fastcall **)())(a2 + 264) == rmnet_rx_handler )
    v6 = *(_QWORD *)(a2 + 272);
  else
    v6 = 0;
  *(_QWORD *)(v6 + 2056) = v2;
  *(_BYTE *)(v6 + 13) = 2;
  *(_BYTE *)(v3 + 13) = 2;
  *(_QWORD *)(v3 + 2056) = a2;
  return 0;
}
