__int64 __fastcall hif_exec_tasklet_kill(__int64 result)
{
  __int64 v1; // x19
  int v2; // w8
  __int64 v3; // x20
  __int64 v4; // x0
  unsigned int v11; // w9

  v1 = result;
  if ( *(_BYTE *)(result + 2680) == 1 )
    goto LABEL_8;
  while ( 1 )
  {
    v2 = *(_DWORD *)(v1 + 16);
    *(_BYTE *)(v1 + 2680) = 0;
    if ( !v2 )
      break;
    v3 = 0;
    while ( v3 != 25 )
    {
      v4 = _irq_apply_affinity_hint(*(unsigned int *)(v1 + 120 + 4 * v3), 0, 1);
      result = qdf_status_from_os_return(v4);
      if ( ++v3 >= (unsigned __int64)*(unsigned int *)(v1 + 16) )
        return result;
    }
    __break(0x5512u);
LABEL_8:
    _X8 = (unsigned int *)(v1 + 3480);
    __asm { PRFM            #0x11, [X8] }
    do
      v11 = __ldxr(_X8);
    while ( __stxr(v11 + 1, _X8) );
    __dmb(0xBu);
    tasklet_unlock_wait(v1 + 3464);
    __dmb(0xBu);
    result = tasklet_kill(v1 + 3464);
  }
  return result;
}
