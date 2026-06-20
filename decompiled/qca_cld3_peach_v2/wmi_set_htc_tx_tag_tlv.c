__int64 __fastcall wmi_set_htc_tx_tag_tlv(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        int a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 result; // x0
  int v15; // w9

  result = 0;
  if ( a11 > 118791 )
  {
    if ( a11 == 118792 )
    {
      if ( *(_DWORD *)(a1 + 696) )
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: Target is already suspended, Ignore FW Hang Command",
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          "wmi_tag_fw_hang_cmd",
          v11,
          v12);
        return 0;
      }
      else
      {
        v15 = *(unsigned __int8 *)(a1 + 720);
        *(_BYTE *)(a1 + 720) = 0;
        if ( v15 )
          return 12;
        else
          return 0;
      }
    }
    if ( a11 != 143361 )
      return result;
    return 12;
  }
  if ( (unsigned int)(a11 - 77828) <= 0xD && ((1 << (a11 - 4)) & 0x2003) != 0 || (unsigned int)(a11 - 69633) < 2 )
    return 12;
  return result;
}
