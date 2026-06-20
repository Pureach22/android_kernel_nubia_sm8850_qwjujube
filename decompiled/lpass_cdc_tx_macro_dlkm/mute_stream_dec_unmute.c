__int64 __fastcall mute_stream_dec_unmute(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 _X6)
{
  __int64 v7; // x9
  __int64 v8; // x20
  __int64 v9; // x21
  char v10; // w8
  __int64 v11; // x19
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x25

  v7 = *(unsigned int *)(result - 8);
  if ( (unsigned int)v7 > 4 )
  {
    __break(0x5512u);
    __asm { SUBG            SP, X6, #0xE0, #2 }
    return lpass_cdc_tx_macro_enable_micbias();
  }
  else
  {
    v8 = *(_QWORD *)(result - 16);
    v9 = 8 * v7;
    v10 = 0;
    v11 = *(_QWORD *)(v8 + 120);
    do
    {
      v12 = (unsigned __int8)((-1LL << v10) & *(_DWORD *)(v8 + 2544 + v9));
      if ( !v12 )
        break;
      v13 = __clz(__rbit64(v12));
      result = snd_soc_component_update_bits(v11, ((_DWORD)v13 << 7) | 0x400u, 16, 0);
      if ( *(_BYTE *)(v8 + 2721) == 1 )
        result = snd_soc_component_update_bits(v11, ((_DWORD)v13 << 7) | 0x408u, 1, 0);
      v10 = v13 + 1;
    }
    while ( v13 < 7 );
  }
  return result;
}
