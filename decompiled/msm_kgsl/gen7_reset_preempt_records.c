__int64 __fastcall gen7_reset_preempt_records(__int64 result)
{
  __int64 v1; // x19
  int v2; // w22
  __int64 v3; // x20

  if ( (*(_QWORD *)(result + 14240) & 0x200) != 0 )
  {
    v1 = result;
    if ( *(int *)(result + 19632) >= 1 )
    {
      v2 = 0;
      v3 = result + 14352;
      do
      {
        result = reset_rb_preempt_record_0(v1, v3);
        ++v2;
        v3 += 1320;
      }
      while ( v2 < *(_DWORD *)(v1 + 19632) );
    }
  }
  return result;
}
