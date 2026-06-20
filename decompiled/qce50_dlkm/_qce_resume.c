__int64 __fastcall qce_resume(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x24
  __int64 v5; // x23
  unsigned int v6; // w0
  __int64 v7; // x20
  __int64 result; // x0
  unsigned int v9; // w20
  __int64 v10; // x25
  __int64 v11; // x26
  __int64 v12; // x27
  __int64 v13; // x23
  unsigned int v14; // w23
  unsigned int v15; // w8
  unsigned int v16; // w19

  if ( !a1 )
    return 4294967277LL;
  v3 = a1 + 69632;
  if ( *(_BYTE *)(a1 + 70250) == 1 && *(_DWORD *)(a1 + 316) )
  {
    v5 = *(_QWORD *)(a1 + 1520);
    memset(*(void **)(a1 + 1584), 0, *(unsigned int *)(a1 + 1608));
    v6 = sps_connect(v5, a1 + 1528);
    if ( v6 )
    {
LABEL_29:
      v16 = v6;
      printk(&unk_14D4C, "_qce_resume", v5);
      return v16;
    }
    v7 = *(_QWORD *)(a1 + 416);
    memset(*(void **)(a1 + 480), 0, *(unsigned int *)(a1 + 504));
    if ( (unsigned int)sps_connect(v7, a1 + 424) )
      printk(&unk_14D4C, "_qce_resume", v7);
    result = sps_register_event(v7, a1 + 568);
    if ( (_DWORD)result )
    {
      v9 = result;
      printk(&unk_14F76, "_qce_resume", (unsigned int)result);
      result = v9;
    }
  }
  else
  {
    result = 4294967277LL;
  }
  v10 = -920;
  v11 = 320;
  do
  {
    if ( *(_BYTE *)(v3 + 619) != 1 )
      break;
    if ( *(_DWORD *)(a1 + v11) )
    {
      v12 = a1 + v10;
      v5 = *(_QWORD *)(a1 + v10 + 2624);
      memset(*(void **)(a1 + v10 + 2688), 0, *(unsigned int *)(a1 + v10 + 2712));
      v6 = sps_connect(v5, a1 + v10 + 2632);
      if ( v6 )
        goto LABEL_29;
      v13 = *(_QWORD *)(v12 + 1520);
      memset(*(void **)(v12 + 1584), 0, *(unsigned int *)(v12 + 1608));
      if ( (unsigned int)sps_connect(v13, v12 + 1528) )
        printk(&unk_14D4C, "_qce_resume", v13);
      result = sps_register_event(v13, a1 + v10 + 1672);
      if ( (_DWORD)result )
      {
        v14 = result;
        printk(&unk_14F76, "_qce_resume", (unsigned int)result);
        result = v14;
      }
    }
    v10 += 184;
    v11 += 4;
  }
  while ( v10 );
  if ( *(_BYTE *)(v3 + 620) == 1 )
  {
    v16 = result;
    printk(&unk_15E51, "qce_enable_clock_gating", a3);
  }
  else
  {
    v15 = *(_DWORD *)(a1 + 408);
    if ( v15 == 5 )
    {
      if ( *(_DWORD *)(a1 + 404) <= 8u )
        return result;
    }
    else if ( v15 < 6 )
    {
      return result;
    }
    v16 = result;
    writel();
  }
  return v16;
}
