__int64 icnss_is_qmi_disable()
{
  return (*(_QWORD *)(penv + 328) >> 2) & 1LL;
}
