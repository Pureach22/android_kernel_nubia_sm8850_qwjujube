__int64 __fastcall handle_output_metadata_buffer(__int64 a1, _DWORD *a2)
{
  __int64 buffers; // x0
  __int64 v5; // x4
  int v6; // w9
  const char *v7; // x1
  const char *v8; // x2
  __int64 v9; // x0
  int v11; // w10
  int v12; // w9
  int v13; // w8

  buffers = msm_vidc_get_buffers(a1, 4u, (__int64)"handle_output_metadata_buffer");
  if ( buffers )
  {
    v5 = buffers;
    while ( 1 )
    {
      v5 = *(_QWORD *)v5;
      if ( v5 == buffers )
        break;
      if ( *(_DWORD *)(v5 + 32) == a2[1] )
      {
        v6 = *(_DWORD *)(v5 + 80);
        if ( (v6 & 8) != 0 )
        {
          v11 = a2[7];
          *(_DWORD *)(v5 + 64) = 0;
          v7 = "low ";
          *(_DWORD *)(v5 + 48) = v11;
          v8 = "dqbuf";
          *(_DWORD *)(v5 + 80) = v6 & 0xFFFFFFE7 | 0x10;
          v9 = 4;
          v12 = ((a2[10] & 0x30000000) != 0) << 20;
          *(_DWORD *)(v5 + 64) = v12;
          if ( *(_QWORD *)(a1 + 35768) )
            v13 = 0;
          else
            v13 = v12;
          *(_DWORD *)(v5 + 64) = v13;
        }
        else
        {
          v7 = "err ";
          v8 = "not queued";
          v9 = 1;
        }
        print_vidc_buffer(v9, (__int64)v7, (__int64)v8, a1, v5);
        return 0;
      }
    }
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_83D6C, "err ", a1 + 340, "handle_output_metadata_buffer", (unsigned int)a2[1]);
  }
  return 4294967274LL;
}
