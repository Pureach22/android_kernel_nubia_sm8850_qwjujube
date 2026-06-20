__int64 ipa3_qmi_init()
{
  __int64 result; // x0

  result = _mutex_init(&ipa3_qmi_lock, "&ipa3_qmi_lock", &ipa3_qmi_init___key);
  nat_move_qmi_disabled = 1;
  return result;
}
