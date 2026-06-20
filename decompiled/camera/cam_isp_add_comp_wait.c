__int64 __fastcall cam_isp_add_comp_wait(__int64 a1, _QWORD *a2, unsigned int a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned int v6; // w8
  unsigned int v7; // w9
  _QWORD *v8; // x9
  __int64 v9; // x8
  unsigned int v10; // w7
  unsigned int v11; // w9
  __int64 v12; // x10
  __int64 v13; // x12
  _DWORD *v15; // x11
  __int64 v16; // x0
  unsigned int v18; // w0
  unsigned int v19; // w19
  __int64 result; // x0
  const char *v21; // x5
  __int64 v22; // x4
  int v23; // w8
  __int64 v24; // x9
  __int64 v25; // x10
  __int64 v26; // x11
  int v27; // w12
  int v28; // w8
  int v29; // [xsp+14h] [xbp-4Ch]
  int v30; // [xsp+18h] [xbp-48h]
  __int64 v31; // [xsp+20h] [xbp-40h] BYREF
  __int64 v32; // [xsp+28h] [xbp-38h]
  __int64 v33; // [xsp+30h] [xbp-30h]
  __int64 v34; // [xsp+38h] [xbp-28h]
  __int64 v35; // [xsp+40h] [xbp-20h]
  __int64 v36; // [xsp+48h] [xbp-18h]
  __int64 v37; // [xsp+50h] [xbp-10h]
  __int64 v38; // [xsp+58h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_DWORD *)(a1 + 40);
  v7 = *(_DWORD *)(a1 + 24);
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  if ( v6 >= v7 )
  {
    v21 = "Insufficient  HW entries";
    v22 = 1491;
LABEL_16:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_add_comp_wait",
      v22,
      v21);
LABEL_17:
    result = 4294967274LL;
    goto LABEL_18;
  }
  v8 = (_QWORD *)*a2;
  if ( (_QWORD *)*a2 == a2 )
    goto LABEL_15;
  while ( 1 )
  {
    if ( *((_DWORD *)v8 + 4) )
    {
      v9 = v8[4];
      if ( v9 )
      {
        if ( v8[5] )
          break;
      }
    }
    v8 = (_QWORD *)*v8;
    if ( v8 == a2 )
      goto LABEL_15;
  }
  if ( !v8 )
  {
LABEL_15:
    v21 = "No src with multi_vfe config";
    v22 = 1507;
    goto LABEL_16;
  }
  v10 = *(_DWORD *)(a4 + 20);
  v11 = *(_DWORD *)(a4 + 24);
  if ( v10 <= v11 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_add_comp_wait",
      1521,
      "no free mem %d %d %d",
      a3);
    goto LABEL_17;
  }
  v12 = *(_QWORD *)(v9 + 16);
  v13 = *(_QWORD *)(a4 + 8);
  LODWORD(v34) = v10 - v11;
  v15 = *(_DWORD **)(v12 + 88);
  v16 = *(_QWORD *)(v12 + 112);
  LODWORD(v32) = 28;
  v33 = v13 + (v11 & 0xFFFFFFFC);
  v31 = v9;
  if ( *(v15 - 1) != -1055839300 )
    __break(0x822Bu);
  v18 = ((__int64 (__fastcall *)(__int64, __int64, __int64 *, __int64, __int64, __int64, _QWORD))v15)(
          v16,
          28,
          &v31,
          56,
          a5,
          a6,
          a3);
  if ( v18 )
  {
    v19 = v18;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_add_comp_wait",
      1541,
      "wait_comp_event addition failed for dual vfe");
    result = v19;
  }
  else
  {
    v23 = HIDWORD(v34);
    if ( HIDWORD(v34) )
    {
      v24 = *(unsigned int *)(a1 + 40);
      v25 = a1;
      v26 = a4;
      *(_DWORD *)(*(_QWORD *)(a1 + 32) + 32 * v24) = *(_DWORD *)a4;
      *(_DWORD *)(*(_QWORD *)(a1 + 32) + 32 * v24 + 8) = v23;
      *(_DWORD *)(*(_QWORD *)(a1 + 32) + 32 * v24 + 4) = *(_DWORD *)(a4 + 16);
      *(_DWORD *)(*(_QWORD *)(a1 + 32) + 32 * v24 + 12) = 3;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v30 = v24;
        v29 = v23;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_isp_add_comp_wait",
          1560,
          "num_ent=%d handle=0x%x, len=%u, offset=%u",
          v24,
          *(_DWORD *)(*(_QWORD *)(a1 + 32) + 32 * v24),
          *(_DWORD *)(*(_QWORD *)(a1 + 32) + 32 * v24 + 8),
          *(_DWORD *)(*(_QWORD *)(a1 + 32) + 32 * v24 + 4));
        v23 = v29;
        LODWORD(v24) = v30;
        v25 = a1;
        v26 = a4;
      }
      result = 0;
      v27 = *(_DWORD *)(v26 + 24) + v23;
      v28 = *(_DWORD *)(v26 + 16) + v23;
      *(_DWORD *)(v26 + 24) = v27;
      *(_DWORD *)(v26 + 16) = v28;
      *(_DWORD *)(v25 + 40) = v24 + 1;
    }
    else
    {
      result = 0;
    }
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
