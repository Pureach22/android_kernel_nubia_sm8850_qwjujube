const void *__fastcall hif_mem_alloc_consistent_unaligned(
        __int64 a1,
        __int64 a2,
        const void **a3,
        unsigned int a4,
        _BYTE *a5)
{
  _DWORD *v7; // x8
  __int64 v11; // x0
  const void *v12; // x22
  const char *v13; // x4

  *a5 = 0;
  v7 = *(_DWORD **)(a1 + 2520);
  if ( !v7 )
    goto LABEL_6;
  if ( *(v7 - 1) != -601762988 )
    __break(0x8228u);
  v11 = ((__int64 (__fastcall *)(__int64, const void **, _QWORD))v7)(a2, a3, a4);
  if ( v11 )
  {
    v12 = (const void *)v11;
    v13 = "pre-alloc";
    *a5 = 1;
  }
  else
  {
LABEL_6:
    v12 = (const void *)_qdf_mem_alloc_consistent(
                          *(_QWORD *)(a1 + 576),
                          *(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL),
                          a2,
                          a3,
                          "hif_mem_alloc_consistent_unaligned",
                          2952);
    if ( *a5 )
      v13 = "pre-alloc";
    else
      v13 = "dynamic-alloc";
  }
  qdf_trace_msg(
    69,
    5,
    "%s: %s va_unaligned %pK pa_unaligned %pK size %d ring_type %d",
    "hif_mem_alloc_consistent_unaligned",
    v13,
    v12,
    *a3,
    a2,
    a4);
  return v12;
}
