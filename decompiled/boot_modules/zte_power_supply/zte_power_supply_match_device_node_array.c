__int64 __fastcall zte_power_supply_match_device_node_array(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8
  __int64 v4; // x8
  __int64 v5; // x9
  unsigned int v12; // w9

  v2 = *(_QWORD *)(a1 + 96);
  if ( !v2 || *(_QWORD *)(v2 + 744) != *a2 )
    return 0;
  v4 = a2[3];
  if ( v4 >= a2[2] )
    return 4294967221LL;
  v5 = a2[1];
  *(_QWORD *)(v5 + 8 * v4) = *(_QWORD *)(a1 + 152);
  _X8 = (unsigned int *)(*(_QWORD *)(v5 + 8LL * a2[3]) + 1112LL);
  __asm { PRFM            #0x11, [X8] }
  do
    v12 = __ldxr(_X8);
  while ( __stxr(v12 + 1, _X8) );
  ++a2[3];
  return 0;
}
