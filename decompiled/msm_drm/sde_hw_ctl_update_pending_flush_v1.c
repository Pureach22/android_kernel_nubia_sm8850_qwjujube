__int64 __fastcall sde_hw_ctl_update_pending_flush_v1(_DWORD *a1, _DWORD *a2)
{
  __int64 result; // x0
  int v4; // w11
  int v5; // w12
  int v6; // w12
  int v7; // w12
  int v8; // w12
  int v9; // w12
  int v10; // w10

  result = 4294967274LL;
  if ( a1 )
  {
    if ( a2 )
    {
      v4 = a1[24];
      a1[25] |= a2[1];
      v5 = a1[27];
      a1[26] |= a2[2];
      a1[27] = v5 | a2[3];
      v6 = a1[29];
      a1[28] |= a2[4];
      a1[29] = v6 | a2[5];
      v7 = a1[31];
      a1[30] |= a2[6];
      a1[31] = v7 | a2[7];
      v8 = a1[33];
      a1[32] |= a2[8];
      a1[33] = v8 | a2[9];
      v9 = a1[35];
      v10 = a1[36];
      a1[34] |= a2[10];
      a1[35] = v9 | a2[11];
      a1[36] = v10 | a2[12];
      a1[24] = v4 | *a2;
      return 0;
    }
  }
  return result;
}
