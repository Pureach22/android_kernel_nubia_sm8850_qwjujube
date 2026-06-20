__int64 __fastcall dwc3_core_stop_hw_active_transfers(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  int *v3; // x21
  int v4; // t1

  v1 = 0;
  v2 = a1 + 592;
  v3 = (int *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 368) + 96LL) + 152LL) + 1280LL);
  do
  {
    v4 = *v3;
    v3 += 10;
    if ( v4 == 2 )
      dwc3_core_stop_active_transfer(*(_QWORD *)(v2 + v1));
    v1 += 8;
  }
  while ( v1 != 256 );
  return 0;
}
