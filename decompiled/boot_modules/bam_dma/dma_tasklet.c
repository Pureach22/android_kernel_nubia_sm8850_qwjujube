__int64 __fastcall dma_tasklet(__int64 result)
{
  __int64 v1; // x19
  unsigned __int64 v2; // x22
  __int64 v3; // x23
  unsigned __int16 *v4; // x26
  __int64 v5; // x21
  __int64 v6; // x10

  if ( *(_DWORD *)(result - 48) )
  {
    v1 = result;
    v2 = 0;
    v3 = 362;
    do
    {
      v4 = (unsigned __int16 *)(*(_QWORD *)(v1 - 56) + v3);
      v5 = raw_spin_lock_irqsave(v4 - 101);
      if ( v4 - 81 != *(unsigned __int16 **)(v4 - 81) )
      {
        if ( *(_BYTE *)(v1 + 68) )
          v6 = -32;
        else
          v6 = -4096;
        if ( (v6 | (*v4 - (unsigned __int64)*(v4 - 1))) != 0xFFFFFFFFFFFFFFFFLL )
          bam_start_dma(v4 - 181);
      }
      result = raw_spin_unlock_irqrestore(v4 - 101, v5);
      ++v2;
      v3 += 408;
    }
    while ( v2 < *(unsigned int *)(v1 - 48) );
  }
  return result;
}
