_DWORD *__fastcall tmc_sg_table_sync_table(_DWORD *result)
{
  int v1; // w8
  _DWORD *v2; // x19
  __int64 v3; // x21
  __int64 v4; // x20

  v1 = result[10];
  if ( v1 >= 1 )
  {
    v2 = result;
    v3 = 0;
    v4 = *(_QWORD *)(*(_QWORD *)result + 96LL);
    do
    {
      if ( (*(_BYTE *)(v4 + 844) & 0x40) == 0 )
      {
        result = (_DWORD *)_dma_sync_single_for_device(v4, *(_QWORD *)(*((_QWORD *)v2 + 6) + 8 * v3), 4096, 1);
        v1 = v2[10];
      }
      ++v3;
    }
    while ( v3 < v1 );
  }
  return result;
}
