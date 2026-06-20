__int64 __fastcall gen8_hfi_cmdq_write(__int64 a1, int *a2, unsigned int a3)
{
  __int64 v6; // x19
  int v7; // w8
  unsigned int v8; // w0
  unsigned int v9; // w21

  v6 = to_gen8_gmu(a1);
  raw_spin_lock(v6 + 972);
  v7 = *a2;
  if ( ((*(_QWORD *)(v6 + ((unsigned __int64)((unsigned __int8)v7 & 0xC0) >> 3) + 976) >> v7) & 1) != 0 )
    *a2 = v7 | 0x80000;
  v8 = gen8_hfi_queue_write(a1, 0, a2, a3);
  *a2 &= 0xFFF3FFFF;
  v9 = v8;
  __dsb(0xEu);
  if ( !v8 )
    gmu_core_regwrite(a1, 129428, 1);
  raw_spin_unlock(v6 + 972);
  return v9;
}
