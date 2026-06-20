__int64 __fastcall slim_xfer_msg(__int64 a1, unsigned __int16 *a2, unsigned __int8 a3, __int64 a4, __int64 a5)
{
  char v5; // w8
  unsigned int v6; // w8
  _QWORD *v7; // x0
  unsigned int v8; // w9
  int v9; // w8
  int v10; // w10
  unsigned int v11; // w10
  char v12; // w8
  __int16 v14; // [xsp+0h] [xbp-20h] BYREF
  unsigned __int8 v15; // [xsp+2h] [xbp-1Eh]
  char v16; // [xsp+3h] [xbp-1Dh]
  __int16 v17; // [xsp+4h] [xbp-1Ch]
  char v18; // [xsp+6h] [xbp-1Ah]
  char v19; // [xsp+7h] [xbp-19h]
  unsigned __int16 *v20; // [xsp+8h] [xbp-18h]
  __int64 v21; // [xsp+10h] [xbp-10h]
  __int64 v22; // [xsp+18h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 6;
  v5 = *(_BYTE *)(a1 + 932);
  v15 = a3;
  v19 = v5;
  v6 = -22;
  v16 = 0;
  v18 = 0;
  v20 = a2;
  v21 = 0;
  if ( !a2 )
    goto LABEL_31;
  v7 = *(_QWORD **)(a1 + 920);
  if ( !v7 )
    goto LABEL_31;
  v8 = *((unsigned __int8 *)a2 + 2);
  v9 = *a2;
  if ( v8 >= 0x11 || v9 + v8 > 0xC00 )
    goto LABEL_32;
  if ( a3 > 0x5Fu )
  {
    if ( a3 == 104 )
      goto LABEL_16;
    if ( a3 == 97 )
    {
LABEL_15:
      if ( !*((_QWORD *)a2 + 1) )
        goto LABEL_32;
      goto LABEL_16;
    }
    if ( a3 != 96 )
      goto LABEL_32;
  }
  else if ( a3 != 32 )
  {
    if ( a3 != 33 )
    {
      if ( a3 != 40 )
        goto LABEL_32;
LABEL_16:
      if ( *((_QWORD *)a2 + 2) )
        goto LABEL_17;
LABEL_32:
      dev_err(*v7, "Sanity check failed:msg:offset:0x%x, mc:%d\n", v9, a3);
      v6 = -22;
      goto LABEL_31;
    }
    goto LABEL_15;
  }
  if ( !*((_QWORD *)a2 + 1) )
    goto LABEL_32;
LABEL_17:
  if ( v8 <= 1 )
    v10 = 1;
  else
    v10 = *((unsigned __int8 *)a2 + 2);
  v11 = v10 - 1;
  if ( v11 > 0xF )
  {
    __break(1u);
    if ( a5 )
      JUMPOUT(0x7250);
    JUMPOUT(0xFFFFFFFFFFFD7E5CLL);
  }
  v17 = slim_slicesize_sizetocode[v11] | (unsigned __int16)(16 * v9) | 8;
  v12 = 7;
  if ( a3 > 0x60u )
  {
    if ( a3 != 104 && a3 != 97 )
      goto LABEL_28;
  }
  else if ( a3 != 33 && a3 != 40 )
  {
    goto LABEL_28;
  }
  LOBYTE(v14) = v8 + 6;
  v12 = v8 + 7;
LABEL_28:
  if ( ((a3 - 32) & 0xBE) == 0 )
    LOBYTE(v14) = v12;
  v6 = slim_do_transfer(v7, (unsigned __int8 *)&v14);
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return v6;
}
