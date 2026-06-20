__int64 __fastcall pdm_notify_prepare(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 v4; // x8
  int v5; // w9
  unsigned int v6; // w0
  unsigned int v7; // w19
  __int64 result; // x0
  unsigned int v9; // w19

  v2 = _kmalloc_cache_noprof(timer_delete_sync, 3520, 1000);
  v3 = v2;
  if ( !v2 )
    return 4294967284LL;
  v4 = *(_QWORD *)(a1 + 48);
  *(_QWORD *)(v2 + 808) = pdm_dev_release;
  *(_QWORD *)(v2 + 912) = "pd-mapper";
  v5 = *(_DWORD *)(a1 + 56);
  *(_QWORD *)(v2 + 96) = v4;
  *(_DWORD *)(v2 + 920) = v5;
  v6 = auxiliary_device_init(v2);
  if ( v6 )
  {
    v7 = v6;
    kfree(v3);
    return v7;
  }
  else
  {
    result = _auxiliary_device_add(v3, "rproc_qcom_common");
    if ( (_DWORD)result )
    {
      v9 = result;
      put_device(v3);
      return v9;
    }
    else
    {
      *(_QWORD *)(a1 + 64) = v3;
    }
  }
  return result;
}
