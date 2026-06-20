__int64 __fastcall lpass_cdc_rx_macro_iir_band_audio_mixer_get(__int64 a1, __int64 a2)
{
  __int64 v2; // x23
  __int64 v3; // x20
  _DWORD *v4; // x24
  int v5; // w25
  int v6; // w26
  int v7; // w21
  int v8; // w22
  unsigned int v9; // w22
  unsigned int v10; // w22
  size_t v11; // x2
  _QWORD src[2]; // [xsp+10h] [xbp-20h] BYREF
  int v15; // [xsp+20h] [xbp-10h]
  __int64 v16; // [xsp+28h] [xbp-8h]

  v2 = 0;
  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD **)(a1 + 120);
  v3 = *(_QWORD *)(a1 + 128);
  v15 = 0;
  src[0] = 0;
  src[1] = 0;
  v5 = *v4 << 7;
  v6 = 20 * v4[1];
  do
  {
    v7 = ((_BYTE)v6 + (_BYTE)v2) & 0x7C;
    snd_soc_component_write(v3, (unsigned int)(v5 + 6700), ((_BYTE)v6 + (_BYTE)v2) & 0x7C);
    v8 = snd_soc_component_read(v3, (unsigned int)(v5 + 6704));
    snd_soc_component_write(v3, (unsigned int)(v5 + 6700), v7 | 1u);
    v9 = v8 | ((unsigned int)snd_soc_component_read(v3, (unsigned int)(v5 + 6704)) << 8);
    snd_soc_component_write(v3, (unsigned int)(v5 + 6700), v7 | 2u);
    v10 = v9 | ((unsigned int)snd_soc_component_read(v3, (unsigned int)(v5 + 6704)) << 16);
    snd_soc_component_write(v3, (unsigned int)(v5 + 6700), v7 | 3u);
    *(_DWORD *)((char *)src + v2) = v10 | ((snd_soc_component_read(v3, (unsigned int)(v5 + 6704)) & 0x3F) << 24);
    v2 += 4;
  }
  while ( v2 != 20 );
  v11 = (int)v4[2];
  if ( (unsigned int)v11 >= 0x15 )
    _fortify_panic(16, -1);
  memcpy((void *)(a2 + 72), src, v11);
  _ReadStatusReg(SP_EL0);
  return 0;
}
