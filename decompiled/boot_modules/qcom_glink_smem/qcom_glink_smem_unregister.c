__int64 __fastcall qcom_glink_smem_unregister(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20

  if ( result )
  {
    v1 = *(_QWORD *)(result + 952);
    v2 = result;
    disable_irq(*(unsigned int *)(result + 912));
    qcom_glink_native_remove(v1);
    mbox_free_channel(*(_QWORD *)(v2 + 1016));
    return device_unregister(v2);
  }
  return result;
}
