__int64 __fastcall syna_dev_set_stability_level(_QWORD *a1, int a2, unsigned int a3)
{
  void *v6; // x0
  __int64 result; // x0

  printk(unk_3A85B, "syna_dev_set_stability_level", "syna_dev_set_stability_level");
  if ( !a1 )
    return 4294967274LL;
  v6 = unk_3BDBF;
  if ( a2 <= 1 )
  {
    if ( a2 )
    {
      if ( a2 == 1 )
      {
        result = syna_tcm_set_dynamic_config(
                   *a1,
                   249,
                   *((_DWORD *)a1 + 383) | (16 * *((_DWORD *)a1 + 384)) | 0x100u,
                   a3);
        if ( (result & 0x80000000) != 0 )
          return result;
        v6 = unk_36F87;
      }
    }
    else
    {
      result = syna_tcm_set_dynamic_config(
                 *a1,
                 249,
                 *((_DWORD *)a1 + 383) | (unsigned int)(16 * *((_DWORD *)a1 + 384)),
                 a3);
      if ( (result & 0x80000000) != 0 )
        return result;
      v6 = unk_3B0D9;
    }
  }
  else
  {
    switch ( a2 )
    {
      case 2:
        result = syna_tcm_set_dynamic_config(
                   *a1,
                   249,
                   *((_DWORD *)a1 + 383) | (16 * *((_DWORD *)a1 + 384)) | 0x200u,
                   a3);
        if ( (result & 0x80000000) != 0 )
          return result;
        v6 = unk_3A1F3;
        break;
      case 3:
        result = syna_tcm_set_dynamic_config(
                   *a1,
                   249,
                   *((_DWORD *)a1 + 383) | (16 * *((_DWORD *)a1 + 384)) | 0x300u,
                   a3);
        if ( (result & 0x80000000) != 0 )
          return result;
        v6 = unk_3984B;
        break;
      case 4:
        result = syna_tcm_set_dynamic_config(
                   *a1,
                   249,
                   *((_DWORD *)a1 + 383) | (16 * *((_DWORD *)a1 + 384)) | 0x400u,
                   a3);
        if ( (result & 0x80000000) != 0 )
          return result;
        v6 = unk_35465;
        break;
    }
  }
  printk(v6, "syna_dev_set_stability_level", "syna_dev_set_stability_level");
  return 0;
}
