__int64 __fastcall stm_unregister_device(_QWORD *a1)
{
  __int64 v1; // x20
  _QWORD *v3; // x8
  _QWORD *v4; // x22
  __int64 v5; // x8
  unsigned int v6; // w21
  __int64 result; // x0
  __int64 v8; // x22
  unsigned int v9; // w9
  unsigned int v10; // w9
  __int64 v11; // x0

  v1 = a1[1];
  _pm_runtime_use_autosuspend(v1, 0);
  _pm_runtime_disable(v1, 1);
  mutex_lock(v1 + 992);
  v3 = *(_QWORD **)(v1 + 1048);
  if ( v3 != (_QWORD *)(v1 + 1048) )
  {
    do
    {
      v4 = (_QWORD *)*v3;
      if ( (unsigned int)_stm_source_link_drop(v3 - 117, v1) )
        __break(0x800u);
      v3 = v4;
    }
    while ( v4 != (_QWORD *)(v1 + 1048) );
  }
  mutex_unlock(v1 + 992);
  synchronize_srcu(&stm_source_srcu);
  _unregister_chrdev(*(unsigned int *)(v1 + 976), 0, 256, *a1);
  mutex_lock(v1 + 928);
  if ( *(_QWORD *)(v1 + 920) )
    stp_policy_unbind();
  mutex_unlock(v1 + 928);
  v5 = *(_QWORD *)(v1 + 984);
  v6 = *(_DWORD *)(v5 + 16);
  if ( v6 <= *(_DWORD *)(v5 + 20) )
  {
    v8 = v1 + 1088;
    do
    {
      v9 = *(_DWORD *)(v5 + 16);
      if ( v9 <= v6 )
      {
        v10 = v6 - v9;
        v11 = *(_QWORD *)(v8 + 8LL * v10);
        if ( v11 )
        {
          *(_QWORD *)(v8 + 8LL * v10) = 0;
          kfree(v11);
          v5 = *(_QWORD *)(v1 + 984);
        }
      }
      ++v6;
    }
    while ( v6 <= *(_DWORD *)(v5 + 20) );
  }
  result = device_unregister(v1);
  a1[1] = 0;
  return result;
}
