__int64 __fastcall dp_neighbour_peers_detach(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0
  _QWORD *v3; // x19
  _QWORD *v4; // x8
  __int64 v5; // x20
  _QWORD *v6; // x9

  v1 = *(_QWORD *)(a1 + 95560) + 36864LL;
  result = *(_QWORD *)(*(_QWORD *)(a1 + 95560) + 37240LL);
  if ( result )
  {
    v3 = (_QWORD *)(v1 + 384);
    do
    {
      v5 = *(_QWORD *)(result + 32);
      v4 = *(_QWORD **)(result + 40);
      v6 = (_QWORD *)(v5 + 40);
      if ( !v5 )
        v6 = v3;
      *v6 = v4;
      *v4 = *(_QWORD *)(result + 32);
      *(_QWORD *)(result + 32) = 0;
      *(_QWORD *)(result + 40) = 0;
      _qdf_mem_free(result);
      result = v5;
    }
    while ( v5 );
  }
  return result;
}
