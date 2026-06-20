__int64 __fastcall f_cdev_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  unsigned __int64 v5; // x20
  __int64 v7; // x0
  _QWORD *v8; // x27
  unsigned __int64 v9; // x26
  __int64 v10; // x24
  __int64 v11; // x9
  __int64 v12; // x22
  __int64 v13; // x23
  unsigned __int64 StatusReg; // x28
  _QWORD *v15; // x10
  _QWORD *v16; // x8
  __int64 v17; // x11
  unsigned __int64 v18; // x25
  unsigned __int64 v19; // x8
  __int64 v20; // x0
  unsigned __int64 v21; // x8
  unsigned __int64 v27; // x9
  unsigned __int64 v28; // x8
  unsigned __int64 v30; // x9
  unsigned __int64 v31; // x25
  bool v32; // cc
  _QWORD *v33; // x0
  _QWORD *v34; // x1
  __int64 v35; // x1
  __int64 v36; // x2
  __int64 v37; // x3
  _QWORD *v38; // x0
  _QWORD *v39; // x1
  _QWORD *v41; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 )
  {
    v5 = a3;
    v7 = raw_spin_lock_irqsave(v4 + 1068);
    v8 = *(_QWORD **)(v4 + 1168);
    *(_QWORD *)(v4 + 1168) = 0;
    v9 = *(_QWORD *)(v4 + 1176);
    *(_QWORD *)(v4 + 1176) = 0;
    v10 = *(_QWORD *)(v4 + 1184);
    *(_QWORD *)(v4 + 1184) = 0;
    v41 = (_QWORD *)(v4 + 1136);
    v11 = v7;
    if ( *(_QWORD *)(v4 + 1136) != v4 + 1136 || v9 )
    {
      v12 = 0;
      v13 = v4 + 1120;
      StatusReg = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        if ( v9 )
        {
          if ( !v5 )
            goto LABEL_34;
        }
        else
        {
          v15 = (_QWORD *)*v41;
          if ( (_QWORD *)*v41 == v41 || !v5 )
          {
LABEL_34:
            *(_QWORD *)(v4 + 1176) = v9;
            *(_QWORD *)(v4 + 1184) = v10;
            *(_QWORD *)(v4 + 1168) = v8;
            goto LABEL_35;
          }
          v16 = (_QWORD *)v15[1];
          if ( (_QWORD *)*v16 == v15 && (v17 = *v15, *(_QWORD **)(*v15 + 8LL) == v15) )
          {
            *(_QWORD *)(v17 + 8) = v16;
            *v16 = v17;
          }
          else
          {
            _list_del_entry_valid_or_report(*v41);
          }
          *v15 = v15;
          v8 = v15 - 8;
          v15[1] = v15;
          v9 = *((unsigned int *)v15 + 6);
          v10 = *(v15 - 8);
        }
        raw_spin_unlock_irqrestore(v4 + 1068, v11);
        v18 = v5 >= v9 ? v9 : v5;
        if ( v18 >> 31 )
        {
          v20 = v18;
          __break(0x800u);
        }
        else
        {
          _check_object_size(v10, v18, 1);
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v19 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v19 = a2 & ((__int64)(a2 << 8) >> 8);
          v20 = v18;
          if ( 0x8000000000LL - v18 >= v19 )
          {
            v21 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v27 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v27 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v27);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v21);
            v20 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v10, v18);
            v28 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v30 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v30 - 4096);
            _WriteStatusReg(TTBR1_EL1, v30);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v28);
          }
        }
        v31 = v18 - v20;
        *(_QWORD *)(v4 + 1584) += v31;
        v11 = raw_spin_lock_irqsave(v4 + 1068);
        if ( (*(_BYTE *)(v4 + 1560) & 1) == 0 )
          break;
        v32 = v9 > v31;
        v9 -= v31;
        v12 += v31;
        v5 -= v31;
        a2 += v31;
        if ( v32 )
        {
          v10 += v31;
        }
        else
        {
          v33 = v8 + 8;
          v34 = *(_QWORD **)(v4 + 1128);
          if ( v8 + 8 == (_QWORD *)v13 || v34 == v33 || *v34 != v13 )
          {
            _list_add_valid_or_report(v33, v34);
            v9 = 0;
            v10 = 0;
            v8 = nullptr;
          }
          else
          {
            v9 = 0;
            v10 = 0;
            *(_QWORD *)(v4 + 1128) = v33;
            v8[8] = v13;
            v8[9] = v34;
            v8 = nullptr;
            *v34 = v33;
          }
        }
      }
      v38 = v8 + 8;
      v39 = *(_QWORD **)(v4 + 1128);
      if ( v8 + 8 == (_QWORD *)v13 || v39 == v38 || *v39 != v13 )
      {
        _list_add_valid_or_report(v38, v39);
      }
      else
      {
        *(_QWORD *)(v4 + 1128) = v38;
        v8[8] = v13;
        v8[9] = v39;
        *v39 = v38;
      }
      raw_spin_unlock_irqrestore(v4 + 1068, v11);
      return -11;
    }
    else
    {
      v12 = 0;
LABEL_35:
      raw_spin_unlock_irqrestore(v4 + 1068, v11);
      usb_cser_start_rx(v4, v35, v36, v37);
    }
  }
  else
  {
    printk(&unk_90C6, "f_cdev_read", a3, a4);
    return -22;
  }
  return v12;
}
