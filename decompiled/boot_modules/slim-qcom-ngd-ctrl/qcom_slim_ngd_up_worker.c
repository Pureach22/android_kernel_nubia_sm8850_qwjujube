__int64 __fastcall qcom_slim_ngd_up_worker(__int64 a1)
{
  __int64 v2; // x1

  if ( !wait_for_completion_interruptible_timeout(a1 + 40, 250) )
    return dev_err(*(_QWORD *)(a1 - 3008), "QMI wait timeout\n");
  mutex_lock(a1 + 272, v2);
  qcom_slim_ngd_enable(a1 - 4976, 1);
  return mutex_unlock(a1 + 272);
}
