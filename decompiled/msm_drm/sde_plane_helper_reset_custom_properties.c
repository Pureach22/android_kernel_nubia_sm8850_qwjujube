__int64 __fastcall sde_plane_helper_reset_custom_properties(__int64 a1, __int64 a2)
{
  __int64 v4; // x22
  unsigned __int64 v5; // x21
  __int64 v6; // x23
  __int64 v7; // x26
  __int64 v8; // x27
  __int64 v9; // x28

  if ( a1 && a2 )
  {
    v4 = 0;
    v5 = 0;
    v6 = 208;
    *(_DWORD *)(a2 + 2744) = 0;
    do
    {
      if ( v5 < *(unsigned int *)(a1 + 3376) && (v7 = *(_QWORD *)(*(_QWORD *)(a1 + 3360) + 8 * v5)) != 0 )
      {
        v8 = *(_QWORD *)(a2 + v6);
        mutex_lock(a1 + 3424);
        if ( v5 >= *(unsigned int *)(a1 + 3376) )
          v9 = 0;
        else
          v9 = *(_QWORD *)(*(_QWORD *)(a1 + 3368) + v4);
        mutex_unlock(a1 + 3424);
        if ( v8 != v9 )
        {
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(
              0,
              0,
              0,
              "plane%d set prop %s idx %d from %llu to %llu\n",
              *(_DWORD *)(a1 + 104),
              (const char *)(v7 + 52),
              v5,
              v8,
              v9);
          if ( (unsigned int)sde_plane_atomic_set_property(a1, a2, v7, v9) )
            printk(&unk_257579, "sde_plane_helper_reset_custom_properties");
        }
      }
      else if ( (_drm_debug & 4) != 0 )
      {
        _drm_dev_dbg(0, 0, 0, "plane%d invalid property index %d\n", *(_DWORD *)(a1 + 104), v5);
      }
      ++v5;
      v4 += 16;
      v6 += 32;
    }
    while ( v5 != 48 );
    return 0;
  }
  else
  {
    printk(&unk_223EAA, "sde_plane_helper_reset_custom_properties");
    return 4294967274LL;
  }
}
