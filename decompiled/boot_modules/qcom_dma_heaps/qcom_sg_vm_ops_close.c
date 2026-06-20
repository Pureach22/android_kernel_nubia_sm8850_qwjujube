__int64 __fastcall qcom_sg_vm_ops_close(__int64 a1)
{
  return mem_buf_vmperm_unpin(*(_QWORD *)(a1 + 96));
}
