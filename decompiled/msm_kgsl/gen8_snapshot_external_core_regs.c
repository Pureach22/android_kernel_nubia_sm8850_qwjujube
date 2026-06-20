__int64 __fastcall gen8_snapshot_external_core_regs(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x22
  __int64 *v4; // x23
  __int64 v6; // x20
  __int64 v7; // t1

  v2 = *(_QWORD *)(*(_QWORD *)(result + 14264) + 192LL);
  v3 = *(unsigned int *)(v2 + 72);
  gen8_snapshot_block_list = v2;
  if ( v3 )
  {
    v4 = *(__int64 **)(v2 + 64);
    v6 = result;
    do
    {
      v7 = *v4++;
      result = kgsl_snapshot_add_section(v6, 514, a2, adreno_snapshot_registers_v2, v7);
      --v3;
    }
    while ( v3 );
  }
  return result;
}
