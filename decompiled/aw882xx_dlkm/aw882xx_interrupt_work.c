__int64 __fastcall aw882xx_interrupt_work(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 *v4; // x8
  __int64 v5; // x1
  __int64 *v6; // x8
  __int64 v7; // x1
  __int64 result; // x0
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 - 120);
  v3 = *(_QWORD *)(a1 - 160);
  v9 = 0;
  aw882xx_i2c_read(v3, *(_DWORD *)(v2 + 528), &v9);
  v4 = *(__int64 **)(a1 - 152);
  v5 = v4[14];
  if ( !v5 )
    v5 = *v4;
  printk(&unk_26B58, v5, "aw882xx_interrupt_work");
  aw882xx_i2c_read(*(_QWORD *)(a1 - 160), *(_DWORD *)(v2 + 300), &v9);
  v6 = *(__int64 **)(a1 - 152);
  v7 = v6[14];
  if ( !v7 )
    v7 = *v6;
  printk(&unk_25089, v7, "aw882xx_interrupt_work");
  result = aw882xx_dev_set_intmask(*(_QWORD *)(a1 - 120), 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
