__int64 fw_resume()
{
  return qcom_scm_set_remote_state(1, 0);
}
