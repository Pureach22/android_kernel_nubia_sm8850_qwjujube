__int64 __fastcall release_runtime_env(__int64 a1)
{
  __int64 v2; // x0
  int v3; // w8
  int v4; // w3
  __int64 v5; // x20

  v2 = mutex_lock(a1 + 456);
  v3 = *(_DWORD *)(a1 + 512);
  if ( !v3 || (v4 = v3 - 1, *(_DWORD *)(a1 + 512) = v3 - 1, v3 == 1) )
  {
    v5 = *(_QWORD *)(a1 + 8);
    *(_QWORD *)(v5 + 520) = ktime_get_mono_fast_ns(v2);
    _pm_runtime_suspend(*(_QWORD *)(a1 + 8), 13);
    pm_relax(*(_QWORD *)(a1 + 8));
  }
  else if ( v4 < 0 )
  {
    dev_err(*(_QWORD *)(a1 + 8), "%s: priv->runtime_env_counter %d underrun\n", "release_runtime_env", v4);
    *(_DWORD *)(a1 + 512) = 0;
  }
  return mutex_unlock(a1 + 456);
}
