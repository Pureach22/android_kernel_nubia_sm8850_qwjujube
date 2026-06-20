void *__fastcall hdd_copy_file_name_and_oem_data(
        _BYTE *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int64 v10; // x4
  unsigned int v11; // w5

  v10 = *(_QWORD *)(a2 + 8);
  if ( !v10 )
    return (void *)qdf_trace_msg(
                     0x33u,
                     2u,
                     "%s: Invalid file name or data length",
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     "hdd_copy_file_name_and_oem_data");
  v11 = *(_DWORD *)(a2 + 32);
  if ( !v11 )
    return (void *)qdf_trace_msg(
                     0x33u,
                     2u,
                     "%s: Invalid file name or data length",
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     "hdd_copy_file_name_and_oem_data");
  if ( v10 > 0x400 || v11 >= 0x41 )
    return (void *)qdf_trace_msg(
                     0x33u,
                     2u,
                     "%s: Invalid oem data len %zu or file name len %d",
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     "hdd_copy_file_name_and_oem_data");
  qdf_mem_set(a1 + 7100, 0x400u, 0);
  qdf_mem_set(a1 + 8125, 0x40u, 0);
  qdf_mem_copy(a1 + 7100, *(const void **)(a2 + 24), *(unsigned int *)(a2 + 8));
  a1[8124] = *(_QWORD *)(a2 + 8);
  return qdf_mem_copy(a1 + 8125, *(const void **)(a2 + 40), *(unsigned int *)(a2 + 32));
}
