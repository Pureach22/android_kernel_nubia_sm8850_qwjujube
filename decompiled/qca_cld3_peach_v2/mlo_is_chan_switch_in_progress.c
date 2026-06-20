__int64 __fastcall mlo_is_chan_switch_in_progress(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 1360);
  if ( v1 )
  {
    v1 = *(_QWORD *)(v1 + 2224);
    if ( v1 )
      LOBYTE(v1) = *(_BYTE *)(v1 + 1493);
  }
  return v1 & 1;
}
