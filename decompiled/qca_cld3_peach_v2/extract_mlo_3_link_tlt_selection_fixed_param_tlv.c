__int64 __fastcall extract_mlo_3_link_tlt_selection_fixed_param_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        __int64 a11)
{
  __int64 v11; // x19
  char v13; // w8
  const void *v14; // x1
  __int64 v16; // x20
  __int64 v17; // x20

  if ( a10 )
  {
    if ( a11 )
    {
      v11 = *a10;
      v13 = *(_DWORD *)(*a10 + 4);
      v14 = (const void *)(*a10 + 32);
      *(_BYTE *)a11 = v13;
      *(_BYTE *)(a11 + 1) = BYTE1(*(_DWORD *)(v11 + 4));
      *(_BYTE *)(a11 + 2) = *(_WORD *)(v11 + 6);
      *(_BYTE *)(a11 + 3) = *(_BYTE *)(v11 + 7);
      *(_WORD *)(a11 + 4) = *(_DWORD *)(v11 + 8);
      qdf_mem_copy((void *)(a11 + 28), v14, 8u);
      qdf_mem_copy((void *)(a11 + 8), (const void *)(v11 + 12), 0x14u);
      return 0;
    }
    v17 = jiffies;
    if ( extract_mlo_3_link_tlt_selection_fixed_param_tlv___last_ticks_64 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: params is NULL",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_mlo_3_link_tlt_selection_fixed_param_tlv");
      extract_mlo_3_link_tlt_selection_fixed_param_tlv___last_ticks_64 = v17;
    }
  }
  else
  {
    v16 = jiffies;
    if ( extract_mlo_3_link_tlt_selection_fixed_param_tlv___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Param_buf is NULL",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_mlo_3_link_tlt_selection_fixed_param_tlv");
      extract_mlo_3_link_tlt_selection_fixed_param_tlv___last_ticks = v16;
    }
  }
  return 29;
}
