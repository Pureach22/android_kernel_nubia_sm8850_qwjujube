__int64 qdf_va_md_notif_handler()
{
  __int64 v0; // x1
  __int64 **v1; // x0
  __int64 *v2; // x19

  v0 = raw_spin_lock_irqsave(&qdf_va_md_list_lock);
  v1 = (__int64 **)qdf_va_md_list;
  qword_825CA0 = v0;
  if ( (__int64 *)qdf_va_md_list != &qdf_va_md_list )
  {
    do
    {
      v2 = *v1;
      qcom_va_md_add_region(v1 + 2);
      v1 = (__int64 **)v2;
    }
    while ( v2 != &qdf_va_md_list );
    v0 = qword_825CA0;
  }
  raw_spin_unlock_irqrestore(&qdf_va_md_list_lock, v0);
  return 1;
}
