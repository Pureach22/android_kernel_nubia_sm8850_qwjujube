__int64 __fastcall msm_vidc_remove_dangling_session(__int64 a1)
{
  __int64 v1; // x20
  __int64 *v3; // x21
  __int64 *v4; // x8
  __int64 *v5; // x22
  int v6; // w10
  __int64 *v7; // x9
  __int64 **v8; // x10
  __int64 v9; // x4
  _QWORD *v10; // x9
  int v11; // w5

  v1 = *(_QWORD *)(a1 + 320);
  mutex_lock(v1 + 3856);
  v3 = (__int64 *)(v1 + 3544);
  v4 = *(__int64 **)(v1 + 3544);
  v5 = (__int64 *)(v1 + 3544);
  while ( v4 != v3 )
  {
    v6 = *((_DWORD *)v4 + 83);
    v7 = v4;
    v4 = (__int64 *)*v4;
    if ( v6 == *(_DWORD *)(a1 + 332) )
    {
      v8 = (__int64 **)v7[1];
      if ( *v8 == v7 && (__int64 *)v4[1] == v7 )
      {
        v4[1] = (__int64)v8;
        *v8 = v4;
      }
      else
      {
        _list_del_entry_valid_or_report(v7);
      }
      *v7 = (__int64)v7;
      v7[1] = (__int64)v7;
      if ( a1 && (msm_vidc_debug & 2) != 0 )
        printk(&unk_96DE4, "high", a1 + 340, "msm_vidc_remove_dangling_session", *((unsigned int *)v7 + 83));
      break;
    }
  }
  LODWORD(v9) = -1;
  v10 = (_QWORD *)(v1 + 3528);
  do
  {
    v10 = (_QWORD *)*v10;
    v9 = (unsigned int)(v9 + 1);
  }
  while ( v10 != (_QWORD *)(v1 + 3528) );
  v11 = -1;
  do
  {
    v5 = (__int64 *)*v5;
    ++v11;
  }
  while ( v5 != v3 );
  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_93C20, "high", a1 + 340, "msm_vidc_remove_dangling_session", v9);
  mutex_unlock(v1 + 3856);
  return 0;
}
