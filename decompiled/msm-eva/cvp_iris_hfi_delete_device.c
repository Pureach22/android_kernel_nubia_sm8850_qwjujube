__int64 __fastcall cvp_iris_hfi_delete_device(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19

  if ( result )
  {
    v1 = *(_QWORD *)(cvp_driver + 48);
    if ( v1 )
    {
      v2 = **(_QWORD **)(v1 + 256);
      if ( v2 )
      {
        destroy_workqueue(*(_QWORD *)(v2 + 2176));
        destroy_workqueue(*(_QWORD *)(v2 + 2184));
        free_irq(**(unsigned int **)(v2 + 2168), v2);
        iounmap(*(_QWORD *)(*(_QWORD *)(v2 + 2168) + 16LL));
        iounmap(*(_QWORD *)(*(_QWORD *)(v2 + 2168) + 24LL));
        kfree(*(_QWORD *)(v2 + 2168));
        kfree(*(_QWORD *)(v2 + 2432));
        kfree(*(_QWORD *)(v2 + 2440));
        return kfree(v2);
      }
    }
  }
  return result;
}
