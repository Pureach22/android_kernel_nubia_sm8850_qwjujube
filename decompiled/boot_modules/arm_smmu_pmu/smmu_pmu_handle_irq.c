__int64 __fastcall smmu_pmu_handle_irq(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 v5; // x8
  unsigned int v6; // w8
  __int64 v7; // x22
  unsigned int next_bit; // w0
  unsigned int v9; // w20
  __int64 v10; // x21
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 result; // x0
  _QWORD v15[2]; // [xsp+0h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 2480) + 3264LL));
  v4 = (unsigned int)v3;
  writel_relaxed(v3, *(_QWORD *)(a2 + 2480) + 3200LL);
  v5 = *(_QWORD *)(a2 + 2512);
  v15[0] = v4;
  if ( (v5 & v4) == 0 )
  {
    result = 0;
    goto LABEL_16;
  }
  v6 = 0;
  v7 = a2 + 16;
  while ( 1 )
  {
    next_bit = find_next_bit(v15, *(unsigned int *)(a2 + 2464), v6);
    v9 = next_bit;
    if ( *(_DWORD *)(a2 + 2464) <= next_bit )
      break;
    if ( next_bit >= 0x100uLL )
      goto LABEL_17;
    v10 = *(_QWORD *)(v7 + 8LL * next_bit);
    if ( v10 )
    {
      v11 = smmu_pmu_event_update(*(_QWORD *)(v7 + 8LL * next_bit));
      v12 = *(unsigned int *)(v10 + 396);
      if ( (unsigned int)v12 >= 0x100 )
LABEL_17:
        __break(0x5512u);
      if ( (*(_QWORD *)(*(_QWORD *)(v7 + 8 * v12) + 224LL) & 0xFF80LL) == 0 )
      {
        *(_QWORD *)(v10 + 488) = 0x80000000LL;
        v13 = *(_QWORD *)(a2 + 2480);
        if ( *(_BYTE *)(a2 + 2528) == 1 )
          writel_relaxed(0x80000000LL, v13 + (unsigned int)(4 * v12));
        else
          writeq_relaxed(v11, v13 + 8 * v12);
        __dsb(0xEu);
        goto LABEL_5;
      }
      *(_QWORD *)(v10 + 488) = (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 2496)
                                                                          + (unsigned __int16)*(_QWORD *)(*(_QWORD *)(v7 + 8 * v12) + 224LL)
                                                                          + 1280LL));
      v6 = v9 + 1;
    }
    else
    {
LABEL_5:
      v6 = v9 + 1;
    }
  }
  result = 1;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
