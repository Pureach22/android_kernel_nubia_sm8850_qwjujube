__int64 __fastcall sde_get_dt_props(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, unsigned int *a5)
{
  __int64 v10; // x19
  __int64 v11; // x0
  int dt_entry; // w23
  __int64 v13; // x20

  v10 = _kvmalloc_node_noprof(328, 0, 3520, 0xFFFFFFFFLL);
  if ( !v10 )
    return -12;
  v11 = _kvmalloc_node_noprof(768 * a2, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(v10 + 320) = v11;
  if ( !v11 )
  {
    v13 = -12;
    goto LABEL_8;
  }
  dt_entry = validate_dt_entry(a1, a3, a4, (_DWORD *)(v10 + 64), a5);
  if ( dt_entry || (dt_entry = read_dt_entry(a1, a3, a4, v10 + 64, v10, *(_QWORD *)(v10 + 320))) != 0 )
  {
    kvfree(*(_QWORD *)(v10 + 320));
    v13 = dt_entry;
LABEL_8:
    kvfree(v10);
    return v13;
  }
  return v10;
}
