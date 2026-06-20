__int64 __fastcall adreno_snapshot_preemption_record(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  unsigned int v4; // w23
  __int64 v5; // x24

  if ( (*(_QWORD *)(result + 14240) & 0x200) != 0 )
  {
    v2 = result;
    if ( *(_DWORD *)(result + 19632) )
    {
      v4 = 0;
      v5 = 14536;
      do
      {
        result = kgsl_snapshot_add_section(v2, 2818, a2, snapshot_preemption_record_0, *(_QWORD *)(v2 + v5));
        ++v4;
        v5 += 1320;
      }
      while ( v4 < *(_DWORD *)(v2 + 19632) );
    }
  }
  return result;
}
