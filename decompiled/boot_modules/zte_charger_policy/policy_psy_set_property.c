__int64 __fastcall policy_psy_set_property(__int64 a1, unsigned int a2, _DWORD *a3)
{
  __int64 drvdata; // x0
  __int64 v6; // x2
  __int64 v7; // x3
  unsigned int v8; // w19
  __int64 v10; // x21

  drvdata = power_supply_get_drvdata();
  if ( drvdata )
  {
    if ( a2 == 4 )
    {
      v8 = 0;
      *(_DWORD *)(drvdata + 492) = *a3;
    }
    else
    {
      v10 = drvdata;
      if ( a2 == 3 )
      {
        printk(&unk_A1FA, "policy_psy_set_property", (unsigned int)*a3, v7);
        v8 = 0;
        drvdata = v10;
        *(_DWORD *)(v10 + 488) = *a3 == 0;
      }
      else
      {
        printk(&unk_9D87, a2, v6, v7);
        v8 = -22;
        drvdata = v10;
      }
    }
    queue_delayed_work_on(32, *(_QWORD *)(drvdata + 160), drvdata + 168, 25);
  }
  else
  {
    printk(&unk_ADFB, "policy_psy_set_property", v6, v7);
    return (unsigned int)-61;
  }
  return v8;
}
