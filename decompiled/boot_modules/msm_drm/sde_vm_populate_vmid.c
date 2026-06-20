_WORD *__fastcall sde_vm_populate_vmid(__int16 a1)
{
  _WORD *result; // x0

  result = (_WORD *)_kmalloc_cache_noprof(_mutex_init, 3520, 8);
  if ( !result )
    return (_WORD *)&_ksymtab___traceiter_tracing_mark_write;
  result[2] = a1;
  *result = 1;
  return result;
}
