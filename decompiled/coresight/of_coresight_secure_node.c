bool __fastcall of_coresight_secure_node(__int64 a1)
{
  return of_find_property(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 744LL), "qcom,secure-component", 0) != 0;
}
