__int64 __fastcall sde_hw_ctl_get_pending_flush(_QWORD *a1, _QWORD *a2)
{
  __int64 result; // x0
  __int64 v4; // x9
  __int64 v5; // x11
  __int64 v6; // x12
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 v9; // x8
  __int64 v10; // x11

  result = 4294967274LL;
  if ( a1 )
  {
    if ( a2 )
    {
      v4 = a1[15];
      v5 = a1[12];
      v6 = a1[13];
      a2[2] = a1[14];
      a2[3] = v4;
      *a2 = v5;
      a2[1] = v6;
      v8 = a1[18];
      v7 = a1[19];
      v10 = a1[16];
      v9 = a1[17];
      a2[6] = v8;
      a2[7] = v7;
      a2[4] = v10;
      a2[5] = v9;
      return 0;
    }
  }
  return result;
}
