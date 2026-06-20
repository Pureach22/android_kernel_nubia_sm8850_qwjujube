__int64 __fastcall etm_perf_add_symlink_sink(__int64 a1)
{
  __int64 v2; // x21
  __int64 v4; // x19
  __int64 v5; // x0
  unsigned __int64 v6; // x20
  unsigned int v7; // w22
  __int64 v8; // x0
  int v9; // w0
  unsigned __int64 v10; // x8

  if ( (*(_DWORD *)(a1 + 8) | 2) != 2 || *(_QWORD *)(a1 + 984) )
    return 4294967274LL;
  v2 = *(_QWORD *)(a1 + 168);
  if ( !v2 )
    v2 = *(_QWORD *)(a1 + 56);
  if ( etm_perf_up != 1 )
  {
    LODWORD(v10) = -517;
    *(_QWORD *)(a1 + 984) = 0;
    return (unsigned int)v10;
  }
  v4 = qword_11970;
  v5 = devm_kmalloc(a1 + 56, 40, 3520);
  if ( !v5 || (v6 = v5, v7 = hashlen_string(0, v2), v8 = devm_kstrdup(a1 + 56, v2, 3264), (*(_QWORD *)v6 = v8) == 0) )
  {
    LODWORD(v10) = -12;
LABEL_15:
    *(_QWORD *)(a1 + 984) = 0;
    return (unsigned int)v10;
  }
  *(_WORD *)(v6 + 8) = 292;
  *(_QWORD *)(v6 + 32) = v7;
  v9 = sysfs_add_file_to_group(v4, v6, "sinks");
  v10 = v9;
  if ( !v9 )
    v10 = v6;
  *(_QWORD *)(a1 + 984) = v10;
  if ( v10 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_15;
  *(_QWORD *)(v10 + 16) = etm_perf_sink_name_show;
  LODWORD(v10) = 0;
  return (unsigned int)v10;
}
