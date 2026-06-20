__int64 qcom_scm_shutdown()
{
  __int64 v0; // x0
  __int64 v1; // x1
  __int64 v2; // x2
  __int64 v3; // x3
  __int64 v4; // x4
  __int64 v5; // x5
  __int64 v6; // x6
  __int64 v7; // x7
  __int64 result; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x4
  __int64 v13; // x5
  __int64 v14; // x6
  __int64 v15; // x7

  idr_destroy(_scm + 192);
  v0 = qcom_scm_disable_sdi();
  result = qcom_scm_halt_spmi_pmic_arbiter(v0, v1, v2, v3, v4, v5, v6, v7);
  if ( download_mode == 1 )
    return qcom_scm_set_download_mode(0, v9, v10, v11, v12, v13, v14, v15);
  return result;
}
