__int64 __fastcall btfmcodec_codec_probe(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x24
  __int64 v4; // x20
  void (__fastcall **v5)(_QWORD); // x8
  void (__fastcall *v6)(_QWORD); // x8
  unsigned __int64 v7; // x21
  char *v8; // x22
  unsigned int current_transport; // w0
  void *v10; // x0
  __int64 v12; // x26
  char *v13; // x8
  __int64 v14; // x0
  int v15; // w16

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  v3 = *(_QWORD *)(v2 + 984);
  v4 = *(unsigned int *)(v3 + 100);
  if ( (unsigned int)btfmcodec_get_current_transport(v2 + 912) )
  {
    current_transport = btfmcodec_get_current_transport(v2 + 912);
    coverttostring(current_transport);
    v10 = &unk_CFA2;
LABEL_11:
    printk(v10, "btfmcodec_codec_probe");
    return 0;
  }
  v5 = *(void (__fastcall ***)(_QWORD))(v3 + 72);
  if ( !v5 )
    return 0;
  v6 = *v5;
  if ( !v6 )
    return 0;
  if ( *((_DWORD *)v6 - 1) != -725583242 )
    __break(0x8228u);
  v6(a1);
  if ( !*(_QWORD *)(v3 + 88) || (int)v4 < 1 )
    return 0;
  v7 = 80 * v4;
  v8 = (char *)_kmalloc_noprof(80 * v4, 3520);
  if ( !v8 )
  {
    printk(&unk_CC57, "btfmcodec_codec_probe");
    return 0;
  }
  printk(&unk_C5DB, "btfmcodec_codec_probe");
  memcpy(v8, *(const void **)(v3 + 88), 80 * v4);
  v12 = 0;
  while ( v7 > v12 + 16 )
  {
    printk(&unk_C600, "btfmcodec_codec_probe");
    if ( v7 <= v12 + 48 )
      break;
    *(_QWORD *)&v8[v12 + 48] = btfm_codec_get_mixer_control;
    if ( v7 < v12 + 56 )
      break;
    v13 = &v8[v12];
    v12 += 80;
    *((_QWORD *)v13 + 7) = btfmcodec_put_mixer_control;
    if ( 80 * v4 == v12 )
    {
      snd_soc_add_component_controls(a1, v8, (unsigned int)v4);
      kfree(v8);
      v10 = &unk_C0AF;
      goto LABEL_11;
    }
  }
  __break(1u);
  v14 = _fortify_panic(17, 80 * v4, 80 * v4);
  if ( (v15 & 0x80000) != 0 )
    JUMPOUT(0x509C);
  return btfmcodec_codec_remove(v14);
}
