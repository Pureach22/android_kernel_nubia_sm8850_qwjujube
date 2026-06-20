__int64 __fastcall get_dma_info(_QWORD *a1, __int64 a2)
{
  _QWORD *v4; // x21
  const char *v5; // x20

  if ( (qcom_is_dma_buf_file(a2) & 1) != 0 )
  {
    v4 = *(_QWORD **)(a2 + 32);
    v5 = (const char *)v4[8];
    if ( !strcmp(v5, "qcom,system")
      || !strcmp(v5, "qcom,system-uncached")
      || !strcmp(v5, "system-secure")
      || !strcmp(v5, "qcom,secure-pixel")
      || !strcmp(v5, "qcom,secure-non-pixel") )
    {
      *a1 += *v4;
    }
  }
  return 0;
}
