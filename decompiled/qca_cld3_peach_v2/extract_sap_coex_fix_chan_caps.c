__int64 __fastcall extract_sap_coex_fix_chan_caps(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 v3; // x8

  if ( !a2 )
    return 4;
  v3 = *(_QWORD *)(a2 + 208);
  if ( !v3 )
    return 4;
  *a3 = *(_DWORD *)(v3 + 4);
  return 0;
}
