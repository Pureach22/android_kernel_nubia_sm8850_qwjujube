bool __fastcall mhi_queue_is_full(__int64 a1, int a2)
{
  __int64 v2; // x8
  _QWORD *v3; // x8
  __int64 v4; // x9
  __int64 v5; // x10
  __int64 v6; // x11
  __int64 v7; // x8
  unsigned __int64 v8; // x12
  unsigned __int64 v9; // x9

  v2 = 32;
  if ( a2 == 1 )
    v2 = 24;
  v3 = *(_QWORD **)(a1 + v2);
  v4 = v3[19];
  v5 = v3[20];
  v6 = v3[21];
  v8 = v3[17];
  v7 = v3[18];
  v9 = v4 + v5;
  if ( v9 >= v8 + v6 )
    v9 = v8;
  return v9 == v7;
}
