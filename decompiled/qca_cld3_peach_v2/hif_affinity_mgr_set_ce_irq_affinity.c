__int64 __fastcall hif_affinity_mgr_set_ce_irq_affinity(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4)
{
  __int64 v6; // x20
  __int64 v7; // x0

  if ( (*(_BYTE *)(a1 + 4196) & 1) != 0 )
  {
    if ( a3 >= 0xD )
    {
      __break(0x5512u);
      JUMPOUT(0x174154);
    }
    return hif_affinity_mgr_set_irq_affinity(a1, a2, a1 + 48LL * a3 + 4208, a4);
  }
  else
  {
    v6 = a4;
    irq_modify_status(a2, 0x2000, 0);
    v7 = _irq_apply_affinity_hint(a2, v6, 1);
    LODWORD(v6) = qdf_status_from_os_return(v7);
    irq_modify_status(a2, 0, 0x2000);
    return (unsigned int)v6;
  }
}
