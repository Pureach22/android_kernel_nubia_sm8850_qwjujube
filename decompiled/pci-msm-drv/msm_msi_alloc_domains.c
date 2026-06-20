__int64 __fastcall msm_msi_alloc_domains(__int64 a1)
{
  __int64 v2; // x8
  unsigned __int64 v3; // x0
  unsigned __int64 v4; // x2
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 irq_domain; // x0
  __int64 result; // x0
  __int64 v9; // [xsp+8h] [xbp-68h] BYREF
  int v10; // [xsp+10h] [xbp-60h]
  int v11; // [xsp+14h] [xbp-5Ch]
  __int64 v12; // [xsp+18h] [xbp-58h]
  __int64 v13; // [xsp+20h] [xbp-50h]
  __int64 v14; // [xsp+28h] [xbp-48h]
  __int64 v15; // [xsp+30h] [xbp-40h]
  void *v16; // [xsp+38h] [xbp-38h]
  __int64 v17; // [xsp+40h] [xbp-30h]
  __int64 v18; // [xsp+48h] [xbp-28h]
  __int64 v19; // [xsp+50h] [xbp-20h]
  __int64 v20; // [xsp+58h] [xbp-18h]
  __int64 v21; // [xsp+60h] [xbp-10h]
  __int64 v22; // [xsp+68h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned int *)(a1 + 36);
  v9 = 0;
  v10 = 0;
  v14 = 0;
  v15 = 0;
  v11 = v2;
  v12 = v2;
  v13 = 0;
  v16 = &msi_domain_ops;
  v17 = a1;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v3 = irq_domain_instantiate(&v9);
  if ( v3 <= 0xFFFFFFFFFFFFF000LL )
    v4 = v3;
  else
    v4 = 0;
  *(_QWORD *)(a1 + 112) = v4;
  if ( !v4 )
  {
    dev_err(*(_QWORD *)(a1 + 16), "MSI: failed to create IRQ domain\n");
LABEL_13:
    result = 4294967284LL;
    goto LABEL_10;
  }
  v5 = *(_QWORD *)(a1 + 24);
  if ( v5 )
    v6 = v5 + 24;
  else
    v6 = 0;
  irq_domain = pci_msi_create_irq_domain(v6, &msm_msi_domain_info);
  *(_QWORD *)(a1 + 120) = irq_domain;
  if ( !irq_domain )
  {
    dev_err(*(_QWORD *)(a1 + 16), "MSI: failed to create MSI domain\n");
    irq_domain_remove(*(_QWORD *)(a1 + 112));
    goto LABEL_13;
  }
  result = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
