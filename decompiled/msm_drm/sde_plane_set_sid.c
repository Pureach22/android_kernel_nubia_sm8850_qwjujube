__int64 __fastcall sde_plane_set_sid(unsigned int *a1, unsigned int a2)
{
  __int64 v2; // x8
  __int64 v3; // x9

  if ( !a1 || !*(_QWORD *)a1 )
    return printk(&unk_226FC0, "sde_plane_set_sid");
  v2 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( v2 && (v3 = *(_QWORD *)(v2 + 8)) != 0 )
    return sde_hw_set_sspp_sid(*(_QWORD *)(v3 + 3552), a1[482], a2, *(_QWORD *)(v3 + 152));
  else
    return printk(&unk_25EA03, "sde_plane_set_sid");
}
