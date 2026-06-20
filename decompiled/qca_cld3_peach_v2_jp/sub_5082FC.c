void __fastcall sub_5082FC(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x2

  v2 = *(_QWORD *)(a2 + 72);
  if ( v2 )
    v3 = *(_QWORD *)(v2 + 40);
  else
    v3 = 0;
  qdf_trace_dp_packet(*(_QWORD *)(a2 + 8), 0, v3, *(_QWORD *)(a2 + 80) / 1000LL, *(unsigned __int8 *)(a2 + 49));
  if ( !*(_QWORD *)(a2 + 72) )
    JUMPOUT(0x508218);
  JUMPOUT(0x5082AC);
}
