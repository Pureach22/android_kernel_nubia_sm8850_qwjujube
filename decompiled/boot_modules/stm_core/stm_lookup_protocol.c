__int64 __fastcall stm_lookup_protocol(const char *a1, _QWORD *a2, _QWORD *a3)
{
  __int64 *v6; // x22
  __int64 v7; // x24
  unsigned int v8; // w21

  mutex_lock(&stm_pdrv_mutex);
  if ( !a1 || !*a1 )
    a1 = "p_basic";
  v6 = &stm_pdrv_head;
  do
  {
    v6 = (__int64 *)*v6;
    if ( v6 == &stm_pdrv_head )
      goto LABEL_11;
    v7 = v6[2];
  }
  while ( strcmp(a1, *(const char **)(v7 + 8)) );
  if ( !v6 )
  {
LABEL_11:
    v8 = -2;
    goto LABEL_12;
  }
  if ( v7 )
  {
    v8 = 0;
    if ( (try_module_get(*(_QWORD *)v7) & 1) != 0 )
    {
      *a2 = v6[2];
      *a3 = v6[3];
    }
  }
  else
  {
    v8 = 0;
  }
LABEL_12:
  mutex_unlock(&stm_pdrv_mutex);
  return v8;
}
