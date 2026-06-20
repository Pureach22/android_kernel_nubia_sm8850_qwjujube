__int64 __fastcall wcd_irq_init(_QWORD *a1, unsigned __int64 *a2)
{
  __int64 v2; // x8
  unsigned __int64 v5; // x0
  __int64 v6; // x20
  __int64 v7; // x21
  unsigned int mapping_affinity; // w0
  unsigned int v9; // w19
  __int64 result; // x0
  void *v11; // x0
  __int64 v12; // [xsp+8h] [xbp-68h] BYREF
  int v13; // [xsp+10h] [xbp-60h]
  int v14; // [xsp+14h] [xbp-5Ch]
  __int64 v15; // [xsp+18h] [xbp-58h]
  __int64 v16; // [xsp+20h] [xbp-50h]
  __int64 v17; // [xsp+28h] [xbp-48h]
  __int64 v18; // [xsp+30h] [xbp-40h]
  void *v19; // [xsp+38h] [xbp-38h]
  __int64 v20; // [xsp+40h] [xbp-30h]
  __int64 v21; // [xsp+48h] [xbp-28h]
  __int64 v22; // [xsp+50h] [xbp-20h]
  __int64 v23; // [xsp+58h] [xbp-18h]
  __int64 v24; // [xsp+60h] [xbp-10h]
  __int64 v25; // [xsp+68h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v11 = &unk_A1EB;
LABEL_10:
    printk(v11, "wcd_irq_init");
    result = 4294967274LL;
    goto LABEL_7;
  }
  v2 = a1[1];
  v12 = 0;
  v13 = 0;
  wcd_irq_chip = v2;
  v14 = 1;
  v15 = 1;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = &wcd_domain_ops;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  v5 = irq_domain_instantiate(&v12);
  if ( v5 > 0xFFFFFFFFFFFFF000LL )
    v5 = 0;
  *a2 = v5;
  if ( !v5 )
  {
    v11 = &unk_A202;
    goto LABEL_10;
  }
  v6 = a1[4];
  v7 = a1[2];
  mapping_affinity = irq_create_mapping_affinity(v5, 0, 0);
  v9 = devm_regmap_add_irq_chip(v6, v7, mapping_affinity, 0x2000, 0, *a1, a1 + 3);
  result = 0;
  if ( v9 )
  {
    printk(&unk_A0BF, "wcd_irq_init");
    result = v9;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
