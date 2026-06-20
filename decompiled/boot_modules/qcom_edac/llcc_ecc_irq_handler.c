__int64 __fastcall llcc_ecc_irq_handler(__int64 a1, __int64 a2)
{
  __int64 v2; // x23
  __int64 v4; // x21
  unsigned int v5; // w20
  unsigned int v6; // w22
  void *v7; // x0
  unsigned int v8; // w22
  void *v9; // x0
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(*(_QWORD *)(a2 + 192) + 144LL);
  if ( *(_DWORD *)(v2 + 100) )
  {
    v4 = 0;
    v5 = 0;
    v11[0] = 0;
    while ( 1 )
    {
      if ( (unsigned int)regmap_read(
                           *(_QWORD *)(*(_QWORD *)v2 + 8 * v4),
                           *(unsigned int *)(*(_QWORD *)(v2 + 32) + 52LL),
                           (char *)v11 + 4) )
        goto LABEL_11;
      if ( (v11[0] & 0x100000000LL) != 0 )
      {
        v8 = 0;
        v9 = &unk_6891;
      }
      else
      {
        v8 = 1;
        if ( (v11[0] & 0x200000000LL) == 0 )
        {
          v5 = 1;
          goto LABEL_11;
        }
        v9 = &unk_69E7;
      }
      printk(v9);
      if ( !(unsigned int)dump_syn_reg(a2, v8, (unsigned int)v4) )
        v5 = 1;
LABEL_11:
      if ( !(unsigned int)regmap_read(
                            *(_QWORD *)(*(_QWORD *)v2 + 8 * v4),
                            *(unsigned int *)(*(_QWORD *)(v2 + 32) + 20LL),
                            v11) )
      {
        if ( (v11[0] & 1) != 0 )
        {
          v6 = 2;
          v7 = &unk_697C;
          goto LABEL_4;
        }
        if ( (v11[0] & 2) != 0 )
        {
          v6 = 3;
          v7 = &unk_6828;
LABEL_4:
          printk(v7);
          if ( !(unsigned int)dump_syn_reg(a2, v6, (unsigned int)v4) )
            v5 = 1;
          goto LABEL_6;
        }
        v5 = 1;
      }
LABEL_6:
      if ( ++v4 >= (unsigned __int64)*(unsigned int *)(v2 + 100) )
        goto LABEL_21;
    }
  }
  v5 = 0;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return v5;
}
