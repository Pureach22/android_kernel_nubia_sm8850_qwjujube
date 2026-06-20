__int64 __fastcall msm_property_get_blob(__int64 a1, __int64 a2, _QWORD *a3, unsigned int a4)
{
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 result; // x0
  __int64 v8; // x8

  if ( !a1 || !a2 || (v5 = *(_QWORD *)(a2 + 8)) == 0 || *(_DWORD *)(a1 + 36) <= a4 )
  {
    _drm_err("invalid argument(s)\n");
LABEL_9:
    v8 = 0;
    result = 0;
    if ( !a3 )
      return result;
    goto LABEL_10;
  }
  v6 = *(_QWORD *)(v5 + 32LL * a4 + 8);
  if ( !v6 )
    goto LABEL_9;
  v8 = *(_QWORD *)(v6 + 72);
  result = *(_QWORD *)(v6 + 80);
  if ( a3 )
LABEL_10:
    *a3 = v8;
  return result;
}
