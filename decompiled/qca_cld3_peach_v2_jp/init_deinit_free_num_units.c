__int64 __fastcall init_deinit_free_num_units(
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
  __int64 v10; // x8
  __int64 (*v12)(void); // x8
  __int64 v14; // x20
  unsigned __int64 v15; // x21
  int *v16; // x22
  const char *v17; // x2

  if ( !a2 )
  {
    v17 = "%s: target_psoc_info is null";
LABEL_16:
    qdf_trace_msg(0x49u, 2u, v17, a3, a4, a5, a6, a7, a8, a9, a10, "init_deinit_free_num_units");
    return 4;
  }
  v10 = *(_QWORD *)(a2 + 4512);
  if ( v10 )
  {
    v12 = *(__int64 (**)(void))(v10 + 88);
    if ( v12 )
    {
      if ( *((_DWORD *)v12 - 1) != -2039706441 )
        __break(0x8228u);
      return v12();
    }
  }
  if ( !a1 || (v14 = *(_QWORD *)(a1 + 2120)) == 0 )
  {
    v17 = "%s: qdf_dev is null";
    goto LABEL_16;
  }
  if ( *(_DWORD *)(a2 + 3328) )
  {
    v15 = 0;
    v16 = (int *)(a2 + 3360);
    while ( v15 != 32 )
    {
      _qdf_mem_free_consistent(v14, *(_QWORD *)(v14 + 40), *v16);
      *v16 = 0;
      ++v15;
      *((_QWORD *)v16 - 3) = 0;
      *((_QWORD *)v16 - 2) = 0;
      v16 += 8;
      if ( v15 >= *(unsigned int *)(a2 + 3328) )
        goto LABEL_13;
    }
    __break(0x5512u);
    return init_deinit_handle_host_mem_req();
  }
  else
  {
LABEL_13:
    *(_DWORD *)(a2 + 3328) = 0;
    return 0;
  }
}
