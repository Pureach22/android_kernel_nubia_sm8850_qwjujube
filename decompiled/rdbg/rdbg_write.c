__int64 __fastcall rdbg_write(__int64 a1, unsigned __int64 a2, int a3)
{
  __int64 v3; // x24
  int v4; // w23
  size_t v5; // x19
  __int64 v6; // x27
  unsigned int v7; // w25
  unsigned __int64 StatusReg; // x20
  _DWORD *v9; // x9
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x9
  unsigned int v13; // w21
  char v14; // w21
  unsigned int *v15; // x8
  int v16; // w10
  int v17; // t1
  _DWORD *v18; // x9
  unsigned int v19; // w11
  unsigned __int16 *v20; // x9
  unsigned int v21; // t1
  __int64 v22; // x8
  int v23; // w9
  unsigned int v24; // w9
  __int64 v25; // x11
  int v26; // w10
  int v27; // w12
  unsigned int v28; // w13
  int v29; // w9
  unsigned int v30; // w8
  __int64 v31; // x9
  __int64 v32; // x9
  __int64 v33; // x10
  __int64 v34; // x22
  unsigned __int64 v35; // x8
  size_t v36; // x23
  int v37; // w8
  unsigned __int64 v38; // x8
  unsigned __int64 v44; // x9
  unsigned __int64 v45; // x8
  unsigned __int64 v47; // x9
  __int64 v48; // x0
  __int64 v49; // x21
  __int64 v50; // x22
  int v51; // w20
  __int64 v53; // [xsp+8h] [xbp-28h]
  unsigned __int64 v54; // [xsp+10h] [xbp-20h]
  unsigned int v57; // [xsp+2Ch] [xbp-4h]

  v3 = *(_QWORD *)(a1 + 32);
  if ( !v3 )
  {
    printk(&unk_787E);
    return -22;
  }
  v4 = a3;
  v5 = a3;
  v6 = (unsigned int)((a3 + 127) >> 7);
  v7 = 0;
  v57 = a3 + 127;
  v53 = a2 & ((__int64)(a2 << 8) >> 8);
  StatusReg = _ReadStatusReg(SP_EL0);
  v54 = 0x8000000000LL - a3;
  do
  {
    mutex_lock(*(_QWORD *)(v3 + 160));
    v9 = *(_DWORD **)(v3 + 136);
    if ( *v9 == -16711934 && *(_BYTE *)(*(_QWORD *)(v3 + 120) + 1LL) == 1 )
    {
      v10 = *(_QWORD *)(v3 + 128);
      if ( *(_DWORD *)(v10 + 4) == v9[1] )
      {
        while ( 1 )
        {
          v17 = *(_DWORD *)(v10 + 12);
          v15 = (unsigned int *)(v10 + 12);
          v16 = v17;
          if ( v17 == v9[3] )
            break;
          v18 = &v9[v16];
          v19 = *(_DWORD *)(v3 + 152);
          v21 = *((unsigned __int16 *)v18 + 8);
          v20 = (unsigned __int16 *)(v18 + 4);
          if ( v19 <= v21 )
            goto LABEL_10;
          *v15 = (v16 + 1) % v19;
          v22 = *v20;
          v23 = *(unsigned __int8 *)(*(_QWORD *)(v3 + 184) + v22);
          if ( *(_BYTE *)(*(_QWORD *)(v3 + 184) + v22) )
          {
            do
            {
              --v23;
              *(_BYTE *)(*(_QWORD *)(v3 + 184) + v22++) = 0;
            }
            while ( v23 );
          }
          __dsb(0xDu);
          v10 = *(_QWORD *)(v3 + 128);
          v9 = *(_DWORD **)(v3 + 136);
        }
      }
    }
    LODWORD(v11) = *(_DWORD *)(v3 + 176);
    if ( (_DWORD)v6 != 1 )
    {
      v24 = *(_DWORD *)(v3 + 180);
      v25 = *(_QWORD *)(v3 + 184);
      v26 = 0;
      v27 = *(_DWORD *)(v3 + 176);
      v28 = v24;
      while ( 1 )
      {
        if ( *(_BYTE *)(v25 + (unsigned int)v11) )
        {
          v26 = 0;
          v13 = v24;
          LODWORD(v11) = v11 + *(unsigned __int8 *)(v25 + (unsigned int)v11) - 1;
        }
        else
        {
          if ( v28 <= (unsigned int)v11 )
            ++v26;
          else
            v26 = 1;
          if ( v28 > (unsigned int)v11 )
            v27 = v11;
          if ( v28 >= (unsigned int)v11 )
            v13 = v11;
          else
            v13 = v28;
          if ( v26 == (_DWORD)v6 )
          {
            if ( v57 >= 0x80 )
            {
              v31 = v6;
              if ( v28 < (unsigned int)v11 )
                LODWORD(v11) = v28;
              do
              {
                *(_BYTE *)(*(_QWORD *)(v3 + 184) + (unsigned int)v11) = v31--;
                LODWORD(v11) = v11 + 1;
              }
              while ( v31 );
              v11 = *(unsigned int *)(v3 + 176);
              v29 = *(unsigned __int8 *)(*(_QWORD *)(v3 + 184) + v11);
            }
            else
            {
              v29 = 0;
            }
            v30 = v11 + v29 - 1;
            goto LABEL_38;
          }
        }
        LODWORD(v11) = ((int)v11 + 1) % v24;
        v28 = v13;
        *(_DWORD *)(v3 + 176) = v11;
        if ( v27 == (_DWORD)v11 )
          goto LABEL_10;
      }
    }
    v12 = *(_QWORD *)(v3 + 184);
    v13 = *(_DWORD *)(v3 + 176);
    while ( *(_BYTE *)(v12 + v13) )
    {
      v13 = (v13 + 1) % *(_DWORD *)(v3 + 180);
      *(_DWORD *)(v3 + 176) = v13;
      if ( (_DWORD)v11 == v13 )
        goto LABEL_10;
    }
    *(_BYTE *)(v12 + v13) = 1;
    v30 = (unsigned int)(*(_DWORD *)(v3 + 176) + 1) % *(_DWORD *)(v3 + 180);
LABEL_38:
    v32 = *(_QWORD *)(v3 + 144);
    v33 = v13 << 7;
    *(_DWORD *)(v3 + 176) = v30;
    v34 = v32 + v33;
    if ( v4 < 0 )
    {
      __break(0x800u);
      if ( !v34 )
      {
LABEL_55:
        v4 = a3;
        v14 = 0;
        goto LABEL_50;
      }
    }
    else
    {
      _check_object_size(v32 + v33, v5, 0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v35 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v35 = v53;
      v36 = v5;
      if ( v54 >= v35 )
      {
        v38 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v44 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v44 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v44);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v38);
        v36 = _arch_copy_from_user(v34, a2 & 0xFF7FFFFFFFFFFFFFLL, v5);
        v45 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v47 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v47 - 4096);
        _WriteStatusReg(TTBR1_EL1, v47);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v45);
        if ( !v36 )
          goto LABEL_49;
      }
      memset((void *)(v34 + v5 - v36), 0, v36);
      if ( !(_DWORD)v36 )
      {
LABEL_49:
        v4 = a3;
        *(_WORD *)(*(_QWORD *)(v3 + 128) + 4LL * *(unsigned int *)(*(_QWORD *)(v3 + 128) + 8LL) + 16) = v13;
        v14 = 1;
        *(_WORD *)(*(_QWORD *)(v3 + 128) + 4LL * *(unsigned int *)(*(_QWORD *)(v3 + 128) + 8LL) + 18) = v57 >> 7;
        *(_DWORD *)(*(_QWORD *)(v3 + 128) + 8LL) = (unsigned int)(*(_DWORD *)(*(_QWORD *)(v3 + 128) + 8LL) + 1)
                                                 % *(_DWORD *)(v3 + 152);
        goto LABEL_50;
      }
      if ( !v34 )
        goto LABEL_55;
    }
    v4 = a3;
    v37 = *(unsigned __int8 *)(*(_QWORD *)(v3 + 184) + v13);
    if ( *(_BYTE *)(*(_QWORD *)(v3 + 184) + v13) )
    {
      do
      {
        --v37;
        *(_BYTE *)(*(_QWORD *)(v3 + 184) + v13++) = 0;
      }
      while ( v37 );
    }
LABEL_10:
    v14 = 0;
LABEL_50:
    v48 = mutex_unlock(*(_QWORD *)(v3 + 160));
    if ( (v14 & 1) != 0 )
      break;
  }
  while ( v7++ < 0x14 );
  if ( (v14 & 1) == 0 )
  {
    printk(&unk_7B44);
    return -70;
  }
  v49 = *(unsigned int *)(v3 + 92);
  if ( (unsigned int)v49 < 0x20 )
  {
    v50 = v3 + 4 * v49;
    v51 = *(_DWORD *)(v50 + 328) ^ (1LL << (*(_BYTE *)(v3 + 72) + (unsigned __int8)v49));
    qcom_smem_state_update_bits(*(_QWORD *)(v3 + 80));
    *(_DWORD *)(v50 + 328) = v51;
    *(_DWORD *)(v3 + 92) = ((_BYTE)v49 + 1) & 0x1F;
    return v5;
  }
  __break(0x5512u);
  return rdbg_open(v48);
}
