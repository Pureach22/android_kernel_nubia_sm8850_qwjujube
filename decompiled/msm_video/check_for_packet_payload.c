__int64 __fastcall check_for_packet_payload(__int64 result, unsigned int *a2, __int64 a3)
{
  unsigned int v3; // w5
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x4

  v3 = a2[3];
  if ( v3 > 0xD )
    goto LABEL_10;
  if ( ((1 << v3) & 0x706) != 0 )
  {
    v4 = 36;
    goto LABEL_15;
  }
  if ( ((1 << v3) & 0x2018) != 0 )
  {
    v4 = 40;
    goto LABEL_15;
  }
  if ( v3 == 5 )
  {
    v4 = 32;
    if ( a2[1] == 16777225 )
      v4 = 96;
  }
  else
  {
LABEL_10:
    if ( !v3 )
    {
      if ( !result )
        return result;
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_8A28B, "high", result + 340, a3, a2[1]);
      return 0;
    }
    v4 = 32;
  }
LABEL_15:
  v5 = *a2;
  if ( v4 > v5 )
  {
    if ( !result )
      return result;
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8F7FC, "err ", result + 340, a3, v5);
    return 0;
  }
  return 1;
}
