__int64 __fastcall adc5_gen3_isr(unsigned int a1, _QWORD *a2, __int64 a3)
{
  __int64 v4; // x1
  int v5; // w8
  __int64 v6; // x9
  __int64 v7; // x21
  __int64 v8; // x20
  unsigned int v9; // w0
  unsigned int v10; // w0
  unsigned int v11; // w0
  char v12; // w8
  unsigned int v13; // w0
  _QWORD *v14; // x2
  __int64 v15; // x9
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 result; // x0
  void *v20; // x0
  unsigned int v21; // w19
  __int64 v22; // x1
  _BYTE v23[4]; // [xsp+4h] [xbp-1Ch] BYREF
  _BYTE v24[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v25[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v26[4]; // [xsp+10h] [xbp-10h] BYREF
  __int16 v27; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+18h] [xbp-8h]

  v4 = a1;
  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *((_DWORD *)a2 + 9);
  v25[0] = 0;
  v27 = 0;
  v24[0] = 0;
  v23[0] = 0;
  if ( !v5 )
    goto LABEL_29;
  v6 = a2[3];
  v7 = 0;
  v8 = 0;
  while ( *(_DWORD *)(v6 + 24LL * (int)v8 + 16) != a1 )
  {
    ++v8;
    v7 += 24;
    if ( v5 == (_DWORD)v8 )
      goto LABEL_29;
  }
  if ( (v8 & 0x80000000) != 0 )
  {
LABEL_29:
    v20 = &unk_957D;
LABEL_35:
    printk(v20, v4, a3);
LABEL_36:
    result = 0;
    goto LABEL_37;
  }
  v9 = regmap_bulk_read(*a2, (unsigned int)*(unsigned __int16 *)(v6 + v7) + 74, v24, 1);
  if ( (v9 & 0x80000000) != 0 )
  {
    v21 = v9;
    printk(&unk_9458, 74, 1);
    v20 = &unk_9855;
LABEL_34:
    v4 = v21;
    goto LABEL_35;
  }
  v10 = regmap_bulk_read(*a2, (unsigned int)*(unsigned __int16 *)(a2[3] + v7) + 70, v25, 1);
  if ( (v10 & 0x80000000) != 0 )
  {
    v21 = v10;
    printk(&unk_9458, 70, 1);
    v20 = &unk_9435;
    goto LABEL_34;
  }
  v11 = regmap_bulk_read(*a2, (unsigned int)*(unsigned __int16 *)(a2[3] + v7) + 110, v23, 1);
  if ( (v11 & 0x80000000) != 0 )
  {
    v21 = v11;
    printk(&unk_9458, 110, 1);
    v20 = &unk_9671;
    goto LABEL_34;
  }
  v12 = v25[0];
  if ( (v25[0] & 1) != 0 && !v23[0] && (v24[0] & 1) != 0 )
  {
    complete(a2 + 8);
    v12 = v25[0];
  }
  if ( (v12 & 0x80) == 0 )
    goto LABEL_15;
  if ( (unsigned int)__ratelimit(&adc5_gen3_isr__rs, "adc5_gen3_isr") )
    printk(&unk_9934, v25[0], v24[0]);
  ipc_log_string(
    a2[2],
    "Unexpected conversion fault, status:%#x, eoc_status:%#x, conv_err:%#x\n",
    v25[0],
    v24[0],
    v23[0]);
  adc5_gen3_dump_regs_debug((__int64)a2);
  v15 = a2[3];
  v16 = *a2;
  v26[0] = v23[0];
  if ( (regmap_bulk_write(v16, (unsigned int)*(unsigned __int16 *)(v15 + v7) + 78, v26, 1) & 0x80000000) != 0 )
  {
    v22 = 78;
LABEL_41:
    printk(&unk_95F2, v22, 1);
    goto LABEL_36;
  }
  v17 = a2[3];
  v26[0] = 0;
  if ( (regmap_bulk_write(*a2, (unsigned int)*(unsigned __int16 *)(v17 + v7) + 80, v26, 1) & 0x80000000) != 0 )
  {
    v22 = 80;
    goto LABEL_41;
  }
  v18 = a2[3];
  v26[0] = 1;
  if ( (regmap_bulk_write(*a2, (unsigned int)*(unsigned __int16 *)(v18 + v7) + 229, v26, 1) & 0x80000000) != 0 )
  {
    v22 = 229;
    goto LABEL_41;
  }
  if ( !(_DWORD)v8 && (v23[0] & 1) != 0 )
    goto LABEL_28;
  if ( v23[0] )
  {
    raw_spin_lock(a2 + 31);
    *(_BYTE *)(a2[30] + v8) |= v23[0];
    raw_spin_unlock(a2 + 31);
    v14 = a2 + 26;
    goto LABEL_27;
  }
LABEL_15:
  v13 = regmap_bulk_read(*a2, (unsigned int)*(unsigned __int16 *)(a2[3] + v7) + 72, &v27, 2);
  if ( (v13 & 0x80000000) != 0 )
  {
    v21 = v13;
    printk(&unk_9458, 72, 2);
    v20 = &unk_997D;
    goto LABEL_34;
  }
  if ( (unsigned __int8)v27 | HIBYTE(v27) )
  {
    v14 = a2 + 22;
LABEL_27:
    queue_work_on(32, system_wq, v14);
  }
LABEL_28:
  result = 1;
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
