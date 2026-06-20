__int64 __fastcall btfmcodec_dai_hw_params(__int64 a1, _DWORD *a2, __int64 a3)
{
  unsigned int v4; // w8
  __int64 v5; // x21
  int v6; // w9
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 (*v10)(void); // x8
  unsigned int current_transport; // w0

  v4 = a2[9];
  v5 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a3 + 96) + 24LL) + 152LL);
  if ( v4 )
  {
    v6 = 0;
LABEL_5:
    v4 = __clz(__rbit32(v4)) | v6;
    goto LABEL_6;
  }
  v4 = a2[10];
  if ( v4 )
  {
    v6 = 32;
    goto LABEL_5;
  }
LABEL_6:
  bits_per_second = snd_pcm_format_width(v4);
  num_channels = a2[71];
  if ( (unsigned int)btfmcodec_get_current_transport(v5 + 912)
    && (unsigned int)btfmcodec_get_current_transport(v5 + 912) != 2 )
  {
    current_transport = btfmcodec_get_current_transport(v5 + 912);
    coverttostring(current_transport);
    printk(&unk_C7AA, "btfmcodec_dai_hw_params");
    return 0;
  }
  else
  {
    v7 = *(_QWORD *)(v5 + 984);
    if ( v7
      && (v8 = *(_QWORD *)(v7 + 80)) != 0
      && (v9 = *(_QWORD *)(v8 + 112)) != 0
      && (v10 = *(__int64 (**)(void))(v9 + 16)) != nullptr )
    {
      if ( *((_DWORD *)v10 - 1) != 851138883 )
        __break(0x8228u);
      return v10();
    }
    else
    {
      return 0xFFFFFFFFLL;
    }
  }
}
