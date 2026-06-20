__int64 __fastcall i2c_pmic_irq_set_type(__int64 a1, __int64 a2, __int64 a3)
{
  _BYTE *v3; // x9
  __int64 result; // x0
  char v6; // w10
  char v7; // w10
  char v8; // w11
  char v9; // w10

  v3 = *(_BYTE **)(a1 + 48);
  if ( (int)a2 <= 2 )
  {
    if ( (_DWORD)a2 != 1 )
    {
      if ( (_DWORD)a2 == 2 )
      {
        result = 0;
        v6 = v3[10] | *(_BYTE *)(a1 + 8);
        goto LABEL_9;
      }
      goto LABEL_15;
    }
    result = 0;
    v9 = v3[10] | *(_BYTE *)(a1 + 8);
LABEL_14:
    v3[10] = v9;
    v3[11] |= *(_BYTE *)(a1 + 8);
    v3[12] &= ~*(_BYTE *)(a1 + 8);
    return result;
  }
  switch ( (_DWORD)a2 )
  {
    case 3:
      result = 0;
      v8 = v3[11];
      v3[10] |= *(_BYTE *)(a1 + 8);
      v7 = v8 | *(_BYTE *)(a1 + 8);
      goto LABEL_11;
    case 4:
      result = 0;
      v9 = v3[10] & ~*(_BYTE *)(a1 + 8);
      goto LABEL_14;
    case 8:
      result = 0;
      v6 = v3[10] & ~*(_BYTE *)(a1 + 8);
LABEL_9:
      v3[10] = v6;
      v7 = v3[11] & ~*(_BYTE *)(a1 + 8);
LABEL_11:
      v3[11] = v7;
      v3[12] |= *(_BYTE *)(a1 + 8);
      return result;
  }
LABEL_15:
  printk(&unk_784F, a2, a3);
  return 4294967274LL;
}
