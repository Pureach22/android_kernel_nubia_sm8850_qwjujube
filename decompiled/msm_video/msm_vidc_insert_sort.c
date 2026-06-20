__int64 __fastcall msm_vidc_insert_sort(_QWORD *a1, _QWORD *a2)
{
  _QWORD *v2; // x2
  __int64 v3; // x8
  unsigned int v4; // w8
  _QWORD *v6; // x9
  _QWORD *v7; // x10
  _QWORD *v8; // x2
  _QWORD *v9; // x2
  _QWORD *v10; // x0

  if ( a1 )
  {
    v2 = (_QWORD *)*a1;
    if ( (_QWORD *)*a1 == a1 )
    {
      if ( (_QWORD *)v2[1] != a1 || a2 == a1 )
        goto LABEL_30;
    }
    else
    {
      v3 = a2[2];
      if ( v3 >= v2[2] )
      {
        v6 = nullptr;
        do
        {
          v7 = v6;
          v6 = v2;
          if ( v7 && v3 >= v7[2] && v3 <= v2[2] )
          {
            v8 = (_QWORD *)*v7;
            if ( *(_QWORD **)(*v7 + 8LL) == v7 && v7 != a2 && v8 != a2 )
            {
              v4 = 0;
              v8[1] = a2;
              *a2 = v8;
              a2[1] = v7;
              *v7 = a2;
              return v4;
            }
            v10 = a2;
            goto LABEL_31;
          }
          v2 = (_QWORD *)*v2;
        }
        while ( (_QWORD *)*v6 != a1 );
        if ( !v6 )
          return 0;
        v9 = (_QWORD *)*v6;
        if ( *(_QWORD **)(*v6 + 8LL) == v6 && v6 != a2 && v9 != a2 )
        {
          v4 = 0;
          v9[1] = a2;
          *a2 = v9;
          a2[1] = v6;
          *v6 = a2;
          return v4;
        }
        v10 = a2;
        goto LABEL_31;
      }
      if ( (_QWORD *)v2[1] != a1 || a2 == a1 || v2 == a2 )
      {
LABEL_30:
        v10 = a2;
LABEL_31:
        _list_add_valid_or_report(v10);
        return 0;
      }
    }
    v4 = 0;
    v2[1] = a2;
    *a2 = v2;
    a2[1] = a1;
    *a1 = a2;
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_insert_sort");
    return (unsigned int)-22;
  }
  return v4;
}
