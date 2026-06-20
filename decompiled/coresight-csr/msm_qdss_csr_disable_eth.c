__int64 __fastcall msm_qdss_csr_disable_eth(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0

  if ( result && result != 120 && (unsigned __int64)(result - 120) <= 0xFFFFFFFFFFFFF000LL )
  {
    v1 = result;
    v2 = raw_spin_lock_irqsave(result + 32);
    *(_DWORD *)(*(_QWORD *)(v1 - 120) + 4016LL) = -978530731;
    __dsb(0xFu);
    *(_DWORD *)(*(_QWORD *)(v1 - 120) + 304LL) = 0;
    *(_DWORD *)(*(_QWORD *)(v1 - 120) + 308LL) = 0;
    __dsb(0xFu);
    *(_DWORD *)(*(_QWORD *)(v1 - 120) + 4016LL) = 0;
    return raw_spin_unlock_irqrestore(v1 + 32, v2);
  }
  return result;
}
