__int64 __fastcall sde_plane_is_sw_fence_signaled(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 (__fastcall *v3)(_QWORD); // x8

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 1768);
    if ( v1 )
    {
      v2 = *(_QWORD *)(v1 + 1752);
      if ( !v2 || (*(_QWORD *)(v2 + 48) & 1) != 0 )
        return 1;
      v3 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v2 + 8) + 32LL);
      if ( v3 )
      {
        if ( *((_DWORD *)v3 - 1) != 1879296680 )
          __break(0x8228u);
        if ( (v3(v2) & 1) != 0 )
        {
          dma_fence_signal(v2);
          return 1;
        }
      }
      return 0;
    }
    else
    {
      printk(&unk_2246B5, "sde_plane_is_sw_fence_signaled");
      return 0;
    }
  }
  else
  {
    printk(&unk_226FC0, "sde_plane_is_sw_fence_signaled");
    return 0;
  }
}
