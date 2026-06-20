__int64 __fastcall qbt_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  _DWORD *v6; // x24
  int v7; // w23
  __int64 v8; // x22
  __int64 v9; // x26
  __int64 v10; // x27
  __int64 v11; // x25
  int v12; // w26
  int v13; // w22
  _DWORD *v14; // x21
  int v15; // w8
  __int64 v16; // x25
  _QWORD *v17; // x26
  int v18; // w8
  _QWORD *v19; // x8
  __int64 v20; // x9
  __int64 v21; // x10
  __int64 v22; // x8
  __int64 v23; // x11
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v25; // x9
  __int64 v26; // x22
  unsigned __int64 v27; // x9
  unsigned __int64 v33; // x8
  unsigned __int64 v34; // x8
  unsigned __int64 v36; // x9
  __int64 v37; // x22
  __int64 v38; // x26
  __int64 v39; // x27
  int v40; // w26
  __int64 v41; // x22
  __int64 v42; // x26
  __int64 v43; // x27
  int v44; // w26
  __int64 v45; // x22
  __int64 v46; // x26
  __int64 v47; // x27
  __int64 v48; // x28
  int v49; // w27
  void *v50; // x0
  __int64 v51; // x0
  int v52; // w8
  _QWORD v54[5]; // [xsp+8h] [xbp-38h] BYREF
  int v55; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v56; // [xsp+38h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v55 = 0;
  printk(&unk_99DD, "qbt_read");
  if ( !a1 || (v6 = *(_DWORD **)(a1 + 32)) == nullptr )
  {
    v50 = &unk_9A11;
LABEL_48:
    printk(v50, "qbt_read");
    v26 = -22;
    goto LABEL_49;
  }
  v7 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 76LL) & 0xFFFFF;
  memset(v6 + 288, 0, 0x1408u);
  if ( v7 )
  {
    if ( v7 != 1 )
    {
      v50 = &unk_9C65;
      goto LABEL_48;
    }
    if ( a3 > 3 )
    {
      v8 = 2859;
      v9 = 2858;
      v10 = 102;
      v11 = 280;
      goto LABEL_9;
    }
    goto LABEL_44;
  }
  if ( a3 >> 3 <= 0x280 )
  {
LABEL_44:
    v50 = &unk_A2CC;
    goto LABEL_48;
  }
  v8 = 1573;
  v9 = 1572;
  v10 = 90;
  v11 = 274;
LABEL_9:
  mutex_lock(&v6[v10]);
  v12 = v6[v9];
  v13 = v6[v8];
  mutex_unlock(&v6[v10]);
  if ( v12 == v13 )
  {
    do
    {
      if ( (*(_BYTE *)(a1 + 49) & 8) != 0 )
      {
        printk(&unk_925A, "qbt_read");
        v26 = -11;
        goto LABEL_49;
      }
      if ( v7 )
      {
        v41 = 102;
        v42 = 2858;
        v43 = 2859;
      }
      else
      {
        v41 = 90;
        v42 = 1572;
        v43 = 1573;
      }
      mutex_lock(&v6[v41]);
      v44 = v6[v42] - v6[v43];
      mutex_unlock(&v6[v41]);
      if ( v44 > 0 )
      {
LABEL_38:
        if ( v7 )
        {
LABEL_39:
          v37 = 102;
          v38 = 2858;
          v39 = 2859;
          goto LABEL_24;
        }
      }
      else
      {
        memset(v54, 0, sizeof(v54));
        init_wait_entry(v54, 0);
        while ( 1 )
        {
          v45 = prepare_to_wait_event(&v6[v11], v54, 1);
          if ( v7 )
          {
            v46 = 102;
            v47 = 2858;
            v48 = 2859;
          }
          else
          {
            v46 = 90;
            v47 = 1572;
            v48 = 1573;
          }
          mutex_lock(&v6[v46]);
          v49 = v6[v47] - v6[v48];
          mutex_unlock(&v6[v46]);
          if ( v49 > 0 )
            break;
          if ( v45 )
          {
            if ( !(_DWORD)v45 )
              goto LABEL_38;
            v26 = -512;
            goto LABEL_49;
          }
          schedule();
        }
        finish_wait(&v6[v11], v54);
        if ( v7 )
          goto LABEL_39;
      }
      v37 = 90;
      v38 = 1572;
      v39 = 1573;
LABEL_24:
      mutex_lock(&v6[v37]);
      v40 = v6[v38] - v6[v39];
      mutex_unlock(&v6[v37]);
    }
    while ( !v40 );
  }
  if ( v7 )
  {
    v14 = v6 + 102;
    v51 = mutex_lock(v6 + 102);
    v52 = v6[2859];
    if ( v6[2858] == v52 )
    {
      v51 = printk(&unk_9D32, "qbt_read");
    }
    else
    {
      v55 = v6[(v6[2860] & v52) + 2864];
      __dmb(0xAu);
      ++v6[2859];
    }
    ktime_get(v51);
    printk(&unk_96F3, "qbt_read");
    v26 = inline_copy_to_user(a2, &v55, 4);
  }
  else
  {
    v14 = v6 + 90;
    mutex_lock(v6 + 90);
    v15 = v6[1572] - v6[1573];
    v6[288] = v15;
    if ( v15 )
    {
      v16 = 0;
      v17 = v6 + 290;
      while ( 1 )
      {
        if ( v16 == 129 )
          __break(0x5512u);
        v18 = v6[1573];
        if ( v6[1572] == v18 )
          break;
        v19 = &v6[10 * (v6[1574] & v18) + 1578];
        *v17 = *v19;
        v21 = v19[3];
        v20 = v19[4];
        v23 = v19[1];
        v22 = v19[2];
        v17[3] = v21;
        v17[4] = v20;
        v17[1] = v23;
        v17[2] = v22;
        __dmb(0xAu);
        ++v6[1573];
        v17 += 5;
        printk(&unk_9A30, "qbt_read");
        if ( ++v16 >= (unsigned __int64)(unsigned int)v6[288] )
          goto LABEL_16;
      }
      printk(&unk_9F6A, "qbt_read");
      v6[288] = v16;
    }
LABEL_16:
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v25 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v25 = a2 & ((__int64)(a2 << 8) >> 8);
    v26 = 5128;
    if ( v25 <= 0x7FFFFFEBF8LL )
    {
      v27 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v33 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v33 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v33);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v27);
      v26 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v6 + 288, 5128);
      v34 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v36 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v36 - 4096);
      _WriteStatusReg(TTBR1_EL1, v36);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v34);
    }
  }
  mutex_unlock(v14);
  if ( v26 )
    printk(&unk_972E, "qbt_read");
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return v26;
}
