__int64 __fastcall sde_connector_set_property_for_commit(__int64 a1, __int64 a2, unsigned int a3, __int64 a4)
{
  __int64 v6; // x21
  unsigned __int64 connector_state; // x0
  void *v9; // x0

  if ( !a1 || !a2 )
  {
    printk(&unk_25774E, "sde_connector_set_property_for_commit");
    return 4294967274LL;
  }
  if ( *(_DWORD *)(a1 + 3344) <= a3 || (v6 = *(_QWORD *)(*(_QWORD *)(a1 + 3328) + 8LL * a3)) == 0 )
  {
    v9 = &unk_25EFA4;
LABEL_12:
    printk(v9, "sde_connector_set_property_for_commit");
    return 4294967274LL;
  }
  connector_state = drm_atomic_get_connector_state(a2, a1);
  if ( !connector_state || connector_state >= 0xFFFFFFFFFFFFF001LL )
  {
    v9 = &unk_23F9AE;
    goto LABEL_12;
  }
  return sde_connector_atomic_set_property(a1, connector_state, v6, a4);
}
