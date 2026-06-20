__int64 __fastcall ufs_qcom_host_clk_enable(__int64 a1, const char *a2, __int64 a3)
{
  unsigned int v6; // w0
  __int64 result; // x0
  unsigned int v8; // w22

  v6 = clk_prepare(a3);
  if ( v6 )
  {
    v8 = v6;
LABEL_6:
    dev_err(a1, "%s: %s enable failed %d\n", "ufs_qcom_host_clk_enable", a2, v8);
    return v8;
  }
  result = clk_enable(a3);
  if ( (_DWORD)result )
  {
    v8 = result;
    clk_unprepare(a3);
    goto LABEL_6;
  }
  return result;
}
