__int64 __fastcall max_ssr_get(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(cvp_driver + 48);
  if ( v2 )
    *a2 = *(unsigned int *)(v2 + 856);
  return 0;
}
