__int64 __fastcall dp_runtime_resume(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x21
  unsigned int multiplier; // w0
  unsigned int v5; // w21
  _DWORD *v7; // x8

  v1 = a1 + 0x4000;
  if ( *(_BYTE *)(a1 + 17784) == 2 )
  {
    v3 = jiffies;
    multiplier = qdf_timer_get_multiplier();
    mod_timer(a1 + 17728, v3 + 2LL * multiplier);
  }
  if ( *(_DWORD *)(v1 + 3544) )
  {
    v5 = 0;
    do
    {
      qdf_sleep();
      if ( !*(_DWORD *)(v1 + 3544) )
        break;
    }
    while ( v5++ < 9 );
  }
  v7 = *(_DWORD **)(a1 + 1768);
  if ( *(v7 - 1) != 357773931 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD))v7)(a1, 0);
  *(_DWORD *)(v1 + 3548) = 0;
  return 0;
}
