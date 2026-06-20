__int64 __fastcall csr_release_command_buffer(
        __int64 a1,
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
  int v10; // w9
  bool v11; // vf
  int v12; // w9
  int v13; // w8
  __int64 v14; // x19
  void *v15; // x0
  __int64 v16; // x20
  size_t v17; // x1

  v10 = *(_DWORD *)(a1 + 17292);
  v11 = __OFSUB__(v10, 1);
  v12 = v10 - 1;
  if ( v12 < 0 != v11 )
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: no pending commands",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "csr_release_command_buffer");
  *(_DWORD *)(a1 + 17292) = v12;
  if ( !a2 )
  {
    v14 = a1;
    v16 = 0;
    qdf_trace_msg(0x34u, 2u, "%s: pCommand is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "csr_free_cmd_memory");
LABEL_10:
    a2 = v16;
    a1 = v14;
    return sme_release_command(a1, a2);
  }
  v13 = *(_DWORD *)(a2 + 16);
  if ( v13 == 65538 )
  {
    v14 = a1;
    v15 = (void *)(a2 + 32);
    v16 = a2;
    v17 = 44;
    goto LABEL_9;
  }
  if ( v13 == 65537 )
  {
    v14 = a1;
    v15 = (void *)(a2 + 32);
    v16 = a2;
    v17 = 20;
LABEL_9:
    qdf_mem_set(v15, v17, 0);
    goto LABEL_10;
  }
  return sme_release_command(a1, a2);
}
