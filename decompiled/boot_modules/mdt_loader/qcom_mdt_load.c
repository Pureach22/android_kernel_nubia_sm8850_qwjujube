__int64 __fastcall qcom_mdt_load(
        __int64 a1,
        _QWORD *a2,
        char *a3,
        unsigned int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 result; // x0

  result = qcom_mdt_pas_init(a1, a2, a3, a4, a6, 0, 0);
  if ( !(_DWORD)result )
    return _qcom_mdt_load(a1, a2, a3, a5, a6, a7, a8);
  return result;
}
