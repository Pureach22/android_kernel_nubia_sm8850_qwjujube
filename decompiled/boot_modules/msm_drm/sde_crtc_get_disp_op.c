__int64 __fastcall sde_crtc_get_disp_op(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x9
  __int64 v3; // x9
  void *v5; // x0
  const char *v6; // x1

  if ( !a1 || !*(_QWORD *)a1 || (v1 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) == 0 )
  {
    v5 = &unk_25E167;
    v6 = "sde_crtc_get_disp_op";
LABEL_10:
    printk(v5, v6);
    return 0;
  }
  v2 = *(_QWORD *)(v1 + 8);
  if ( !v2 )
  {
    v5 = &unk_234896;
    v6 = "_sde_crtc_get_kms";
    goto LABEL_10;
  }
  v3 = *(_QWORD *)(v2 + 152);
  if ( v3 && (*(_QWORD *)(v3 + 22008) & 0x8000000000000LL) != 0 )
    return *(unsigned int *)(v1 + 5912);
  return 0;
}
