__int64 __fastcall preemption_store_0(__int64 a1, char a2)
{
  if ( ((*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 32LL) & 4) != 0 || *(_BYTE *)(a1 + 20443) == 1)
    && ((*(_QWORD *)(a1 + 14240) >> 9) & 1) != (a2 & 1) )
  {
    return adreno_power_cycle(a1, (void (__fastcall *)(__int64, __int64))change_preemption_0, 0);
  }
  else
  {
    return 0;
  }
}
