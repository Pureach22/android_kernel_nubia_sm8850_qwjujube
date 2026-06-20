__int64 __fastcall gh_get_irq(unsigned int a1, unsigned int a2, __int64 a3)
{
  int v4; // w8
  __int64 result; // x0
  __int64 v7; // [xsp+8h] [xbp-58h] BYREF
  __int64 v8; // [xsp+10h] [xbp-50h]
  __int64 v9; // [xsp+18h] [xbp-48h]
  __int64 v10; // [xsp+20h] [xbp-40h]
  __int64 v11; // [xsp+28h] [xbp-38h]
  __int64 v12; // [xsp+30h] [xbp-30h]
  __int64 v13; // [xsp+38h] [xbp-28h]
  __int64 v14; // [xsp+40h] [xbp-20h]
  __int64 v15; // [xsp+48h] [xbp-18h]
  __int64 v16; // [xsp+50h] [xbp-10h]
  __int64 v17; // [xsp+58h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v9 = 0;
  v10 = 0;
  v8 = 0;
  if ( a1 <= 0x1F )
    goto LABEL_9;
  if ( a1 > 0x3FB )
  {
    if ( a1 > 0xFFF && a1 >> 10 <= 4 )
    {
      v8 = 0x200000003LL;
      v4 = -4096;
      goto LABEL_7;
    }
LABEL_9:
    _warn_printk("Unexpected virq: %d\n", a1);
    __break(0x800u);
    printk(&unk_6461, a2, a1, 4294967274LL);
    result = 4294967274LL;
    goto LABEL_8;
  }
  LODWORD(v8) = 3;
  v4 = -32;
LABEL_7:
  v7 = a3;
  LODWORD(v9) = v4 + a1;
  HIDWORD(v9) = a2;
  result = irq_create_fwspec_mapping(&v7);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
