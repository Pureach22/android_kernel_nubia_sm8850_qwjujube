__int64 __fastcall cfg80211_cqm_rssi_update(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 v3; // x8
  unsigned __int64 v4; // x12
  int v5; // w9
  int v6; // w11
  unsigned int v11; // w8
  __int64 v12; // x3
  __int64 v13; // x22
  _DWORD *v14; // x21
  __int64 v15; // x19
  __int64 v16; // x20
  __int64 result; // x0
  _QWORD v18[34]; // [xsp+0h] [xbp-110h] BYREF

  v18[33] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v3) = a3[5];
  if ( (_DWORD)v3 )
    goto LABEL_2;
  v13 = *(_QWORD *)(*(_QWORD *)(a2 + 992) + 400LL);
  if ( !v13 )
  {
    LODWORD(v3) = 0;
    goto LABEL_2;
  }
  v3 = *(_QWORD *)(*(_QWORD *)a1 + 160LL);
  if ( !v3 )
    goto LABEL_2;
  v14 = a3;
  v15 = a1;
  v16 = a2;
  memset(v18, 0, 0x108u);
  result = rdev_get_station(v15, v16, v13 + 184, v18);
  if ( !(_DWORD)result )
  {
    kfree(v18[25]);
    if ( (v18[0] & 0x40000000LL) != 0 )
    {
      LODWORD(v3) = SLOBYTE(v18[24]);
      a3 = v14;
      v14[5] = SLOBYTE(v18[24]);
    }
    else
    {
      LODWORD(v3) = v14[5];
      a3 = v14;
    }
    a2 = v16;
    a1 = v15;
LABEL_2:
    v4 = (unsigned int)a3[8];
    v5 = a3[4];
    if ( (int)v4 < 1 )
    {
      v6 = 0;
    }
    else
    {
      v6 = 0;
      do
      {
        __asm { HINT            #0x14 }
        v6 &= -(v6 + (v6 < v4));
        if ( (int)v3 < a3[v6 + 9] )
          break;
        ++v6;
      }
      while ( v6 < (int)v4 );
      if ( v6 - 1 >= 0 )
      {
        __asm { HINT            #0x14 }
        v11 = a3[((v6 - 1) & -((_DWORD)v4 + ((unsigned int)(v6 - 1) < v4))) + 9] - v5;
        if ( v6 >= (int)v4 )
        {
LABEL_8:
          v12 = 0x7FFFFFFF;
LABEL_17:
          result = rdev_set_cqm_rssi_range_config(a1, a2, v11, v12);
          goto LABEL_18;
        }
LABEL_16:
        __asm { HINT            #0x14 }
        v12 = (unsigned int)(v5 + a3[(v6 & -((_DWORD)v4 + (v6 < (unsigned __int64)(int)v4))) + 9] - 1);
        goto LABEL_17;
      }
    }
    v11 = 0x80000000;
    if ( v6 >= (int)v4 )
      goto LABEL_8;
    goto LABEL_16;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
