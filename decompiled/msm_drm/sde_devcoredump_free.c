__int64 sde_devcoredump_free()
{
  __int64 v0; // x0
  __int64 result; // x0

  v0 = *(_QWORD *)(sde_dbg_base + 786464);
  if ( v0 )
  {
    kvfree(v0);
    *(_QWORD *)(sde_dbg_base + 786464) = 0;
  }
  result = qword_2945E0;
  if ( qword_2945E0 )
  {
    result = kvfree(qword_2945E0);
    qword_2945E0 = 0;
  }
  word_294380 = 0;
  return result;
}
