__int64 __fastcall syna_dev_set_sensibility_level(_QWORD *a1, int a2, unsigned int a3)
{
  void *v6; // x0
  __int64 result; // x0

  printk(unk_3A85B, "syna_dev_set_sensibility_level", "syna_dev_set_sensibility_level");
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
                   (16 * *((_DWORD *)a1 + 384)) | (*((_DWORD *)a1 + 385) << 8) | 1u,
                   a3);
        if ( (result & 0x80000000) != 0 )
          return result;
        v6 = unk_38158;
      }
    }
    else
    {
      result = syna_tcm_set_dynamic_config(
                 *a1,
                 249,
                 (unsigned int)(16 * *((_DWORD *)a1 + 384)) | (*((_DWORD *)a1 + 385) << 8),
                 a3);
      if ( (result & 0x80000000) != 0 )
        return result;
      v6 = unk_33BBE;
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
                   (16 * *((_DWORD *)a1 + 384)) | (*((_DWORD *)a1 + 385) << 8) | 2u,
                   a3);
        if ( (result & 0x80000000) != 0 )
          return result;
        v6 = unk_32E7C;
        break;
      case 3:
        result = syna_tcm_set_dynamic_config(
                   *a1,
                   249,
                   (16 * *((_DWORD *)a1 + 384)) | (*((_DWORD *)a1 + 385) << 8) | 3u,
                   a3);
        if ( (result & 0x80000000) != 0 )
          return result;
        v6 = unk_32EAC;
        break;
      case 4:
        result = syna_tcm_set_dynamic_config(
                   *a1,
                   249,
                   (16 * *((_DWORD *)a1 + 384)) | (*((_DWORD *)a1 + 385) << 8) | 4u,
                   a3);
        if ( (result & 0x80000000) != 0 )
          return result;
        v6 = unk_359E9;
        break;
    }
  }
  printk(v6, "syna_dev_set_sensibility_level", "syna_dev_set_sensibility_level");
  return 0;
}
