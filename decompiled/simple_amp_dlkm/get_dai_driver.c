__int64 *__fastcall get_dai_driver(__int64 a1, int a2)
{
  __int64 *result; // x0
  __int64 *v5; // x20
  __int64 v6; // x23
  __int64 v7; // x22
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x23
  __int64 v11; // x22
  __int64 v12; // x0
  bool v13; // zf

  result = (__int64 *)devm_kmalloc(a1, 624, 3520);
  if ( result )
  {
    v5 = result;
    memcpy(result, &simple_amp_dai, 0x270u);
    v6 = devm_kasprintf(a1, 3264, "simple_amp_stereo_%d", a2);
    *v5 = v6;
    v7 = devm_kasprintf(a1, 3264, "simple_amp_mono_ch1_%d", a2);
    v5[26] = v7;
    v8 = devm_kasprintf(a1, 3264, "simple_amp_mono_ch2_%d", a2);
    v5[52] = v8;
    if ( !v6 )
      return nullptr;
    v9 = v8;
    result = nullptr;
    if ( !v7 || !v9 )
      return result;
    v10 = devm_kasprintf(a1, 3264, "Simple Amp AIF%d Stereo Playback", a2);
    v5[19] = v10;
    v11 = devm_kasprintf(a1, 3264, "Simple Amp AIF%d Mono_Ch1 Playback", a2);
    v5[45] = v11;
    v12 = devm_kasprintf(a1, 3264, "Simple Amp AIF%d Mono_Ch2 Playback", a2);
    v5[71] = v12;
    if ( !v10 )
      return nullptr;
    if ( v12 )
      v13 = v11 == 0;
    else
      v13 = 1;
    if ( v13 )
      return nullptr;
    else
      return v5;
  }
  return result;
}
