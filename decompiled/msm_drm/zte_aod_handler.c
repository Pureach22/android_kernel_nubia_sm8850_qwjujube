__int64 __fastcall zte_aod_handler(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  int v4; // w9
  int v5; // w20
  int v6; // w21
  char v7; // w22
  __int64 v8; // x21
  __int64 v9; // x21
  char v10; // w8

  v2 = *(unsigned int *)(result + 2552);
  v3 = result;
  if ( (int)a2 > 2 )
  {
    if ( (_DWORD)a2 == 3 )
    {
      if ( (_DWORD)v2 == 1 )
        v4 = 3;
      else
        v4 = 2;
    }
    else
    {
      if ( (_DWORD)a2 != 4 )
        return result;
      v4 = v2 == 3;
    }
  }
  else if ( (_DWORD)a2 == 1 )
  {
    if ( (v2 & 0xFFFFFFFE) == 2 )
      v4 = 3;
    else
      v4 = 1;
  }
  else
  {
    if ( (_DWORD)a2 != 2 )
      return result;
    v4 = 2 * ((_DWORD)v2 == 3);
  }
  *(_DWORD *)(result + 2552) = v4;
  if ( (unsigned int)v2 >= 4 )
  {
    __break(0x5512u);
    __break(1u);
    return zte_fod_handler(result, a2);
  }
  v5 = a2;
  printk(&unk_25CCA6, aodstate[v2]);
  v6 = *(_DWORD *)(v3 + 2552);
  if ( v6 == 3 )
  {
    printk(&unk_2413A9, 0);
    v7 = 1;
  }
  else
  {
    if ( v5 == 3 )
      v7 = *(_BYTE *)(v3 + 2556);
    else
      v7 = 0;
    printk(&unk_2413A9, v6 == 0);
    if ( !v6 )
    {
      if ( *(_DWORD *)(v3 + 2320) )
      {
        v8 = *(_QWORD *)(v3 + 2488);
        printk(&unk_2590DD, work2string[0]);
        queue_work_on(32, v8, v3 + 2456);
        *(_BYTE *)(v3 + 2448) = 1;
      }
      goto LABEL_25;
    }
  }
  printk(&unk_2590DD, work2string[0]);
  if ( *(_BYTE *)(v3 + 2448) )
    *(_BYTE *)(v3 + 2448) = 0;
LABEL_25:
  v9 = *(_QWORD *)(v3 + 2536);
  result = printk(&unk_2590DD, off_FAB0[0]);
  if ( (v7 & 1) != 0 )
  {
    if ( !*(_DWORD *)(v3 + 2324) )
      *(_DWORD *)(v3 + 2324) = 2;
    result = queue_work_on(32, v9, v3 + 2504);
    v10 = 1;
  }
  else
  {
    v10 = 0;
  }
  *(_BYTE *)(v3 + 2496) = v10;
  return result;
}
