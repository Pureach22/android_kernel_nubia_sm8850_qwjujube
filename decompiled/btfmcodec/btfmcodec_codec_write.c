__int64 __fastcall btfmcodec_codec_write(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v6; // x22
  __int64 v7; // x23
  __int64 v8; // x8
  _DWORD *v9; // x8
  unsigned int current_transport; // w0

  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  v7 = *(_QWORD *)(v6 + 984);
  if ( (unsigned int)btfmcodec_get_current_transport(v6 + 912) )
  {
    current_transport = btfmcodec_get_current_transport(v6 + 912);
    coverttostring(current_transport);
    printk(&unk_CFA2, "btfmcodec_codec_write");
    return 0;
  }
  v8 = *(_QWORD *)(v7 + 72);
  if ( !v8 || !*(_QWORD *)(v8 + 8) )
    return 0;
  v9 = *(_DWORD **)(v8 + 24);
  if ( *(v9 - 1) != 146939955 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v9)(a1, a2, a3);
}
