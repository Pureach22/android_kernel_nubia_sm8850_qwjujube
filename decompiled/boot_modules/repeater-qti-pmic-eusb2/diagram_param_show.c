__int64 __fastcall diagram_param_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 *v3; // x22
  void (**v5)(void); // x8
  void (*v6)(void); // x8
  __int64 v7; // x19
  __int64 v8; // x21
  _DWORD *v9; // x9
  __int64 v10; // x0
  __int64 v11; // x21
  _DWORD *v12; // x9
  __int64 v13; // x0
  __int64 v14; // x21
  _DWORD *v15; // x9
  __int64 v16; // x0
  __int64 v17; // x21
  _DWORD *v18; // x9
  __int64 v19; // x0
  __int64 v20; // x21
  _DWORD *v21; // x9
  __int64 v22; // x0
  __int64 v23; // x8
  int v24; // w19
  __int64 result; // x0
  _BYTE v26[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(__int64 **)(a1 + 152);
  if ( v3 )
  {
    if ( v3[11] )
    {
      mutex_lock(v3 + 4);
      v5 = (void (**)(void))v3[1];
      if ( v5 && *v3 )
      {
        v6 = *v5;
        v7 = v3[11];
        v26[0] = 0;
        if ( *((_DWORD *)v6 - 1) != 1459254474 )
          __break(0x8228u);
        v6();
        v8 = v7 + (int)scnprintf(v7, 4096, "0x%02x,0x%02x,", 81, v26[0]);
        v9 = *(_DWORD **)v3[1];
        v10 = *v3;
        if ( *(v9 - 1) != 1459254474 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _BYTE *, __int64, __int64))v9)(v10, v26, 82, 1);
        v11 = v8 + (int)scnprintf(v8, 4096, "0x%02x,0x%02x,", 82, v26[0]);
        v12 = *(_DWORD **)v3[1];
        v13 = *v3;
        if ( *(v12 - 1) != 1459254474 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _BYTE *, __int64, __int64))v12)(v13, v26, 83, 1);
        v14 = v11 + (int)scnprintf(v11, 4096, "0x%02x,0x%02x,", 83, v26[0]);
        v15 = *(_DWORD **)v3[1];
        v16 = *v3;
        if ( *(v15 - 1) != 1459254474 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _BYTE *, __int64, __int64))v15)(v16, v26, 84, 1);
        v17 = v14 + (int)scnprintf(v14, 4096, "0x%02x,0x%02x,", 84, v26[0]);
        v18 = *(_DWORD **)v3[1];
        v19 = *v3;
        if ( *(v18 - 1) != 1459254474 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _BYTE *, __int64, __int64))v18)(v19, v26, 86, 1);
        v20 = v17 + (int)scnprintf(v17, 4096, "0x%02x,0x%02x,", 86, v26[0]);
        v21 = *(_DWORD **)v3[1];
        v22 = *v3;
        if ( *(v21 - 1) != 1459254474 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _BYTE *, __int64, __int64))v21)(v22, v26, 87, 1);
        v23 = v20 + (int)scnprintf(v20, 4096, "0x%02x,0x%02x,", 87, v26[0]);
        if ( v23 != v7 )
          *(_BYTE *)(v23 - 1) = 10;
        v24 = v23 - v7;
        if ( v24 >= 1 )
          v24 = scnprintf(a3, 4096, "%s", (const char *)v3[11]);
      }
      else
      {
        v24 = -22;
      }
      mutex_unlock(v3 + 4);
      result = v24;
    }
    else
    {
      result = -12;
    }
  }
  else
  {
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
