__int64 __fastcall rpmh_flush(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  unsigned int v5; // w8
  unsigned int i; // w22
  int *v7; // x27
  int v8; // w9
  int v9; // w10
  int v11; // w8
  int v12; // w8
  int v13; // w9
  __int64 v14; // [xsp+0h] [xbp-F0h] BYREF
  __int64 v15; // [xsp+8h] [xbp-E8h]
  int *v16; // [xsp+10h] [xbp-E0h]
  int v17; // [xsp+18h] [xbp-D8h] BYREF
  int v18; // [xsp+1Ch] [xbp-D4h]
  __int64 v19; // [xsp+20h] [xbp-D0h]
  __int64 v20; // [xsp+28h] [xbp-C8h]
  __int64 v21; // [xsp+30h] [xbp-C0h]
  __int64 v22; // [xsp+38h] [xbp-B8h]
  __int64 v23; // [xsp+40h] [xbp-B0h]
  __int64 v24; // [xsp+48h] [xbp-A8h]
  __int64 v25; // [xsp+50h] [xbp-A0h]
  __int64 v26; // [xsp+58h] [xbp-98h]
  __int64 v27; // [xsp+60h] [xbp-90h]
  __int64 v28; // [xsp+68h] [xbp-88h]
  __int64 v29; // [xsp+70h] [xbp-80h]
  __int64 v30; // [xsp+78h] [xbp-78h]
  __int64 v31; // [xsp+80h] [xbp-70h]
  __int64 v32; // [xsp+88h] [xbp-68h]
  __int64 v33; // [xsp+90h] [xbp-60h]
  __int64 v34; // [xsp+98h] [xbp-58h]
  __int64 v35; // [xsp+A0h] [xbp-50h]
  __int64 v36; // [xsp+A8h] [xbp-48h]
  __int64 v37; // [xsp+B0h] [xbp-40h]
  __int64 v38; // [xsp+B8h] [xbp-38h]
  __int64 v39; // [xsp+C0h] [xbp-30h]
  __int64 v40; // [xsp+C8h] [xbp-28h]
  __int64 v41; // [xsp+D0h] [xbp-20h]
  __int64 v42; // [xsp+D8h] [xbp-18h]
  __int64 v43; // [xsp+E0h] [xbp-10h]
  __int64 v44; // [xsp+E8h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a1 + 4) != 1 )
  {
LABEL_16:
    rpmh_rsc_write_next_wakeup(a1 - 1152);
    result = 0;
    goto LABEL_17;
  }
  rpmh_rsc_invalidate(a1 - 1152, a2);
  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))rpmh_rsc_write_ctrl_data)(a1 - 1152, a1 + 16, a2);
  if ( !(_DWORD)result )
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))rpmh_rsc_write_ctrl_data)(a1 - 1152, a1 + 248, a2);
    if ( !(_DWORD)result )
    {
      v5 = *(_DWORD *)(a1 + 480);
      if ( v5 )
      {
        for ( i = 0; i < v5; ++i )
        {
          v7 = (int *)(*(_QWORD *)(a1 + 488) + 32LL * (int)i);
          v8 = v7[1];
          if ( v8 != -1 )
          {
            v9 = v7[2];
            if ( v9 != -1 && v8 != v9 )
            {
              v11 = *v7;
              v42 = 0;
              v43 = 0;
              v40 = 0;
              v41 = 0;
              v38 = 0;
              v39 = 0;
              v36 = 0;
              v37 = 0;
              v34 = 0;
              v35 = 0;
              v32 = 0;
              v33 = 0;
              v30 = 0;
              v31 = 0;
              v28 = 0;
              v29 = 0;
              v26 = 0;
              v27 = 0;
              v24 = 0;
              v25 = 0;
              v22 = 0;
              v23 = 0;
              v20 = 0;
              v21 = 0;
              v19 = 0;
              v15 = 1;
              v14 = 0;
              v16 = &v17;
              v17 = v11;
              v18 = v8;
              result = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))rpmh_rsc_write_ctrl_data)(
                         a1 - 1152,
                         &v14,
                         a2);
              if ( (_DWORD)result )
                goto LABEL_17;
              v12 = *v7;
              v13 = v7[2];
              v42 = 0;
              v43 = 0;
              v40 = 0;
              v41 = 0;
              v38 = 0;
              v39 = 0;
              v36 = 0;
              v37 = 0;
              v34 = 0;
              v35 = 0;
              v32 = 0;
              v33 = 0;
              v30 = 0;
              v31 = 0;
              v28 = 0;
              v29 = 0;
              v26 = 0;
              v27 = 0;
              v24 = 0;
              v25 = 0;
              v22 = 0;
              v23 = 0;
              v20 = 0;
              v21 = 0;
              v19 = 0;
              v15 = 1;
              v14 = 0x100000001LL;
              v16 = &v17;
              v17 = v12;
              v18 = v13;
              result = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))rpmh_rsc_write_ctrl_data)(
                         a1 - 1152,
                         &v14,
                         a2);
              if ( (_DWORD)result )
                goto LABEL_17;
              v5 = *(_DWORD *)(a1 + 480);
            }
          }
        }
      }
      *(_BYTE *)(a1 + 4) = 0;
      goto LABEL_16;
    }
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
