__int64 __fastcall qcom_devcd_freev(_QWORD *a1)
{
  _QWORD *v1; // x19

  v1 = a1 + 1;
  vfree(*a1);
  return complete_all(v1);
}
