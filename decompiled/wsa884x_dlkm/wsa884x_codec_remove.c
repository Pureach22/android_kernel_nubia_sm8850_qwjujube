__int64 __fastcall wsa884x_codec_remove(__int64 result)
{
  if ( *(_QWORD *)(*(_QWORD *)(result + 24) + 152LL) )
    return snd_soc_component_exit_regmap();
  return result;
}
