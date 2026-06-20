__int64 __fastcall hdd_set_p2p_ps(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  unsigned int v11; // w9
  unsigned int v12; // w10
  int v13; // w9
  unsigned int v14; // w9
  __int64 result; // x0
  unsigned int v16[4]; // [xsp+4h] [xbp-2Ch] BYREF
  __int64 v17; // [xsp+14h] [xbp-1Ch]
  int v18; // [xsp+1Ch] [xbp-14h]
  int v19; // [xsp+20h] [xbp-10h]
  int v20; // [xsp+24h] [xbp-Ch]
  __int64 v21; // [xsp+28h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a2 + 12);
  v11 = *((_DWORD *)a2 + 1);
  v12 = a2[8];
  v20 = 0;
  v17 = v10;
  LODWORD(v10) = *((_DWORD *)a2 + 5);
  v16[2] = v11;
  v16[3] = v12;
  v13 = a2[24];
  v18 = v10;
  v19 = v13;
  v14 = *a2;
  v16[0] = *(unsigned __int8 *)(*(_QWORD *)(a1 + 55512) + 8LL);
  v16[1] = v14;
  result = wlan_hdd_set_power_save(a1 + 2688, v16, a3, a4, a5, a6, a7, a8, a9, a10);
  _ReadStatusReg(SP_EL0);
  return result;
}
