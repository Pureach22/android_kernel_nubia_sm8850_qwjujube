__int64 __fastcall get_hfi_port_from_buffer_type(__int64 result, unsigned int a2)
{
  __int64 v2; // x4
  unsigned int v3; // w8
  unsigned int *v4; // x9
  __int64 v5; // x2
  void *v6; // x0

  v2 = *(unsigned int *)(result + 308);
  if ( (_DWORD)v2 == 1 )
  {
    v3 = a2 - 1;
    if ( a2 - 1 < 0xE && ((0x2FCFu >> v3) & 1) != 0 )
    {
      v4 = (unsigned int *)&unk_9ABF8;
      return v4[v3];
    }
    goto LABEL_10;
  }
  if ( (_DWORD)v2 == 2 )
  {
    v3 = a2 - 1;
    if ( a2 - 1 < 0xF && ((0x5F4Fu >> v3) & 1) != 0 )
    {
      v4 = (unsigned int *)&unk_9ABBC;
      return v4[v3];
    }
LABEL_10:
    if ( !result )
      return result;
    if ( (msm_vidc_debug & 1) == 0 )
      return 0;
    v5 = result + 340;
    v6 = &unk_88043;
    v2 = a2;
    goto LABEL_18;
  }
  if ( !result )
    return result;
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v5 = result + 340;
    v6 = &unk_801EE;
LABEL_18:
    printk(v6, "err ", v5, "get_hfi_port_from_buffer_type", v2);
  }
  return 0;
}
