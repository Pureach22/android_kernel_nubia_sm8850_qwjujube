__int64 __fastcall platform_mpam_schemata_show(__int64 a1, __int64 a2)
{
  __int64 v4; // x20
  int *v5; // x8
  int v6; // w3
  __int64 v7; // x8

  v4 = (int)scnprintf(a2, 4096, "gear=%d\n", **(_DWORD **)(a1 + 152));
  if ( *(_QWORD *)(a1 + 160) )
  {
    qcom_mpam_get_bw_limit_rpmsg();
    v5 = *(int **)(a1 + 160);
    v6 = *v5;
    v7 = 1374389535LL * v5[2] * *v5;
    return v4
         - 1
         + (int)scnprintf(
                  a2 + v4 - 1,
                  4097 - v4,
                  ",limit_ratio=%d,limit_mbps=%d\n",
                  v6,
                  (v7 >> 37) + ((unsigned __int64)v7 >> 63));
  }
  return v4;
}
