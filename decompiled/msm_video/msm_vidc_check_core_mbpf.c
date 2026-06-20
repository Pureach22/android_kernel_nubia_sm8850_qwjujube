__int64 __fastcall msm_vidc_check_core_mbpf(__int64 a1)
{
  _QWORD *v1; // x22
  __int64 *v3; // x8
  __int64 *v4; // x23
  unsigned int v5; // w20
  unsigned int v6; // w10
  int v7; // w11
  int v8; // w10
  void *v9; // x0
  __int64 v10; // x2
  __int64 v11; // x4
  __int64 *v12; // x8
  unsigned int v13; // w21
  unsigned int v14; // w9
  int v15; // w10
  int v16; // w9
  unsigned int v17; // w9
  int v18; // w10
  __int64 *v19; // x8
  unsigned int v21; // w10
  int v22; // w11
  int v23; // w10

  v1 = *(_QWORD **)(a1 + 320);
  mutex_lock(v1 + 482);
  v3 = (__int64 *)v1[441];
  v4 = v1 + 441;
  if ( v3 == v1 + 441 )
  {
    v5 = 0;
  }
  else
  {
    v5 = 0;
    do
    {
      if ( v3[4219] )
      {
        v8 = *((_DWORD *)v3 + 77);
        if ( v8 == 1 )
        {
          v6 = *((_DWORD *)v3 + 472);
          v7 = *((_DWORD *)v3 + 473);
        }
        else if ( v8 == 2 )
        {
          v6 = *((_DWORD *)v3 + 98);
          if ( v6 <= *((_DWORD *)v3 + 472) )
            v6 = *((_DWORD *)v3 + 472);
          if ( *((_DWORD *)v3 + 99) <= *((_DWORD *)v3 + 473) )
            v7 = *((_DWORD *)v3 + 473);
          else
            v7 = *((_DWORD *)v3 + 99);
        }
        else
        {
          v6 = 0;
          v7 = 0;
        }
        v5 += ((v7 + 15) >> 4) * ((int)(v6 + 15) >> 4);
      }
      v3 = (__int64 *)*v3;
    }
    while ( v3 != v4 );
  }
  mutex_unlock(v1 + 482);
  if ( v1[516] < (__int64)v5 )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967284LL;
    v9 = &unk_8E5B8;
    goto LABEL_20;
  }
  mutex_lock(v1 + 482);
  v12 = (__int64 *)*v4;
  if ( (__int64 *)*v4 == v4 )
  {
    v5 = 0;
    v13 = 0;
  }
  else
  {
    v13 = 0;
    v5 = 0;
    do
    {
      if ( !v12[4072] )
      {
        v16 = *((_DWORD *)v12 + 77);
        if ( *((_DWORD *)v12 + 78) == 8 )
        {
          if ( v16 == 1 )
          {
            v17 = *((_DWORD *)v12 + 472);
            v18 = *((_DWORD *)v12 + 473);
          }
          else if ( v16 == 2 )
          {
            v17 = *((_DWORD *)v12 + 98);
            if ( v17 <= *((_DWORD *)v12 + 472) )
              v17 = *((_DWORD *)v12 + 472);
            if ( *((_DWORD *)v12 + 99) <= *((_DWORD *)v12 + 473) )
              v18 = *((_DWORD *)v12 + 473);
            else
              v18 = *((_DWORD *)v12 + 99);
          }
          else
          {
            v17 = 0;
            v18 = 0;
          }
          v5 += ((v18 + 15) >> 4) * ((int)(v17 + 15) >> 4);
        }
        else
        {
          if ( v16 == 1 )
          {
            v14 = *((_DWORD *)v12 + 472);
            v15 = *((_DWORD *)v12 + 473);
          }
          else if ( v16 == 2 )
          {
            v14 = *((_DWORD *)v12 + 98);
            if ( v14 <= *((_DWORD *)v12 + 472) )
              v14 = *((_DWORD *)v12 + 472);
            if ( *((_DWORD *)v12 + 99) <= *((_DWORD *)v12 + 473) )
              v15 = *((_DWORD *)v12 + 473);
            else
              v15 = *((_DWORD *)v12 + 99);
          }
          else
          {
            v14 = 0;
            v15 = 0;
          }
          v13 += ((v15 + 15) >> 4) * ((int)(v14 + 15) >> 4);
        }
      }
      v12 = (__int64 *)*v12;
    }
    while ( v12 != v4 );
  }
  mutex_unlock(v1 + 482);
  if ( v1[516] < (__int64)v13 )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967284LL;
    v9 = &unk_87627;
    v10 = a1 + 340;
    v11 = v13;
    goto LABEL_51;
  }
  if ( v1[520] < (__int64)v5 )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967284LL;
    v9 = &unk_924CD;
    goto LABEL_20;
  }
  mutex_lock(v1 + 482);
  v19 = (__int64 *)*v4;
  if ( (__int64 *)*v4 == v4 )
  {
    v5 = 0;
  }
  else
  {
    v5 = 0;
    do
    {
      if ( !v19[4177] && !v19[4072] && *((_DWORD *)v19 + 78) != 8 && *((_DWORD *)v19 + 40) != 5 )
      {
        v23 = *((_DWORD *)v19 + 77);
        if ( v23 == 1 )
        {
          v21 = *((_DWORD *)v19 + 472);
          v22 = *((_DWORD *)v19 + 473);
        }
        else if ( v23 == 2 )
        {
          v21 = *((_DWORD *)v19 + 98);
          if ( v21 <= *((_DWORD *)v19 + 472) )
            v21 = *((_DWORD *)v19 + 472);
          if ( *((_DWORD *)v19 + 99) <= *((_DWORD *)v19 + 473) )
            v22 = *((_DWORD *)v19 + 473);
          else
            v22 = *((_DWORD *)v19 + 99);
        }
        else
        {
          v21 = 0;
          v22 = 0;
        }
        v5 += ((v22 + 15) >> 4) * ((int)(v21 + 15) >> 4);
      }
      v19 = (__int64 *)*v19;
    }
    while ( v19 != v4 );
  }
  mutex_unlock(v1 + 482);
  if ( v1[514] < (__int64)v5 )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967284LL;
    v9 = &unk_9250C;
LABEL_20:
    v10 = a1 + 340;
    v11 = v5;
LABEL_51:
    printk(v9, "err ", v10, "msm_vidc_check_core_mbpf", v11);
    return 4294967284LL;
  }
  return 0;
}
