__int64 __fastcall qce_dump_req(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x21
  int v3; // w19
  __int64 result; // x0
  __int64 v5; // x2
  __int64 v6; // x23
  unsigned int *v7; // x27
  __int64 v8; // x2
  __int64 v9; // x2
  __int64 v10; // x2
  __int64 v11; // x2
  __int64 v12; // x2
  __int64 v13; // x19
  unsigned int v14; // w25
  unsigned int v15; // w25
  unsigned int v16; // w8
  int v17; // w19
  unsigned int v18; // w26
  __int64 v19; // x22

  v1 = 0;
  v2 = a1 + 2624;
  do
  {
    v3 = *(_DWORD *)(v2 + 7432 * v1);
    result = printk(&unk_15571, "qce_dump_req", "qce_dump_req");
    if ( v3 )
    {
      v6 = v2 + 7432 * v1;
      v7 = *(unsigned int **)(v6 + 40);
      printk(&unk_14A83, "_qce_dump_descr_fifos", v5);
      printk(&unk_14E3F, "_qce_dump_descr_fifos", v8);
      printk(&unk_14A83, "_qce_dump_descr_fifos", v9);
      if ( *(_DWORD *)(v6 + 48) )
      {
        v15 = 0;
        do
        {
          printk(&unk_15F85, "_qce_dump_descr_fifos", v15);
          v16 = v7[1];
          if ( (v16 & 0x8000000) != 0 )
          {
            v17 = (unsigned __int16)v16 >> 4;
            if ( (unsigned __int16)v16 >> 4 )
            {
              v18 = 0;
              v19 = *(_QWORD *)(a1 + 16) - *(_QWORD *)(a1 + 24) + *v7;
              do
              {
                v19 += 16;
                printk(&unk_15362, "_qce_dump_descr_fifos", v18++);
              }
              while ( v17 != v18 );
            }
          }
          ++v15;
          v7 += 2;
        }
        while ( v15 < *(_DWORD *)(v6 + 48) );
      }
      printk(&unk_14A83, "_qce_dump_descr_fifos", v10);
      printk(&unk_15165, "_qce_dump_descr_fifos", v11);
      result = printk(&unk_14A83, "_qce_dump_descr_fifos", v12);
      if ( *(_DWORD *)(v6 + 80) )
      {
        v13 = *(_QWORD *)(v6 + 72);
        v14 = 0;
        do
        {
          v13 += 8;
          result = printk(&unk_15F85, "_qce_dump_descr_fifos", v14++);
        }
        while ( v14 < *(_DWORD *)(v6 + 80) );
      }
    }
    ++v1;
  }
  while ( v1 != 8 );
  return result;
}
