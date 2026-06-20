__int64 __fastcall gen8_gmu_hfi_probe(__int64 a1)
{
  int *v1; // x19
  int v2; // w8

  v1 = (int *)(a1 - 1784);
  v2 = kgsl_request_irq(*(_QWORD *)(a1 + 1544), "hfi", gen8_hfi_irq_handler, a1);
  *v1 = v2;
  return v2 & (unsigned int)(v2 >> 31);
}
