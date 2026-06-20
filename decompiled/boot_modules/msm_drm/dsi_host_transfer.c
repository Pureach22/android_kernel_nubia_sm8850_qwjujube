__int64 __fastcall dsi_host_transfer(__int64 a1, __int64 *a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x10
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 result; // x0
  __int64 v8; // [xsp+8h] [xbp-48h] BYREF
  __int64 v9; // [xsp+10h] [xbp-40h]
  __int64 v10; // [xsp+18h] [xbp-38h]
  __int64 v11; // [xsp+20h] [xbp-30h]
  __int64 v12; // [xsp+28h] [xbp-28h]
  __int128 v13; // [xsp+30h] [xbp-20h]
  __int64 v14; // [xsp+40h] [xbp-10h]
  __int64 v15; // [xsp+48h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  v12 = 0;
  v13 = 0u;
  v10 = 0;
  v11 = 0;
  v8 = 0;
  v9 = 0;
  if ( a2 )
  {
    v2 = a2[2];
    v3 = a2[3];
    v4 = a2[4];
    *(_QWORD *)((char *)&v13 + 4) = 0;
    HIDWORD(v13) = 0;
    v10 = v2;
    v11 = v3;
    v6 = *a2;
    v5 = a2[1];
    v12 = v4;
    v8 = v6;
    v9 = v5;
    result = (int)((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))dsi_host_transfer_sub)(a1, &v8, 0);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
