__int64 ipa3_uc_interface_destroy()
{
  __int64 result; // x0

  if ( *(_BYTE *)(ipa3_ctx + 34656) == 1 )
  {
    ((void (__fastcall *)(__int64))ipa3_remove_interrupt_handler)(3);
    ((void (__fastcall *)(__int64))ipa3_remove_interrupt_handler)(2);
    ((void (__fastcall *)(__int64))ipa3_remove_interrupt_handler)(1);
    result = iounmap(*(_QWORD *)(ipa3_ctx + 34752));
    *(_BYTE *)(ipa3_ctx + 34656) = 0;
  }
  return result;
}
