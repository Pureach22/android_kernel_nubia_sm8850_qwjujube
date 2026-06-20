__int64 __fastcall adc_tm_channel_measure_gen3(__int64 a1, __int64 a2, __int64 a3)
{
  int v4; // w8
  __int64 v6; // x21
  int v7; // w9
  __int64 v9; // x9
  __int64 *v10; // x8
  char v11; // w10
  __int64 v12; // x9
  int v13; // w9
  __int64 v14; // x0
  int v15; // w9
  __int64 v16; // x10
  int v17; // w11
  __int64 v18; // x2
  __int64 *v19; // x1
  unsigned int v20; // w0
  __int64 v21; // x2
  __int64 v22; // x2
  unsigned int v23; // w20

  if ( !a2 )
    return 4294967274LL;
  if ( !*(_QWORD *)(a2 + 32) )
    return 4294967274LL;
  v4 = *(_DWORD *)(a1 + 40);
  if ( v4 )
  {
    v6 = 0;
    v7 = 0;
    while ( (*(unsigned __int8 *)(*(_QWORD *)(a1 + 48) + 200LL * v7)
           | ((*(_WORD *)(*(_QWORD *)(a1 + 48) + 200LL * v7 + 12) & 0x1F) << 8) & 0x9FFF
           | ((*(_DWORD *)(*(_QWORD *)(a1 + 48) + 200LL * v7 + 32) & 3) << 13)) != *(_DWORD *)(a2 + 16) )
    {
      ++v7;
      v6 += 200;
      if ( v4 == v7 )
        goto LABEL_7;
    }
    mutex_lock(a1 + 96);
    v9 = *(_QWORD *)(a1 + 48);
    v10 = *(__int64 **)(v9 + v6 + 176);
    if ( (__int64 *)(v9 + v6 + 176) != v10 )
    {
      v11 = 0;
LABEL_11:
      v12 = v9 + v6 + 176;
      do
      {
        if ( *(_QWORD *)v10[2] == *(_QWORD *)a2 )
        {
          *((_DWORD *)v10 + 6) = *(_DWORD *)(a2 + 8);
          *((_DWORD *)v10 + 7) = *(_DWORD *)(a2 + 12);
          v13 = *(_DWORD *)(a2 + 20);
          *((_WORD *)v10 + 16) = 0;
          *((_DWORD *)v10 + 9) = v13;
          v10 = (__int64 *)*v10;
          v9 = *(_QWORD *)(a1 + 48);
          v11 = 1;
          if ( (__int64 *)(v9 + v6 + 176) != v10 )
            goto LABEL_11;
          goto LABEL_24;
        }
        v10 = (__int64 *)*v10;
      }
      while ( (__int64 *)v12 != v10 );
      if ( (v11 & 1) != 0 )
        goto LABEL_24;
    }
    v14 = devm_kmalloc(*(_QWORD *)(a1 + 8), 40, 3520);
    if ( v14 )
    {
      **(_QWORD **)(v14 + 16) = v14;
      v15 = *(_DWORD *)(a2 + 12);
      v16 = *(_QWORD *)(a1 + 48);
      v17 = *(_DWORD *)(a2 + 20);
      *(_DWORD *)(v14 + 24) = *(_DWORD *)(a2 + 8);
      *(_DWORD *)(v14 + 28) = v15;
      *(_DWORD *)(v14 + 36) = v17;
      v18 = v16 + v6 + 176;
      v19 = *(__int64 **)(v16 + v6 + 184);
      if ( v18 == v14 || v19 == (__int64 *)v14 || v18 != *v19 )
      {
        _list_add_valid_or_report();
      }
      else
      {
        *(_QWORD *)(v16 + v6 + 184) = v14;
        *(_QWORD *)v14 = v18;
        *(_QWORD *)(v14 + 8) = v19;
        *v19 = v14;
      }
    }
LABEL_24:
    v20 = adc_tm_gen3_manage_thresholds(*(_QWORD *)(a1 + 48) + v6);
    if ( (v20 & 0x80000000) != 0 )
      printk(&unk_92ED, v20, v21);
    v23 = adc_tm5_gen3_configure(*(_QWORD *)(a1 + 48) + v6);
    if ( (v23 & 0x80000000) != 0 )
      printk(&unk_9A3C, v23, v22);
    mutex_unlock(a1 + 96);
    return v23;
  }
  else
  {
LABEL_7:
    printk(&unk_93F9, a2, a3);
    return 4294967274LL;
  }
}
