__int64 __fastcall qcom_smem_get_item_count(_QWORD *a1)
{
  _DWORD *v1; // x8
  __int64 result; // x0
  int v3; // w2
  _DWORD *v4; // x8
  _DWORD *v5; // x8
  int v6; // t1

  v1 = (_DWORD *)a1[4];
  if ( *v1 != 1129272356 )
    return 512;
  v3 = v1[1];
  if ( v3 == 1 )
  {
    result = 512;
    if ( v1 && (unsigned __int64)v1 <= 0xFFFFFFFFFFFFF000LL )
    {
      v4 = &v1[12 * v1[2]];
      v6 = v4[8];
      v5 = v4 + 8;
      if ( v6 == 1229539667 )
        return *((unsigned __int16 *)v5 + 8);
    }
  }
  else
  {
    dev_err(*a1, "Unsupported partition header version %d\n", v3);
    return 512;
  }
  return result;
}
