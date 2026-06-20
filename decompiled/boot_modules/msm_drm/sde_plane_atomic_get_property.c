__int64 __fastcall sde_plane_atomic_get_property(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x21
  __int64 v7; // x22
  void *v9; // x0

  if ( !a1 )
  {
    v9 = &unk_226FC0;
LABEL_9:
    printk(v9, "sde_plane_atomic_get_property");
    return 4294967274LL;
  }
  if ( !a2 )
  {
    v9 = &unk_279EAB;
    goto LABEL_9;
  }
  if ( (_drm_debug & 4) != 0 )
  {
    v6 = a3;
    v7 = a4;
    _drm_dev_dbg(0, 0, 0, "plane%d \n", *(_DWORD *)(a1 + 104));
    a3 = v6;
    a4 = v7;
  }
  return msm_property_atomic_get(a1 + 3344, a2 + 176, a3, a4);
}
