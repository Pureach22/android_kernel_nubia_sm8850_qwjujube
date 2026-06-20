__int64 __fastcall cnss_plat_ipc_init_file_data(__int64 a1, __int64 a2, int a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 v9; // x19
  unsigned int v10; // w8

  v8 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3264, 72);
  v9 = v8;
  if ( v8 )
  {
    *(_QWORD *)v8 = a1;
    *(_QWORD *)(v8 + 8) = a2;
    *(_DWORD *)(v8 + 20) = a3;
    *(_DWORD *)(v8 + 24) = a4;
    *(_DWORD *)(v8 + 28) = 0;
    *(_DWORD *)(v8 + 36) = 0;
    if ( a4 )
    {
      v10 = a4 / 0xF000;
      if ( a4 % 0xF000 )
        ++v10;
    }
    else
    {
      v10 = 0;
    }
    *(_DWORD *)(v8 + 32) = v10;
    *(_DWORD *)(v8 + 40) = 0;
    _init_swait_queue_head(v8 + 48, "&x->wait", &init_completion___key);
    mutex_lock(&unk_7D78);
    *(_DWORD *)(v9 + 16) = idr_alloc_cyclic(&qword_7D60, v9, 0, 0xFFFFFFFFLL, 3264);
    mutex_unlock(&unk_7D78);
  }
  return v9;
}
