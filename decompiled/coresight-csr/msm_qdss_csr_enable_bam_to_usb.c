__int64 __fastcall msm_qdss_csr_enable_bam_to_usb(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  unsigned int v3; // w9

  if ( result
    && result != 120
    && (unsigned __int64)(result - 120) <= 0xFFFFFFFFFFFFF000LL
    && *(_BYTE *)(result + 36) == 1 )
  {
    v1 = result;
    v2 = raw_spin_lock_irqsave(result + 32);
    *(_DWORD *)(*(_QWORD *)(v1 - 120) + 4016LL) = -978530731;
    __dsb(0xFu);
    v3 = *(_DWORD *)(*(_QWORD *)(v1 - 120) + 48LL) & 0xFFFFFFFC | *(_DWORD *)(v1 - 56);
    *(_DWORD *)(*(_QWORD *)(v1 - 120) + 48LL) = v3;
    *(_DWORD *)(*(_QWORD *)(v1 - 120) + 48LL) = v3 | 4;
    __dsb(0xFu);
    *(_DWORD *)(*(_QWORD *)(v1 - 120) + 4016LL) = 0;
    return raw_spin_unlock_irqrestore(v1 + 32, v2);
  }
  return result;
}
