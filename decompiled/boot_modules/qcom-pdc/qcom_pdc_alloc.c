__int64 __fastcall qcom_pdc_alloc(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4)
{
  __int64 result; // x0
  __int64 v8; // x0
  __int64 v9; // x9
  _DWORD *v10; // x8
  int v11; // w9
  int v12; // [xsp+Ch] [xbp-64h] BYREF
  __int64 v13; // [xsp+10h] [xbp-60h] BYREF
  __int64 v14; // [xsp+18h] [xbp-58h] BYREF
  __int64 v15; // [xsp+20h] [xbp-50h]
  __int64 v16; // [xsp+28h] [xbp-48h]
  __int64 v17; // [xsp+30h] [xbp-40h]
  __int64 v18; // [xsp+38h] [xbp-38h]
  __int64 v19; // [xsp+40h] [xbp-30h]
  __int64 v20; // [xsp+48h] [xbp-28h]
  __int64 v21; // [xsp+50h] [xbp-20h]
  __int64 v22; // [xsp+58h] [xbp-18h]
  __int64 v23; // [xsp+60h] [xbp-10h]
  __int64 v24; // [xsp+68h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v13 = 0;
  v12 = 0;
  result = irq_domain_translate_twocell(a1, a4, &v13, &v12);
  if ( !(_DWORD)result )
  {
    if ( v13 == 0xFFFFFFFFLL )
    {
      v8 = a1;
LABEL_14:
      result = irq_domain_disconnect_hierarchy(v8, a2);
      goto LABEL_15;
    }
    result = irq_domain_set_hwirq_and_chip(a1, a2, v13, &qcom_pdc_gic_chip, 0);
    if ( !(_DWORD)result )
    {
      v9 = (unsigned int)pdc_region_cnt;
      if ( pdc_region_cnt < 1 )
        goto LABEL_13;
      v10 = (_DWORD *)pdc_region;
      while ( *v10 > (unsigned int)v13 || v10[2] + *v10 <= (unsigned int)v13 )
      {
        --v9;
        v10 += 3;
        if ( !v9 )
          goto LABEL_13;
      }
      if ( !v10 )
      {
LABEL_13:
        v8 = *(_QWORD *)(a1 + 144);
        goto LABEL_14;
      }
      v11 = v12;
      if ( (v12 & 3) != 0 )
      {
        v11 = 1;
      }
      else
      {
        if ( (v12 & 0xC) == 0 )
        {
LABEL_19:
          v14 = *(_QWORD *)(*(_QWORD *)(a1 + 144) + 104LL);
          v15 = 3;
          LODWORD(v16) = v10[1] + v13 - *v10;
          HIDWORD(v16) = v11;
          ipc_log_string(pdc_ipc_log, "Alloc: PIN=%lu", v13);
          result = irq_domain_alloc_irqs_parent(a1, a2, a3, &v14);
          goto LABEL_15;
        }
        v11 = 4;
      }
      v12 = v11;
      goto LABEL_19;
    }
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
