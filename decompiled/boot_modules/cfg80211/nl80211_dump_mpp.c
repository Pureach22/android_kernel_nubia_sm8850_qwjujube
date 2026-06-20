__int64 __fastcall nl80211_dump_mpp(__int64 a1, __int64 a2)
{
  unsigned int v4; // w21
  __int64 result; // x0
  __int64 v6; // x24
  __int64 v7; // x25
  __int64 v8; // x1
  _DWORD *v9; // x8
  unsigned int v10; // w0
  unsigned int v11; // w19
  __int64 v12; // [xsp+10h] [xbp-50h] BYREF
  __int64 v13; // [xsp+18h] [xbp-48h] BYREF
  _QWORD v14[4]; // [xsp+20h] [xbp-40h] BYREF
  int v15; // [xsp+40h] [xbp-20h]
  int v16; // [xsp+48h] [xbp-18h] BYREF
  __int16 v17; // [xsp+4Ch] [xbp-14h]
  int v18; // [xsp+50h] [xbp-10h] BYREF
  __int16 v19; // [xsp+54h] [xbp-Ch]
  __int64 v20; // [xsp+58h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a2 + 96);
  v15 = 0;
  memset(v14, 0, sizeof(v14));
  v12 = 0;
  v13 = 0;
  v19 = 0;
  v18 = 0;
  v17 = 0;
  v16 = 0;
  result = nl80211_prepare_wdev_dump(a2, &v13, &v12, 0);
  if ( !(_DWORD)result )
  {
    v6 = v13;
    if ( *(_QWORD *)(*(_QWORD *)v13 + 224LL) && (v7 = v12, *(_DWORD *)(v12 + 8) == 7) )
    {
      _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v8 = *(_QWORD *)(v7 + 32);
        v9 = *(_DWORD **)(*(_QWORD *)v6 + 224LL);
        if ( *(v9 - 1) != 1289374138 )
          __break(0x8228u);
        v10 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, int *, int *, _QWORD *))v9)(
                v6 + 992,
                v8,
                v4,
                &v18,
                &v16,
                v14);
        if ( v10 )
          break;
        v7 = v12;
        if ( (nl80211_send_mpath(
                a1,
                *(unsigned int *)(*(_QWORD *)a2 + 52LL),
                *(unsigned int *)(*(_QWORD *)(a2 + 8) + 8LL),
                2,
                *(_QWORD *)(v12 + 32),
                &v18,
                &v16,
                v14)
            & 0x80000000) != 0 )
          goto LABEL_12;
        v6 = v13;
        ++v4;
      }
      if ( v10 == -2 )
      {
LABEL_12:
        *(_QWORD *)(a2 + 96) = (int)v4;
        v11 = *(_DWORD *)(a1 + 112);
        goto LABEL_14;
      }
      v11 = v10;
    }
    else
    {
      v11 = -95;
    }
LABEL_14:
    mutex_unlock(v13 + 992);
    result = v11;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
