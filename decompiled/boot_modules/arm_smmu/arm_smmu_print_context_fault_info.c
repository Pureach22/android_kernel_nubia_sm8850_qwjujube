__int64 __fastcall arm_smmu_print_context_fault_info(_QWORD *a1, __int64 a2, __int64 a3)
{
  int v5; // w2
  const char *v6; // x4
  const char *v7; // x5
  const char *v8; // x6
  const char *v9; // x7
  const char *v10; // x8
  const char *v11; // x9

  dev_err(*a1, "FSR    = %08x [%s%sFormat=%u%s%s%s%s%s%s%s%s], SID=0x%x\n");
  v5 = *(_DWORD *)(a3 + 12);
  if ( (v5 & 0x800) != 0 )
    v6 = " AFR";
  else
    v6 = (const char *)&unk_17C28;
  if ( (v5 & 0x400) != 0 )
    v7 = " PTWF";
  else
    v7 = (const char *)&unk_17C28;
  if ( (v5 & 0x100) != 0 )
    v8 = " NSATTR";
  else
    v8 = (const char *)&unk_17C28;
  if ( (v5 & 0x40) != 0 )
    v9 = " IND";
  else
    v9 = (const char *)&unk_17C28;
  if ( (v5 & 0x20) != 0 )
    v10 = " PNU";
  else
    v10 = (const char *)&unk_17C28;
  v11 = " WNR";
  if ( (v5 & 0x10) == 0 )
    v11 = (const char *)&unk_17C28;
  return dev_err(
           *a1,
           "FSYNR0 = %08x [S1CBNDX=%u%s%s%s%s%s%s PLVL=%u]\n",
           *(_DWORD *)(a3 + 12),
           (unsigned __int8)BYTE2(*(_DWORD *)(a3 + 12)),
           v6,
           v7,
           v8,
           v9,
           v10,
           v11,
           *(_DWORD *)(a3 + 12) & 3);
}
