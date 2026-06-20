_DWORD *__fastcall cam_ife_mgr_user_dump_stream_info(__int64 a1, _DWORD *a2)
{
  __int64 v2; // x10
  __int64 v3; // x9
  __int64 v4; // x9
  int v5; // w9
  __int64 v6; // x10
  __int64 v7; // x10
  int v8; // w10
  __int64 v9; // x12
  __int64 v10; // x11
  __int64 v11; // x11
  int v12; // w11
  __int64 v13; // x12
  __int64 v14; // x12
  int v15; // w12
  int v16; // w13

  v2 = *(_QWORD *)(a1 + 224);
  if ( v2 != a1 + 224 )
  {
    v3 = *(_QWORD *)(v2 + 32);
    if ( v3 && (v4 = *(_QWORD *)(v3 + 16)) != 0 )
    {
      v5 = *(_DWORD *)(v4 + 4);
      v6 = *(_QWORD *)(v2 + 40);
      if ( !v6 )
        goto LABEL_9;
    }
    else
    {
      v5 = -1;
      v6 = *(_QWORD *)(v2 + 40);
      if ( !v6 )
      {
LABEL_9:
        v8 = -1;
        goto LABEL_11;
      }
    }
    v7 = *(_QWORD *)(v6 + 16);
    if ( v7 )
    {
      v8 = *(_DWORD *)(v7 + 4);
      goto LABEL_11;
    }
    goto LABEL_9;
  }
  v8 = -1;
  v5 = -1;
LABEL_11:
  v9 = *(_QWORD *)(a1 + 240);
  if ( v9 == a1 + 240 )
  {
    v15 = -1;
    v12 = -1;
    goto LABEL_21;
  }
  v10 = *(_QWORD *)(v9 + 32);
  if ( v10 && (v11 = *(_QWORD *)(v10 + 16)) != 0 )
  {
    v12 = *(_DWORD *)(v11 + 4);
    v13 = *(_QWORD *)(v9 + 40);
    if ( !v13 )
      goto LABEL_19;
  }
  else
  {
    v12 = -1;
    v13 = *(_QWORD *)(v9 + 40);
    if ( !v13 )
    {
LABEL_19:
      v15 = -1;
      goto LABEL_21;
    }
  }
  v14 = *(_QWORD *)(v13 + 16);
  if ( !v14 )
    goto LABEL_19;
  v15 = *(_DWORD *)(v14 + 4);
LABEL_21:
  *a2 = *(unsigned __int8 *)(a1 + 9379);
  v16 = *(_DWORD *)(a1 + 9312);
  a2[3] = v8;
  a2[4] = v12;
  a2[5] = v15;
  a2[1] = v16;
  a2[2] = v5;
  a2[6] = *(unsigned __int8 *)(a1 + 9387);
  a2[7] = *(unsigned __int8 *)(a1 + 9388);
  a2[8] = *(unsigned __int8 *)(a1 + 9381);
  a2[9] = *(unsigned __int8 *)(a1 + 9380);
  return a2 + 10;
}
