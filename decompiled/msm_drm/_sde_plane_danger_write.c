__int64 __fastcall sde_plane_danger_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 result; // x0
  __int64 v5; // x20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x9
  size_t v10; // x22
  unsigned __int64 v11; // x1
  unsigned __int64 v12; // x9
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x8
  unsigned __int64 v21; // x9
  __int64 v22; // x0
  int v23; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-18h] BYREF
  __int16 v25; // [xsp+10h] [xbp-10h]
  __int64 v26; // [xsp+18h] [xbp-8h]

  result = -14;
  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 > 9 )
    goto LABEL_24;
  v5 = *(_QWORD *)(a1 + 32);
  if ( !*(_QWORD *)(v5 + 152) )
    goto LABEL_24;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  _check_object_size(&v24, a3, 0);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v9 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v9 = a2 & ((__int64)(a2 << 8) >> 8);
  v10 = a3;
  if ( 0x8000000000LL - a3 >= v9 )
  {
    v12 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v18 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v18 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v18);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v12);
    v10 = _arch_copy_from_user(&v24, a2 & 0xFF7FFFFFFFFFFFFFLL, a3);
    v19 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v21 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v21 - 4096);
    _WriteStatusReg(TTBR1_EL1, v21);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v19);
    if ( !v10 )
      goto LABEL_14;
  }
  if ( a3 - v10 <= 0xA )
    v11 = 10 - (a3 - v10);
  else
    v11 = 0;
  if ( v11 >= v10 )
  {
    memset((char *)&v24 + a3 - v10, 0, v10);
    if ( v10 )
    {
LABEL_15:
      result = -14;
LABEL_24:
      _ReadStatusReg(SP_EL0);
      return result;
    }
LABEL_14:
    *((_BYTE *)&v24 + a3) = 0;
    if ( !(unsigned int)kstrtoint(&v24, 0, &v23) )
    {
      if ( v23 )
      {
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "Disabling danger:\n");
        sde_plane_set_danger_state(v5);
        *(_BYTE *)(v5 + 3652) = 0;
      }
      else
      {
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "Enabling danger:\n");
        *(_BYTE *)(v5 + 3652) = 1;
        sde_plane_set_danger_state(v5);
      }
      result = a3;
      goto LABEL_24;
    }
    goto LABEL_15;
  }
  v22 = _fortify_panic(15, v11, v10);
  return sde_plane_set_danger_state(v22);
}
