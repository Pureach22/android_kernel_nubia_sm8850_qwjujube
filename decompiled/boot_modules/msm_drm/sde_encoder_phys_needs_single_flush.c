__int64 __fastcall sde_encoder_phys_needs_single_flush(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x9
  __int64 v3; // x8
  __int64 v4; // x4
  unsigned __int64 v5; // x8
  void *v6; // x0

  if ( result )
  {
    v1 = *(_QWORD *)(result + 8);
    if ( v1 && (v2 = *(_QWORD *)(v1 + 2512)) != 0 )
    {
      if ( *(_DWORD *)(v2 + 1376) == 10 )
        return 1;
      v3 = *(_QWORD *)(result + 512);
      if ( v3 )
      {
        v4 = *(_QWORD *)(v2 + 1376);
        if ( (unsigned int)(v4 - 17) > 0xFFFFFFEF )
        {
          v5 = *(_QWORD *)(v3 + 2472) + 28LL * (unsigned int)v4;
          if ( v5 && v5 < 0xFFFFFFFFFFFFF001LL )
            return *(_DWORD *)(v5 + 16) != 2;
          goto LABEL_13;
        }
LABEL_12:
        printk(&unk_22E16F, "sde_rm_topology_get_topology_def");
LABEL_13:
        v6 = &unk_23F597;
        goto LABEL_14;
      }
    }
    else if ( *(_QWORD *)(result + 512) )
    {
      goto LABEL_12;
    }
    v6 = &unk_21D882;
LABEL_14:
    printk(v6, "_sde_encoder_phys_is_dual_ctl");
    return 1;
  }
  return result;
}
