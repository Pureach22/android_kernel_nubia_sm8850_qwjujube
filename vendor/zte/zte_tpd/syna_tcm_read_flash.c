__int64 __fastcall syna_tcm_read_flash(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4, int a5)
{
  unsigned int v5; // w20
  size_t v10; // x19
  unsigned int v11; // w8
  unsigned int v12; // w8
  unsigned int v13; // w25
  int v14; // w27
  unsigned int v15; // w28
  __int64 v16; // x2
  _DWORD *v17; // x8
  unsigned int v18; // w0
  const void *v19; // x1
  __int64 v20; // x2
  __int64 result; // x0
  void *v22; // x0
  unsigned int v23; // w21
  _BYTE v24[8]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a3 )
  {
    v22 = unk_37A2E;
LABEL_38:
    printk(v22, "syna_tcm_read_flash", a3);
    result = 4294967055LL;
    goto LABEL_34;
  }
  v5 = a2;
  if ( !a2 || !a4 )
  {
    v22 = unk_3A57A;
    goto LABEL_38;
  }
  LODWORD(v10) = a4;
  if ( *(_BYTE *)(a1 + 8) == 2
    && (v11 = *(_DWORD *)(a1 + 60), LODWORD(v10) = a4, v11 < a4)
    && (LODWORD(v10) = v11 - 6, v11 == 6) )
  {
    v12 = 0;
  }
  else
  {
    v12 = (a4 + (unsigned int)v10 - 1) / (unsigned int)v10;
  }
  v13 = 0;
  if ( v12 <= 1 )
    v14 = 1;
  else
    v14 = v12;
  while ( 1 )
  {
    v10 = a4 - v13 >= (unsigned int)v10 ? (unsigned int)v10 : a4 - v13;
    v15 = a5 ? ((unsigned int)v10 >> 1) * a5 / 0x3E8 : 0;
    v5 += v13;
    v16 = *(unsigned __int8 *)(a1 + 9);
    v24[4] = (unsigned int)v10 >> 1;
    v24[0] = v5 >> 1;
    v24[1] = v5 >> 9;
    v24[2] = v5 >> 17;
    v24[3] = v5 >> 25;
    v24[5] = (unsigned int)v10 >> 9;
    if ( (_DWORD)v16 == 11 )
    {
      if ( v15 )
        goto LABEL_21;
    }
    else
    {
      printk(unk_37A54, "syna_tcm_reflash_send_command", v16);
      if ( v15 )
        goto LABEL_21;
    }
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) != 0 )
    {
      v15 = 0;
    }
    else
    {
      v15 = *(_DWORD *)(a1 + 524);
      printk(unk_36818, "syna_tcm_reflash_send_command", v15);
    }
LABEL_21:
    v17 = *(_DWORD **)(a1 + 920);
    if ( *(v17 - 1) != 606091918 )
      __break(0x8228u);
    v18 = ((__int64 (__fastcall *)(__int64, __int64, _BYTE *, __int64, _QWORD, _QWORD))v17)(a1, 19, v24, 6, 0, v15);
    if ( (v18 & 0x80000000) != 0 )
    {
      v23 = v18;
      printk(unk_39AB7, "syna_tcm_reflash_send_command", 19);
      printk(unk_38AC3, "syna_tcm_read_flash", v5);
      result = v23;
      goto LABEL_34;
    }
    if ( *(_DWORD *)(a1 + 340) != (_DWORD)v10 )
    {
      printk(unk_31B98, "syna_tcm_read_flash", (unsigned int)v10);
      result = 4294967055LL;
      goto LABEL_34;
    }
    if ( !(a3 + v13) )
      goto LABEL_42;
    v19 = *(const void **)(a1 + 328);
    if ( !v19 )
      goto LABEL_42;
    v20 = *(unsigned int *)(a1 + 336);
    if ( (unsigned int)v10 > a4 || (unsigned int)v10 > (unsigned int)v20 )
      break;
    memcpy((void *)(a3 + v13), v19, v10);
    --v14;
    v13 += *(_DWORD *)(a1 + 340);
    if ( !v14 )
    {
      result = 0;
      goto LABEL_34;
    }
  }
  printk(unk_3944E, "syna_pal_mem_cpy", v20);
  LODWORD(v10) = *(_DWORD *)(a1 + 340);
LABEL_42:
  printk(unk_350C8, "syna_tcm_read_flash", (unsigned int)v10);
  result = 4294967274LL;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
