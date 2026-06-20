__int64 __fastcall sde_plane_flush(__int64 a1)
{
  __int64 v1; // x20
  unsigned int v3; // w9
  __int64 v4; // x8
  __int64 result; // x0
  __int64 v6; // x10
  __int64 (*v7)(void); // x9
  __int64 v8; // x11

  if ( !a1 )
    return printk(&unk_226FC0, "sde_plane_flush");
  v1 = *(_QWORD *)(a1 + 1768);
  if ( !v1 )
    return printk(&unk_226FC0, "sde_plane_flush");
  v3 = 0;
  v4 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( *(_QWORD *)a1 && v4 )
    v3 = *(_DWORD *)(v4 + 5912);
  if ( *(_BYTE *)(a1 + 2380) == 1 || (*(_DWORD *)(a1 + 2376) & 0x80000000) != 0 )
  {
    result = sde_plane_color_fill();
  }
  else
  {
    result = *(_QWORD *)(a1 + 2208);
    if ( result && *(_QWORD *)(v1 + 2912) )
    {
      if ( v3 >= 3 )
      {
        __break(0x5512u);
        return sde_plane_color_fill();
      }
      v6 = v3;
      v7 = *(__int64 (**)(void))(result + 8LL * v3 + 232);
      if ( v7 )
      {
        v8 = *(_QWORD *)(a1 + 4272);
        if ( v8 )
        {
          *(_DWORD *)(result + 1408) = *(_DWORD *)(v8 + 8);
          v7 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 2208) + 8 * v6 + 232);
        }
        if ( *((_DWORD *)v7 - 1) != 1154965516 )
          __break(0x8229u);
        result = v7();
      }
    }
  }
  if ( *(_QWORD *)(a1 + 1768) )
    *(_BYTE *)(v1 + 1785) = 0;
  return result;
}
