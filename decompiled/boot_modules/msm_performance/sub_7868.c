void sub_7868()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x21
  __int64 (__fastcall *v2)(_QWORD, _QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = qcom_pmu_event_supported;
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  _kmalloc_cache_noprof(v2, 3520, 16);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x7570);
}
