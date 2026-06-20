__int64 __fastcall sde_kms_get_dsc_count(__int64 a1, int a2, unsigned int *a3)
{
  unsigned int v3; // w5
  unsigned int v4; // w6
  void *v6; // x0

  if ( !a3 )
  {
    v6 = &unk_2627A9;
LABEL_10:
    printk(v6, "sde_kms_get_dsc_count");
    return 4294967274LL;
  }
  *a3 = 0;
  if ( !a1 || !a2 )
  {
    v6 = &unk_2503C4;
    goto LABEL_10;
  }
  v3 = *(_DWORD *)(*(_QWORD *)(a1 + 152) + 21572LL);
  v4 = (a2 + v3 - 1) / v3;
  *a3 = v4;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "h=%d, max_dsc_width=%d, num_dsc=%d\n", a2, v3, v4);
  return 0;
}
