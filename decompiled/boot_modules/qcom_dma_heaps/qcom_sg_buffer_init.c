__int64 __fastcall qcom_sg_buffer_init(__int64 a1)
{
  __int64 result; // x0

  *(_QWORD *)(a1 + 8) = a1 + 8;
  *(_QWORD *)(a1 + 16) = a1 + 8;
  result = _mutex_init(a1 + 24, "&buffer->lock", &qcom_sg_buffer_init___key);
  *(_DWORD *)(a1 + 168) = 1;
  return result;
}
