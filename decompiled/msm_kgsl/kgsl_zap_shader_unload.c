__int64 __fastcall kgsl_zap_shader_unload(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w20

  result = qcom_scm_pas_shutdown_retry(13);
  if ( (_DWORD)result )
  {
    v3 = result;
    dev_err(a1, "Error %d while PAS shutdown\n", result);
    return v3;
  }
  return result;
}
