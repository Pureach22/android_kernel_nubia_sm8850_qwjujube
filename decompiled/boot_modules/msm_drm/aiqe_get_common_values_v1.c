void __fastcall aiqe_get_common_values_v1(__int64 a1, _DWORD *a2, int *a3)
{
  __int64 v3; // x9
  unsigned int v4; // w8
  int v5; // w4
  unsigned int v6; // w8
  int v7; // w1
  int v8; // w8

  v3 = *(_QWORD *)(a1 + 32);
  v4 = a3[1] & 0xFFFFFFFE;
  if ( *a2 )
    ++v4;
  a3[1] = v4;
  v5 = *(_DWORD *)(v3 + 32);
  if ( v5 == 3 )
  {
    v6 = v4 | 2;
  }
  else
  {
    if ( v5 != 1 )
    {
      _drm_dev_dbg(0, 0, 1, "AIQE not supported on LM idx %d", v5);
      return;
    }
    v6 = v4 & 0xFFFFFFFD;
  }
  a3[1] = v6;
  v7 = *(_DWORD *)(a1 + 28);
  switch ( v7 )
  {
    case 1:
      v8 = 0;
      goto LABEL_14;
    case 4:
      v8 = 3;
      goto LABEL_14;
    case 2:
      v8 = 1;
LABEL_14:
      *a3 = v8;
      a3[2] = *(_DWORD *)(a1 + 92);
      a3[3] = *(_DWORD *)(a1 + 96);
      return;
  }
  _drm_err("Invalid number of mixers %d", v7);
}
