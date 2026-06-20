__int64 __fastcall hif_deregister_exec_group(__int64 result, const char *a2)
{
  __int64 v3; // x20
  __int64 v4; // x24
  __int64 v5; // x25
  __int64 v6; // x23
  void (__fastcall *v7)(_QWORD); // x8

  v3 = result;
  v4 = 0;
  v5 = result + 27120;
  do
  {
    v6 = *(_QWORD *)(v5 + v4);
    if ( v6 )
    {
      qdf_trace_msg(
        61,
        8,
        "%s: %s: Deregistering grp id %d name %s",
        "hif_deregister_exec_group",
        "hif_deregister_exec_group",
        *(_DWORD *)(v6 + 232),
        *(const char **)(v6 + 240));
      result = strcmp(*(const char **)(v6 + 240), a2);
      if ( !(_DWORD)result )
      {
        v7 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)v6 + 24LL);
        if ( *((_DWORD *)v7 - 1) != -836874276 )
          __break(0x8228u);
        v7(v6);
        *(_QWORD *)(v5 + v4) = 0;
        result = _qdf_mem_free(v6);
        --*(_DWORD *)(v3 + 27264);
      }
    }
    v4 += 8;
  }
  while ( v4 != 144 );
  return result;
}
