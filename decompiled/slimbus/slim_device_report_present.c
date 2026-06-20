__int64 __fastcall slim_device_report_present(__int64 *a1, __int64 a2, _BYTE *a3)
{
  int v6; // w0
  int v7; // w2
  unsigned __int64 child; // x0
  char v10; // w9
  unsigned int v11; // w20
  __int64 v12; // x8
  unsigned int v13; // w9
  unsigned int v20; // w11
  __int64 v21; // x21

  v6 = _pm_runtime_resume(*a1, 4);
  if ( v6 < 0 )
  {
    v11 = v6;
    dev_err(*a1, "slim %s: PM get_sync failed ret :%d\n", "slim_device_report_present", v6);
    v12 = *a1;
    v13 = *(_DWORD *)(*a1 + 480);
    do
    {
      if ( !v13 )
        break;
      _X13 = (unsigned int *)(v12 + 480);
      __asm { PRFM            #0x11, [X13] }
      while ( 1 )
      {
        v20 = __ldxr(_X13);
        if ( v20 != v13 )
          break;
        if ( !__stlxr(v13 - 1, _X13) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v20 == v13;
      v13 = v20;
    }
    while ( !_ZF );
    _pm_runtime_set_status(*a1, 2);
  }
  else
  {
    v7 = *((_DWORD *)a1 + 44);
    if ( v7 )
    {
      v11 = v6;
      dev_err(*a1, "slim ctrl not active,state:%d, ret:%d\n", v7, v6);
    }
    else
    {
      child = device_find_child(*a1, a2, slim_match_dev);
      if ( !child )
      {
        child = slim_alloc_device(a1, a2, 0);
        if ( !child )
          return 4294967277LL;
      }
      if ( child > 0xFFFFFFFFFFFFF000LL )
        return 4294967277LL;
      if ( *(_BYTE *)(child + 933) == 1 )
      {
        v10 = *(_BYTE *)(child + 932);
        *a3 = v10;
        return 0;
      }
      v11 = slim_device_alloc_laddr(child, 1);
    }
    v21 = *a1;
    *(_QWORD *)(v21 + 520) = ktime_get_mono_fast_ns();
    _pm_runtime_suspend(*a1, 13);
  }
  return v11;
}
