__int64 __fastcall qcom_pdm_remove(__int64 result)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(result + 152);
  if ( v1 )
  {
    result = refcount_dec_and_mutex_lock(*(_QWORD *)(result + 152), &qcom_pdm_mutex);
    if ( (result & 1) != 0 )
    {
      _qcom_pdm_data = 0;
      qcom_pdm_stop(v1);
      return mutex_unlock(&qcom_pdm_mutex);
    }
  }
  return result;
}
