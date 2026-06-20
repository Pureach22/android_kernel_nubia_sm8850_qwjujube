__int64 __fastcall wmi_fill_keys_from_tlv(
        __int64 result,
        __int64 a2,
        _BYTE *a3,
        _BYTE *a4,
        unsigned __int8 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  int v13; // w24
  __int64 v15; // x20
  unsigned int v17; // w25
  unsigned __int8 v18; // w23
  unsigned int v19; // w22
  __int64 v20; // x20

  if ( (unsigned __int8)*(_DWORD *)(*(_QWORD *)result + 64LL) <= 0x30u )
    v13 = *(_DWORD *)(*(_QWORD *)result + 64LL);
  else
    LOBYTE(v13) = 48;
  *a3 = v13;
  if ( (_BYTE)v13 )
  {
    v15 = result;
    v17 = a5;
    v18 = v13;
    while ( *(_QWORD *)v15 )
    {
      if ( (unsigned __int8)*a4 >= v17 )
        return qdf_trace_msg(
                 0x31u,
                 8u,
                 "%s: Read all TLVs count:%d",
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 a13,
                 "wmi_fill_keys_from_tlv");
      if ( (v18 & 0xE0) != 0 )
        v19 = 32;
      else
        v19 = v18;
      result = (__int64)qdf_mem_copy(
                          (void *)(a2 + (unsigned __int8)(v13 - v18)),
                          (const void *)(*(_QWORD *)v15 + 24LL),
                          v19);
      v18 -= v19;
      *(_QWORD *)v15 += 72LL;
      ++*a4;
      if ( !v18 )
        return result;
    }
    v20 = jiffies;
    if ( wmi_fill_keys_from_tlv___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x31u,
                 2u,
                 "%s: ml_keys is NULL. rem_key_len:%d",
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 a13,
                 "wmi_fill_keys_from_tlv",
                 v18);
      wmi_fill_keys_from_tlv___last_ticks = v20;
    }
  }
  return result;
}
