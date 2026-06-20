__int64 __fastcall sde_connector_set_prop_retire_fence(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  int v6; // w21
  __int64 hw_ctl; // x3
  unsigned int v8; // w0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v10; // x9
  unsigned __int64 v11; // x9
  unsigned __int64 v17; // x8
  int v18; // w0
  unsigned __int64 v19; // x8
  unsigned __int64 v21; // x9
  __int64 result; // x0
  unsigned int v23; // w19
  __int64 v24; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v25[2]; // [xsp+10h] [xbp-10h] BYREF

  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  v25[0] = 0;
  if ( (unsigned int)inline_copy_from_user_4((int)&v24, a3, 8u) )
  {
    printk(&unk_276C1D, "_sde_connector_set_prop_retire_fence");
    result = 4294967282LL;
    goto LABEL_15;
  }
  if ( v24 == -1 )
  {
    v6 = *(_DWORD *)(a2 + 896);
    if ( *(_DWORD *)(a1 + 2736) != 15 )
      goto LABEL_7;
    if ( !a1 )
    {
      printk(&unk_242658, "sde_connector_best_encoder");
      hw_ctl = 0;
      goto LABEL_8;
    }
    if ( *(_QWORD *)(a1 + 2744) && (((__int64 (*)(void))sde_encoder_in_clone_mode)() & 1) == 0 )
      hw_ctl = sde_encoder_get_hw_ctl(a1);
    else
LABEL_7:
      hw_ctl = 0;
LABEL_8:
    v8 = sde_fence_create(*(_QWORD *)(a1 + 2864), v25, (unsigned int)(v6 + 1), hw_ctl);
    if ( v8 )
    {
      v23 = v8;
      printk(&unk_21219E, "_sde_connector_set_prop_retire_fence");
      result = v23;
      goto LABEL_15;
    }
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v10 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v10 = a3 & ((__int64)(a3 << 8) >> 8);
    if ( v10 > 0x7FFFFFFFF8LL )
      goto LABEL_19;
    v11 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v17 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v17 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v17);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v11);
    v18 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL);
    v19 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v21 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v21 - 4096);
    _WriteStatusReg(TTBR1_EL1, v21);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v19);
    if ( v18 )
    {
LABEL_19:
      printk(&unk_2121D2, "_sde_connector_set_prop_retire_fence");
      put_unused_fd(LODWORD(v25[0]));
      result = 4294967282LL;
      goto LABEL_15;
    }
  }
  result = 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
