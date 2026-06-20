__int64 fw_suspend()
{
  return qcom_scm_set_remote_state(0, 0);
}
