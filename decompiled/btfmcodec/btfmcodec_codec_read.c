__int64 __fastcall btfmcodec_codec_read(__int64 a1, unsigned int a2)
{
  __int64 v4; // x21
  __int64 v5; // x22
  __int64 v6; // x8
  _DWORD *v7; // x8
  unsigned int current_transport; // w0

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  v5 = *(_QWORD *)(v4 + 984);
  if ( (unsigned int)btfmcodec_get_current_transport(v4 + 912) )
  {
    current_transport = btfmcodec_get_current_transport(v4 + 912);
    coverttostring(current_transport);
    printk(&unk_CFA2, "btfmcodec_codec_read");
    return 0;
  }
  v6 = *(_QWORD *)(v5 + 72);
  if ( !v6 )
    return 0;
  v7 = *(_DWORD **)(v6 + 16);
  if ( !v7 )
    return 0;
  if ( *(v7 - 1) != 1117347427 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD))v7)(a1, a2);
}
