__int64 __fastcall qcom_sg_vm_ops_open(__int64 a1)
{
  return mem_buf_vmperm_pin(*(_QWORD *)(a1 + 96));
}
