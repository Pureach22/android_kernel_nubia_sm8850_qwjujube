__int64 __fastcall sde_kms_splash_mem_get(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 (*v4)(void); // x8
  __int64 result; // x0
  __int64 v6; // x20
  char v7; // w9
  int v8; // w6
  unsigned int v9; // w19
  void *v10; // x0
  unsigned int v11; // w19

  v2 = *(_QWORD *)(a1 + 1704);
  if ( !v2 )
  {
    v10 = &unk_22E5DE;
    goto LABEL_18;
  }
  v3 = *(_QWORD *)(v2 + 256);
  if ( !v3 )
  {
    v10 = &unk_24CCB9;
    goto LABEL_18;
  }
  if ( !a2 || !*(_QWORD *)v3 || (v4 = *(__int64 (**)(void))(*(_QWORD *)v3 + 88LL)) == nullptr )
  {
    v10 = &unk_219C2B;
LABEL_18:
    printk(v10, "_sde_kms_splash_mem_get");
    return 4294967274LL;
  }
  if ( *(_DWORD *)(a2 + 32) )
  {
    result = 0;
  }
  else
  {
    v6 = a2;
    if ( *((_DWORD *)v4 - 1) != 1814495457 )
      __break(0x8228u);
    result = v4();
    if ( (_DWORD)result )
    {
      v11 = result;
      printk(&unk_27DBE3, "_sde_kms_splash_mem_get");
      result = v11;
    }
    a2 = v6;
  }
  v7 = _drm_debug;
  v8 = *(_DWORD *)(a2 + 32) + 1;
  *(_DWORD *)(a2 + 32) = v8;
  if ( (v7 & 4) != 0 )
  {
    v9 = result;
    _drm_dev_dbg(
      0,
      0,
      0,
      "one2one mapping done for base:%lx size:%u ref_cnt:%d\n",
      *(_QWORD *)(a2 + 8),
      *(_DWORD *)a2,
      v8);
    return v9;
  }
  return result;
}
