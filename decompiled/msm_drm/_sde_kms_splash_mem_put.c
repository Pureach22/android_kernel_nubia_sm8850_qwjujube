__int64 __fastcall sde_kms_splash_mem_put(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v4; // x8
  unsigned int v5; // w8
  unsigned int v6; // w5
  char v8; // w9
  unsigned int *v9; // x21
  __int64 v10; // x2
  unsigned int *v11; // x21
  void (__fastcall *v12)(__int64, __int64, __int64); // x9
  __int64 v13; // x1
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 1704);
  if ( !v2 || (v3 = *(_QWORD *)(v2 + 256)) == 0 || (v4 = *(_QWORD *)(a1 + 136)) == 0 || !*(_QWORD *)(v4 + 64) )
  {
    printk(&unk_223EAA, "_sde_kms_splash_mem_put");
    return 4294967274LL;
  }
  if ( !a2 )
    return 4294967274LL;
  v5 = a2[8];
  if ( !v5 || !*(_QWORD *)v3 || !*(_QWORD *)(*(_QWORD *)v3 + 96LL) )
    return 4294967274LL;
  v6 = v5 - 1;
  v8 = _drm_debug;
  a2[8] = v5 - 1;
  if ( (v8 & 4) != 0 )
  {
    v9 = a2;
    _drm_dev_dbg(0, 0, 0, "splash base:%lx refcnt:%d\n", *((_QWORD *)a2 + 1), v6);
    v6 = v9[8];
    a2 = v9;
  }
  if ( v6 )
    return 0;
  v10 = *a2;
  v11 = a2;
  v12 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)v3 + 96LL);
  v13 = *((_QWORD *)a2 + 1);
  if ( *((_DWORD *)v12 - 1) != 921090776 )
    __break(0x8229u);
  v12(v3, v13, v10);
  if ( **(_DWORD **)(*(_QWORD *)(a1 + 136) + 64LL) )
    return 0;
  result = sde_kms_release_shared_buffer(*((_QWORD *)v11 + 1), *v11, v11[6], v11[4]);
  *((_QWORD *)v11 + 1) = 0;
  *v11 = 0;
  return result;
}
