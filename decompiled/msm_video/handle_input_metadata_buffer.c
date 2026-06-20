__int64 __fastcall handle_input_metadata_buffer(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x23
  __int64 buffers; // x0
  __int64 v6; // x20
  __int64 v7; // x8
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  unsigned int v9; // w5
  int v10; // w6
  __int64 v11; // x4
  int v12; // w8
  const char *v13; // x1
  const char *v14; // x2
  __int64 v15; // x0
  unsigned int v17; // w9
  int v18; // w8

  v2 = *(_QWORD *)(a1 + 320);
  buffers = msm_vidc_get_buffers(a1, 3u, (__int64)"handle_input_metadata_buffer");
  if ( buffers )
  {
    v6 = buffers;
    do
    {
      v6 = *(_QWORD *)v6;
      if ( v6 == buffers )
      {
        if ( a1 && (msm_vidc_debug & 1) != 0 )
          printk(&unk_83D6C, "err ", a1 + 340, "handle_input_metadata_buffer", a2[1]);
        return 4294967274LL;
      }
    }
    while ( *(_DWORD *)(v6 + 32) != a2[1] );
    if ( !msm_vidc_is_super_buffer(a1) )
      goto LABEL_20;
    if ( v2
      && (v7 = *(_QWORD *)(v2 + 6560)) != 0
      && (v8 = *(__int64 (__fastcall **)(__int64, __int64))(v7 + 48)) != nullptr )
    {
      if ( *((_DWORD *)v8 - 1) != 1958436756 )
        __break(0x8228u);
      v9 = v8(a1, 3);
      v10 = *(_DWORD *)(a1 + 23336);
      if ( v9 && v10 )
      {
        v11 = a2[4];
        if ( (unsigned int)v11 / v9 < v10 - 1 )
        {
          if ( a1 )
          {
            if ( (msm_vidc_debug & 4) != 0 )
              printk(&unk_8DED9, "low ", a1 + 340, "handle_input_metadata_buffer", v11);
          }
          return 0;
        }
LABEL_20:
        v12 = *(_DWORD *)(v6 + 80);
        if ( (v12 & 8) != 0 )
        {
          v17 = a2[7];
          *(_DWORD *)(v6 + 64) = 0;
          v13 = "low ";
          *(_DWORD *)(v6 + 48) = v17;
          v14 = "dqbuf";
          *(_DWORD *)(v6 + 80) = v12 & 0xFFFFFFE7 | 0x10;
          v15 = 4;
          v18 = ((a2[10] & 0x30000000) != 0) << 20;
          *(_DWORD *)(v6 + 64) = v18;
          if ( *(_QWORD *)(a1 + 35768) )
            v18 = 0;
          *(_DWORD *)(v6 + 64) = v18;
        }
        else
        {
          v13 = "err ";
          v14 = "not queued";
          v15 = 1;
        }
        print_vidc_buffer(v15, (__int64)v13, (__int64)v14, a1, v6);
        return 0;
      }
    }
    else
    {
      v9 = 0;
    }
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_7FF39, "err ", a1 + 340, "handle_input_metadata_buffer", v9);
  }
  return 4294967274LL;
}
