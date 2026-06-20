__int64 __fastcall dp_update_vdev_be_basic_stats(__int64 result, __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x8
  __int64 v6; // x9

  if ( result )
  {
    if ( a2 )
    {
      v2 = *(_QWORD *)(a2 + 2480);
      *(_QWORD *)(a2 + 2472) += *(_QWORD *)(result + 16);
      v3 = v2 + *(_QWORD *)(result + 24);
      LODWORD(v2) = *(_DWORD *)(a2 + 2572);
      *(_QWORD *)(a2 + 2480) = v3;
      LODWORD(v3) = v2 + *(_DWORD *)(result + 12);
      v4 = *(_QWORD *)(a2 + 4768);
      *(_DWORD *)(a2 + 2572) = v3;
      v5 = v4 + *(_QWORD *)(result + 32);
      v6 = *(_QWORD *)(a2 + 4776);
      *(_QWORD *)(a2 + 4768) = v5;
      *(_QWORD *)(a2 + 4776) = v6 + *(_QWORD *)(result + 40);
    }
  }
  return result;
}
