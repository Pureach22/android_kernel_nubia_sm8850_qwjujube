__int64 __fastcall qce_sps_release_bam(__int64 a1)
{
  __int64 *v2; // x20
  int v3; // w8
  __int64 **v4; // x8
  __int64 *v5; // x9

  mutex_lock(&bam_register_lock);
  v2 = *(__int64 **)(a1 + 8);
  if ( v2 )
  {
    v3 = *((_DWORD *)v2 + 6) - 1;
    *((_DWORD *)v2 + 6) = v3;
    if ( !v3 )
    {
      if ( *(_QWORD *)(a1 + 392) )
      {
        sps_deregister_bam_device();
        *(_QWORD *)(a1 + 392) = 0;
      }
      iounmap(v2[4]);
      v4 = (__int64 **)v2[1];
      if ( *v4 == v2 && (v5 = (__int64 *)*v2, *(__int64 **)(*v2 + 8) == v2) )
      {
        v5[1] = (__int64)v4;
        *v4 = v5;
      }
      else
      {
        _list_del_entry_valid_or_report(v2);
      }
      *v2 = 0xDEAD000000000100LL;
      v2[1] = 0xDEAD000000000122LL;
      kfree(v2);
    }
  }
  *(_QWORD *)(a1 + 8) = 0;
  return mutex_unlock(&bam_register_lock);
}
