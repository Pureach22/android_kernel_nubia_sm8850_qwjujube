__int64 __fastcall tpdm_disable(__int64 result)
{
  __int64 *v1; // x20
  __int64 v2; // x19
  __int64 v3; // x8
  int v4; // w0
  int v5; // w0
  __int64 v6; // x8

  v1 = *(__int64 **)(*(_QWORD *)(result + 152) + 152LL);
  if ( (unsigned int)*(_QWORD *)(result + 968) == 1 )
  {
    v2 = result;
    raw_spin_lock(v1 + 3);
    writel_relaxed(3316436565LL, *v1 + 4016);
    __dsb(0xFu);
    v3 = v1[4];
    if ( (v3 & 2) != 0 )
    {
      v4 = readl_relaxed((unsigned int *)(*v1 + 1920));
      writel_relaxed(v4 & 0xFFFFFFFE, *v1 + 1920);
      v3 = v1[4];
    }
    if ( (v3 & 0x44) != 0 )
    {
      v5 = readl_relaxed((unsigned int *)(*v1 + 2560));
      writel_relaxed(v5 & 0xFFFFFFFE, *v1 + 2560);
    }
    v6 = *v1;
    __dsb(0xFu);
    writel_relaxed(0, v6 + 4016);
    coresight_csr_set_etr_atid(v2, *((unsigned int *)v1 + 7), 0, 0);
    *((_DWORD *)v1 + 7) = 0;
    result = raw_spin_unlock(v1 + 3);
    *(_QWORD *)(v2 + 968) = 0;
  }
  return result;
}
