__int64 __fastcall zte_cam_cci_i2c_write(__int64 a1, int a2, int a3, int a4, int a5)
{
  unsigned int v5; // w19
  _QWORD *v6; // x9
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 (__fastcall *v9)(__int64, __int64); // x8
  __int64 (__fastcall *v10)(__int64, __int64); // x9
  _DWORD v12[2]; // [xsp+0h] [xbp-60h] BYREF
  __int64 v13; // [xsp+8h] [xbp-58h]
  __int64 v14; // [xsp+10h] [xbp-50h]
  _QWORD *v15; // [xsp+18h] [xbp-48h]
  __int64 v16; // [xsp+20h] [xbp-40h]
  _DWORD *v17; // [xsp+28h] [xbp-38h]
  __int64 v18; // [xsp+30h] [xbp-30h]
  __int64 v19; // [xsp+38h] [xbp-28h]
  __int64 v20; // [xsp+40h] [xbp-20h]
  __int64 v21; // [xsp+48h] [xbp-18h]
  __int64 v22; // [xsp+50h] [xbp-10h]
  __int64 v23; // [xsp+58h] [xbp-8h]

  v5 = -14;
  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)(a4 - 5) >= 0xFFFFFFFC && (unsigned int)(a5 - 5) >= 0xFFFFFFFC )
  {
    v18 = 0;
    v19 = 0;
    v17 = v12;
    v16 = 6;
    v6 = *(_QWORD **)(a1 + 16);
    v21 = 0;
    v22 = 0;
    v20 = 0;
    v12[0] = a2;
    v12[1] = a3;
    v13 = 0;
    v14 = 0;
    v15 = v6;
    HIDWORD(v18) = a4;
    LODWORD(v19) = a5;
    LODWORD(v18) = 1;
    v7 = *v6;
    if ( *v6 )
    {
      v8 = **(_QWORD **)(v7 + 160);
      if ( v8 && (v9 = *(__int64 (__fastcall **)(__int64, __int64))(v8 + 56)) != nullptr )
      {
        if ( !v4l2_subdev_call_wrappers
          || (v10 = *(__int64 (__fastcall **)(__int64, __int64))(v4l2_subdev_call_wrappers + 56LL)) == nullptr )
        {
          v10 = v9;
        }
        if ( *((_DWORD *)v10 - 1) != 1356305480 )
          __break(0x8229u);
        v5 = v10(v7, 3225966295LL);
        if ( (v5 & 0x80000000) == 0 )
        {
          v5 = v14;
          goto LABEL_16;
        }
      }
      else
      {
        v5 = -515;
      }
    }
    else
    {
      v5 = -19;
    }
    printk(&unk_4078D2);
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return v5;
}
