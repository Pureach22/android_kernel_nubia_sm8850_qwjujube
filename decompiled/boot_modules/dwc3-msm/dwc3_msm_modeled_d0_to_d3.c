__int64 __fastcall dwc3_msm_modeled_d0_to_d3(__int64 a1)
{
  __int64 result; // x0

  result = _pm_runtime_idle(**(_QWORD **)(a1 + 2816), 4);
  if ( !(_DWORD)result )
    return _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)(a1 + 2816) + 8LL), 4);
  return result;
}
