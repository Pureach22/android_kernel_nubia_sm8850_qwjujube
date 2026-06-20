__int64 __fastcall kgsl_bus_close(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0

  kfree(*(_QWORD *)(a1 + 10392));
  v2 = *(_QWORD *)(a1 + 10456);
  *(_QWORD *)(a1 + 10392) = 0;
  result = icc_put(v2);
  *(_QWORD *)(a1 + 10456) = 0;
  return result;
}
