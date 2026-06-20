__int64 __fastcall wcd9378_ear_pa_gain_get(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  unsigned int v4; // w8

  v2 = *(_QWORD *)(a1 + 128);
  if ( !v2 )
    return 4294967274LL;
  v4 = snd_soc_component_read(v2, 1075314699);
  *(_DWORD *)(a2 + 72) = (v4 >> 2) & 0x1F;
  return 0;
}
