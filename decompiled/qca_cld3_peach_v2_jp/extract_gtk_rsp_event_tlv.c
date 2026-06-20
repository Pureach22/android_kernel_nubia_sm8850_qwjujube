__int64 __fastcall extract_gtk_rsp_event_tlv(
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
        __int64 a11,
        unsigned int a12)
{
  const char *v12; // x2
  __int64 v14; // x8
  unsigned int v15; // w4
  __int64 v16; // x20

  if ( !a10 )
  {
    v12 = "%s: gtk param_buf is NULL";
    goto LABEL_5;
  }
  if ( a12 <= 0x93 )
  {
    v12 = "%s: Invalid length for GTK status";
LABEL_5:
    qdf_trace_msg(0x31u, 2u, v12, a1, a2, a3, a4, a5, a6, a7, a8, "extract_gtk_rsp_event_tlv");
    return 4;
  }
  v14 = *a10;
  v15 = *(_DWORD *)(*a10 + 4);
  if ( v15 < 6 )
  {
    *(_BYTE *)a11 = v15;
    *(_DWORD *)(a11 + 4) = 0;
    *(_DWORD *)(a11 + 8) = *(_DWORD *)(v14 + 12);
    qdf_mem_copy((void *)(a11 + 16), (const void *)(v14 + 16), 8u);
    return 0;
  }
  v16 = jiffies;
  if ( extract_gtk_rsp_event_tlv___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(0x31u, 2u, "%s: Invalid vdev_id %u", a1, a2, a3, a4, a5, a6, a7, a8, "extract_gtk_rsp_event_tlv");
    extract_gtk_rsp_event_tlv___last_ticks = v16;
  }
  return 4;
}
