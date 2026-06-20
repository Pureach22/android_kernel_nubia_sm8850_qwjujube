__int64 __fastcall fastrpc_session_alloc(__int64 a1, char a2, int a3)
{
  __int64 v3; // x21
  char v4; // w22
  int v6; // w23
  __int64 v7; // x20
  __int64 v8; // x0
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x5
  __int64 v13; // x6
  __int64 v14; // x9
  __int64 v15; // x9
  __int64 v16; // x8
  __int64 v17; // x11
  __int64 v18; // x13
  int v19; // w12
  int v20; // w13
  __int64 v21; // x8

  v3 = *(_QWORD *)(a1 + 128);
  if ( !*(_QWORD *)(v3 + 168) )
    return 0;
  v4 = *(_BYTE *)(a1 + 308);
  if ( ((a3 == 1) & (unsigned __int8)byte_27530) != 0 )
    v6 = 9;
  else
    v6 = a3;
  if ( (a2 & 1) != 0 )
  {
    v4 |= *(_BYTE *)(v3 + 64132);
    if ( *(_BYTE *)(v3 + 64132) )
      v6 = 6;
    else
      v6 = 0;
    goto LABEL_12;
  }
  v7 = *(_QWORD *)(a1 + 136);
  if ( v7 && *(_DWORD *)(v7 + 1008) == v6 )
    return v7;
LABEL_12:
  v8 = raw_spin_lock_irqsave(v3 + 51600);
  v14 = *(unsigned int *)(v3 + 4);
  if ( (int)v14 < 1 )
  {
LABEL_27:
    v7 = 0;
LABEL_28:
    raw_spin_unlock_irqrestore(v3 + 51600, v8);
    return v7;
  }
  v15 = v14 << 10;
  v16 = 0;
  v17 = 51;
  while ( v17 )
  {
    v18 = v3 + v16;
    v19 = *(_DWORD *)(v3 + v16 + 1184);
    if ( v19 == 10 )
      v4 |= *(_BYTE *)(v18 + 1189);
    v20 = *(_DWORD *)(v18 + 1196);
    if ( (!v20 || *(_DWORD *)(v3 + v16 + 1192) >= 2u)
      && *(_BYTE *)(v3 + v16 + 188) == 1
      && *(_BYTE *)(v3 + v16 + 1188) == (a2 & 1)
      && *(_BYTE *)(v3 + v16 + 1189) == (v4 & 1)
      && (!v6 || v19 == v6 || (a2 & 1) != 0) )
    {
      v21 = v3 + v16;
      *(_DWORD *)(v21 + 1196) = v20 + 1;
      v7 = v21 + 176;
      goto LABEL_28;
    }
    v16 += 1024;
    --v17;
    if ( v15 == v16 )
      goto LABEL_27;
  }
  __break(0x5512u);
  return trace_fastrpc_dma_map(v8, v8, v9, v10, v11, v12, v13);
}
