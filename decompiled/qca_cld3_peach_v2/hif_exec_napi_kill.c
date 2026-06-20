__int64 __fastcall hif_exec_napi_kill(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x0

  v1 = a1;
  if ( *(_BYTE *)(a1 + 2680) == 1 )
  {
    a1 = napi_disable(a1 + 6208);
    *(_BYTE *)(v1 + 2680) = 0;
  }
  if ( *(_DWORD *)(v1 + 16) )
  {
    v2 = 0;
    while ( v2 != 25 )
    {
      v3 = _irq_apply_affinity_hint(*(unsigned int *)(v1 + 120 + 4 * v2), 0, 1);
      a1 = qdf_status_from_os_return(v3);
      if ( ++v2 >= (unsigned __int64)*(unsigned int *)(v1 + 16) )
        goto LABEL_7;
    }
    __break(0x5512u);
    return hif_exec_tasklet_schedule(a1);
  }
  else
  {
LABEL_7:
    v4 = _netif_napi_del(v1 + 6208);
    return synchronize_net(v4);
  }
}
