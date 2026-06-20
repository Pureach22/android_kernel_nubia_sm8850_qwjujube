__int64 __fastcall cvp_power_get(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8
  __int64 *v3; // x8
  __int64 v4; // x8

  v2 = *(_QWORD *)(cvp_driver + 48);
  if ( v2 )
  {
    v3 = *(__int64 **)(v2 + 256);
    if ( v3 )
    {
      v4 = *v3;
      if ( v4 )
        *a2 = *(unsigned __int8 *)(v4 + 72);
    }
  }
  return 0;
}
