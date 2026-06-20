__int64 __fastcall gpi_alloc_chan(__int64 a1, char a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  _DWORD *v7; // x8
  int *v8; // x22
  unsigned int v10; // w19
  char v11; // w25
  __int64 v12; // x26
  int v13; // w27
  int v14; // w23
  int v15; // w28
  unsigned int v16; // w21
  __int64 v17; // x24
  __int64 v18; // x0
  int v19; // w19
  int v20; // w23
  int v21; // w28
  unsigned int v22; // w27
  char v23; // w21
  __int64 v24; // x25
  char v25; // w26
  __int64 result; // x0
  __int64 v27; // x6
  __int64 v28; // x8
  unsigned int v29; // w19
  int v30; // w19
  unsigned int v31; // w19
  unsigned int v32; // [xsp+0h] [xbp-20h]
  char v33; // [xsp+0h] [xbp-20h]
  int v34; // [xsp+4h] [xbp-1Ch]
  int v35; // [xsp+8h] [xbp-18h]
  int v36; // [xsp+Ch] [xbp-14h]
  unsigned int v37; // [xsp+10h] [xbp-10h]
  unsigned int v38; // [xsp+14h] [xbp-Ch]
  __int64 v39; // [xsp+18h] [xbp-8h]

  v7 = *(_DWORD **)(a1 + 352);
  v8 = *(int **)(a1 + 280);
  v10 = *(_DWORD *)(a1 + 256);
  v11 = *(_BYTE *)(a1 + 264);
  v12 = *((_QWORD *)v8 + 102);
  v13 = *(_DWORD *)(a1 + 268);
  v14 = *(_DWORD *)(a1 + 260);
  v15 = v10 == 0;
  v37 = v7[14];
  v16 = v7[5];
  v35 = v7[15];
  v36 = *(_DWORD *)(a1 + 348);
  v38 = v7[4];
  v17 = *(_QWORD *)(a1 + 296);
  v39 = *(_QWORD *)(a1 + 304);
  v34 = *v8;
  if ( (unsigned int)v8[267] >= 3 )
  {
    v33 = a2;
    printk(&unk_123DE, v8 + 269, v10, "gpi_alloc_chan", a5, a6, a7);
    a2 = v33;
    v18 = *((_QWORD *)v8 + 132);
    if ( !v18 )
      goto LABEL_5;
  }
  else
  {
    v18 = *((_QWORD *)v8 + 132);
    if ( !v18 )
      goto LABEL_5;
  }
  if ( (unsigned int)v8[266] >= 3 )
  {
    v32 = v10;
    v19 = v14;
    v20 = v15;
    v21 = v13;
    v22 = v16;
    v23 = v11;
    v24 = v12;
    v25 = a2;
    ipc_log_string(v18, "ch:%u %s: Enter\n", *(_DWORD *)(a1 + 256), "gpi_alloc_chan");
    a2 = v25;
    v12 = v24;
    v11 = v23;
    v16 = v22;
    v13 = v21;
    v15 = v20;
    v14 = v19;
    v10 = v32;
  }
LABEL_5:
  if ( (a2 & 1) != 0
    && (result = ((__int64 (__fastcall *)(int *, __int64, _QWORD))gpi_send_cmd)(v8, a1, 0), (_DWORD)result) )
  {
    if ( (unsigned int)v8[267] >= 2 )
    {
      v31 = result;
      printk(
        &unk_147A5,
        v8 + 269,
        *(unsigned int *)(a1 + 256),
        "gpi_alloc_chan",
        "CH ALLOCATE",
        (unsigned int)result,
        v27);
      result = v31;
      v28 = *((_QWORD *)v8 + 132);
      if ( !v28 )
        return result;
    }
    else
    {
      v28 = *((_QWORD *)v8 + 132);
      if ( !v28 )
        return result;
    }
    if ( (unsigned int)v8[266] >= 2 )
    {
      v29 = result;
      ipc_log_string(
        v28,
        "ch:%u %s: Error with cmd:%s ret:%d\n",
        *(_DWORD *)(a1 + 256),
        "gpi_alloc_chan",
        "CH ALLOCATE",
        result);
      return v29;
    }
  }
  else
  {
    if ( v17 )
    {
      writel_relaxed((v35 << 24) | (8 * v36) | 2u, v17);
      writel_relaxed(v37, v17 + 4);
      writel_relaxed(v38, v17 + 8);
      writel_relaxed(v16, v17 + 12);
      if ( v39 )
      {
        writel_relaxed(v16, v39 + 4);
        if ( v12 )
        {
          v30 = (v10 << 7) + (v34 << 14) + 131164;
          writel_relaxed(v14 | (16 * v13) | (v15 << 16) | ((unsigned __int8)(v11 & 1) << 15), v12 + v30 + 4);
          writel_relaxed(0, v12 + v30 + 8);
          writel_relaxed(0, v12 + v30 + 12);
          writel_relaxed(0, v12 + v30 + 16);
          writel_relaxed(1, v12 + v30);
        }
      }
    }
    __dsb(0xEu);
    return 0;
  }
  return result;
}
