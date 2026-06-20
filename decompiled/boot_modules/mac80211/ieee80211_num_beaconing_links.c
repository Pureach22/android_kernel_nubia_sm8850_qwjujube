__int64 __fastcall ieee80211_num_beaconing_links(__int64 a1)
{
  int v1; // w8
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x9
  __int64 v5; // x9
  __int64 v6; // x9
  __int64 v7; // x9
  __int64 v8; // x9
  __int64 v9; // x9
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 v12; // x9
  __int64 v13; // x9
  __int64 v14; // x9
  __int64 v15; // x9
  __int64 v16; // x9

  v1 = *(_DWORD *)(a1 + 4720);
  if ( v1 != 9 && v1 != 3 )
  {
    LODWORD(v2) = 0;
    return (unsigned int)v2;
  }
  LODWORD(v2) = *(unsigned __int16 *)(a1 + 5800);
  if ( !*(_WORD *)(a1 + 5800) )
    return (unsigned int)v2;
  v2 = *(_QWORD *)(a1 + 4568);
  if ( v2 )
    LODWORD(v2) = *(_QWORD *)(v2 + 536) != 0;
  v3 = *(_QWORD *)(a1 + 4576);
  if ( v3 && *(_QWORD *)(v3 + 536) )
    LODWORD(v2) = v2 + 1;
  v4 = *(_QWORD *)(a1 + 4584);
  if ( v4 && *(_QWORD *)(v4 + 536) )
    LODWORD(v2) = v2 + 1;
  v5 = *(_QWORD *)(a1 + 4592);
  if ( v5 && *(_QWORD *)(v5 + 536) )
    LODWORD(v2) = v2 + 1;
  v6 = *(_QWORD *)(a1 + 4600);
  if ( v6 && *(_QWORD *)(v6 + 536) )
    LODWORD(v2) = v2 + 1;
  v7 = *(_QWORD *)(a1 + 4608);
  if ( v7 && *(_QWORD *)(v7 + 536) )
    LODWORD(v2) = v2 + 1;
  v8 = *(_QWORD *)(a1 + 4616);
  if ( v8 && *(_QWORD *)(v8 + 536) )
    LODWORD(v2) = v2 + 1;
  v9 = *(_QWORD *)(a1 + 4624);
  if ( v9 && *(_QWORD *)(v9 + 536) )
    LODWORD(v2) = v2 + 1;
  v10 = *(_QWORD *)(a1 + 4632);
  if ( v10 && *(_QWORD *)(v10 + 536) )
    LODWORD(v2) = v2 + 1;
  v11 = *(_QWORD *)(a1 + 4640);
  if ( v11 && *(_QWORD *)(v11 + 536) )
    LODWORD(v2) = v2 + 1;
  v12 = *(_QWORD *)(a1 + 4648);
  if ( v12 && *(_QWORD *)(v12 + 536) )
    LODWORD(v2) = v2 + 1;
  v13 = *(_QWORD *)(a1 + 4656);
  if ( v13 && *(_QWORD *)(v13 + 536) )
    LODWORD(v2) = v2 + 1;
  v14 = *(_QWORD *)(a1 + 4664);
  if ( v14 && *(_QWORD *)(v14 + 536) )
    LODWORD(v2) = v2 + 1;
  v15 = *(_QWORD *)(a1 + 4672);
  if ( v15 && *(_QWORD *)(v15 + 536) )
    LODWORD(v2) = v2 + 1;
  v16 = *(_QWORD *)(a1 + 4680);
  if ( !v16 )
    return (unsigned int)v2;
  if ( *(_QWORD *)(v16 + 536) )
    return (unsigned int)(v2 + 1);
  else
    return (unsigned int)v2;
}
