__int64 __fastcall btfmcodec_dai_set_channel_map(__int64 a1)
{
  __int64 v1; // x8
  unsigned int v2; // w0
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 (*v6)(void); // x8

  v1 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 24LL) + 152LL);
  v2 = *(_DWORD *)(v1 + 964);
  if ( v2 )
  {
    coverttostring(v2);
    printk(&unk_CFA2, "btfmcodec_dai_set_channel_map");
    return 0;
  }
  else
  {
    v3 = *(_QWORD *)(v1 + 984);
    if ( v3
      && (v4 = *(_QWORD *)(v3 + 80)) != 0
      && (v5 = *(_QWORD *)(v4 + 112)) != 0
      && (v6 = *(__int64 (**)(void))(v5 + 32)) != nullptr )
    {
      if ( *((_DWORD *)v6 - 1) != -593712550 )
        __break(0x8228u);
      return v6();
    }
    else
    {
      return 0xFFFFFFFFLL;
    }
  }
}
