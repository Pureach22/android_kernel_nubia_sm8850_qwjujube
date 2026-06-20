_DWORD *__fastcall synx_util_log_error(_DWORD *result, int a2, int a3)
{
  int v5; // w22
  _DWORD *v6; // x19
  __int64 v7; // x8
  _QWORD *v8; // x0
  _QWORD *v9; // x2
  _QWORD *v10; // x1
  __int64 v11; // [xsp+0h] [xbp-40h] BYREF
  __int64 v12; // [xsp+8h] [xbp-38h]
  __int64 v13; // [xsp+10h] [xbp-30h]
  __int64 v14; // [xsp+18h] [xbp-28h]
  __int64 v15; // [xsp+20h] [xbp-20h]
  _QWORD v16[3]; // [xsp+28h] [xbp-18h] BYREF

  v16[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(synx_dev + 328) )
  {
    v5 = (int)result;
    result = (_DWORD *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 72);
    v6 = result;
    if ( result )
    {
      result[11] = a2;
      result[12] = a3;
      result[10] = v5;
      v16[0] = 0;
      v16[1] = 0;
      v14 = 0;
      v15 = 0;
      v12 = 0;
      v13 = 0;
      v11 = 0;
      ktime_get_real_ts64(v16);
      time64_to_tm(v16[0], 0, &v11);
      snprintf((char *)v6, 0x20u, "%02d-%02d %02d:%02d:%02d", v13 + 1, HIDWORD(v12), v12, HIDWORD(v11), v11);
      mutex_lock(synx_dev + 352);
      v7 = synx_dev;
      v8 = v6 + 14;
      v9 = *(_QWORD **)(synx_dev + 336);
      v10 = (_QWORD *)(synx_dev + 336);
      if ( v9[1] != synx_dev + 336 || v8 == v10 || v9 == v8 )
      {
        _list_add_valid_or_report(v8, v10);
        v7 = synx_dev;
      }
      else
      {
        v9[1] = v8;
        *((_QWORD *)v6 + 7) = v9;
        *((_QWORD *)v6 + 8) = v10;
        *v10 = v8;
      }
      result = (_DWORD *)mutex_unlock(v7 + 352);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
