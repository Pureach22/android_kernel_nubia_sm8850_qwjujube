__int64 __fastcall msm_qdss_csr_enable_flush(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x1
  int v3; // w10

  if ( result
    && result != 120
    && (unsigned __int64)(result - 120) <= 0xFFFFFFFFFFFFF000LL
    && *(_BYTE *)(result + 36) == 1 )
  {
    v1 = result;
    v2 = raw_spin_lock_irqsave(result + 32);
    *(_DWORD *)(*(_QWORD *)(v1 - 120) + 4016LL) = -978530731;
    __dsb(0xFu);
    *(_DWORD *)(*(_QWORD *)(v1 - 120) + 52LL) = *(_DWORD *)(*(_QWORD *)(v1 - 120) + 52LL) & 0xFFFC0003
                                              | (4 * *(_DWORD *)(v1 - 52));
    __dsb(0xFu);
    *(_DWORD *)(*(_QWORD *)(v1 - 120) + 4016LL) = 0;
    *(_DWORD *)(*(_QWORD *)(v1 - 120) + 4016LL) = -978530731;
    __dsb(0xFu);
    if ( *(_BYTE *)(v1 + 37) )
      v3 = 262146;
    else
      v3 = 2;
    *(_DWORD *)(*(_QWORD *)(v1 - 120) + 52LL) |= v3;
    __dsb(0xFu);
    *(_DWORD *)(*(_QWORD *)(v1 - 120) + 4016LL) = 0;
    *(_BYTE *)(v1 + 41) = 1;
    return raw_spin_unlock_irqrestore(v1 + 32, v2);
  }
  return result;
}
