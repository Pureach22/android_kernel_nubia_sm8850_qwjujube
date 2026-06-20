__int64 __fastcall msm_vidc_check_max_sessions(__int64 a1)
{
  _QWORD *v1; // x23
  __int64 *v3; // x8
  unsigned int v4; // w15
  unsigned int v5; // w16
  unsigned int v6; // w20
  unsigned int v7; // w21
  unsigned int v8; // w22
  int v9; // w17
  __int64 v10; // x15
  __int64 v11; // x16
  unsigned int v12; // w17
  void *v15; // x0
  __int64 v16; // x2
  __int64 v17; // x4

  v1 = *(_QWORD **)(a1 + 320);
  mutex_lock(v1 + 482);
  v3 = (__int64 *)v1[441];
  if ( v3 != v1 + 441 )
  {
    v4 = 0;
    v5 = 0;
    v6 = 0;
    v7 = 0;
    v8 = 0;
    while ( *((_DWORD *)v3 + 78) == 8 )
    {
LABEL_4:
      v3 = (__int64 *)*v3;
      if ( v3 == v1 + 441 )
        goto LABEL_28;
    }
    v9 = *((_DWORD *)v3 + 77);
    if ( v9 == 2 )
    {
      v10 = 49;
      v11 = 396;
    }
    else
    {
      if ( v9 != 1 )
      {
LABEL_11:
        if ( v5 > 0x1800 || v4 > 0x1800 || (v12 = ((v4 + 15) >> 4) * ((v5 + 15) >> 4), v12 >= 0x13201) )
        {
          ++v8;
          v7 += 2;
          v6 += 4;
        }
        else if ( v5 > 0xB40 || v4 > 0xB40 || v12 >= 0x47B9 )
        {
          ++v7;
          v6 += 2;
        }
        else if ( v4 > 0x780 || v12 > 0x2058 || v5 > 0x780 )
        {
          ++v6;
        }
        goto LABEL_4;
      }
      v10 = 236;
      v11 = 1892;
    }
    v4 = v3[v10];
    v5 = *(_DWORD *)((char *)v3 + v11);
    goto LABEL_11;
  }
  v8 = 0;
  v7 = 0;
  v6 = 0;
LABEL_28:
  mutex_unlock(v1 + 482);
  if ( v1[508] < (__int64)v8 )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967284LL;
    v15 = &unk_82328;
    v16 = a1 + 340;
    v17 = v8;
    goto LABEL_40;
  }
  if ( v1[506] < (__int64)v7 )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967284LL;
    v15 = &unk_925DE;
    v16 = a1 + 340;
    v17 = v7;
    goto LABEL_40;
  }
  if ( v1[504] >= (__int64)v6 )
    return 0;
  if ( a1 && (msm_vidc_debug & 1) != 0 )
  {
    v15 = &unk_82370;
    v16 = a1 + 340;
    v17 = v6;
LABEL_40:
    printk(v15, "err ", v16, "msm_vidc_check_max_sessions", v17);
  }
  return 4294967284LL;
}
