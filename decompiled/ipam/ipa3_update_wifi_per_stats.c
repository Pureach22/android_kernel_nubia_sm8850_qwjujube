__int64 ipa3_update_wifi_per_stats()
{
  int v0; // w9
  __int64 v1; // x8
  __int64 v2; // x9
  __int64 v3; // x10
  __int64 v4; // x11

  v0 = *(_DWORD *)(ipa3_ctx + 32256);
  v1 = *(_QWORD *)(ipa3_ctx + 51432);
  if ( !v0 )
  {
    v2 = 120;
    v3 = 112;
    v4 = 104;
    goto LABEL_5;
  }
  if ( v0 == 1 )
  {
    v2 = 84;
    v3 = 76;
    v4 = 68;
LABEL_5:
    *(_DWORD *)(v1 + v4) = 0;
    *(_DWORD *)(v1 + v3) = 0;
    *(_DWORD *)(v1 + v2) = 0;
  }
  return 0;
}
