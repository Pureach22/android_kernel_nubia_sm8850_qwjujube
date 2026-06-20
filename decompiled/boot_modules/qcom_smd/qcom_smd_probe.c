__int64 __fastcall qcom_smd_probe(__int64 a1)
{
  __int64 result; // x0
  _QWORD *v3; // x20

  if ( (qcom_smem_is_available() & 1) == 0 )
    return 4294966779LL;
  result = of_get_next_available_child(*(_QWORD *)(a1 + 760), 0);
  if ( result )
  {
    v3 = (_QWORD *)result;
    do
    {
      qcom_smd_register_edge((const char **)(a1 + 16), v3);
      result = of_get_next_available_child(*(_QWORD *)(a1 + 760), v3);
      v3 = (_QWORD *)result;
    }
    while ( result );
  }
  return result;
}
