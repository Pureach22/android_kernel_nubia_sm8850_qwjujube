__int64 __fastcall msm_ext_disp_remove(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 v2; // x8
  __int64 v3; // x8
  void *v5; // x0

  if ( !a1 )
  {
    v5 = &unk_70BE;
    return printk(v5, "msm_ext_disp_remove");
  }
  v1 = *(_QWORD **)(a1 + 168);
  if ( !v1 )
  {
    v5 = &unk_734E;
    return printk(v5, "msm_ext_disp_remove");
  }
  v2 = v1[2];
  if ( !v2 )
  {
    printk(&unk_7309, "msm_ext_disp_extcon_unregister");
    v3 = v1[2];
    if ( v3 )
      goto LABEL_5;
LABEL_12:
    printk(&unk_7309, "msm_ext_disp_extcon_unregister");
    return devm_kfree(v1[2] + 16LL, v1);
  }
  devm_extcon_dev_unregister(v2 + 16, v1[6]);
  v3 = v1[2];
  if ( !v3 )
    goto LABEL_12;
LABEL_5:
  devm_extcon_dev_unregister(v3 + 16, v1[7]);
  return devm_kfree(v1[2] + 16LL, v1);
}
