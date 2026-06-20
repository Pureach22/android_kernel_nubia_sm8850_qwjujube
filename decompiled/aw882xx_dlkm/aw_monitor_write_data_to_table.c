__int64 __fastcall aw_monitor_write_data_to_table(__int64 result, unsigned __int8 *a2, __int64 a3)
{
  __int64 v4; // x20
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x14
  unsigned __int16 v7; // kr00_2
  __int16 v8; // w16
  unsigned int v9; // w12
  __int64 v10; // x23
  unsigned __int64 v11; // x24
  __int64 *v12; // x8
  __int64 v13; // x1

  if ( *a2 )
  {
    v4 = result;
    v5 = 0;
    do
    {
      v6 = a3 + 11 + v5;
      v7 = v5;
      v8 = *(_WORD *)(a3 + v5);
      v5 += 12LL;
      v9 = v7 / 0xCu;
      *(_WORD *)(*((_QWORD *)a2 + 1) + 12LL * v9) = v8;
      *(_WORD *)(*((_QWORD *)a2 + 1) + 12LL * v9 + 2) = *(_WORD *)(v6 - 9);
      *(_WORD *)(*((_QWORD *)a2 + 1) + 12LL * v9 + 4) = *(_WORD *)(v6 - 7);
      *(_WORD *)(*((_QWORD *)a2 + 1) + 12LL * v9 + 6) = *(_WORD *)(v6 - 5);
      *(_DWORD *)(*((_QWORD *)a2 + 1) + 12LL * v9 + 8) = *(_DWORD *)(v6 - 3);
    }
    while ( 12 * (unsigned __int64)*a2 > v5 );
    if ( *a2 )
    {
      v10 = 0;
      v11 = 0;
      do
      {
        v12 = *(__int64 **)(v4 + 112);
        v13 = v12[14];
        if ( !v13 )
          v13 = *v12;
        result = printk(&unk_241F0, v13, "aw_monitor_write_data_to_table");
        ++v11;
        v10 += 12;
      }
      while ( v11 < *a2 );
    }
  }
  return result;
}
