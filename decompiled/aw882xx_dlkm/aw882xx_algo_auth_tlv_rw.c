__int64 __fastcall aw882xx_algo_auth_tlv_rw(__int64 a1, int a2, unsigned int a3, unsigned __int64 a4)
{
  __int64 (*v9)(void); // x8
  __int64 v10; // x0
  __int64 (__fastcall *v11)(); // x8
  __int64 v12; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v14; // x9
  unsigned __int64 v15; // x9
  unsigned __int64 v21; // x8
  __int64 v22; // x0
  unsigned __int64 v23; // x8
  unsigned __int64 v25; // x9
  __int64 result; // x0
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x9
  __int64 v29; // x20
  unsigned __int64 v30; // x9
  unsigned __int64 v32; // x8
  size_t v33; // x2
  unsigned __int64 v34; // x8
  unsigned __int64 v36; // x9
  unsigned int v37; // w20
  __int64 v38; // x19
  __int64 *v39; // x8
  __int64 v40; // x1
  __int64 *v41; // x8
  __int64 v42; // x1
  __int64 v43; // x0
  _QWORD v45[2]; // [xsp+0h] [xbp-20h] BYREF
  int v46; // [xsp+10h] [xbp-10h]
  __int64 v47; // [xsp+18h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = aw_componet_codec_ops[0];
  if ( *((_DWORD *)aw_componet_codec_ops[0] - 1) != 1008210333 )
    __break(0x8228u);
  v10 = v9();
  v11 = off_350;
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8228u);
  v12 = ((__int64 (__fastcall *)(__int64))v11)(v10);
  v46 = 0;
  v45[0] = 0;
  v45[1] = 0;
  if ( !a4 )
  {
    v39 = *(__int64 **)(v12 + 64);
    v40 = v39[14];
    if ( !v40 )
      v40 = *v39;
    printk(&unk_25CCB, v40, "aw882xx_algo_auth_tlv_rw");
    result = 4294967274LL;
    goto LABEL_28;
  }
  if ( a3 <= 0x13 )
  {
    v41 = *(__int64 **)(v12 + 64);
    v42 = v41[14];
    if ( !v42 )
      v42 = *v41;
    printk(&unk_26F49, v42, "aw882xx_algo_auth_tlv_rw");
    result = 4294967274LL;
    goto LABEL_28;
  }
  if ( a2 != 1 )
  {
    if ( a2 )
    {
      result = 4294967274LL;
    }
    else
    {
      aw882xx_dev_algo_auth_get(*(_QWORD *)(v12 + 96), v45);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v14 = a4, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v14 = a4 & ((__int64)(a4 << 8) >> 8);
      if ( v14 >= 0x7FFFFFFFEDLL )
      {
        result = 4294967282LL;
      }
      else
      {
        v15 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v21 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v21 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v21);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v15);
        v22 = _arch_copy_to_user(a4 & 0xFF7FFFFFFFFFFFFFLL, v45, 20);
        v23 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v25 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v25 - 4096);
        _WriteStatusReg(TTBR1_EL1, v25);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v23);
        if ( v22 )
          result = 4294967282LL;
        else
          result = 0;
      }
    }
    goto LABEL_28;
  }
  v27 = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(v27 + 70) & 0x20) != 0 || (v28 = a4, (*(_QWORD *)v27 & 0x4000000) != 0) )
    v28 = a4 & ((__int64)(a4 << 8) >> 8);
  if ( v28 >= 0x7FFFFFFFEDLL )
  {
    v33 = 20;
  }
  else
  {
    v29 = v12;
    v30 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v32 = *(_QWORD *)(v27 + 8);
    _WriteStatusReg(TTBR1_EL1, v32 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v32);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v30);
    v33 = _arch_copy_from_user(v45, a4 & 0xFF7FFFFFFFFFFFFFLL, 20);
    v34 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v36 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v36 - 4096);
    _WriteStatusReg(TTBR1_EL1, v36);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v34);
    v12 = v29;
    if ( !v33 )
    {
      v37 = 0;
LABEL_27:
      aw882xx_dev_algo_auth_set(*(_QWORD *)(v12 + 96), v45);
      result = v37;
LABEL_28:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  if ( v33 < 0x15 )
  {
    v38 = v12;
    memset((char *)&v45[2] - v33 + 4, 0, v33);
    v37 = -14;
    v12 = v38;
    goto LABEL_27;
  }
  v43 = _fortify_panic(15);
  __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
  return aw882xx_get_rx_en(v43);
}
