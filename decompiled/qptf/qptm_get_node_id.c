__int64 __fastcall qptm_get_node_id(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x9
  __int64 result; // x0

  if ( !a1 )
    return 4294967277LL;
  if ( !*(_QWORD *)(a1 + 1112) )
    return 0;
  v1 = *(_QWORD *)(a1 + 1168);
  v2 = a1 + 1168;
  result = 4294967277LL;
  if ( v1 != v2 && v1 != 56 )
    return *(unsigned __int16 *)(v1 - 32);
  return result;
}
