__int64 __fastcall coresight_remove_sink_ref(__int64 a1, __int64 a2)
{
  if ( *(_QWORD *)(a1 + 936) == a2 )
    *(_QWORD *)(a1 + 936) = 0;
  return 0;
}
