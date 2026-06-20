__int64 __fastcall wcd9378_loopback_mode_get(__int64 a1, __int64 a2)
{
  __int64 v2; // x0

  v2 = *(_QWORD *)(a1 + 128);
  if ( !v2 )
    return 4294967274LL;
  *(_QWORD *)(a2 + 72) = snd_soc_component_read(v2, 1075315843) & 7;
  return 0;
}
