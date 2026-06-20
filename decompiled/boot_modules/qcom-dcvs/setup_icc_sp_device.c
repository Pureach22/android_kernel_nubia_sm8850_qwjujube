__int64 __fastcall setup_icc_sp_device(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w8
  __int64 v8; // x0
  _QWORD *v9; // x20
  unsigned __int64 v10; // x0
  __int64 result; // x0
  __int64 v12; // x8
  unsigned __int64 v13; // x19

  v3 = *(_DWORD *)(a2 + 104);
  if ( v3 > 4 || v3 == 2 )
    return 4294967274LL;
  v8 = devm_kmalloc(a1, 8, 3520);
  if ( !v8 )
    return 4294967284LL;
  v9 = (_QWORD *)v8;
  v10 = of_icc_get(a1, 0);
  *v9 = v10;
  if ( v10 < 0xFFFFFFFFFFFFF001LL )
  {
    v12 = *(unsigned int *)(a2 + 104);
    if ( (unsigned int)v12 <= 4 && ((0x1Bu >> v12) & 1) != 0 )
      icc_set_tag(v10, dword_CD6C[v12]);
    result = 0;
    *(_QWORD *)(a3 + 120) = v9;
    *(_QWORD *)(a3 + 128) = commit_icc_freq;
  }
  else if ( (_DWORD)v10 == -517 )
  {
    return 4294966779LL;
  }
  else
  {
    v13 = v10;
    dev_err(a1, "Unable to register icc path: %d\n", v10);
    return v13;
  }
  return result;
}
