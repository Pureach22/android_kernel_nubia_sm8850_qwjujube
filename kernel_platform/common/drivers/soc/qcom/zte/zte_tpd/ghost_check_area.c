__int64 __fastcall ghost_check_area(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w9
  int v4; // w12
  int v5; // w10
  int v6; // w13
  int v7; // w11
  int v8; // w10
  __int64 result; // x0
  int v10; // w12
  int v11; // w9
  void *v12; // x0
  int v13; // w8

  v3 = *(unsigned __int16 *)(a1 + 24);
  v4 = *(_DWORD *)(tpd_cdev + 16);
  if ( (v4 | 2) == 3 )
  {
    v5 = *(unsigned __int16 *)(a1 + 28);
    v6 = *(_DWORD *)(tpd_cdev + 1180);
    if ( v6 > v5
      || *(unsigned __int16 *)(tpd_cdev + 1092) - v6 < v5
      || v6 > v3
      || (v7 = *(unsigned __int16 *)(tpd_cdev + 1090), v7 - v6 < v3) )
    {
LABEL_21:
      v12 = unk_323DB;
LABEL_29:
      printk(v12, a2, a3);
      return 0;
    }
  }
  else
  {
    v8 = *(_DWORD *)(tpd_cdev + 1180);
    if ( v8 > v3 )
      goto LABEL_21;
    v7 = *(unsigned __int16 *)(tpd_cdev + 1090);
    if ( v7 - v8 < v3 )
      goto LABEL_21;
    v5 = *(unsigned __int16 *)(a1 + 28);
  }
  result = 1;
  if ( v4 > 1 )
  {
    if ( v4 != 2 )
    {
      if ( v4 != 3 )
        return result;
      goto LABEL_16;
    }
    if ( *(_DWORD *)(tpd_cdev + 1188) <= v5 )
      return result;
  }
  else
  {
    if ( v4 )
    {
      if ( v4 != 1 )
        return result;
LABEL_16:
      v10 = *(_DWORD *)(tpd_cdev + 1188);
      if ( v10 > v3 || v7 - v10 < v3 )
      {
        v11 = *(_DWORD *)(tpd_cdev + 1184);
        if ( v11 > v5 || *(unsigned __int16 *)(tpd_cdev + 1092) - v11 < v5 )
          goto LABEL_28;
      }
      return result;
    }
    if ( *(unsigned __int16 *)(tpd_cdev + 1092) - *(_DWORD *)(tpd_cdev + 1188) >= v5 )
      return result;
  }
  v13 = *(_DWORD *)(tpd_cdev + 1184);
  if ( v13 > v3 || v7 - v13 < v3 )
  {
LABEL_28:
    v12 = unk_3BD64;
    goto LABEL_29;
  }
  return result;
}
