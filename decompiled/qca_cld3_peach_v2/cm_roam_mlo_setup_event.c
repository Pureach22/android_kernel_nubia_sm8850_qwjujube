__int64 __fastcall cm_roam_mlo_setup_event(__int64 a1, __int64 a2, _BYTE *a3)
{
  void *v5; // x0
  unsigned __int64 time_of_the_day_us; // x0
  unsigned __int64 v7; // x8
  __int64 v8; // x23
  unsigned __int64 v9; // x24
  _QWORD *v10; // x25
  unsigned __int64 v11; // x26
  unsigned int v12; // w9
  char *v13; // x28
  char v14; // w10
  char v15; // w8
  unsigned int v16; // w8
  char v17; // w8
  char *v18; // x9
  __int64 v19; // x8
  int v20; // w11
  __int64 v21; // x10
  __int64 result; // x0
  __int64 v23; // [xsp+8h] [xbp-88h] BYREF
  unsigned __int64 v24; // [xsp+10h] [xbp-80h]
  __int64 v25; // [xsp+18h] [xbp-78h]
  __int64 v26; // [xsp+20h] [xbp-70h]
  _QWORD v27[5]; // [xsp+28h] [xbp-68h] BYREF
  __int64 v28; // [xsp+50h] [xbp-40h]
  __int64 v29; // [xsp+58h] [xbp-38h]
  __int64 v30; // [xsp+60h] [xbp-30h]
  __int64 v31; // [xsp+68h] [xbp-28h]
  __int64 v32; // [xsp+70h] [xbp-20h]
  __int64 v33; // [xsp+78h] [xbp-18h]
  int v34; // [xsp+80h] [xbp-10h]
  _BYTE v35[4]; // [xsp+84h] [xbp-Ch]
  __int64 v36; // [xsp+88h] [xbp-8h] BYREF

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  memset(v27, 0, sizeof(v27));
  v24 = 0;
  v25 = 0;
  v23 = 0;
  if ( (mlo_is_mld_sta(a1) & 1) != 0 && *a3 == 1 )
  {
    v5 = qdf_mem_set(&v23, 0x7Cu, 0);
    v26 = ktime_get(v5) / 1000;
    time_of_the_day_us = qdf_get_time_of_the_day_us();
    LODWORD(v7) = (unsigned __int8)a3[1];
    v24 = time_of_the_day_us;
    LOBYTE(v27[0]) = 3;
    if ( (_DWORD)v7 )
    {
      v8 = 0;
      v9 = 0;
      v10 = a3 + 24;
      v11 = -48;
      while ( 1 )
      {
        if ( !v11 )
          goto LABEL_22;
        v12 = *((_DWORD *)v10 - 2);
        v13 = (char *)&v23 + v8;
        v14 = *(_BYTE *)(a1 + 168);
        *((_BYTE *)v27 + v8 + 5) = *((_BYTE *)v10 - 10);
        v15 = v12 < 3 ? v12 + 1 : 0;
        v13[38] = v14;
        v13[36] = v15;
        qdf_mem_copy((char *)&v27[1] + v8 + 2, v10 - 2, 6u);
        v13[41] = *((_BYTE *)v10 - 9) ^ 1;
        if ( v11 < 0xFFFFFFFFFFFFFF83LL )
          break;
        v35[v11 + 1] = *((_BYTE *)v10 - 10);
        if ( v11 + 1 < 0xFFFFFFFFFFFFFF83LL )
          break;
        v35[v11 + 2] = *(_BYTE *)(a1 + 168);
        qdf_mem_copy((char *)&v36 + v11 + 2, v10 - 2, 6u);
        v16 = *((_DWORD *)v10 - 2);
        v17 = v16 < 3 ? v16 + 1 : 0;
        v35[v11] = v17;
        if ( v11 + 4 < 0xFFFFFFFFFFFFFF83LL )
          break;
        v18 = (char *)&v23 + v11;
        *((_BYTE *)&v36 + v11 + 1) = *((_BYTE *)v10 - 9) ^ 1;
        if ( v11 + 11 < 0xFFFFFFFFFFFFFF83LL )
          break;
        v19 = *v10;
        v20 = *((_DWORD *)v10 - 1);
        ++v9;
        v11 += 16LL;
        v8 += 12;
        v10 += 3;
        v21 = 1000 * v19;
        v7 = (unsigned __int8)a3[1];
        *((_DWORD *)v18 + 34) = v20;
        v25 = v21;
        if ( v9 >= v7 )
          goto LABEL_18;
      }
      __break(1u);
LABEL_22:
      __break(0x5512u);
    }
LABEL_18:
    BYTE1(v27[0]) = v7;
    BYTE2(v27[0]) = v7;
    LODWORD(v28) = 16;
    host_diag_event_report_payload(3415, 124, &v23);
    result = 0;
  }
  else
  {
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
