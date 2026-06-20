const char *__fastcall hif_get_hw_name(_DWORD *a1)
{
  const char *result; // x0
  char *v3; // x20
  __int64 i; // x8
  char *v5; // x0

  qdf_trace_msg(61, 8, "%s: target version = %d, target revision = %d", "hif_get_hw_name", *a1, a1[2]);
  v3 = (char *)(a1 + 4);
  result = *((const char **)a1 + 2);
  if ( !result )
  {
    for ( i = 0; i != 656; i += 16 )
    {
      if ( *a1 == *(_DWORD *)((char *)&qwlan_hw_list + i) && a1[2] == *(_DWORD *)((char *)&qwlan_hw_list + i + 4) )
      {
        v3 = (char *)&qwlan_hw_list + i + 8;
        return *(const char **)v3;
      }
    }
    v5 = (char *)_qdf_mem_malloc(64, "hif_get_hw_name", 530);
    *(_QWORD *)v3 = v5;
    if ( v5 )
    {
      if ( (snprintf(v5, 0x40u, "HW_VERSION=%x.", *a1) & 0x80000000) == 0 )
        return *(const char **)v3;
      return "Unknown Device (snprintf failure)";
    }
    else
    {
      return "Unknown Device (nomem)";
    }
  }
  return result;
}
