__int64 __fastcall adc_tm_disable_chan_meas_gen3(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w8
  int v6; // w22
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 *v10; // x21
  unsigned int v11; // w0
  __int64 v12; // x2
  unsigned int v13; // w20
  void *v14; // x8
  unsigned int v15; // w20

  if ( !a2 )
    return 4294967274LL;
  v3 = *(_DWORD *)(a1 + 40);
  if ( v3 )
  {
    v6 = 0;
    while ( (*(unsigned __int8 *)(*(_QWORD *)(a1 + 48) + 200LL * v6)
           | ((*(_WORD *)(*(_QWORD *)(a1 + 48) + 200LL * v6 + 12) & 0x1F) << 8) & 0x9FFF
           | ((*(_DWORD *)(*(_QWORD *)(a1 + 48) + 200LL * v6 + 32) & 3) << 13)) != *(_DWORD *)(a2 + 16) )
    {
      if ( v3 == ++v6 )
        goto LABEL_20;
    }
  }
  else
  {
    v6 = 0;
  }
  if ( v6 == v3 )
  {
LABEL_20:
    printk(&unk_93F9, a2, a3);
    return 4294967274LL;
  }
  mutex_lock(a1 + 96);
  v8 = *(_QWORD *)(a1 + 48);
  v9 = v8 + 200LL * v6;
  v10 = *(__int64 **)(v9 + 176);
  if ( v10 == (__int64 *)(v9 + 176) )
  {
    v11 = 0;
    goto LABEL_18;
  }
  v11 = 0;
  while ( *(_QWORD *)v10[2] != *(_QWORD *)a2 )
  {
LABEL_12:
    v10 = (__int64 *)*v10;
    if ( v10 == (__int64 *)(v8 + 200LL * v6 + 176) )
      goto LABEL_18;
  }
  *((_DWORD *)v10 + 9) = 5;
  v11 = adc_tm_gen3_manage_thresholds(*(_QWORD *)(a1 + 48) + 200LL * v6);
  if ( (v11 & 0x80000000) != 0 )
  {
    v14 = &unk_92ED;
    goto LABEL_23;
  }
  v11 = adc_tm5_gen3_configure(*(_QWORD *)(a1 + 48) + 200LL * v6);
  if ( (v11 & 0x80000000) == 0 )
  {
    v8 = *(_QWORD *)(a1 + 48);
    goto LABEL_12;
  }
  v14 = &unk_9A3C;
LABEL_23:
  v15 = v11;
  printk(v14, v11, v12);
  v11 = v15;
LABEL_18:
  v13 = v11;
  mutex_unlock(a1 + 96);
  return v13;
}
