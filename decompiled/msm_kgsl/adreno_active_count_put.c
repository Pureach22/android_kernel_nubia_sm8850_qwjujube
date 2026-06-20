__int64 __fastcall adreno_active_count_put(__int64 result)
{
  __int64 v1; // x19
  void (*v2)(void); // x8
  __int64 v3; // x21
  unsigned int v10; // w8
  unsigned int v11; // w8

  if ( *(_QWORD *)(result + 11112) )
  {
    v1 = result;
    if ( *(_DWORD *)(result + 11128) )
    {
      _X9 = (unsigned int *)(result + 11128);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v10 = __ldxr(_X9);
        v11 = v10 - 1;
      }
      while ( __stlxr(v11, _X9) );
      __dmb(0xBu);
      if ( !v11 )
      {
        if ( (*(_BYTE *)(result + 14232) & 1) == 0 )
        {
          v2 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(result + 14264) + 40LL) + 296LL);
          if ( *((_DWORD *)v2 - 1) != 994519391 )
            __break(0x8228u);
          v2();
        }
        kgsl_pwrscale_update_stats(v1);
        kgsl_pwrscale_update(v1);
        v3 = jiffies;
        *(_QWORD *)(v1 + 14144) = _msecs_to_jiffies(*(_QWORD *)(v1 + 10080)) + v3;
        mod_timer(v1 + 8792);
      }
      return _wake_up(v1 + 11144, 3, 1, 0);
    }
    else
    {
      result = _warn_printk("Unbalanced get/put calls to KGSL active count\n");
      __break(0x800u);
    }
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
