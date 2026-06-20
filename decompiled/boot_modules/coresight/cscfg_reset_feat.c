__int64 __fastcall cscfg_reset_feat(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x9
  __int64 v3; // x10
  __int64 v4; // x11
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x10
  __int64 v8; // x13
  __int64 v9; // x11
  int *v10; // x12
  __int64 v11; // x11
  __int64 v12; // x13
  int v13; // w14
  __int64 v14; // x12

  if ( *(int *)(result + 40) >= 1 )
  {
    v1 = 0;
    v2 = 16;
    v3 = 8;
    do
    {
      ++v1;
      v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)result + 40LL) + v3);
      v3 += 16;
      *(_QWORD *)(*(_QWORD *)(result + 48) + v2) = v4;
      v2 += 32;
    }
    while ( v1 < *(int *)(result + 40) );
  }
  if ( *(int *)(result + 56) >= 1 )
  {
    v5 = 0;
    v6 = 0;
    v7 = 0;
    do
    {
      v8 = *(_QWORD *)(*(_QWORD *)result + 56LL);
      v9 = *(_QWORD *)(result + 64);
      v10 = (int *)(v9 + v6);
      *(_BYTE *)(v9 + v6) = *(_DWORD *)(v8 + v5);
      if ( (*(_BYTE *)(v8 + v5) & 8) != 0 )
      {
        v11 = v9 + v6;
        v12 = *(_QWORD *)(result + 48) + 32LL * *(unsigned int *)(v8 + v5 + 8);
        *(_QWORD *)(v12 + 8) = v10;
        v13 = *v10;
        v14 = *(_QWORD *)(v12 + 16);
        *(_BYTE *)(v12 + 24) = (v13 & 2) != 0;
        if ( (v13 & 2) != 0 )
          *(_QWORD *)(v11 + 8) = v14;
        else
          *(_DWORD *)(v11 + 8) = v14;
      }
      else
      {
        *((_QWORD *)v10 + 1) = *(_QWORD *)(v8 + v5 + 8);
      }
      ++v7;
      v6 += 24;
      v5 += 16;
    }
    while ( v7 < *(int *)(result + 56) );
  }
  return result;
}
