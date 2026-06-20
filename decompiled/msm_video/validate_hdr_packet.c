__int64 __fastcall validate_hdr_packet(__int64 a1, _DWORD *a2, __int64 a3)
{
  __int64 result; // x0
  unsigned int v7; // w23
  unsigned int *v8; // x22

  if ( *a2 > 0x3Fu )
  {
    if ( a2[7] )
    {
      v7 = 0;
      v8 = a2 + 8;
      while ( 1 )
      {
        result = validate_packet(v8, *(_QWORD *)(a1 + 6480), *(_DWORD *)(a1 + 6472), a3);
        if ( (_DWORD)result )
          break;
        ++v7;
        v8 = (unsigned int *)((char *)v8 + *v8);
        if ( v7 >= a2[7] )
          return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83CE8, "err ", 0xFFFFFFFFLL, "codec", "validate_hdr_packet");
    return 4294967274LL;
  }
  return result;
}
