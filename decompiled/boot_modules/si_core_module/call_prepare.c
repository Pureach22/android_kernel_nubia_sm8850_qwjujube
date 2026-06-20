unsigned __int64 __fastcall call_prepare(__int64 a1, unsigned int a2, __int64 a3)
{
  _DWORD *v6; // x23
  unsigned __int64 result; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x5
  __int64 v13; // x6
  __int64 v14; // x7
  _DWORD *v15; // x8
  __int64 v16; // x9
  unsigned int *si_object; // x0
  _DWORD *v18; // x8
  unsigned int *v19; // x24
  __int64 v20; // x0
  unsigned __int64 v21; // x22
  int v22; // w8
  int v23; // w21
  _QWORD *v24; // x0
  __int64 v25; // x2
  _QWORD *v26; // x1
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x9
  unsigned __int64 v29; // x8
  _QWORD v30[2]; // [xsp+0h] [xbp-50h] BYREF
  __int64 v31; // [xsp+10h] [xbp-40h]
  __int64 v32; // [xsp+18h] [xbp-38h]
  unsigned __int64 v33; // [xsp+20h] [xbp-30h]
  __int64 v34; // [xsp+28h] [xbp-28h]
  __int64 v35; // [xsp+30h] [xbp-20h]
  __int64 v36; // [xsp+38h] [xbp-18h]
  __int64 v37; // [xsp+40h] [xbp-10h]
  __int64 v38; // [xsp+48h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_DWORD **)a3;
  result = si_object_type(a2);
  if ( (_DWORD)result == 2 )
  {
    v15 = *(_DWORD **)a3;
    v16 = *(_QWORD *)(a3 + 8);
    v36 = 0;
    v37 = 0;
    v34 = 0;
    v35 = 0;
    v33 = 0;
    v30[1] = v15 + 6;
    v31 = v16 - 24;
    v30[0] = 2;
    v32 = 4;
    si_object = qtee_get_si_object(a2, v8, v9, v10, v11, v12, v13, v14);
    v18 = *(_DWORD **)(*((_QWORD *)si_object + 3) + 32LL);
    if ( v18 )
    {
      v19 = si_object;
      if ( *(v18 - 1) != 754366907 )
        __break(0x8228u);
      v20 = ((__int64 (__fastcall *)(unsigned int *, _QWORD *))v18)(si_object, v30);
      if ( v20 != 65533 )
      {
        v21 = v33;
        v22 = v20;
        si_object = v19;
        v6[4] = a2;
        if ( v21 && (v21 == 1 || *(_DWORD *)(v21 + 12) != 16) )
        {
          v23 = v22;
          if ( (unsigned int)get_object_id(v21, v6 + 5) )
          {
            si_object = (unsigned int *)v21;
            goto LABEL_18;
          }
          get_si_object(v21);
          v24 = (_QWORD *)(v21 + 32);
          v25 = a1 + 1576;
          v26 = *(_QWORD **)(a1 + 1584);
          if ( v21 + 32 == a1 + 1576 || v26 == v24 || *v26 != v25 )
          {
            _list_add_valid_or_report(v24, v26);
          }
          else
          {
            *(_QWORD *)(a1 + 1584) = v24;
            *(_QWORD *)(v21 + 32) = v25;
            *(_QWORD *)(v21 + 40) = v26;
            *v26 = v24;
          }
          si_object = v19;
          v22 = v23;
        }
        v6[1] = v22;
        v6[2] = 1;
        *v6 = 65538;
        v27 = (v31 + 31) & 0xFFFFFFFFFFFFFFF8LL;
        v28 = *(_QWORD *)a3 + v27;
        v29 = *(_QWORD *)(a3 + 8) - v27;
        *(_QWORD *)a3 = v28;
        *(_QWORD *)(a3 + 8) = v29;
        goto LABEL_18;
      }
      si_object = v19;
    }
LABEL_18:
    result = put_si_object((unsigned __int64)si_object);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
