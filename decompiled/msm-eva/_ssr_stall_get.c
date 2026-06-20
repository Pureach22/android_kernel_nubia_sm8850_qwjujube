__int64 __fastcall ssr_stall_get(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(cvp_driver + 48);
  if ( v2 )
    *a2 = *(unsigned __int8 *)(v2 + 1045);
  return 0;
}
