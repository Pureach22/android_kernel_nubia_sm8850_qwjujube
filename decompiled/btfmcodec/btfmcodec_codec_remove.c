__int64 __fastcall btfmcodec_codec_remove(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 result; // x0
  __int64 v5; // x8
  __int64 (__fastcall *v6)(_QWORD); // x8
  unsigned int current_transport; // w0

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  v3 = *(_QWORD *)(v2 + 984);
  result = btfmcodec_get_current_transport(v2 + 912);
  if ( (_DWORD)result )
  {
    current_transport = btfmcodec_get_current_transport(v2 + 912);
    coverttostring(current_transport);
    return printk(&unk_CFA2, "btfmcodec_codec_remove");
  }
  else
  {
    v5 = *(_QWORD *)(v3 + 72);
    if ( v5 )
    {
      v6 = *(__int64 (__fastcall **)(_QWORD))(v5 + 8);
      if ( v6 )
      {
        if ( *((_DWORD *)v6 - 1) != 933030000 )
          __break(0x8228u);
        return v6(a1);
      }
    }
  }
  return result;
}
