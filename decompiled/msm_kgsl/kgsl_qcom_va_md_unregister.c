__int64 __fastcall kgsl_qcom_va_md_unregister(_QWORD *a1)
{
  __int64 result; // x0

  result = qcom_va_md_enabled();
  if ( (result & 1) != 0 )
  {
    result = qcom_va_md_unregister("KGSL", &kgsl_va_minidump_nb);
    if ( (_DWORD)result )
      return dev_err(*a1, "Failed to unregister notifier with va_minidump: %d\n", result);
  }
  return result;
}
