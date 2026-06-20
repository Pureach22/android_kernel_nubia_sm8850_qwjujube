__int64 __fastcall spmi_pmic_arb_remove(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x20
  __int64 v4; // x20
  __int64 v5; // x20

  v1 = *(_QWORD *)(result + 168);
  if ( *(int *)(v1 + 104) >= 1 )
  {
    v2 = *(_QWORD *)(v1 + 72);
    debugfs_remove(*(_QWORD *)(v2 + 176));
    result = *(unsigned int *)(v2 + 164);
    if ( (int)result > 0 )
    {
      irq_set_chained_handler_and_data();
      result = irq_domain_remove(*(_QWORD *)(v2 + 8));
    }
    if ( *(int *)(v1 + 104) >= 2 )
    {
      v3 = *(_QWORD *)(v1 + 80);
      debugfs_remove(*(_QWORD *)(v3 + 176));
      result = *(unsigned int *)(v3 + 164);
      if ( (int)result >= 1 )
      {
        irq_set_chained_handler_and_data();
        result = irq_domain_remove(*(_QWORD *)(v3 + 8));
      }
      if ( *(int *)(v1 + 104) >= 3 )
      {
        v4 = *(_QWORD *)(v1 + 88);
        debugfs_remove(*(_QWORD *)(v4 + 176));
        result = *(unsigned int *)(v4 + 164);
        if ( (int)result >= 1 )
        {
          irq_set_chained_handler_and_data();
          result = irq_domain_remove(*(_QWORD *)(v4 + 8));
        }
        if ( *(int *)(v1 + 104) >= 4 )
        {
          v5 = *(_QWORD *)(v1 + 96);
          debugfs_remove(*(_QWORD *)(v5 + 176));
          result = *(unsigned int *)(v5 + 164);
          if ( (int)result >= 1 )
          {
            irq_set_chained_handler_and_data();
            result = irq_domain_remove(*(_QWORD *)(v5 + 8));
          }
          if ( *(int *)(v1 + 104) > 4 )
          {
            __break(0x5512u);
            return readl_relaxed(result);
          }
        }
      }
    }
  }
  return result;
}
