unsigned __int64 __fastcall a6xx_preemption_pre_ibsubmit(__int64 a1, _QWORD *a2, __int64 a3, __int64 a4)
{
  int v5; // w9
  unsigned __int64 v6; // x8
  char v7; // w10
  __int64 v8; // x8
  unsigned __int64 v9; // x10
  __int64 v10; // x19
  __int64 v11; // x21

  if ( (*(_QWORD *)(a1 + 14240) & 0x200) == 0 )
    return 0;
  v5 = 1893105676;
  if ( !a3 )
  {
    v6 = 0;
LABEL_8:
    v7 = 1;
    goto LABEL_9;
  }
  v6 = *(_QWORD *)(a3 + 272);
  if ( !v6 )
    goto LABEL_8;
  v6 = *(_QWORD *)(v6 + 32);
  if ( !v6 )
    goto LABEL_8;
  v7 = 0;
  v5 = 1893105679;
LABEL_9:
  *(_DWORD *)a4 = v5;
  *(_QWORD *)(a4 + 4) = 0;
  *(_QWORD *)(a4 + 12) = 0x100000000LL;
  *(_QWORD *)(a4 + 20) = *(_QWORD *)(a2[23] + 24LL);
  *(_DWORD *)(a4 + 28) = 2;
  *(_QWORD *)(a4 + 32) = *(_QWORD *)(a2[24] + 24LL);
  if ( (v7 & 1) != 0 )
  {
    v8 = a4 + 40;
  }
  else
  {
    v9 = HIDWORD(v6);
    *(_DWORD *)(a4 + 40) = 3;
    *(_DWORD *)(a4 + 44) = v6;
    v8 = a4 + 52;
    *(_DWORD *)(a4 + 48) = v9;
  }
  v10 = v8 + 12;
  *(_DWORD *)v8 = 4;
  *(_QWORD *)(v8 + 4) = *(_QWORD *)(a2[25] + 24LL);
  if ( a3 )
  {
    v11 = a4;
    v10 += 4LL * (unsigned int)adreno_prepare_preib_preempt_scratch(a1, a3);
    if ( (*(_BYTE *)(a1 + 23968) & 1) == 0 )
      v10 += 4LL * (unsigned int)adreno_prepare_preib_postamble_scratch(a1, v10);
    a4 = v11;
  }
  return (unsigned __int64)(v10 - a4) >> 2;
}
