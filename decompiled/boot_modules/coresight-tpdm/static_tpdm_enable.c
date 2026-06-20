__int64 __fastcall static_tpdm_enable(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v4; // x20
  unsigned int aggre_atid; // w0
  unsigned int v6; // w1
  unsigned __int64 v14; // x9

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
  _X11 = (unsigned __int64 *)(a1 + 968);
  __asm { PRFM            #0x11, [X11] }
  while ( 1 )
  {
    v14 = __ldxr(_X11);
    if ( v14 )
      break;
    if ( !__stlxr(a3, _X11) )
    {
      __dmb(0xBu);
      break;
    }
  }
  if ( v14 )
  {
    dev_err(*(_QWORD *)(v4 + 8), "TPDM setup already enabled,Skipping enable\n");
    return 0;
  }
  aggre_atid = coresight_get_aggre_atid(a1);
  v6 = aggre_atid;
  if ( (aggre_atid & 0x80000000) == 0 )
  {
    *(_DWORD *)(v4 + 28) = aggre_atid;
    coresight_csr_set_etr_atid(a1, aggre_atid, 1, 0);
    dev_info(*(_QWORD *)(v4 + 8), "TPDM tracing enabled\n");
    return 0;
  }
  return v6;
}
