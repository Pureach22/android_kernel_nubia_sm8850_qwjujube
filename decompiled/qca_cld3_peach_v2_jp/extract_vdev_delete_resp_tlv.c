__int64 __fastcall extract_vdev_delete_resp_tlv(
        int a1,
        __int64 *a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x19
  const char *v14; // x2

  if ( a2 )
  {
    v11 = *a2;
    if ( *a2 )
    {
      qdf_mem_set(a3, 1u, 0);
      *a3 = *(_DWORD *)(v11 + 4);
      return 0;
    }
    v14 = "%s: Invalid vdev delete response event";
  }
  else
  {
    v14 = "%s: Invalid vdev delete response event buffer";
  }
  qdf_trace_msg(0x31u, 2u, v14, a4, a5, a6, a7, a8, a9, a10, a11, "extract_vdev_delete_resp_tlv");
  return 4;
}
