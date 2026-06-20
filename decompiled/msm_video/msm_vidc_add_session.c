__int64 __fastcall msm_vidc_add_session(_QWORD *a1)
{
  __int64 v1; // x21
  __int64 v3; // x0
  _QWORD *v4; // x8
  _QWORD *v5; // x2
  unsigned int v6; // w5
  __int64 v7; // x10
  unsigned int v8; // w20
  __int64 v9; // x4
  _QWORD *v10; // x1
  __int64 v12; // x0

  v1 = a1[40];
  mutex_lock(v1 + 3856);
  v3 = *(unsigned int *)(v1 + 3704);
  if ( (_DWORD)v3 == 2 )
  {
    v4 = *(_QWORD **)(v1 + 3528);
    v5 = (_QWORD *)(v1 + 3528);
    if ( v4 == (_QWORD *)(v1 + 3528) )
    {
      v6 = 0;
    }
    else
    {
      v6 = 0;
      do
      {
        v7 = v4[4492];
        v4 = (_QWORD *)*v4;
        if ( v7 )
          v6 += 3;
        else
          ++v6;
      }
      while ( v4 != v5 );
    }
    v9 = *(_QWORD *)(v1 + 4000);
    if ( v9 <= v6 )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_85AA4, "err ", (char *)a1 + 340, "msm_vidc_add_session", v9);
      v8 = -11;
    }
    else
    {
      v10 = *(_QWORD **)(v1 + 3536);
      if ( v5 == a1 || v10 == a1 || (_QWORD *)*v10 != v5 )
      {
        _list_add_valid_or_report(a1);
        v8 = 0;
      }
      else
      {
        v8 = 0;
        *(_QWORD *)(v1 + 3536) = a1;
        *a1 = v5;
        a1[1] = v10;
        *v10 = a1;
      }
    }
  }
  else
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      v12 = core_state_name(v3);
      printk(&unk_8A773, "err ", (char *)a1 + 340, "msm_vidc_add_session", v12);
    }
    v8 = -22;
  }
  mutex_unlock(v1 + 3856);
  return v8;
}
