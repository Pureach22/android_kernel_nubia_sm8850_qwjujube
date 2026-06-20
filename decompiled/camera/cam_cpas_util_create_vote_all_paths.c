__int64 __fastcall cam_cpas_util_create_vote_all_paths(__int64 a1, __int64 a2, char a3)
{
  unsigned int v3; // w8
  __int64 v4; // x10
  __int64 v5; // x11
  unsigned __int64 v6; // x8
  __int64 v7; // x12
  __int64 v8; // x13
  __int64 v9; // x9
  __int64 v10; // x14
  __int64 v11; // x17
  __int64 v12; // x13
  __int64 *v13; // x14
  __int64 v14; // x0

  v3 = -22;
  if ( !a1 || !a2 )
    return v3;
  v4 = *(_QWORD *)(a2 + 24);
  v5 = *(_QWORD *)(a2 + 32);
  v6 = 0;
  v7 = *(_QWORD *)(a2 + 40);
  v8 = 0;
  v9 = a2 + 8;
  v10 = a1 + 1040;
  *(_DWORD *)a2 = 0;
  while ( !*(_QWORD *)v10 )
  {
LABEL_5:
    ++v8;
    v10 += 16;
    if ( v8 == 42 )
    {
      v12 = 0;
      v13 = (__int64 *)(a1 + 1048);
      do
      {
        a1 = *v13;
        if ( *v13 )
        {
          if ( v6 > 0xF )
            goto LABEL_19;
          v14 = v9 + 40 * v6;
          *(_DWORD *)(v14 + 4) = 1;
          *(_DWORD *)(v14 + 8) = v12;
          *(_QWORD *)(v14 + 16) = v4;
          *(_QWORD *)(v14 + 24) = v5;
          *(_QWORD *)(v14 + 32) = v7;
          if ( *(int *)(*v13 + 16) >= 1 )
            *(_DWORD *)(v14 + 12) = 2;
          *(_DWORD *)a2 = ++v6;
          if ( (a3 & 1) != 0 )
            break;
        }
        ++v12;
        v13 += 2;
      }
      while ( v12 != 42 );
      return 0;
    }
  }
  if ( v6 <= 0xF )
  {
    v11 = v9 + 40 * v6;
    *(_DWORD *)(v11 + 4) = 0;
    *(_DWORD *)(v11 + 8) = v8;
    *(_QWORD *)(v11 + 16) = v4;
    *(_QWORD *)(v11 + 24) = v5;
    *(_QWORD *)(v11 + 32) = v7;
    if ( *(int *)(*(_QWORD *)v10 + 16LL) >= 1 )
      *(_DWORD *)(v11 + 12) = 2;
    *(_DWORD *)a2 = ++v6;
    if ( (a3 & 1) != 0 )
      return 0;
    goto LABEL_5;
  }
LABEL_19:
  __break(0x5512u);
  return cam_cpas_util_translate_client_paths(a1);
}
