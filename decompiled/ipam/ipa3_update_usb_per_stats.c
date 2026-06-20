__int64 ipa3_update_usb_per_stats()
{
  int v0; // w9
  __int64 v1; // x8
  __int64 v2; // x9
  __int64 v3; // x10
  __int64 v4; // x11
  __int64 v5; // x12

  v0 = *(_DWORD *)(ipa3_ctx + 32256);
  v1 = *(_QWORD *)(ipa3_ctx + 51432);
  if ( !v0 )
  {
    v2 = 96;
    v3 = 88;
    v4 = 80;
    v5 = 72;
    goto LABEL_5;
  }
  if ( v0 == 1 )
  {
    v2 = 60;
    v3 = 52;
    v4 = 44;
    v5 = 36;
LABEL_5:
    *(_DWORD *)(v1 + v5) = 0;
    *(_DWORD *)(v1 + v4) = 0;
    *(_DWORD *)(v1 + v3) = 0;
    *(_DWORD *)(v1 + v2) = 0;
  }
  return 0;
}
