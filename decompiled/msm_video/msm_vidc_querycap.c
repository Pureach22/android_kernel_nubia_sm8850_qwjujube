__int64 __fastcall msm_vidc_querycap(__int64 a1, __int64 a2)
{
  int v2; // w8
  __int64 result; // x0
  const char *v4; // x8
  __int64 v5; // x8
  __int64 v6; // x9

  *(_QWORD *)(a2 + 92) = 0;
  *(_DWORD *)(a2 + 100) = 0;
  strcpy((char *)a2, "msm_vidc_driver");
  *(_DWORD *)(a2 + 80) = 330240;
  strcpy((char *)(a2 + 48), "platform:msm_vidc_bus");
  v2 = *(_DWORD *)(a1 + 308);
  if ( v2 == 1 )
  {
    result = 0;
    v4 = "msm_vidc_encoder";
    goto LABEL_5;
  }
  if ( v2 == 2 )
  {
    result = 0;
    v4 = "msm_vidc_decoder";
LABEL_5:
    v6 = *(_QWORD *)v4;
    v5 = *((_QWORD *)v4 + 1);
    *(_BYTE *)(a2 + 32) = 0;
    *(_QWORD *)(a2 + 16) = v6;
    *(_QWORD *)(a2 + 24) = v5;
    return result;
  }
  return 4294967274LL;
}
