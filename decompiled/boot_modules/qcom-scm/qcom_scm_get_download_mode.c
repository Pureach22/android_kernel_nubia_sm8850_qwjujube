__int64 __fastcall qcom_scm_get_download_mode(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 result; // x0
  int v5; // w8
  __int64 v6; // x0
  unsigned int v7; // w19

  if ( !_scm )
  {
    v3 = 0;
    goto LABEL_6;
  }
  v2 = *(_QWORD *)(_scm + 336);
  v3 = *(_QWORD *)_scm;
  if ( !v2 )
  {
LABEL_6:
    dev_err(v3, "No available mechanism for getting download mode\n");
    v5 = -22;
LABEL_8:
    v6 = v3;
    v7 = v5;
    dev_err(v6, "failed to get download mode: %d\n", v5);
    return v7;
  }
  result = qcom_scm_io_readl(v2, a1);
  if ( (_DWORD)result )
  {
    v5 = result;
    goto LABEL_8;
  }
  return result;
}
