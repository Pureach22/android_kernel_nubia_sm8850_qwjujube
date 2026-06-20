__int64 __fastcall sde_connector_post_init(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v4; // x1
  unsigned __int64 v5; // x4
  __int64 result; // x0

  if ( !a1 || (v2 = *(_QWORD *)(a1 + 64)) == 0 || !a2 || (v4 = *(_QWORD *)(v2 + 8)) == 0 )
  {
    printk(&unk_2120FD, "sde_connector_post_init");
    return 4294967274LL;
  }
  if ( *(_DWORD *)(a2 + 156) != 16 )
    return 0;
  v5 = device_create_with_groups(
         *(_QWORD *)(v4 + 792),
         v4,
         0,
         a2,
         &sde_connector_attr_groups,
         "sde-conn-%d-%s",
         *(_DWORD *)(a2 + 152),
         *(const char **)(a2 + 96));
  *(_QWORD *)(a2 + 3304) = v5;
  if ( !v5 || (result = 0, v5 >= 0xFFFFFFFFFFFFF001LL) )
  {
    printk(&unk_25B4BB, "sde_connector_post_init");
    result = *(_QWORD *)(a2 + 3304);
    if ( !result )
      return 4294967274LL;
  }
  return result;
}
