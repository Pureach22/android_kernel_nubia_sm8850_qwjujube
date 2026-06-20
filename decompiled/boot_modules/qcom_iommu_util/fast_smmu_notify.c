__int64 __fastcall fast_smmu_notify(__int64 a1, __int64 a2, _BYTE *a3)
{
  __int64 result; // x0
  _BYTE *v6; // x19
  __int64 v7; // x20
  __int64 v8; // x0
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 == 1 )
  {
    v6 = *(_BYTE **)(*(_QWORD *)(a1 - 16) + 112LL);
    v7 = (a3 - v6) >> 3;
    v8 = *(_QWORD *)(a1 - 112);
    v9[0] = (a3 - v6) << 9;
    dev_err(v8, "Mapped over stale tlb at %pa\n", v9);
    dev_err(*(_QWORD *)(a1 - 112), "bitmap (failure at idx %lu):\n", v7);
    dev_err(*(_QWORD *)(a1 - 112), "ptep: %pK pmds: %pK diff: %lu\n", a3, v6, v7);
    print_hex_dump(&unk_11A06, "bmap: ", 1, 32, 8, *(_QWORD *)(a1 - 56), *(unsigned int *)(a1 - 64), 0);
    result = 1;
  }
  else
  {
    _warn_printk("Unhandled notifier action");
    result = 0;
    __break(0x800u);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
