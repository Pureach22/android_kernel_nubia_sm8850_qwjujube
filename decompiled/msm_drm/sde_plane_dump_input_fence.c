__int64 __fastcall sde_plane_dump_input_fence(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0

  if ( !a1 )
    return printk(&unk_226FC0, "sde_plane_dump_input_fence");
  v1 = *(_QWORD *)(a1 + 1768);
  if ( !v1 )
    return printk(&unk_2246B5, "sde_plane_dump_input_fence");
  result = *(_QWORD *)(v1 + 1752);
  if ( result )
    return sde_fence_dump();
  return result;
}
