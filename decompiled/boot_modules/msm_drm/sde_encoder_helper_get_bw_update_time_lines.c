unsigned __int64 __fastcall sde_encoder_helper_get_bw_update_time_lines(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  int v3; // w9
  int v4; // w10
  unsigned __int64 v5; // x9
  void *v7; // x0
  void *v8; // x0

  if ( !a1 || !*(_QWORD *)a1 )
  {
    v7 = &unk_26FCAB;
LABEL_12:
    printk(v7, "sde_encoder_get_kms");
    v8 = &unk_234896;
LABEL_13:
    printk(v8, "sde_encoder_helper_get_bw_update_time_lines");
    return 0;
  }
  v1 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v1 || (v2 = *(_QWORD *)(v1 + 8)) == 0 )
  {
    v7 = &unk_234896;
    goto LABEL_12;
  }
  v3 = *(_DWORD *)(a1 + 3944);
  if ( !v3 )
  {
    v8 = &unk_276EAD;
    goto LABEL_13;
  }
  if ( *(_DWORD *)(a1 + 648) == 2 )
    v4 = *(unsigned __int16 *)(*(_QWORD *)(*(_QWORD *)(a1 + 1360) + 2008LL) + 158LL);
  else
    v4 = *(_DWORD *)(a1 + 3948);
  v5 = ((unsigned __int64)(unsigned int)(v4 * v3) + 999999999) / (unsigned int)(v4 * v3);
  return (v5 + *(unsigned int *)(*(_QWORD *)(v2 + 152) + 21588LL) - 1) / v5;
}
