__int64 __fastcall rdbg_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  _QWORD *v3; // x22
  int v6; // w0
  _DWORD *v7; // x8
  __int64 v8; // x9
  int v9; // w21
  unsigned __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x8
  unsigned __int64 v13; // x8
  __int64 v14; // x9
  _DWORD *v15; // x9
  __int64 v16; // x8
  __int64 v17; // x10
  _DWORD *v18; // x9
  unsigned int v19; // w11
  unsigned __int16 *v20; // x9
  unsigned int v21; // t1
  __int64 v22; // x8
  __int64 v23; // x10
  __int64 v24; // x9
  unsigned __int64 v25; // x8
  __int64 v26; // x21
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v28; // x9
  __int64 v29; // x3
  unsigned __int64 v30; // x9
  unsigned __int64 v36; // x8
  unsigned __int64 v37; // x8
  unsigned __int64 v39; // x9
  __int64 v40; // x0
  __int64 v41; // x8
  __int64 v42; // x0
  int v43; // w21

  v3 = *(_QWORD **)(a1 + 32);
  if ( !v3 )
  {
    printk(&unk_787E);
    return -22;
  }
  v6 = wait_for_completion_interruptible(v3 + 1);
  if ( v6 )
  {
    v43 = v6;
    dev_err(*v3, "%s: Error in wait\n", "rdbg_read");
    return v43;
  }
  if ( *((_DWORD *)v3 + 68) == 2 )
  {
    v7 = (_DWORD *)v3[26];
    if ( *v7 == -16711935 && *(_BYTE *)v3[25] == 1 )
    {
      v8 = v3[27];
      v9 = v7[1];
      if ( *(_DWORD *)(v8 + 4) != v9 )
      {
        *(_DWORD *)(v8 + 4) = v9;
        if ( *((_DWORD *)v3 + 58) )
        {
          v10 = 0;
          v11 = 16;
          do
          {
            ++v10;
            *(_WORD *)(v3[27] + v11) = -1;
            v11 += 4;
          }
          while ( v10 < *((unsigned int *)v3 + 58) );
        }
        *(_DWORD *)(v3[27] + 8LL) = 0;
        *(_DWORD *)(v3[27] + 12LL) = 0;
        if ( *((_DWORD *)v3 + 48) == 1 )
        {
          mutex_lock(v3[20]);
          v12 = v3[16];
          if ( *(_DWORD *)(v12 + 4) != v9 )
          {
            *(_DWORD *)(v12 + 4) = v9;
            if ( *((_DWORD *)v3 + 38) )
            {
              v13 = 0;
              v14 = 16;
              do
              {
                ++v13;
                *(_WORD *)(v3[16] + v14) = -1;
                v14 += 4;
              }
              while ( v13 < *((unsigned int *)v3 + 38) );
            }
            if ( v3[23] )
            {
              memset((void *)v3[23], 0, (unsigned int)(*((_DWORD *)v3 + 45) + 1));
              *((_DWORD *)v3 + 44) = 0;
            }
            *(_DWORD *)(v3[16] + 8LL) = 0;
            *(_DWORD *)(v3[16] + 12LL) = 0;
          }
          mutex_unlock(v3[20]);
        }
      }
    }
  }
  v15 = (_DWORD *)v3[26];
  if ( *(_BYTE *)v3[25] != 1 && *v15 != -16711935
    || (v16 = v3[27], v17 = *(unsigned int *)(v16 + 8), (_DWORD)v17 == v15[2])
    || (v18 = &v15[v17],
        v19 = *((_DWORD *)v3 + 58),
        v21 = *((unsigned __int16 *)v18 + 8),
        v20 = (unsigned __int16 *)(v18 + 4),
        v19 <= v21) )
  {
    dev_err(*v3, "%s: Error in smq_recv(). Err code = %d\n", "rdbg_read", 0);
    return -61;
  }
  *(_DWORD *)(v16 + 8) = ((int)v17 + 1) % v19;
  v22 = v20[1];
  v23 = v3[28];
  v24 = *v20;
  __dsb(0xDu);
  v25 = v22 << 7;
  v26 = v23 + (v24 << 7);
  if ( v25 < a3 )
    a3 = v25;
  _check_object_size(v23 + (v24 << 7), a3, 1);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v28 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v28 = a2 & ((__int64)(a2 << 8) >> 8);
  v29 = a3;
  if ( 0x8000000000LL - a3 >= v28 )
  {
    v30 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v36 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v36 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v36);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v30);
    v29 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v26, a3, a3);
    v37 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v39 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v39 - 4096);
    _WriteStatusReg(TTBR1_EL1, v39);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v37);
  }
  if ( (_DWORD)v29 )
  {
    dev_err(*v3, "%s: Error in copy_to_user(). Err code = %d\n", "rdbg_read", v29);
    return -61;
  }
  v40 = v3[30];
  if ( v40 )
    mutex_lock(v40);
  if ( *(_BYTE *)v3[25] == 1 || *(_DWORD *)v3[26] == -16711935 )
  {
    v41 = (v26 - v3[28]) / 128;
    if ( *((_DWORD *)v3 + 58) > (unsigned int)v41 )
    {
      *(_DWORD *)(v3[27] + 4LL * *(unsigned int *)(v3[27] + 12LL) + 16) = (unsigned __int16)v41;
      *(_DWORD *)(v3[27] + 12LL) = (unsigned int)(*(_DWORD *)(v3[27] + 12LL) + 1) % *((_DWORD *)v3 + 58);
    }
  }
  v42 = v3[30];
  if ( v42 )
    mutex_unlock(v42);
  return (int)a3;
}
