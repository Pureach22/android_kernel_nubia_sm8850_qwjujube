__int64 *__fastcall dp_power_clk_put(__int64 *result)
{
  __int64 v1; // x20
  __int64 *v2; // x19

  v1 = *result;
  v2 = result;
  if ( *(_DWORD *)(*result + 48) )
  {
    msm_dss_mmrm_deregister(result[2] + 16, v1 + 16);
    result = (__int64 *)msm_dss_put_clk(*(_QWORD *)(v1 + 56), *(unsigned int *)(v1 + 48));
    v1 = *v2;
  }
  if ( *(_DWORD *)(v1 + 96) )
  {
    msm_dss_mmrm_deregister(v2[2] + 16, v1 + 64);
    result = (__int64 *)msm_dss_put_clk(*(_QWORD *)(v1 + 104), *(unsigned int *)(v1 + 96));
    v1 = *v2;
  }
  if ( *(_DWORD *)(v1 + 144) )
  {
    msm_dss_mmrm_deregister(v2[2] + 16, v1 + 112);
    result = (__int64 *)msm_dss_put_clk(*(_QWORD *)(v1 + 152), *(unsigned int *)(v1 + 144));
    v1 = *v2;
  }
  if ( *(_DWORD *)(v1 + 192) )
  {
    msm_dss_mmrm_deregister(v2[2] + 16, v1 + 160);
    result = (__int64 *)msm_dss_put_clk(*(_QWORD *)(v1 + 200), *(unsigned int *)(v1 + 192));
    v1 = *v2;
  }
  if ( *(_DWORD *)(v1 + 240) )
  {
    msm_dss_mmrm_deregister(v2[2] + 16, v1 + 208);
    result = (__int64 *)msm_dss_put_clk(*(_QWORD *)(v1 + 248), *(unsigned int *)(v1 + 240));
    v1 = *v2;
  }
  if ( *(_DWORD *)(v1 + 288) )
  {
    msm_dss_mmrm_deregister(v2[2] + 16, v1 + 256);
    result = (__int64 *)msm_dss_put_clk(*(_QWORD *)(v1 + 296), *(unsigned int *)(v1 + 288));
    v1 = *v2;
  }
  if ( *(_DWORD *)(v1 + 336) )
  {
    msm_dss_mmrm_deregister(v2[2] + 16, v1 + 304);
    return (__int64 *)msm_dss_put_clk(*(_QWORD *)(v1 + 344), *(unsigned int *)(v1 + 336));
  }
  return result;
}
