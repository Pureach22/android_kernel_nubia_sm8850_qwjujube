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
  __int64 v8; // x10
  __int64 v9; // x20
  char v10; // w8
  __int64 v11; // x19
  __int64 v12; // x21
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x24

  v7 = *(unsigned int *)(result - 8);
  if ( (unsigned int)v7 > 4 )
  {
    __break(0x5512u);
    __asm { SUBG            SP, X6, #0xE0, #2 }
    return lpass_cdc_va_macro_enable_tx();
  }
  else
  {
    v8 = *(_QWORD *)(result - 16);
    v9 = 8 * v7;
    v10 = 0;
    v11 = *(_QWORD *)(v8 + 168);
    v12 = v8 + 1256;
    do
    {
      v13 = (unsigned __int8)(-1LL << v10) & (unsigned __int8)*(_DWORD *)(v12 + v9) & 0xF;
      if ( !v13 )
        break;
      v14 = __clz(__rbit64(v13));
      result = snd_soc_component_update_bits(v11, (unsigned int)(((_DWORD)v14 << 7) + 13312), 16, 0);
      v10 = v14 + 1;
    }
    while ( v14 < 3 );
  }
  return result;
}
