__int64 __fastcall msm_sde_qtimer_install(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 v3; // x22
  __int64 result; // x0
  unsigned int v5; // w21
  _QWORD *resource_byname; // x0
  __int64 v7; // x8
  __int64 v8; // x9
  _QWORD *v9; // x20
  __int64 v10; // x23
  __int64 v11; // x2

  v1 = a1 - 16;
  if ( a1 == 16 )
    return printk(&unk_232766, "msm_sde_qtimer_install");
  v2 = *(_QWORD *)(a1 + 152);
  v3 = *(_QWORD *)(*(_QWORD *)(v2 + 56) + 8LL);
  result = of_property_read_string_helper(*(_QWORD *)(a1 + 744), "interrupt-names", 0, 0, 0);
  if ( (int)result >= 2 )
  {
    result = platform_get_irq(v1, 1);
    if ( (result & 0x80000000) == 0 )
    {
      v5 = result;
      resource_byname = (_QWORD *)platform_get_resource_byname(v1, 512, "qtimer_reg");
      v8 = *resource_byname;
      v7 = resource_byname[1];
      *(_QWORD *)(v3 + 6416) = &sde_qtimer_irq_cb;
      v9 = resource_byname;
      v10 = v7 - v8;
      request_threaded_irq(v5, &sde_qtimer_irq_cb, 0, 2163200, *(_QWORD *)(*(_QWORD *)(v2 + 48) + 152LL), v2);
      irq_set_irq_wake(v5, 1);
      if ( arm64_use_ng_mappings )
        v11 = 0x68000000000F13LL;
      else
        v11 = 0x68000000000713LL;
      result = ioremap_prot(*v9, v10 + 1, v11);
      *(_QWORD *)(v3 + 6424) = result;
    }
  }
  return result;
}
