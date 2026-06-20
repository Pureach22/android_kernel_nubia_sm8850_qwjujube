__int64 __fastcall synx_read(__int64 a1, unsigned __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x0
  unsigned __int64 client; // x0
  unsigned __int64 v9; // x19
  __int64 v10; // x4
  __int64 v11; // x5
  __int64 v12; // x9
  unsigned __int64 v13; // x20
  __int64 v14; // x21
  void *v15; // x0
  __int64 v16; // x3
  __int64 result; // x0
  _QWORD *v18; // x8
  unsigned __int64 v19; // x9
  __int64 v20; // x10
  __int64 v21; // x4
  __int64 v22; // x5
  unsigned __int64 StatusReg; // x8
  char v24; // w12
  unsigned int v25; // w10
  unsigned int v26; // w11
  unsigned __int64 v27; // x9
  unsigned __int64 v28; // x9
  unsigned __int64 v34; // x8
  __int64 v35; // x0
  unsigned __int64 v36; // x8
  unsigned __int64 v38; // x9
  unsigned __int64 v39; // [xsp+0h] [xbp-30h] BYREF
  __int64 v40; // [xsp+8h] [xbp-28h]
  __int64 v41; // [xsp+10h] [xbp-20h]
  __int64 v42; // [xsp+18h] [xbp-18h]
  __int64 v43; // [xsp+20h] [xbp-10h]
  __int64 v44; // [xsp+28h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 32);
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v39 = 0;
  if ( a3 != 40 )
  {
    if ( (synx_debug & 1) == 0 )
    {
LABEL_16:
      result = -22;
      goto LABEL_33;
    }
    v15 = &unk_27325;
    v16 = 3642;
LABEL_35:
    printk(v15, &unk_29207, "synx_read", v16, a5, a6);
    result = -22;
    goto LABEL_33;
  }
  client = synx_get_client(v6);
  if ( !client || (v9 = client, client >= 0xFFFFFFFFFFFFF001LL) )
  {
    if ( (synx_debug & 1) == 0 )
      goto LABEL_16;
    v15 = &unk_2B010;
    v16 = 3648;
    goto LABEL_35;
  }
  mutex_lock(client + 128);
  v12 = *(_QWORD *)(v9 + 176);
  if ( v12 == v9 + 176 )
    v13 = 0;
  else
    v13 = v12 - 48;
  if ( v13 && v13 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( (unsigned int)(*(_DWORD *)(v13 + 4) - 4096) > 0xFFFFF000 )
    {
      v18 = *(_QWORD **)(v13 + 56);
      v19 = v13 + 48;
      if ( *v18 == v13 + 48 && (v20 = *(_QWORD *)v19, *(_QWORD *)(*(_QWORD *)v19 + 8LL) == v19) )
      {
        *(_QWORD *)(v20 + 8) = v18;
        *v18 = v20;
      }
      else
      {
        _list_del_entry_valid_or_report(v13 + 48);
      }
      *(_QWORD *)(v13 + 48) = v13 + 48;
      *(_QWORD *)(v13 + 56) = v19;
      mutex_unlock(v9 + 128);
      v42 = 0;
      v43 = 0;
      StatusReg = _ReadStatusReg(SP_EL0);
      v24 = *(_BYTE *)(StatusReg + 70);
      v41 = 0;
      v25 = *(_DWORD *)(v13 + 16);
      v26 = *(_DWORD *)(v13 + 20);
      v40 = *(_QWORD *)(v13 + 24);
      v39 = __PAIR64__(v26, v25);
      if ( (v24 & 0x20) != 0 || (v27 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v27 = a2 & ((__int64)(a2 << 8) >> 8);
      if ( v27 > 0x7FFFFFFFD8LL )
        goto LABEL_26;
      v28 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v34 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v34 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v34);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v28);
      v35 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, &v39, 40);
      v36 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v38 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v38 - 4096);
      _WriteStatusReg(TTBR1_EL1, v38);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v36);
      if ( v35 )
      {
LABEL_26:
        if ( (synx_debug & 1) != 0 )
          printk(&unk_27A3B, &unk_29207, "synx_read", 3679, v21, v22);
        v14 = -14;
      }
      else
      {
        v14 = 40;
      }
      if ( (unsigned int)synx_util_clear_cb_entry(v9, v13) && (synx_debug & 1) != 0 )
        printk(&unk_294BE, &unk_29207, "synx_read", 3686, *(_QWORD *)(v9 + 104), (unsigned int)v39);
    }
    else
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_28BDA, &unk_29207, "synx_read", 3662, v10, v11);
      mutex_unlock(v9 + 128);
      v14 = -22;
    }
  }
  else
  {
    mutex_unlock(v9 + 128);
    v14 = 0;
  }
  synx_put_client(v9);
  result = v14;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
