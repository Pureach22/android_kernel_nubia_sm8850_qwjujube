__int64 __fastcall qcom_scm_irq_handler(__int64 a1, __int64 a2)
{
  queue_work_on(32, system_wq, a2 + 224);
  return 1;
}
