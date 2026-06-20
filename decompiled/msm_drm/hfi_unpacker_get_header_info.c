__int64 __fastcall hfi_unpacker_get_header_info(__int64 *a1, _DWORD *a2)
{
  __int64 v2; // x8
  __int64 result; // x0

  if ( a1 && (v2 = *a1) != 0 )
  {
    if ( (*(_DWORD *)v2 & 0xFFFFFFu) <= 0x1F )
    {
      printk(&unk_226EA3, "hfi_unpacker_get_header_info");
      return 0xFFFFFFFFLL;
    }
    else
    {
      result = 0;
      *a2 = *(_DWORD *)(v2 + 28);
      a2[1] = *(unsigned __int8 *)(v2 + 3);
      a2[2] = *(unsigned __int16 *)(v2 + 6);
      a2[3] = *(_DWORD *)(v2 + 16);
    }
  }
  else
  {
    printk(&unk_253204, "hfi_unpacker_get_header_info");
    return 0xFFFFFFFFLL;
  }
  return result;
}
