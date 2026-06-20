__int64 __fastcall mmrm_sw_print_crm_table(__int64 result)
{
  unsigned int v1; // w9
  int v2; // w8
  __int64 v3; // x19
  unsigned int i; // w20

  if ( *(_BYTE *)(result + 688) == 1 )
  {
    v1 = *(_DWORD *)(result + 704);
    v2 = msm_mmrm_debug;
    v3 = result;
    if ( v1 )
    {
      for ( i = 0; i < v1; ++i )
      {
        if ( (~v2 & 0x10002) == 0 )
        {
          result = printk(&unk_D68B, "high", "mmrm_sw_print_crm_table");
          v2 = msm_mmrm_debug;
          v1 = *(_DWORD *)(v3 + 704);
        }
      }
    }
    if ( (~v2 & 0x10002) == 0 )
      return printk(&unk_DD36, "high", "mmrm_sw_print_crm_table");
  }
  return result;
}
