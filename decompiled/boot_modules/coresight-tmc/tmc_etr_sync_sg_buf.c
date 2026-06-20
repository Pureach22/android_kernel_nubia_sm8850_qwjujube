__int64 __fastcall tmc_etr_sync_sg_buf(__int64 result, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 *v3; // x8
  __int64 *v4; // x20
  __int64 v5; // x12
  unsigned __int64 *v6; // x11
  __int64 v7; // x13
  unsigned __int64 v8; // x8
  unsigned __int64 *v9; // x9
  unsigned __int64 v10; // x10
  unsigned __int64 v11; // t1
  unsigned __int64 v12; // x9
  __int64 v13; // x13
  __int64 v14; // x14
  unsigned __int64 v15; // x12
  unsigned __int64 v16; // t1
  int v17; // w13
  unsigned __int64 v18; // x8
  __int64 v19; // x11
  unsigned __int64 v20; // x22
  unsigned __int64 v21; // x21
  __int64 v22; // x19
  __int64 v23; // x19
  __int64 v24; // x0
  const char *v25; // x1

  v3 = *(__int64 **)(result + 56);
  v4 = (__int64 *)*v3;
  v5 = *(unsigned int *)(*v3 + 64);
  if ( (int)v5 < 1 )
    goto LABEL_23;
  v6 = (unsigned __int64 *)v4[9];
  v7 = *(unsigned int *)(*v3 + 64);
  v8 = a2;
  v9 = v6;
  while ( 1 )
  {
    v11 = *v9++;
    v10 = v11;
    if ( v11 <= a2 && v10 + 4096 > a2 )
      break;
    --v7;
    v8 += 4096LL;
    if ( !v7 )
      goto LABEL_23;
  }
  v12 = v8 - v10;
  if ( (__int64)(v8 - v10) < 0 )
  {
LABEL_23:
    v23 = result;
    v24 = *v4;
    a3 = a2;
    v25 = "Unable to map RRP %llx to offset\n";
LABEL_25:
    result = dev_warn(v24, v25, a3);
    *(_QWORD *)(v23 + 40) = 0;
  }
  else
  {
    v13 = v5 << 12;
    v14 = 0;
    while ( 1 )
    {
      v16 = *v6++;
      v15 = v16;
      if ( v16 <= a3 && v15 + 4096 > a3 )
        break;
      v14 -= 4096;
      v10 += 4096LL;
      if ( !(v13 + v14) )
        goto LABEL_24;
    }
    if ( (__int64)(a3 - v15 - v14) < 0 )
    {
LABEL_24:
      v23 = result;
      v24 = *v4;
      v25 = "Unable to map RWP %llx to offset\n";
      goto LABEL_25;
    }
    v17 = *(unsigned __int8 *)(result + 8);
    *(_QWORD *)(result + 32) = v12;
    if ( v17 == 1 )
    {
      v18 = *(_QWORD *)(result + 16);
    }
    else
    {
      if ( (__int64)(a3 - v15 - v14) >= (__int64)v12 )
        v19 = 0;
      else
        v19 = *(_QWORD *)(result + 16);
      v18 = v19 + v10 - v15 + a3 - v8;
    }
    v20 = v12 >> 12;
    *(_QWORD *)(result + 40) = v18;
    v21 = (v18 + 4095) >> 12;
    if ( (int)(v21 + (v12 >> 12)) > (int)(v12 >> 12) )
    {
      v22 = *(_QWORD *)(*v4 + 96);
      do
      {
        if ( (*(_BYTE *)(v22 + 844) & 0x40) == 0 )
          result = _dma_sync_single_for_cpu(v22, *(_QWORD *)(v4[9] + 8LL * ((int)v20 % *((_DWORD *)v4 + 16))), 4096, 2);
        LODWORD(v21) = v21 - 1;
        LODWORD(v20) = v20 + 1;
      }
      while ( (_DWORD)v21 );
    }
  }
  return result;
}
