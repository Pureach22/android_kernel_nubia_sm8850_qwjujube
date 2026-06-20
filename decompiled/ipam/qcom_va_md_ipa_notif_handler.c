__int64 qcom_va_md_ipa_notif_handler()
{
  _QWORD *v0; // x0
  _QWORD *v1; // x21

  v0 = *(_QWORD **)(ipa3_ctx + 51408);
  if ( v0 != (_QWORD *)(ipa3_ctx + 51408) )
  {
    do
    {
      v1 = (_QWORD *)*v0;
      qcom_va_md_add_region(v0 + 2);
      v0 = v1;
    }
    while ( v1 != (_QWORD *)(ipa3_ctx + 51408) );
  }
  return 1;
}
