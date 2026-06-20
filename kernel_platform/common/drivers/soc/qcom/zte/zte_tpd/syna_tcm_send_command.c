__int64 __fastcall syna_tcm_send_command(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        _BYTE *a5,
        __int64 a6,
        unsigned int a7)
{
  _DWORD *v11; // x8
  __int64 result; // x0
  __int64 v13; // x1
  unsigned int v14; // w20
  int v15; // w8
  __int64 v16; // x2
  void *v17; // x0
  __int64 v18; // x1
  unsigned int v19; // w20
  int v20; // w8
  __int64 v21; // x2
  unsigned int v22; // w22
  unsigned int v23; // w25
  unsigned int v24; // w23
  __int64 v25; // x24
  _BYTE v26[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[0] = 0;
  if ( !a1 )
  {
    printk(unk_3365A, "syna_tcm_send_command", a3);
    result = 4294967055LL;
    goto LABEL_21;
  }
  if ( !a7 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) != 0 )
    {
      a7 = 0;
    }
    else
    {
      v23 = *(_DWORD *)(a1 + 524);
      v24 = a4;
      v25 = a3;
      printk(unk_3BA3F, "syna_tcm_send_command", a3);
      a7 = v23;
      a3 = v25;
      a4 = v24;
    }
  }
  v11 = *(_DWORD **)(a1 + 920);
  if ( *(v11 - 1) != 606091918 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64, _BYTE *, _QWORD))v11)(a1, a2, a3, a4, v26, a7);
  if ( (result & 0x80000000) == 0 )
  {
    if ( !a5 )
      goto LABEL_10;
    goto LABEL_9;
  }
  v21 = (unsigned __int8)a2;
  v22 = result;
  printk(unk_36CCF, "syna_tcm_send_command", v21);
  result = v22;
  if ( a5 )
LABEL_9:
    *a5 = v26[0];
LABEL_10:
  if ( a6 )
  {
    if ( (unsigned int)v26[0] - 16 > 0xEE )
    {
      if ( (unsigned int)v26[0] - 1 <= 0xE )
      {
        if ( *(_DWORD *)(a1 + 340) )
        {
          v18 = a1 + 328;
          v19 = result;
          v20 = syna_tcm_buf_copy_2(a6, v18);
          result = v19;
          if ( v20 < 0 )
          {
            v16 = v26[0];
            v17 = unk_3C713;
            goto LABEL_19;
          }
        }
      }
    }
    else if ( *(_DWORD *)(a1 + 268) )
    {
      v13 = a1 + 256;
      v14 = result;
      v15 = syna_tcm_buf_copy_2(a6, v13);
      result = v14;
      if ( v15 < 0 )
      {
        v16 = v26[0];
        v17 = unk_3BA0D;
LABEL_19:
        printk(v17, "syna_tcm_send_command", v16);
        result = 4294967053LL;
      }
    }
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
