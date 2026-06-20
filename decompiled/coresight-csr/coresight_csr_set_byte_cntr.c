__int64 __fastcall coresight_csr_set_byte_cntr(__int64 result, int a2, int a3)
{
  __int64 v3; // x19
  __int64 v6; // x0

  if ( result
    && result != 120
    && (unsigned __int64)(result - 120) <= 0xFFFFFFFFFFFFF000LL
    && *(_BYTE *)(result + 39) == 1 )
  {
    v3 = result;
    v6 = raw_spin_lock_irqsave(result + 32);
    *(_DWORD *)(*(_QWORD *)(v3 - 120) + 4016LL) = -978530731;
    __dsb(0xFu);
    *(_DWORD *)(*(_QWORD *)(v3 - 120) + a2) = a3;
    __dsb(0xFu);
    __dsb(0xFu);
    *(_DWORD *)(*(_QWORD *)(v3 - 120) + 4016LL) = 0;
    return raw_spin_unlock_irqrestore(v3 + 32, v6);
  }
  return result;
}
