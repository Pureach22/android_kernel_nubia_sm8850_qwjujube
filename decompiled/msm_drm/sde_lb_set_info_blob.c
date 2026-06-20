__int64 __fastcall sde_lb_set_info_blob(__int64 *a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x8
  void *v8; // x0

  result = 4294967274LL;
  if ( !a1 || !a2 )
    return result;
  v4 = *a1;
  if ( !v4 || (v5 = *(_QWORD *)(v4 + 56)) == 0 )
  {
    v8 = &unk_2207A9;
LABEL_12:
    printk(v8, a2);
    return 4294967274LL;
  }
  v6 = *(_QWORD *)(v5 + 8);
  if ( !v6 )
  {
    v8 = &unk_22A98C;
    goto LABEL_12;
  }
  v7 = *(_QWORD *)(v6 + 152);
  if ( !v7 )
    return 4294967274LL;
  if ( *(_DWORD *)(v7 + 56) == 41 )
    sde_kms_info_add_keyint(a2, (__int64)"has_cac_loopback", 1);
  return 0;
}
