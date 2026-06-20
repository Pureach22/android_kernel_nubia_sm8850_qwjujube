__int64 __fastcall perfmon_counter_dump_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x24
  int v5; // w8
  unsigned int v6; // w9
  __int64 *v7; // x8
  size_t v8; // x21
  __int64 v9; // x20
  int v10; // w22
  int v11; // w23
  __int64 v12; // x27
  __int64 v13; // x26
  int v14; // w9
  __int64 v15; // x9
  __int64 result; // x0
  __int64 v17; // x27
  __int64 v18; // x26
  __int64 v19; // x25
  __int64 v20; // x28
  int v21; // w0
  unsigned __int64 v22; // x3
  __int64 v23; // x8
  int v24; // w3
  __int64 v25; // x22

  v3 = *(_QWORD *)(a1 + 152);
  v5 = *(unsigned __int8 *)(v3 + 133);
  if ( *(_BYTE *)(v3 + 133) )
  {
    if ( v5 == *(unsigned __int8 *)(*(_QWORD *)(v3 + 112) + 5LL) )
      v6 = *(unsigned __int8 *)(v3 + 133);
    else
      v6 = v5 + 1;
  }
  else
  {
    v6 = 0;
  }
  v7 = *(__int64 **)(v3 + 192);
  v8 = 8LL * v6;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = v6;
  v13 = v7[1];
  while ( 1 )
  {
    v14 = 5001;
    while ( (v13 & 1) != 0 )
    {
      if ( v11 == --v14 )
      {
        v11 = 5001;
        break;
      }
    }
    if ( v11 > 4999 )
      return -22;
    v15 = v13;
    if ( v9 != *v7 )
    {
      memcpy(*(void **)(v3 + 56), (const void *)(*(_QWORD *)(v3 + 192) + 16LL), v8);
      v7 = *(__int64 **)(v3 + 192);
      v9 = *v7;
      v15 = v7[1];
    }
    if ( v15 == (unsigned int)v13 )
      break;
    ++v10;
    v13 = v15;
    if ( v10 == 11 )
      goto LABEL_19;
  }
  if ( v10 == 10 )
    return -22;
LABEL_19:
  if ( (_DWORD)v12 )
  {
    v17 = 8 * v12;
    v18 = 0;
    v19 = 0;
    v20 = 1;
    do
    {
      v23 = *(_QWORD *)(v3 + 72);
      v24 = *(unsigned __int8 *)(v23 + v20 - 1);
      if ( v24 == 255 )
      {
        v21 = scnprintf(a3 + v19, 4096 - v19, "CYCLE COUNT,,");
        v22 = *(_QWORD *)(*(_QWORD *)(v3 + 56) + v18)
            / (unsigned __int64)(*(_BYTE *)(*(_QWORD *)(v3 + 112) + 6LL) & 0x3F);
      }
      else
      {
        v21 = scnprintf(a3 + v19, 4096 - v19, "PORT %02u,EVENT %03u,", v24, *(unsigned __int16 *)(v23 + v20));
        v22 = *(_QWORD *)(*(_QWORD *)(v3 + 56) + v18);
      }
      v18 += 8;
      v19 += v21 + (__int64)(int)scnprintf(a3 + v19 + v21, 4096 - (v19 + v21), "0x%016llx\n", v22);
      v20 += 3;
    }
    while ( v17 != v18 );
  }
  else
  {
    v19 = 0;
  }
  v25 = v19 + (int)scnprintf(a3 + v19, 4096 - v19, "LAST CAPTURED TIME,,");
  result = v25 + (int)scnprintf(a3 + v25, 4096 - v25, "0x%016llx\n", v9);
  **(_QWORD **)(v3 + 192) = v9;
  return result;
}
