__int64 __fastcall populate_dot11f_tdls_mgmt_mlo_ie(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x19
  char v5; // w9
  __int64 v6; // x9

  result = 29;
  if ( a1 )
  {
    if ( a2 )
    {
      v4 = a2 + 12288;
      *(_WORD *)(a2 + 12964) = 255;
      v5 = *(_WORD *)(a2 + 12967);
      *(_BYTE *)(a2 + 12966) = 107;
      *(_WORD *)(a2 + 12967) = v5 & 8 | 0x23;
      v6 = *(_QWORD *)(a2 + 16);
      *(_BYTE *)(a2 + 12969) = 2;
      qdf_mem_copy((void *)(a2 + 12970), (const void *)(*(_QWORD *)(v6 + 1360) + 17LL), 6u);
      *(_WORD *)(v4 + 674) = 12;
      return 0;
    }
  }
  return result;
}
