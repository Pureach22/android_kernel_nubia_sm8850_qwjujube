__int64 __fastcall msm_vidc_remove_session(__int64 a1)
{
  __int64 v1; // x24
  __int64 *v3; // x27
  __int64 *v4; // x26
  __int64 *v5; // x22
  int v6; // w8
  __int64 *v7; // x9
  __int64 **v8; // x8
  __int64 **v9; // x1
  __int64 v10; // x4
  __int64 *v11; // x8

  v1 = *(_QWORD *)(a1 + 320);
  mutex_lock(v1 + 3856);
  v3 = *(__int64 **)(v1 + 3528);
  v4 = (__int64 *)(v1 + 3528);
  if ( v3 != (__int64 *)(v1 + 3528) )
  {
    v5 = (__int64 *)(v1 + 3544);
    do
    {
      v6 = *((_DWORD *)v3 + 83);
      v7 = v3;
      v3 = (__int64 *)*v3;
      if ( v6 == *(_DWORD *)(a1 + 332) )
      {
        v8 = (__int64 **)v7[1];
        if ( *v8 == v7 && (__int64 *)v3[1] == v7 )
        {
          v3[1] = (__int64)v8;
          *v8 = v3;
        }
        else
        {
          _list_del_entry_valid_or_report(v7);
        }
        v9 = *(__int64 ***)(v1 + 3552);
        if ( v7 == v5 || v9 == (__int64 **)v7 || *v9 != v5 )
        {
          _list_add_valid_or_report(v7);
          if ( a1 )
          {
LABEL_12:
            if ( (msm_vidc_debug & 2) != 0 )
              printk(&unk_93036, "high", a1 + 340, "msm_vidc_remove_session", *((unsigned int *)v7 + 83));
          }
        }
        else
        {
          *(_QWORD *)(v1 + 3552) = v7;
          *v7 = (__int64)v5;
          v7[1] = (__int64)v9;
          *v9 = v7;
          if ( a1 )
            goto LABEL_12;
        }
      }
    }
    while ( v3 != v4 );
  }
  LODWORD(v10) = -1;
  v11 = (__int64 *)(v1 + 3528);
  do
  {
    v11 = (__int64 *)*v11;
    v10 = (unsigned int)(v10 + 1);
  }
  while ( v11 != v4 );
  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_94969, "high", a1 + 340, "msm_vidc_remove_session", v10);
  mutex_unlock(v1 + 3856);
  return 0;
}
