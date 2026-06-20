__int64 __fastcall hal_srng_dst_set_hp_paddr_confirm(__int64 a1, unsigned __int64 a2)
{
  __int64 v3; // x0
  __int64 v5; // x1
  __int64 v6; // x0
  __int64 v7; // x1

  v3 = *(_QWORD *)(a1 + 160);
  v5 = *(_QWORD *)(a1 + 96) + *(int *)(v3 + 74280);
  if ( (*(_BYTE *)(v3 + 74224) & 1) != 0 )
    hal_write32_mb_confirm(v3, (unsigned int)(v5 - *(_DWORD *)(v3 + 16)), (unsigned int)a2);
  else
    writel_6((unsigned int)a2, v5);
  v6 = *(_QWORD *)(a1 + 160);
  v7 = *(_QWORD *)(a1 + 96) + *(int *)(v6 + 74284);
  if ( (*(_BYTE *)(v6 + 74224) & 1) != 0 )
    return hal_write32_mb_confirm(v6, (unsigned int)(v7 - *(_DWORD *)(v6 + 16)), HIDWORD(a2));
  else
    return writel_6(HIDWORD(a2), v7);
}
