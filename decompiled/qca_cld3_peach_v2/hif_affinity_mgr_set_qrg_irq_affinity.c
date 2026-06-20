__int64 __fastcall hif_affinity_mgr_set_qrg_irq_affinity(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5)
{
  __int64 v8; // x0
  unsigned int v9; // w20

  if ( (*(_BYTE *)(a1 + 4196) & 1) != 0 )
  {
    if ( a3 > 0x11 || a4 >= 0x1A )
    {
      __break(0x5512u);
      return hif_affinity_mgr_set_irq_affinity();
    }
    else
    {
      return hif_affinity_mgr_set_irq_affinity();
    }
  }
  else
  {
    irq_modify_status(a2, 0x2000, 0);
    v8 = _irq_apply_affinity_hint(a2, a5, 1);
    v9 = qdf_status_from_os_return(v8);
    irq_modify_status(a2, 0, 0x2000);
    return v9;
  }
}
