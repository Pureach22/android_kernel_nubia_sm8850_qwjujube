__int64 __fastcall sde_debugfs_hw_fence_features_mask_rd(
        __int64 a1,
        unsigned __int64 a2,
        unsigned __int64 a3,
        __int64 *a4)
{
  __int64 v4; // x9
  __int64 v5; // x22
  unsigned int v8; // w0
  unsigned __int64 v9; // x23
  int v10; // w0
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x19
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x8
  unsigned __int64 v21; // x9
  _QWORD v23[33]; // [xsp+8h] [xbp-108h] BYREF

  v23[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a4;
  memset(v23, 0, 256);
  if ( v4 )
    JUMPOUT(0xD0460);
  if ( !a1 || (v5 = *(_QWORD *)(a1 + 32)) == 0 )
    JUMPOUT(0xD0444);
  v8 = scnprintf(v23, 256, "bit %d: %d\n", 0, *(_DWORD *)(v5 + 7928) & 1);
  if ( v8 > 0x100
    || (v9 = v8
           + (__int64)(int)scnprintf(
                             (char *)v23 + v8,
                             256LL - v8,
                             "bit %d: %d\n",
                             1,
                             ((unsigned int)*(_QWORD *)(v5 + 7928) >> 1) & 1),
        v9 > 0x100) )
  {
    __break(0x5512u);
    JUMPOUT(0xD04B0);
  }
  v10 = scnprintf((char *)v23 + v9, 256 - v9, "bit %d: %d\n", 2, ((unsigned int)*(_QWORD *)(v5 + 7928) >> 2) & 1);
  v11 = v9 + v10;
  if ( v11 >= a3 )
    JUMPOUT(0xD044C);
  v12 = v9 + v10;
  if ( v11 >= 0x101 )
    JUMPOUT(0xD0494);
  _check_object_size(v23, v11, 1);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v14 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v14 = a2 & ((__int64)(a2 << 8) >> 8);
  if ( 0x8000000000LL - v12 < v14 )
    JUMPOUT(0xD0438);
  v15 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v21 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v21 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v21);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v15);
  return sub_D03F4(v12);
}
