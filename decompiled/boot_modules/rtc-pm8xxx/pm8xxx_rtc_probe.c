unsigned __int64 __fastcall pm8xxx_rtc_probe(_QWORD *a1)
{
  __int64 matched; // x0
  _QWORD *v3; // x19
  __int64 v4; // x23
  __int64 v5; // x0
  _QWORD *v6; // x20
  __int64 regmap; // x0
  int irq; // w0
  __int64 property; // x22
  unsigned __int64 result; // x0
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  matched = of_match_node(&_mod_of__pm8xxx_id_table_device_table, a1[95]);
  if ( !matched )
    goto LABEL_8;
  v3 = a1 + 2;
  v4 = matched;
  v5 = devm_kmalloc(a1 + 2, 56, 3520);
  if ( !v5 )
  {
    result = 4294967284LL;
    goto LABEL_10;
  }
  v6 = (_QWORD *)v5;
  regmap = dev_get_regmap(a1[14], 0);
  v6[1] = regmap;
  if ( !regmap || (irq = platform_get_irq(a1, 0), *((_DWORD *)v6 + 5) = irq, irq < 0) )
  {
LABEL_8:
    result = 4294967290LL;
    goto LABEL_10;
  }
  property = of_find_property(a1[95], "allow-set-time", 0);
  *((_BYTE *)v6 + 16) = property != 0;
  result = devm_nvmem_cell_get(a1 + 2, "offset");
  v6[5] = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v6[3] = *(_QWORD *)(v4 + 192);
    v6[4] = v3;
    if ( !property && result )
    {
      v11[0] = 0;
      result = nvmem_cell_read(result, v11);
      if ( result > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_10;
      if ( v11[0] != 4 )
      {
        kfree();
        result = 4294967274LL;
        goto LABEL_10;
      }
      *((_DWORD *)v6 + 12) = *(_DWORD *)result;
      kfree();
    }
  }
  else
  {
    if ( (_DWORD)result != -2 )
      goto LABEL_10;
    v6[5] = 0;
    v6[3] = *(_QWORD *)(v4 + 192);
    v6[4] = v3;
  }
  result = regmap_update_bits_base(v6[1], *(unsigned int *)v6[3], 128, 128, 0, 0, 0);
  if ( !(_DWORD)result )
  {
    a1[21] = v6;
    device_set_wakeup_capable(a1 + 2, 1);
    device_wakeup_enable(a1 + 2);
    result = devm_rtc_allocate_device(a1 + 2);
    *v6 = result;
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      *(_QWORD *)(result + 928) = &pm8xxx_rtc_ops;
      *(_QWORD *)(*v6 + 1456LL) = 0xFFFFFFFFLL;
      result = devm_request_any_context_irq(
                 a1 + 2,
                 *((unsigned int *)v6 + 5),
                 pm8xxx_alarm_trigger,
                 1,
                 "pm8xxx_rtc_alarm",
                 v6);
      if ( (result & 0x80000000) == 0 )
      {
        result = _devm_rtc_register_device(&_this_module, *v6);
        if ( !(_DWORD)result )
          result = dev_pm_set_wake_irq(a1 + 2, *((unsigned int *)v6 + 5));
      }
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
