__int64 __fastcall qcom_scm_pas_shutdown_retry(unsigned int a1)
{
  __int64 result; // x0
  __int64 v3; // x2

  result = qcom_scm_pas_shutdown(a1);
  if ( (_DWORD)result )
  {
    printk(&unk_126B6, "qcom_scm_pas_shutdown_retry", (unsigned int)result);
    printk(&unk_12726, "qcom_scm_pas_shutdown_retry", (unsigned int)pas_shutdown_retry_delay_ms);
    msleep((unsigned int)pas_shutdown_retry_delay_ms);
    printk(&unk_12AE0, "qcom_scm_pas_shutdown_retry", v3);
    return qcom_scm_pas_shutdown(a1);
  }
  return result;
}
