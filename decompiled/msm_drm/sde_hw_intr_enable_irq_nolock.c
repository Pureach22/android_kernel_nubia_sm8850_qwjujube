__int64 __fastcall sde_hw_intr_enable_irq_nolock(__int64 a1, unsigned int a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  unsigned int v4; // w2
  int v5; // w9
  unsigned int *v7; // x22
  unsigned int v8; // w20

  if ( !a1 )
    return 4294967274LL;
  if ( (a2 & 0x80000000) != 0 || *(_DWORD *)(a1 + 328) <= a2 )
  {
    printk(&unk_25F8CA, a2);
    return 4294967274LL;
  }
  v2 = *(_QWORD *)(a1 + 336) + 16LL * a2;
  v3 = *(unsigned int *)(v2 + 12);
  if ( (v3 & 0x80000000) != 0 || (unsigned int)v3 > *(_DWORD *)(a1 + 312) )
  {
    printk(&unk_23281D, (unsigned int)v3);
    return 4294967274LL;
  }
  v4 = *(_DWORD *)(v2 + 8);
  v5 = *(_DWORD *)(*(_QWORD *)(a1 + 296) + 4 * v3);
  if ( (v4 & v5) != 0 )
    return 0;
  v7 = (unsigned int *)(*(_QWORD *)(a1 + 320) + 20LL * (unsigned int)v3);
  v8 = v4 | v5;
  sde_reg_write(a1, *v7, v4, "reg->clr_off");
  sde_reg_write(a1, v7[1], v8, "reg->en_off");
  __dsb(0xEu);
  *(_DWORD *)(*(_QWORD *)(a1 + 296) + 4 * v3) = v8;
  return 0;
}
