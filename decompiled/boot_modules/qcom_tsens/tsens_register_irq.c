__int64 __fastcall tsens_register_irq(_DWORD **a1, __int64 a2, __int64 a3)
{
  __int64 device_by_node; // x0
  __int64 v7; // x19
  unsigned int irq_byname; // w20
  __int64 v9; // x5
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x4
  unsigned int v15; // w21

  device_by_node = of_find_device_by_node(*((_QWORD *)*a1 + 93));
  if ( device_by_node )
  {
    v7 = device_by_node;
    irq_byname = platform_get_irq_byname(device_by_node, a2);
    if ( (irq_byname & 0x80000000) != 0 )
    {
      if ( irq_byname == -6 )
        v15 = 0;
      else
        v15 = irq_byname;
    }
    else
    {
      v9 = *(_QWORD *)(v7 + 128);
      if ( *a1[318] )
      {
        if ( !v9 )
          v9 = *(_QWORD *)(v7 + 16);
        v10 = v7 + 16;
        v11 = irq_byname;
        v12 = 0;
        v13 = a3;
        v14 = 0x2000;
      }
      else
      {
        if ( !v9 )
          v9 = *(_QWORD *)(v7 + 16);
        v10 = v7 + 16;
        v11 = irq_byname;
        v12 = a3;
        v13 = 0;
        v14 = 1;
      }
      v15 = devm_request_threaded_irq(v10, v11, v12, v13, v14, v9, a1);
      if ( v15 )
        dev_err(v7 + 16, "%s: failed to get irq\n", "tsens_register_irq");
      else
        irq_set_irq_wake(irq_byname, 1);
    }
    put_device(v7 + 16);
  }
  else
  {
    return (unsigned int)-19;
  }
  return v15;
}
