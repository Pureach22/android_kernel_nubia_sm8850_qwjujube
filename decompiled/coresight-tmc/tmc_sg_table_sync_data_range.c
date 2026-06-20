__int64 __fastcall tmc_sg_table_sync_data_range(__int64 result, unsigned __int64 a2, __int64 a3)
{
  unsigned __int64 v3; // x22
  unsigned __int64 v4; // x21
  __int64 v5; // x19
  __int64 v6; // x20

  v3 = a2 >> 12;
  v4 = (unsigned __int64)(a3 + 4095) >> 12;
  if ( (int)(v4 + (a2 >> 12)) > (int)(a2 >> 12) )
  {
    v5 = result;
    v6 = *(_QWORD *)(*(_QWORD *)result + 96LL);
    do
    {
      if ( (*(_BYTE *)(v6 + 844) & 0x40) == 0 )
        result = _dma_sync_single_for_cpu(
                   v6,
                   *(_QWORD *)(*(_QWORD *)(v5 + 72) + 8LL * ((int)v3 % *(_DWORD *)(v5 + 64))),
                   4096,
                   2);
      LODWORD(v4) = v4 - 1;
      LODWORD(v3) = v3 + 1;
    }
    while ( (_DWORD)v4 );
  }
  return result;
}
