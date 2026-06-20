__int64 __fastcall aw_monitor_get_data_from_table(__int64 a1, unsigned __int8 a2, __int16 *a3, __int64 a4, int a5)
{
  __int64 v5; // x8
  int v6; // w8
  __int64 v7; // x9
  __int64 v8; // x9
  __int64 v10; // x8
  __int64 *v11; // x8
  __int64 v12; // x1
  const char *v13; // x2
  __int64 *v14; // x8

  if ( *(_BYTE *)(a1 + 873) )
  {
    v5 = 274877907LL * (*(_DWORD *)(a4 + 4) / (int)*(unsigned __int8 *)(a1 + 874) * a5 + *(_DWORD *)a4 * (1000 - a5));
    v6 = (v5 >> 38) + ((unsigned __int64)v5 >> 63);
    *(_DWORD *)(a4 + 4) = v6;
    if ( a3 )
    {
      v7 = a2;
      if ( !a2 )
        return 0;
      while ( v6 < *a3 || v6 > a3[1] )
      {
        --v7;
        a3 += 6;
        if ( !v7 )
          return 0;
      }
      goto LABEL_8;
    }
    v11 = *(__int64 **)(a1 + 112);
    v12 = v11[14];
    if ( !v12 )
      v12 = *v11;
    v13 = "aw_monitor_trace_data_from_table";
  }
  else
  {
    if ( a3 )
    {
      v10 = a2;
      if ( !a2 )
        return 0;
      while ( *(_DWORD *)(a4 + 4) < *a3 )
      {
        --v10;
        a3 += 6;
        if ( !v10 )
          return 0;
      }
LABEL_8:
      v8 = *(_QWORD *)a3;
      *(_DWORD *)(a4 + 16) = *((_DWORD *)a3 + 2);
      *(_QWORD *)(a4 + 8) = v8;
      return 0;
    }
    v14 = *(__int64 **)(a1 + 112);
    v12 = v14[14];
    if ( !v12 )
      v12 = *v14;
    v13 = "aw_monitor_first_get_data_form_table";
  }
  printk(&unk_22E48, v12, v13);
  return 4294967274LL;
}
