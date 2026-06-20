__int64 __fastcall tmc_etr_sync_flat_buf(__int64 result, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x21
  int v4; // w10
  __int64 v5; // x19
  __int64 v6; // x8
  unsigned __int64 v7; // x9
  __int64 v8; // x22
  __int64 v9; // x8
  __int64 v10; // x20
  unsigned int v11; // w23

  v3 = *(_QWORD **)(result + 56);
  v4 = *(unsigned __int8 *)(result + 8);
  v5 = *(_QWORD *)(*v3 + 96LL);
  v6 = a2 - *(_QWORD *)(result + 24);
  *(_QWORD *)(result + 32) = v6;
  v7 = *(_QWORD *)(result + 16);
  if ( v4 == 1 )
    v8 = v7;
  else
    v8 = a3 - a2;
  *(_QWORD *)(result + 40) = v8;
  if ( v8 + v6 <= v7 )
  {
    v9 = v3[4];
    if ( *(_DWORD *)(v9 + 12) )
    {
      v10 = *(_QWORD *)v9;
      v11 = 0;
      do
      {
        if ( (*(_BYTE *)(v5 + 844) & 0x40) == 0 )
          result = _dma_sync_sg_for_cpu(v5, v10, 1, 2);
        v8 -= *(unsigned int *)(v10 + 12);
        if ( v8 < 1 )
          break;
        ++v11;
        result = sg_next(v10);
        v10 = result;
      }
      while ( v11 < *(_DWORD *)(v3[4] + 12LL) );
    }
  }
  else if ( (*(_BYTE *)(v5 + 844) & 0x40) == 0 )
  {
    return _dma_sync_sg_for_cpu(v5, *(_QWORD *)v3[4], *(unsigned int *)(v3[4] + 12LL), 2);
  }
  return result;
}
