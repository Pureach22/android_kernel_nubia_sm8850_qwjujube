__int64 __fastcall stm_source_link_show(__int64 a1, __int64 a2, char *a3)
{
  unsigned int lock; // w0
  const char **v6; // x8
  unsigned int v7; // w20
  const char *v8; // x2
  int v9; // w19

  lock = _srcu_read_lock(&stm_source_srcu);
  v6 = *(const char ***)(a1 + 928);
  v7 = lock;
  if ( v6 )
  {
    v8 = v6[14];
    if ( !v8 )
      v8 = *v6;
  }
  else
  {
    v8 = "<none>";
  }
  v9 = sprintf(a3, "%s\n", v8);
  _srcu_read_unlock(&stm_source_srcu, v7);
  return v9;
}
