__int64 __fastcall get_avail_buffer(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x20
  void *v5; // x0

  if ( a1 )
  {
    mutex_lock(a1 + 368);
    v2 = *(_QWORD *)(a1 + 352) + 48LL;
    while ( 1 )
    {
      v2 = *(_QWORD *)v2;
      if ( v2 == *(_QWORD *)(a1 + 352) + 48LL )
      {
        mutex_unlock(a1 + 368);
        v5 = &unk_25E0DA;
        goto LABEL_10;
      }
      v3 = v2 - 48;
      if ( v2 == 48 )
        break;
      if ( *(_DWORD *)(v2 + 16) )
      {
        *(_DWORD *)(v2 + 16) = 0;
        mutex_unlock(a1 + 368);
        return v3;
      }
    }
    mutex_unlock(a1 + 368);
    printk(&unk_220526, "get_avail_buffer");
  }
  else
  {
    v5 = &unk_245CB0;
LABEL_10:
    printk(v5, "get_avail_buffer");
    return 0;
  }
  return v3;
}
