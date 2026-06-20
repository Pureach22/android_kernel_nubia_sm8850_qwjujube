__int64 __fastcall adsp_unprepare(__int64 a1)
{
  __int64 *v1; // x20
  __int64 v2; // x19

  v1 = *(__int64 **)(a1 + 40);
  if ( *((_BYTE *)v1 + 784) == 1 )
    v2 = *v1;
  else
    v2 = 0;
  qcom_scm_pas_metadata_release(v1 + 145, v2);
  if ( *((_DWORD *)v1 + 115) )
    qcom_scm_pas_metadata_release(v1 + 148, v2);
  return 0;
}
