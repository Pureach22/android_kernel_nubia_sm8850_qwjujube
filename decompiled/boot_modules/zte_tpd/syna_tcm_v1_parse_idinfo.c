__int64 __fastcall syna_tcm_v1_parse_idinfo(__int64 a1, const void *a2, __int64 a3, unsigned int a4)
{
  size_t v4; // x4
  int v6; // w8
  __int64 result; // x0
  __int64 v8; // x2

  if ( a2 && a4 )
  {
    if ( a4 >= 0x30 )
      v4 = 48;
    else
      v4 = a4;
    if ( (unsigned int)v4 > (unsigned int)a3 )
    {
      printk(&unk_3944E, "syna_pal_mem_cpy", a3);
      printk(&unk_320CD, "syna_tcm_v1_parse_idinfo", v8);
      return 4294967274LL;
    }
    else
    {
      memcpy((void *)(a1 + 128), a2, v4);
      v6 = *(_DWORD *)(a1 + 146);
      if ( *(_DWORD *)(a1 + 12) != v6 )
        *(_DWORD *)(a1 + 12) = v6;
      result = 0;
      *(_BYTE *)(a1 + 9) = *(_BYTE *)(a1 + 129);
    }
  }
  else
  {
    printk(&unk_3B313, "syna_tcm_v1_parse_idinfo", a3);
    return 4294967055LL;
  }
  return result;
}
