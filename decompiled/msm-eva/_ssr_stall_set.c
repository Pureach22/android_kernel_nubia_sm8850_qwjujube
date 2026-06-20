__int64 __fastcall ssr_stall_set(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(cvp_driver + 48);
  if ( v2 )
    *(_BYTE *)(v2 + 1045) = a2 != 0;
  return 0;
}
